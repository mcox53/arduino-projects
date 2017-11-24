/*  Matthew Cox
 *  11/22/17
 *  Description: Basic progrm to control a stepper motor with a joystick
 *  Takes running average of joystick position to smooth control.
 *  
 *  Target Device: ATMega328p (Arduino Uno)
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
int AverageArray[arraySize] = { 0 };
int average;

void setup() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(200.0);
}

int AnalogPinAverage(int *values, int sizeOfArray, int analogPin){
  int index,total = 0;
  for (int index = 0; index <= sizeOfArray; index++){
    values[index] = analogRead(analogPin);
    total += values[index];
    index++;
  }
  int average = total / sizeOfArray;
  return average;  
}

void loop() {
  // average = AnalogPinAverage(AverageArray, arraySize, XPos);
  int stepSpeed = map(analogRead(XPos), 0, 1023, -500, 500);
  stepper1.setSpeed(stepSpeed);
  stepper1.run();
}
