#include "Control.h"



Control::Control()
{
}


void Control::setup(motorParam motorLParam, motorParam motorRParam)
{
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
    //le robot ne bouge pas: set m_dep à false!
    m_dep = false;

    // 1 tour moteur.
    // m_stepperL.moveTo(3200 * 5);
    // m_stepperR.moveTo(3200 * 5)
}

void Control::move() {

  Point pointRelatif;

  pointRelatif.x = (m_goal.x - m_coor.x );
  pointRelatif.y = (m_goal.y - m_coor.y);

  double alpha = m_angle - (double)pointRelatif.x/(double)pointRelatif.y;
  double distance = sqrt(pointRelatif.x*pointRelatif.x + pointRelatif.y*pointRelatif.y);

  if (cycle)
  //Activation 1 fois.
  {
      if (m_i==0)
      {
          //En premier la rotation.
          rotate(alpha);
          Serial.print(alpha);
          m_i++;
      }
      else if(m_i==1 && m_stepperL.distanceToGo() == 0)
      {
          //Puis avance
          Serial.print(m_i);
          avance(distance);
          m_i=0;
          int n = m_coors.size();
          if(n!=0) {
            m_coor = m_goal;
            m_goal = m_coors[0];
            m_coors.remove(0);

          }else {
            cycle=!cycle;
          }
      }

    }else { // en vérifiant si le robot se déplace ou non
      int n = m_coors.size();
      if(n!=0) {
        m_goal = m_coors[0];
        m_coors.remove(0);
        cycle2 = !cycle2;
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
    //Moteur pas dans le même sens.
    m_stepperL.setPinsInverted(inverte);
    m_stepperR.setPinsInverted(!inverte);
}


void Control::go(Point goal) {
      cycle = true;
      m_coors.push_back(goal);
      int n = m_coors.size();
      if(n!=0) {
        m_goal = m_coors[0];
        m_coors.remove(0);

      }


}


void Control::rotate(float angle)
{
    float distStep = DIAMETRE_ROUE* PI *REDUCTEUR*2 / NOMBRE_STEP_1TOUR;
    float steps = angle  * 223 / distStep;
    Serial.print(steps);
    m_stepperL.move( (long) - steps);
    m_stepperR.move( (long) steps);
}


void Control::avance(double distance)
{
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
