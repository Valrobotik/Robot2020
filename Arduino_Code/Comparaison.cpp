#include "Gcode.h"


/**
 * Permet de mettre dans les variables m_X les valeurs correspondantes données par le Gcode.
 * On crée un substring à partir de la position du dernier chiffre.
 * @param stringcomplet Le Gcode complet où l'on va extraire les valeurs
 * @param lettre        La lettre dont l'on veut extraire la valeur
 * @param c             Position du dernier chiffre à extraire
 * @param sub_c         Nombre de chiffres à extraires
 */
void Gcode::Compare(String stringcomplet, int lettre, int c, int sub_c){

  switch (lettre) {

    case 'A':
      m_A = stringcomplet.substring(c - sub_c, c).toFloat();
      if (sub_c > 0)
            param += 512;
      break;

    case 'B':
      m_B = stringcomplet.substring(c - sub_c, c).toFloat();
      if (sub_c > 0)
        param += 1024;
      break;

    case 'C':
      m_C = stringcomplet.substring(c - sub_c, c).toFloat();
      if (sub_c > 0)
        param += 2048;
      break;

    case 'D':
      m_D = stringcomplet.substring(c - sub_c, c).toFloat();
      if (sub_c > 0)
        param += 4096;
      break;

    case 'E':
    m_E = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 8192;
    break;

    case 'F':
    m_F = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 16384;
    break;

    case 'G':
    m_G = stringcomplet.substring(c - sub_c, c).toInt();
    if (sub_c > 0)
      param += 1;
    break;

    case 'H':
    m_H = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 32768;
    break;

    case 'I':
    m_I = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 65536;
    break;

    case 'J':
    m_J = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 131072;
    break;

    case 'K':
    m_K = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 262144;
    break;

    case 'L':
    m_L = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 524288;
    break;

    case 'M':
    m_M = stringcomplet.substring(c - sub_c, c).toInt();
    if (sub_c > 0)
      param += 2;
    break;

    case 'N':
    m_N = stringcomplet.substring(c - sub_c, c).toInt();
    if (sub_c > 0)
      param += 4;
    break;

    case 'O':
    m_O = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 1048576;
    break;

    case 'P':
    m_P = stringcomplet.substring(c - sub_c, c).toInt();
    if (sub_c > 0)
      param += 128;
    break;

    case 'Q':
    m_Q = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 2097152;
    break;

    case 'R':
    m_R = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 4194304;
    break;

    case 'S':
    m_S = stringcomplet.substring(c - sub_c, c).toInt();
    if (sub_c > 0)
      param += 64;
    break;

    case 'T':
    m_T = stringcomplet.substring(c - sub_c, c).toInt();
    if (sub_c > 0)
      param += 256;
    break;

    case 'U':
    m_U = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 8388608;
    break;

    case 'V':
    m_V = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 16777216;
    break;

    case 'W':
    m_W = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 33554432;
    break;

    case 'X':
    m_X = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 8;
    break;

    case 'Y':
    m_Y = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 16;
    break;

    case 'Z':
    m_Z = stringcomplet.substring(c - sub_c, c).toFloat();
    if (sub_c > 0)
      param += 32;
    break;

  }


}
