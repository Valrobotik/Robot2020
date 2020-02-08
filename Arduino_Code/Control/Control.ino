#include "Control.h"
#include "AccelStepper.h"


motorParam motorLParam;
motorParam motorRParam;

Control controlMoteur;
Point but[3];
Point a;

void setup()
{
    Serial.begin(9600);
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
    // but[0].x=0,but[0].y=0;
    // but[1].x=0,but[1].y=500;
    // but[2].x=500,but[2].y=500;
    // but[3].x=500,but[3].y=0;
    a.x=2000;a.y=0;
    // controlMoteur.go(but[0]);
    // controlMoteur.go(but[1]);
    // controlMoteur.go(but[2]);
    // controlMoteur.go(but[3]);
}

void loop()
{
    // controlMoteur.go(but);
    //controlMoteur.go(a);
    if (controlMoteur.m_stepperL.distanceToGo() == 0)
        controlMoteur.go(a);

    controlMoteur.run();
}
