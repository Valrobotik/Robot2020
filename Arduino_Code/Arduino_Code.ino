#include "Gcode.h"
#include "Commande.h"


String message;


Commande commande;
//Creation de l'objet pour traduire le Gcode

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  // String Text = "A1B2C3D4E5F6G20H8I9J10K11L12M13N14O15P16Q17S19T20U21V22W23X24Y25Z26";
  // String Text = "G20M0X12Y54";
  // commande.executerGcode(Text);
}

void loop() {
  if (Serial.available())  {
    message = Serial.readString();

    Serial.print("Message =");
    Serial.println(message);
    commande.executerGcode(message);

  }

}
