#include "Control.h"



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


void Control::setMaxMotor()
{
    m_stepperL.setAcceleration(maxAcceleration);
    m_stepperR.setAcceleration(maxAcceleration);

    m_stepperR.setMaxSpeed(maxSpeed);
    m_stepperL.setMaxSpeed(maxSpeed);
}


void Control::reverse(bool inverte)
{
    m_stepperL.setPinsInverted(inverte);
    m_stepperR.setPinsInverted(!inverte);
}

void Control::go(Point *goal) {

      m_coors.add(goal);
      int n = m_coors.size();


      if(n!=0 && !cycle) {
        m_goal = *m_coors.remove();
      }


      cycle = true;
}



void Control::rotate(float angle)
{

    float distStep = DIAMETRE_ROUE* PI *REDUCTEUR / NOMBRE_STEP_1TOUR;
    //coonversion de l'angle à effectuer en nombre de pas
    float steps = (angle/2)  * 223 / distStep;
    m_angle = this->ratioAngle(m_angle + angle);
    m_stepperL.move( (long) - steps);
    m_stepperR.move( (long) steps);
}

void Control::avance(double distance)
{
    //conversion de la distance à effectuer en nombre de staep
    long nombreTour = distance*NOMBRE_STEP_1TOUR /(REDUCTEUR*PI*DIAMETRE_ROUE);

    m_stepperL.move(nombreTour);
    m_stepperR.move(nombreTour);
}

void Control::run()
{
    m_stepperL.run();
    m_stepperR.run();
    this->move();
}


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


Point Control::getRelative() {
    Point relative;
    relative.x = (m_goal.x - m_coor.x);
    relative.y = (m_goal.y - m_coor.y);
    return relative;
}


double Control::getDistance() {
  Point relative = this->getRelative();
  double distance = sqrt(relative.x*relative.x + relative.y*relative.y);
  return distance;
}
