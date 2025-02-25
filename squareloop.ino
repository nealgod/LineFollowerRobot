#include <AFMotor.h>

// Define motors
AF_DCMotor motor1(1); // Left motor (M1)
AF_DCMotor motor3(3); // Right motor (M3)

void setup() {
  Serial.begin(9600);
  
  // Set motor speed (0-255)
  motor1.setSpeed(200);
  motor3.setSpeed(200);
}

void loop() {
  for (int i = 0; i < 4; i++) { // Repeat 4 times to form a square
    moveForward(2000); // Move forward for 2 seconds
    rest(1000); // Rest for 1 second
    turnLeft(1000); // Turn left for 1 second
    rest(1000); // Rest for 1 second
  }
}

// Move both motors forward
void moveForward(int duration) {
  motor1.run(FORWARD);
  motor3.run(FORWARD);
  delay(duration);
}

// Rest (stop both motors)
void rest(int duration) {
  motor1.run(RELEASE);
  motor3.run(RELEASE);
  delay(duration);
}

// Turn left (stop left motor, right motor moves)
void turnLeft(int duration) {
  motor1.run(RELEASE); // Stop left motor
  motor3.run(FORWARD); // Right motor moves
  delay(duration);
}
