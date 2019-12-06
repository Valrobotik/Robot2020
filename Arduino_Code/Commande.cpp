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
      move(gcode.m_X, gcode.m_Y);
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

void Commande::move(float X, float Y){
  Serial.print("Move aux coordonnées : X =");
  Serial.print(X);
  Serial.print(" Y =");
  Serial.println(Y);
}


void Commande::arret(){
  Serial.println("Arret");
}
