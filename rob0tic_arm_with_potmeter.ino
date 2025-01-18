#include <Servo.h>

// Create Servo objects
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

// Variable to store sensor values
int sensorValue0;
int sensorValue1;
int sensorValue2;
int sensorValue3;

void setup() {
  // Attach the servos to the appropriate pins
  servo0.attach(3); // Connect first servo to pin 3
  servo1.attach(5); // Connect second servo to pin 5
  servo2.attach(6); // Connect third servo to pin 6
  servo3.attach(9); // Connect fourth servo to pin 9

  // Initialize analog pins as inputs
  pinMode(A0, INPUT); // Potentiometer for servo0
  pinMode(A1, INPUT); // Potentiometer for servo1
  pinMode(A2, INPUT); // Potentiometer for servo2
  pinMode(A3, INPUT); // Potentiometer for servo3

  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Read the potentiometer values and map them to the servo angles
  sensorValue0 = analogRead(A0);
  sensorValue1 = analogRead(A1);
  sensorValue2 = analogRead(A2);
  sensorValue3 = analogRead(A3);

  // Map the analog values (0-1023) to degrees (0-180)
  int angle0 = map(sensorValue0, 0, 1023, 0, 180);
  int angle1 = map(sensorValue1, 0, 1023, 0, 180);
  int angle2 = map(sensorValue2, 0, 1023, 0, 180);
  int angle3 = map(sensorValue3, 0, 1023, 0, 180);

  // Set the servos to the mapped angles
  servo0.write(angle0);
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);

  // Print the angles to the serial monitor for debugging
  Serial.print("Servo Angles: ");
  Serial.print(angle0);
  Serial.print(", ");
  Serial.print(angle1);
  Serial.print(", ");
  Serial.print(angle2);
  Serial.print(", ");
  Serial.println(angle3);

  delay(15); // Small delay for stability
}
