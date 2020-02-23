#include "Commande.h"

Commande com;
void setup() {
   Serial.begin(9600);
   Serial.flush();
	com.setup();
  //static Point a;a.x=100;a.y=100;
  
  //com.motorControl.go(&a);
}
void loop() {
  //delay(100);
	com.run();
}
