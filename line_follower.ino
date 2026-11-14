
/*
  Arduino UNO Line Following Rover
  IR Sensors + L298N Motor Driver
  2 DC Geared Motors

  Sensor Logic:
  Black = HIGH (1)
  White = LOW  (0)
*/

// IR Sensor Pins
#define LEFT_SENSOR  2
#define RIGHT_SENSOR 3

// L298N Motor Driver Pins
#define ENA 5
#define ENB 6
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

int motorSpeed = 150;

#define BLACK HIGH

void setup() {

  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();
}

void loop() {

  int left = digitalRead(LEFT_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  if (left == BLACK && right == BLACK) {
    moveForward();
  }

  else if (left == BLACK && right != BLACK) {
    turnLeft();
  }

  else if (left != BLACK && right == BLACK) {
    turnRight();
  }

  else {
    stopMotors();
  }
}

// Move Forward
void moveForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}

// Turn Left
void turnLeft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, motorSpeed);
}

// Turn Right
void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, 0);
}

// Stop Motors
void stopMotors() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
