#include "Gcode.h"

Gcode gcode();

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {

  gcode.traductiongcode();
}
