#include "Commande.h"

Commande com;
void setup() {
   Serial.begin(9600);
   Serial.flush();
   com.setup();
   static Point a;a.x=1155;a.y=0;
   static Point b;b.x=1155;b.y=670;
   static Point c;c.x =1155;c.y=0;
   static Point d;d.x=-800;d.y=0;
   static Point e;e.x=-800;e.y=670;
   static Point f;f.x=-800;f.y=0;
   static Point g;g.x =0;g.y=0;

  com.motorControl.go(&a);
  com.motorControl.go(&b);
  com.motorControl.go(&c);
  com.motorControl.go(&d);
  com.motorControl.go(&e);
  com.motorControl.go(&f);
  com.motorControl.go(&g);
}
void loop() {
  //delay(100);
	com.run();
}
