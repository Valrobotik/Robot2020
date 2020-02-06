/*
* @Autor : Momo & Cyril
* @Requierement : AccelStepper Library
* http://www.airspayce.com/mikem/arduino/AccelStepper/
*
* Controle des moteurs pas à pas pour l'association Valrobotik INSA HDF.
*/

#include "AccelStepper.h"
#include <math.h>
#include "Config.h"
#include "Vector.h"



#ifndef DEF_CONTROL
#define DEF_CONTROL

//Strucutre pour les paramètres moteurs.
struct motorParam {
    int StepPin;
    int DirectionPin;
    int EnablePin;
};

//Structure pour les coordonnées.
struct Point {
    float x;
    float y;
};

class Control
{
public :
    Control();

    bool inverte = true;
    int m_i = 0;
    //Definition des maximums des moteurs
    float maxSpeed = 5000.0;
    float maxAcceleration = 500.0;


    //Utile pour executer 1 fois la fonction go()
    bool cycle = false;
    bool cycle2 = true;

    /*Buffer des différente position*/
    Vector<Point> m_coors;
    /*Etat de déplacement*/
    bool m_dep;
    Point m_goal;

    /*
    Maximums pour l'accélération et la vitesse des moteurs.
     */
    void setMaxMotor();

    /*
    Permet d'inverser le sens des moteurs.
     */
    void reverse(bool inverte);

    /*
    Mise en place des paramètres des moteurs pour la classe.
     */
    void setup(motorParam motorL, motorParam motorR);

    /*
    Rotation relative du robot d'un angle alpha en radian.
     */
    void rotate(float angle);

    /*
    Déplacement relatif en ligne droite du robot en mm.
     */
    void avance(double distance);

    /*
    Déplacement du robot vers un point précis de l'espace.
    Fonction à mettre dans void loop.
     */
    void go(Point goal);

    void move();
    /*
    Activation des moteurs.
    Cette fonction est à mettre dans void loop.
     */
    void run();


    Point m_coor;
    double m_angle;
    motorParam m_motorLParam;
    motorParam m_motorRParam;
    AccelStepper m_stepperL;
    AccelStepper m_stepperR;

private:



};



#endif
