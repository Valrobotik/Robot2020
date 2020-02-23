#ifndef COMM_H
#define COMM_H

#include "Gcode.h"
#include "Control.h"


/**
 * Classe pour comprendre les Gcodes et agir avec le robot.
 * !!!!!!!!!!!!!!!!!!!!
 * La classe n'est pas complète, il faut la remplir avec les différenetes fonctions du robot.
 * !!!!!!!!!!!!!!!!!!!!
 */
class Commande
{
  public :
  
  
  /**
   * Fonction pour executer les commandes en fonction des Gcodes reçus.
   * @param commande : String Gcode complet.
   */
  void executerGcode(String commande);
  
  
  /**
   * 
   **/
   void run();
   
   
  /**
   * 
   **/
   void setup();
  Control motorControl;

  private :
  
  Gcode gcode;  // Définition de la variable Gcode qui récupéra les différentes variables du Gcode.

  /**
   * Fonction pour bouger le robot vers les coordonnées X,Y.
   * Les coordonées doivent être des floats.
   * @param X float de la coordonnée X
   * @param Y float de la coordonnée Y
   */
  void move(Point coor);

  /**
   * Arret des moteurs du robot.
   */
  void arret();
  motorParam m_motorLParam;
  motorParam m_motorRParam;



};
#endif
