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

    // 1 tour moteur.
    // m_stepperL.moveTo(3200 * 5);
    // m_stepperR.moveTo(3200 * 5)
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
    Point pointRelatif;
    pointRelatif.x = (goal.x - m_coor.x );
    pointRelatif.y = (goal.y - m_coor.y);

    float alpha = m_angle - atan(pointRelatif.x/pointRelatif.y);
    double distance = sqrt(pointRelatif.x*pointRelatif.x + pointRelatif.y*pointRelatif.y);

    if (cycle2)
    //Activation 1 fois.
    {
        if (m_stepperL.distanceToGo() == 0 && cycle)
        {
            //En premier la rotation.
            rotate(alpha);
            cycle = !cycle;
        }
        if (m_stepperL.distanceToGo() == 0 && !cycle)
        {
            //Puis avance
            avance(distance);
            cycle = !cycle;
            cycle2 = !cycle2;
        }
    }
}


void Control::rotate(float angle)
{
    float distStep = 62* PI *0.4*2 / 3200;
    float steps = angle  * 223 / distStep;
    m_stepperL.move( (long) - steps);
    m_stepperR.move( (long) steps);
}


void Control::avance(double distance)
{
    long nombreTour = distance*3200 /(0.4*PI*62);
    m_stepperL.move(nombreTour);
    m_stepperR.move(nombreTour);
}


void Control::run()
{
    m_stepperL.run();
    m_stepperR.run();
}
