#ifndef GCODE_H
#define GCODE_H

#include <Arduino.h>





class Gcode
{
  public :
  //Fonction pour décripter le Gcode
  void traductiongcode(String commande);
  void Compare(String stringcomplet, String lettre, int c, int sub_c);


  private :

  // Assignation des différentes variables à décomposer du Gcode
  String m_A = "";
  String m_B = "";
  String m_C = "";
  String m_D = "";
  String m_E = "";
  String m_F = "";
  String m_G = "";
  String m_H = "";
  String m_I = "";
  String m_J = "";
  String m_K = "";
  String m_L = "";
  String m_M = "";
  String m_N = "";
  String m_O = "";
  String m_P = "";
  String m_Q = "";
  String m_R = "";
  String m_S = "";
  String m_T = "";
  String m_U = "";
  String m_V = "";
  String m_W = "";
  String m_X = "";
  String m_Y = "";
  String m_Z = "";


};
#endif
