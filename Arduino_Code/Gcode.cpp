#include "Gcode.h"



/**
 * Fonction pour traduire le Gcode et le décomposer en petits parramétres.
 * Les parramètres reçus restent en mémoire ! (A chaques nouvelles receptions, les variables ne sont pas remise à zero)
 * Les décimaux sont séparés par un POINT (.)
 * @param commande : Gcode en entier de taille 190 octets
 */
void Gcode::traductiongcode(String commande){
  // Serial.print(commande);

  int c = 0; //Incrément de la boucle principale
  int sub_c = 0; //Incrément pour le substring (petite tranche de la liste)
  int tString = 190; //Taille max du string
  param=0;

  for (c=0; c < tString; c++){
    //On parcourt le string carractère par carractère


    if ( isDigit(commande[c]) || isPunct(commande[c]) ){
      //Increment pour determiner la taille du sub string contenant les nombres
      sub_c++;
    }
    else {
      //Ici on a la position d'un nombre, on lui associe alors la lettre correspondantes.
      //On assigne les variables (ABCD...) avec la fonction compare.
      //Pour la propreté du code, la comparaison se fait dans un autre fichier.
      Compare(commande, commande[c-sub_c-1], c, sub_c );


      // Serial.print(commande[c-sub_c - 1]);
      // Serial.print("\t");
      // Serial.print(commande.substring(c - sub_c, c));
      // Serial.print("\t");
      // Serial.print(c);
      // Serial.print("\t");
      // Serial.println(sub_c);

      sub_c = 0; //remise à zero du sub string
    }

  }
}








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
    break;
      param += 33554432;

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


void Gcode::affiche()
{
  /*---------------------
  ---------Test
  Attention l'affichage print() n'imprime que 2 décimales.
  ----------------------*/
  Serial.print("Traduction =\n");

  Serial.print("m_A = \t");
  Serial.println(m_A);

  Serial.print("m_B = \t");
  Serial.println(m_B);

  Serial.print("m_C = \t");
  Serial.println(m_C);

  Serial.print("m_D = \t");
  Serial.println(m_D);

  Serial.print("m_E = \t");
  Serial.println(m_E);

  Serial.print("m_F = \t");
  Serial.println(m_F);

  Serial.print("m_G = \t");
  Serial.println(m_G);

  Serial.print("m_H = \t");
  Serial.println(m_H);

  Serial.print("m_I = \t");
  Serial.println(m_I);

  Serial.print("m_J = \t");
  Serial.println(m_J);

  Serial.print("m_K = \t");
  Serial.println(m_K);

  Serial.print("m_L = \t");
  Serial.println(m_L);

  Serial.print("m_M = \t");
  Serial.println(m_M);

  Serial.print("m_N = \t");
  Serial.println(m_N);

  Serial.print("m_O = \t");
  Serial.println(m_O);

  Serial.print("m_P = \t");
  Serial.println(m_P);

  Serial.print("m_Q = \t");
  Serial.println(m_Q);

  Serial.print("m_R = \t");
  Serial.println(m_R);

  Serial.print("m_S = \t");
  Serial.println(m_S);

  Serial.print("m_T = \t");
  Serial.println(m_T);

  Serial.print("m_U = \t");
  Serial.println(m_U);

  Serial.print("m_V = \t");
  Serial.println(m_V);

  Serial.print("m_W = \t");
  Serial.println(m_W);

  Serial.print("m_X = \t");
  Serial.println(m_X);

  Serial.print("m_Y = \t");
  Serial.println(m_Y);

  Serial.print("m_Z = \t");
  Serial.println(m_Z);
}
