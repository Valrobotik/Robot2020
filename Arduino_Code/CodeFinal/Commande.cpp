#include "Commande.h"
#include "Gcode.h"



void Commande::executerGcode(String commande){
  gcode.DecompoGcode(commande); //Décomposition du Gcode dans les différentes variables
  // gcode.affiche();

  // Test de la présence de le lettre M
  // M en premier, car c'est elle qui determine l'arret des moteurs.
  if (gcode.hasM()){
    switch (gcode.m_M){
      case 0:
      // Arret
      arret();
      break;

      case 1:
      // Commande à définir
      break;
    }
  }

  // Test de la présence de G
  else if (gcode.hasG()){
    //Test de la varible G
    switch (gcode.m_G){
      case 20:
      // Fonction pour move
      Point coor;
      //Serial.println(gcode.m_X);
      coor.x = gcode.m_X;
      coor.y = gcode.m_Y;
      move(coor);
      break;

      case 1:
      // Commande à définir
      break;
    }
  }

  // Variable de Test en L
  else if (gcode.hasL())
  {
    switch (int(gcode.m_L)){
      case 0:
      digitalWrite(3, LOW);
      break;

      case 1:
      digitalWrite(3, HIGH);
      break;
    }
  }



}



/**
 * Espace de détermination des différentes fonctions
 */

void Commande::move(Point coor){
  /*Serial.print("Move aux coordonnées : X =");
  Serial.print(coor.x);
  Serial.print(" Y =");
  Serial.println(coor.y);*/
  Point coorStat = coor;
  motorControl.go(&coor);
  
}


void Commande::arret(){
  Serial.println("Arret");
}




void Commande::run() {
  
  static int k;

  if (!k)
      k = 1;
  else
    k++;
  this->motorControl.run();
  
  
  int i=0;
  char commandebuffer[200];

  if (Serial.available())  {
      //delay(100);
      k = 0;
    while (Serial.available() && i<99){
          delay(10);
          commandebuffer[i++] = Serial.read();
      }
    commandebuffer[i++]='\0';
       this->executerGcode(commandebuffer);
    }
    
    //Serial.print("Message =");
    //Serial.println(message);
 
}




void Commande::setup() {
  m_motorLParam.StepPin = L_STEP_PIN;
  m_motorLParam.DirectionPin = L_DIRECTION_PIN;
  m_motorLParam.EnablePin = L_ENABLE_PIN;

  m_motorRParam.StepPin = R_STEP_PIN;
  m_motorRParam.DirectionPin = R_DIRECTION_PIN;
  m_motorRParam.EnablePin = R_ENABLE_PIN;
  this->motorControl.setup(m_motorLParam, m_motorRParam);
} 
