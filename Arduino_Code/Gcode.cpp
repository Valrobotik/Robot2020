#include "Gcode.h"



/**
 * Fonction pour traduire le Gcode et le décomposer en petits parramétres.
 * Les parramètres reçus restent en mémoire ! (A chaques nouvelles receptions, les variables ne sont pas remise à zero)
 * @param commande : Gcode en entier de taille 190 octets
 */
void Gcode::traductiongcode(String commande){
  // Serial.print(commande);

  int c = 0; //Incrément de la boucle principale
  int sub_c = 0; //Incrément pour le substring (petite tranche de la liste)
  int tString = 190; //Taille max du string

  for (c=0; c < tString; c++){
    //On parcourt le string carractère par carractère


    if ( isDigit(commande[c]) ){
      //Increment pour determiner la taille du sub string contenant les nombres
      sub_c++;
    }
    else {
      //Ici on a la position d'un nombre, on lui associe alors la lettre correspondantes.
      //On assigne les variables (ABCD...) avec la fonction compare.
      Compare(commande, String(commande[c-sub_c-1]), c, sub_c );

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


  /*---------------------
  ---------Test
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
