/*
 * Read / Test Joy Stick & Mapping
 */

#define XPosPin 0
#define YPosPin 1
int x,y;

void setup() {
  Serial.begin(9600);

}

void loop() {
  x = analogRead(XPosPin);
  y = analogRead(YPosPin);
  Serial.print(x);
  Serial.println();
  Serial.print(y);
  Serial.println();

}
