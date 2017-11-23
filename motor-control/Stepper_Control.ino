/* 
 *  Basic progrm to control a stepper motor with a joystick
 *  Takes running average of joystick position to smooth control.
 *  
 */


#include <AccelStepper.h>
#define HALFSTEP 8
#define motorPin1 3
#define motorPin2 4
#define motorPin3 5
#define motorPin4 6

AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

int XPos = 0;

const int arraySize = 10;
int AverageArray[arraySize];
int index = 0;
int average = 0;
int total;

void setup() {
  Serial.begin(9600);
  
  for( int i = 0; i < arraySize; i++){
    AverageArray[i] = 0; // Initialize all elements of array to 0
  }

  stepper1.setMaxSpeed(500.0);
  stepper1.setAcceleration(50.0);
  stepper1.setSpeed(100);
  stepper1.moveTo(20000);
}

void loop() {
  total -= AverageArray[index];
  AverageArray[index] = analogRead(XPos);
  total += AverageArray[index];
  index++;
  
  if( index >= arraySize){
    index = 0;
  }
  average = total / arraySize;
}
