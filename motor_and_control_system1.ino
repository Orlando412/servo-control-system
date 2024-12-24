#include <Servo.h>

// C++ code
//

//pins for the motor driver
const int motorEnable = 5; // PWM pin for motor speed
const int motorInput1 = 6;    // Motor direction
const int motorInput2 = 7;

//pins for the leds
const int ledGreen = 8;
const int ledYellow = 9;
const int ledRed = 10;

//pins for the servo
const int servoPin = 3;

//pin for potentiometer
const int potPin = A1;

//servo
Servo servo;

void setup()
{
  //Set motor pins as output
  pinMode(motorEnable, OUTPUT);
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);

  //Set LED pins as output
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);

  // Initialize servo
  servo.attach(servoPin);

  // Start serial communication (optional for debugging)
  Serial.begin(9600);
}

void loop()
{
  //read potentiometer value
  int potValue = analogRead(potPin);
  
  //map potentiometer value to motor speed (0-255)
  int motorSpeed = map(potValue, 0, 1023, 0, 255);
  
  //map potentiometer value to servo angle (0-180)
  int servoAngle = map(potValue, 0, 1023, 0, 180);

  //set motor direction and speed
  digitalWrite(motorInput1, HIGH); // Forward direction
  digitalWrite(motorInput2, LOW);
  analogWrite(motorEnable, motorSpeed);

  //move servo to corresponding angle
  servo.write(servoAngle);

  //Control LEDs based on motor speed
  if (motorSpeed < 85) {
    
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    
  } 
  else if (motorSpeed < 170) {
    
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
    
  } 
  else {
    
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    
  }

  // Optional: Debug output
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Motor Speed: ");
  Serial.print(motorSpeed);
  Serial.print(" | Servo Angle: ");
  Serial.println(servoAngle);

  // Small delay to stabilize
  delay(50);
}