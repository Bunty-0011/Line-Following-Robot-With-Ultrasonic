int enA = 10;  // Speed motor A
int M_A1 = 2;  // Motor A forward
int M_A2 = 3;  // Motor A backward
int M_B1 = 4;  // Motor B backward
int M_B2 = 5;  // Motor B forward
int enB = 9;   // Speed motor B

int R_S = 6;   // Right sensor
int SR_S = 7;  // Slight Right sensor
int S_S = 8;   // Center sensor
int SL_S = 11; // Slight Left sensor
int L_S = 12;  // Left sensor

int TRIG = A0; // Ultrasonic sensor TRIG pin
int ECHO = A1; // Ultrasonic sensor ECHO pin


int M1_Speed = 80;// speed of motor 1 
int M2_Speed = 80; // speed of motor 2
int LeftRotationSpeed = 100;  // Left Rotation Speed
int RightRotationSpeed = 100; // Right Rotation Speed


void setup() {
    pinMode(M_B1, OUTPUT);
    pinMode(M_B2, OUTPUT);
    pinMode(M_A1, OUTPUT);
    pinMode(M_A2, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(enA, OUTPUT);

    pinMode(L_S, INPUT);
    pinMode(SL_S, INPUT);
    pinMode(S_S, INPUT);
    pinMode(SR_S, INPUT);
    pinMode(R_S, INPUT);

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    // analogWrite(S_A, 100);
    // analogWrite(S_B, 100);
    // delay(200);
}

void loop() {
    if (detectObstacle()) {
        Stop();
        delay(3000); // Stop for 3 seconds
    } else {
        followLine();
    }
}

void followLine() {
    if ((digitalRead(L_S) == 0) && (digitalRead(SL_S) == 0) && (digitalRead(S_S) == 1) && (digitalRead(SR_S) == 0) && (digitalRead(R_S) == 0)) { forword(); }

    if ((digitalRead(L_S) == 1) || (digitalRead(SL_S) == 1)) { turnLeft(); }
    if ((digitalRead(R_S) == 1) || (digitalRead(SR_S) == 1)) { turnRight(); }

    if ((digitalRead(L_S) == 0) && (digitalRead(SL_S) == 0) && (digitalRead(S_S) == 0) && (digitalRead(SR_S) == 0) && (digitalRead(R_S) == 0)) { sharpRight(); }

    if ((digitalRead(L_S) == 1) && (digitalRead(SL_S) == 1) && (digitalRead(S_S) == 1) && (digitalRead(SR_S) == 1) && (digitalRead(R_S) == 1)) { Stop(); }
}

bool detectObstacle() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
  
    long duration = pulseIn(ECHO, HIGH);
    int distance = duration * 0.034 / 2; // Convert to cm

    return (distance > 0 && distance <= 10); // Stop if an obstacle is within 10 cm
}

void forword() {
    digitalWrite(M_A1, HIGH);
    digitalWrite(M_A2, LOW);
    digitalWrite(M_B1, HIGH);
    digitalWrite(M_B2, LOW);
      analogWrite(enA, M1_Speed);
      analogWrite(enB, M2_Speed);
}

void turnRight() {
    digitalWrite(M_A1, LOW);
    digitalWrite(M_A2, HIGH);
    digitalWrite(M_B1, HIGH);
    digitalWrite(M_B2, LOW);
      analogWrite(enA, LeftRotationSpeed);
      analogWrite(enB, RightRotationSpeed);
}

void turnLeft() {
    digitalWrite(M_A1, HIGH);
    digitalWrite(M_A2, LOW);
    digitalWrite(M_B1, LOW);
    digitalWrite(M_B2, HIGH);
      analogWrite(enA, LeftRotationSpeed);
      analogWrite(enB, RightRotationSpeed);
}

void sharpRight(){
    digitalWrite(M_A1, LOW);
    digitalWrite(M_A2, HIGH);
    digitalWrite(M_B1, HIGH);
    digitalWrite(M_B2, LOW);
      analogWrite(enA, 150);
      analogWrite(enB, 150);
}

void Stop() {
    digitalWrite(M_A1, LOW);
    digitalWrite(M_A2, LOW);
    digitalWrite(M_B1, LOW);
    digitalWrite(M_B2, LOW);
}