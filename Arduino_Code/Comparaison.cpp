#include "Gcode.h"


/**
 * Permet de mettre dans les variables m_X les valeurs correspondantes données par le Gcode.
 * On crée un substring à partir de la position du dernier chiffre.
 * @param stringcomplet Le Gcode complet où l'on va extraire les valeurs
 * @param lettre        La lettre dont l'on veut extraire la valeur
 * @param c             Position du dernier chiffre à extraire
 * @param sub_c         Nombre de chiffres à extraires
 */
void Gcode::Compare(String stringcomplet, String lettre, int c, int sub_c){

  if ( lettre.equals(String("A")) )
  {
    m_A = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("B")) )
  {
    m_B = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("C")) )
  {
    m_C = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("D")) )
  {
    m_D = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("E")) )
  {
    m_E = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("F")) )
  {
    m_F = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("G")) )
  {
    m_G = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("H")) )
  {
    m_H = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("I")) )
  {
    m_I = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("J")) )
  {
    m_J = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("K")) )
  {
    m_K = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("L")) )
  {
    m_L = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("M")) )
  {
    m_M = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("N")) )
  {
    m_N = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("O")) )
  {
    m_O = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("P")) )
  {
    m_P = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("Q")) )
  {
    m_Q = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("R")) )
  {
    m_R = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("S")) )
  {
    m_S = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("T")) )
  {
    m_T = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("U")) )
  {
    m_U = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("V")) )
  {
    m_V = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("W")) )
  {
    m_W = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("X")) )
  {
    m_X = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("Y")) )
  {
    m_Y = stringcomplet.substring(c - sub_c, c).toFloat();
  }
  else if ( lettre.equals(String("Z")) )
  {
    m_Z = stringcomplet.substring(c - sub_c, c).toFloat();
  }

}
