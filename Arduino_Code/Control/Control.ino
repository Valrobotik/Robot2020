#include "Control.h"
#include <AccelStepper.h>


motorParam motorLParam;
motorParam motorRParam;

Control controlMoteur;
Point but;

void setup()
{
    //Paramétrage des Pins arduino
    motorLParam.StepPin = 6;
    motorLParam.DirectionPin = 5;
    motorLParam.EnablePin = 8;

    motorRParam.StepPin = 10;
    motorRParam.DirectionPin = 9;
    motorRParam.EnablePin = 11;

    //Définition des paramètres du moteur.
    controlMoteur.setup(motorLParam, motorRParam);

    //Point à atteindre.
    but.x=100;but.y=500;
}

void loop()
{
    controlMoteur.go(but);
    controlMoteur.run();
}
