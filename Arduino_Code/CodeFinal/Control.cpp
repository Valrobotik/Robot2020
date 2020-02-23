#include "Control.h"



Control::Control()
{
}

/*Setup les moteurs
 */
void Control::setup(motorParam motorLParam, motorParam motorRParam)
{ //setup les moteurs
    m_motorLParam = motorLParam;
    m_motorRParam = motorRParam;

    pinMode(m_motorLParam.EnablePin, OUTPUT);
    pinMode(m_motorRParam.EnablePin, OUTPUT);

    digitalWrite(m_motorLParam.EnablePin, LOW);
    digitalWrite(m_motorRParam.EnablePin, LOW);

    m_stepperL = AccelStepper(AccelStepper::DRIVER, m_motorLParam.StepPin, m_motorLParam.DirectionPin);
    m_stepperR = AccelStepper(AccelStepper::DRIVER, m_motorRParam.StepPin, m_motorRParam.DirectionPin);
    setMaxMotor();
    reverse(true);
    m_coor.x = 0;
    m_coor.y = 0;
    
    //il faut imposer cycle à false car lors du setup aucune action n'est éxuter
    this->cycle = false;
    
}

void Control::move() {

  

  if (cycle)
  
  //On rentre dans un cycle: cela signifie que le robot est en déplacemlent
  {
    //calcule des coordonnées en relatives
  
      if (m_i==0 && m_stepperL.distanceToGo() == 0)
      {   
          
          /*//tourner d'un angla alpha
          //verifier si l'angle est bien compris en entre -2PI et 2PI
          */
          Serial.println("angle alpha: ");
          //alpha = ratioAngle(alpha);
          Serial.println(getAlpha());
          Serial.println("angle theta: ");
          //alpha = ratioAngle(alpha);
          Serial.println(m_angle);
          
          rotate(getAlpha());
          
          m_i++;
      }

      else if(m_i==1 && m_stepperL.distanceToGo() == 0)
      {
          //Puis avance
          
          avance(this->getDistance());
          
          m_i=0;
          
          int n = m_coors.size();
          
          if(n!=0) {
            
            m_coor = m_goal;
            //mise à jour en reprenant la prochaine coordonnée
            m_goal = *m_coors.remove();
           

          }else {
            cycle=!cycle;
            
          }
      }

    }
}
/*
 ** Définit la vitessse et l'accélaration maximum du robot
 ** @param: pas de paramètre
 ** @return: aucune valeurs de retour
 */
void Control::setMaxMotor()
{
    m_stepperL.setAcceleration(maxAcceleration);
    m_stepperR.setAcceleration(maxAcceleration);

    m_stepperR.setMaxSpeed(maxSpeed);
    m_stepperL.setMaxSpeed(maxSpeed);
}

/*
 * Permet d'inverser le sens d'avance du robot
*/
void Control::reverse(bool inverte)
{
    m_stepperL.setPinsInverted(inverte);
    m_stepperR.setPinsInverted(!inverte);
}

/*
 * La fonction go permet d'ajouter une coordonnée, pour que le robot puisse y aller, si le robot se déplace elle est enregistrer
 * les coordonnées sont appelés par ordre de priorité temporelle
 */
void Control::go(Point *goal) {
      
      m_coors.add(goal);
      int n = m_coors.size();
      
     
      if(n!=0 && !cycle) {
        m_goal = *m_coors.remove();
      }
      
      
      cycle = true;
}


/*
 * converti un angle donnée en nombre de step et effectue la rotation /!\ sensible au signe de l'angle
 * l'angle zéro c'est le robot placé sur l'axe y positivement
 */
void Control::rotate(float angle)
{   
    
    float distStep = DIAMETRE_ROUE* PI *REDUCTEUR / NOMBRE_STEP_1TOUR;
    //coonversion de l'angle à effectuer en nombre de pas
    float steps = (angle/2)  * 223 / distStep;
    m_angle = this->ratioAngle(m_angle + angle);
    m_stepperL.move( (long) - steps);
    m_stepperR.move( (long) steps);
}




/*
 * Converti une distance en mm, en nombre de steps (calculé en fonction des différents paramètres géométriques et 
 * techniques des moteurs) et avance
 */
void Control::avance(double distance)
{
    //conversion de la distance à effectuer en nombre de staep
    long nombreTour = distance*NOMBRE_STEP_1TOUR /(REDUCTEUR*PI*DIAMETRE_ROUE);
    
    m_stepperL.move(nombreTour);
    m_stepperR.move(nombreTour);
}


/*
 * fonction d'éxuction indispensable au fonctionnemnt de la bibliothèque AccelStepper (elle est appelé dans le fonction Loop)
 * Elle permet de générer la pwm nécessaire au fonctionnement des moteurs pas à pas
 * la fonction move est appelé, pour recalculer la distance et et l'angle à effectuer lorsque le robot ne se déplace pas
 * et lorsqu'une nouvelle coordonnée est disponible
 */
void Control::run()
{ 
    m_stepperL.run();
    m_stepperR.run();
    this->move();
}


/*
 * Cette fonction permet de réduire l'angle du robot (en calculant le modulo 2*PI situant l'angle dans l'interval 
 * [-pi, PI])Pour éviter que le robot fasse des tours sur lui même;
 */
double Control::ratioAngle(double angle) {
  double verifAngle = angle;
  if(angle<0) {
    verifAngle=-verifAngle;
  }
  while(verifAngle>2*PI){
    verifAngle-=2*PI;
  }
  if(verifAngle > PI) {
    verifAngle=-PI*2+verifAngle;
  }
  if(angle<0) {
    verifAngle = -verifAngle;
  }
  return verifAngle;
}



  /*
   * Calcul de l'angle relatif que le robot doit effectuer pour se diriger vers sa coordonnée cible
   */
double Control::getAlpha() {
      Point relative = this->getRelative();
      double alpha;
    
      //matrice de rotation (on change de repère -> celui du robot)
      double x = cos(m_angle)*relative.x + sin(m_angle)*relative.y;
      double y = cos(m_angle)*relative.y - sin(m_angle)*relative.x;
      if(y==0){
        y=0.00001;
      }
      //en fonctiondu cadran on se trouve le point goal, on clacule le bonne angle grace à arctan 
      //(en calculant l'angle avec le moins de déplacements possible)
      if(x>0&&y>0){
        alpha=-atan(x/y);
      }if(x<0&&y>0){
        alpha=-atan(x/y);
      }if(x<0&&y<0){
        alpha=PI-atan(x/y);
      }if(x>0&&y<0){
        alpha=-PI-atan(x/y);
      }
      return alpha;
}



/*
 * Calcule les coordonnée relative : calculé à partire de m_angle et de m_goal
 */
Point Control::getRelative() {
    Point relative;
    relative.x = (m_goal.x - m_coor.x);
    relative.y = (m_goal.y - m_coor.y);
    return relative;
}





/*
 * distance relative que le robot doit parcourir cette distance est calculé grâce au coordonnées relatives 
 * données par la fonction getRelative() (qui retourne une struct Point et déclaré en private)
 */
double Control::getDistance() {
  Point relative = this->getRelative();
  double distance = sqrt(relative.x*relative.x + relative.y*relative.y);
  return distance;
}
