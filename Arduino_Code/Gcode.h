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
  float m_A = 0.0;
  float m_B = 0.0;
  float m_C = 0.0;
  float m_D = 0.0;
  float m_E = 0.0;
  float m_F = 0.0;
  float m_G = 0.0;
  float m_H = 0.0;
  float m_I = 0.0;
  float m_J = 0.0;
  float m_K = 0.0;
  float m_L = 0.0;
  float m_M = 0.0;
  float m_N = 0.0;
  float m_O = 0.0;
  float m_P = 0.0;
  float m_Q = 0.0;
  float m_R = 0.0;
  float m_S = 0.0;
  float m_T = 0.0;
  float m_U = 0.0;
  float m_V = 0.0;
  float m_W = 0.0;
  float m_X = 0.0;
  float m_Y = 0.0;
  float m_Z = 0.0;


};
#endif
