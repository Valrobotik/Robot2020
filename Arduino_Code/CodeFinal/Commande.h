#ifndef COMM_H
#define COMM_H

#include "Gcode.h"
#include "Control.h"

class Commande
/**
 * \brief Commande library pour Arduino
 * \brief Permet de comprendre un string Gcode et d'allouer les commandes pour le robot.
 * \author S6ril & Momo
 * \date 2019 - 2020
 * \warning La classe n'est pas complète, il faut la remplir avec les différenetes fonctions du robot.

 */
{
  public :

  /**
   * Fonction pour executer les commandes en fonction des Gcodes reçus.
   * @param commande : String Gcode complet.
   */
  void executerGcode(String commande);


  /**
   * Permet de mettre en route les moteurs.
   * Cette fonction est à placer dans la boucle while.
   **/
   void run();


  /**
   * Fonction pour définir les pins Step, Direction et Enable des 2 moteurs
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
