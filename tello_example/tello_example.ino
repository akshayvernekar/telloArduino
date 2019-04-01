#include <Tello.h>

Tello tello;

void setup() {
  // put your setup code here, to run once: 
  tello.init();
  delay(1000);
  tello.takeoff();

}

void loop() {
  // put your main code here, to run repeatedly:
  tello.takeoff();
  delay(5000);
  tello.up(30);
  delay(2000);
  tello.down(30);
  delay(2000);
  tello.right(30);
  delay(2000);
  tello.left(30);
  delay(2000);
  tello.land();
  //you have 5 seconds to save your tello before it takes off again
  delay(5000);

}
