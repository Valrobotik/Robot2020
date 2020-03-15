#ifndef DEF_CONTROL
#define DEF_CONTROL

#include "AccelStepper.h"
#include <math.h>
#include "Config.h"
#include "coorTab.h"


class Control
/**
 * \brief Control library for Arduino
 * \brief Controle des moteurs pas à pas
 * \author Momo & Cyril
 * \date 2019-2020
 */
{
public :

    /**
    Permet d'inverser le sens de rotation
     */
    bool inverte = true;
    int m_i = 0;

    /**
    * Permet de définir le maximum en vitesse
    */
    float maxSpeed = 8000.0;

    /**
    * Permet de définir le maximum en accélération
    */
    float maxAcceleration = 1000.0;


    /**
    Execute seulement une fois la fonction go
     */
    bool cycle = false;

    /**
    * Buffer des différente position
    */
    coorTab m_coors;
    /**
    * Etat de déplacement
    */
    Point m_goal;

    /**
    * Maximums pour l'accélération et la vitesse des moteurs.
    */
    void setMaxMotor();

    /**
    * Permet d'inverser le sens des moteurs.
    */
    void reverse(bool inverte);

    /**
    * Mise en place des paramètres des moteurs pour la classe.
    */
    void setup(motorParam motorL, motorParam motorR);

    /**
    * Converti un angle donnée en nombre de step et effectue la rotation /!\ sensible au signe de l'angle
    * l'angle zéro c'est le robot placé sur l'axe x positivement
    * @param angle angle de rotation
    */
    void rotate(float angle);

   /**
    * Converti une distance en mm, en nombre de steps (calculé en fonction des différents paramètres géométriques et techniques des moteurs) et avance
    * @param distance distance à avancer
    */
    void avance(double distance);

   /**
    * La fonction go permet d'ajouter une coordonnée, pour que le robot puisse y aller, si le robot se déplace elle est enregistrer
    * les coordonnées sont appelés par ordre de priorité temporelle
    * @param goal le prochain point où aller.
    */
    void go(Point *goal);

    /**
     * Permet de faire déplacer le robot.
     * Avec cycle, on execute une premier rotation vers le point, puis on execute la translation vers le point désiré.
     */
    void move();

    /**
    * fonction d'éxuction indispensable au fonctionnemnt de la bibliothèque AccelStepper (elle est appelé dans le fonction Loop)
    * Elle permet de générer la pwm nécessaire au fonctionnement des moteurs pas à pas
    * la fonction move est appelé, pour recalculer la distance et et l'angle à effectuer lorsque le robot ne se déplace pas
    * et lorsqu'une nouvelle coordonnée est disponible
    */
    void run();

    /**
    * rationnalise l'angle souitée;
    * en calculant le modulo 2pi
    */

    /**
    * Cette fonction permet de réduire l'angle du robot (en calculant le modulo 2*PI situant l'angle dans l'interval
    * [-pi, PI])Pour éviter que le robot fasse des tours sur lui même;
    */
    double ratioAngle(double angle);

    Point m_coor;
    double m_angle;
    motorParam m_motorLParam;
    motorParam m_motorRParam;
    AccelStepper m_stepperL;
    AccelStepper m_stepperR;

private:
    //foonctions de calcules

    /**
    * Calcul de l'angle relatif que le robot doit effectuer pour se diriger vers sa coordonnée cible
    */
    double getAlpha();

    /**
    * distance relative que le robot doit parcourir cette distance est calculé grâce au coordonnées relatives
    * données par la fonction getRelative() (qui retourne une struct Point et déclaré en private)
    */
    double getDistance();

    /**
     * Calcule les coordonnée relative : calculé à partire de m_angle et de m_goal
     */
    Point getRelative();
};



#endif
