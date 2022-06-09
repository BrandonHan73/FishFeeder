#include <Servo.h>
#include <Time.h>

int leftAngle = 67, rightAngle = 107;
int centerAngle;

Servo s;

void(* resetFunc) (void) = 0;

void setup() {
  centerAngle = (leftAngle + rightAngle) / 2;
  Serial.begin(9600);
  
  s.attach(0);
  right(0);
}

void loop() {
  // 43200000
  if(millis() > 43200000) {
    Serial.println("Resetting...");
  
    left(1000);
    right(1000);
    
    resetFunc();
  } else {
    Serial.println(millis());
  }
}

void right(int t) {
  s.write(rightAngle);
  delay(t);
}

void left(int t) {
  s.write(leftAngle);
  delay(t);
}

void center(int t) {
  s.write(centerAngle);
  delay(t);
}
