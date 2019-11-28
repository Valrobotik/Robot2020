#include "Gcode.h"

String message;



Gcode gcode;
//Creation de l'objet pour traduire le Gcode

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  String Text = "A1B2C3D4E5F6G7H8I9J10K11L12M13N14O15P16Q17S19T20U21V22W23X24Y25Z26";
  //String Text = "A25Z15";
  gcode.traductiongcode(Text);
  Serial.println(gcode.hasA() );
}

void loop() {
  // if (Serial.available())  {
  //   message = Serial.readString();
  //
  //   Serial.print("Message =");
  //   Serial.println(message);
  //   gcode.traductiongcode(message);
  // }

}
