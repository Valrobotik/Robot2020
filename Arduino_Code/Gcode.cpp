#include "Gcode.h"


/**
 * Fonction pour traduire le Gcode et le décomposer en petits parramétres
 * @param commande : Gcode en entier de taille 190 octets
 */
void Gcode::traductiongcode(String commande){
  // Serial.print(commande);

  int c = 0; //Incrément de la boucle principale
  int sub_c = 0; //Incrément pour le substring
  int tstring = commande.length(); //Taille max du string


  for (c=0; c < tstring; c++){
    //On parcourt le string carractère par carractère

    if ( isAlpha(commande[c]) ){
      //Determine la lettre

      Compare(commande, String(commande[c-sub_c-1]), c, sub_c );

      // Serial.print(commande[c-sub_c - 1]);
      // Serial.print("\t");
      // Serial.println(commande.substring(c - sub_c, c));

      sub_c = 0; //remise à zero du sub string
    }

    else if ( isDigit(commande[c]) ){
      //Increment pour determiner la taille du sub string contenant les nombres
      sub_c++;
    }


  }

  /*---------------------
  ---------Test
   ----------------------*/

  Serial.print("m_A = \t");
  Serial.println(m_A);

  Serial.print("m_Y = \t");
  Serial.println(m_X);

  Serial.print("m_Z = \t");
  Serial.println(m_Y);
}
