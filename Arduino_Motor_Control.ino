#include <Servo>

int ENA = 5;
int ENB = 6;
int IN1 = 7;
int IN2 = 8;
int IN3 = 9;
int IN4 = 10;
int speedA = 200;
int speedB = 200;

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  servo1.attach(12);
  servo2.attach(11);
  servo1.write(60);
  servo2.write(150);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    switch (c) {
      case '1': servo1.write(60); break;
      case '2': servo1.write(70); break;
      case '3': servo1.write(80); break;
      case '4': servo1.write(90); break;
      case '5': servo1.write(100); break;
      case '6': servo1.write(110); break;
      case '7': servo1.write(120); break;
      case '8': servo1.write(130); break;
      case '9': servo1.write(145); break;
      case 'W': servo2.write(150); break;
      case 'w': servo2.write(60); break;
      case 'F': driveForward(); break;
      case 'B': driveBackward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S': stopMotors(); break;
    }
  }
}

void driveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}

void driveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
