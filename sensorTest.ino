#include <AFMotor.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(1);
int lefts = A5;
int rights = A3;



void setup(){
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  pinMode(lefts, INPUT);
  pinMode(rights, INPUT);
}

void loop(){                                                        // THE CODE IS IN REVERSE TYPE SO INSEAD OF MOVING FORWARD IT GOES BACKWARD 
  if (digitalRead(lefts) == HIGH && digitalRead(rights) == HIGH){  //both sensor see white they will move forward
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
  } else if (digitalRead(lefts) == LOW && digitalRead(rights) == HIGH){ // left sensor see black and right see white robot will turns right
     motor1.run(RELEASE);
     motor2.run(BACKWARD);
  } else if (digitalRead(lefts) == HIGH && digitalRead(rights) == LOW){ // left sensor see white and right see black robot will turns left
     motor1.run(BACKWARD);
     motor2.run(RELEASE);
  } else if (digitalRead(lefts) == LOW && digitalRead(rights) == LOW){  // if both sensors see black it will stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
}






