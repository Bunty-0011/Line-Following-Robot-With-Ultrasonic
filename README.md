# 🤖 Line Following Robot with Ultrasonic Obstacle Detection

A smart **Arduino Nano–based robot** that follows a line using **5 IR sensors** and detects obstacles using an **HC-SR04 ultrasonic sensor**.

---

##  Description

This project implements an autonomous robot capable of:
- Following a predefined path (line)
- Detecting obstacles in real time
- Stopping automatically to avoid collisions

It combines **embedded systems**, **sensor integration**, and **real-time decision making**.

---

##  Features

-  Line following using 5 IR sensors  
-  Obstacle detection (≤ 10 cm)  
-  Real-time motor control  
-  Automatic turning (left/right/sharp turns)  
-  Stops for 3 seconds when obstacle detected  
-  Adjustable motor speed  

---

## Hardware Requirements

- Arduino Nano  
- L298N Motor Driver  
- 2 DC Motors + Wheels  
- 5 IR Sensors  
- Ultrasonic Sensor (HC-SR04)  
- Robot Chassis  
- Battery Pack  

---

## Pin Configuration

### 🔹 Motors

| Component | Pin |
|----------|-----|
| enA (Motor A Speed) | 10 |
| M_A1 (Forward) | 2 |
| M_A2 (Backward) | 3 |
| M_B1 (Backward) | 4 |
| M_B2 (Forward) | 5 |
| enB (Motor B Speed) | 9 |

---

### 🔹 IR Sensors

| Sensor | Pin |
|--------|-----|
| Left (L_S) | 12 |
| Slight Left (SL_S) | 11 |
| Center (S_S) | 8 |
| Slight Right (SR_S) | 7 |
| Right (R_S) | 6 |

---

### 🔹 Ultrasonic Sensor

| Pin | Arduino |
|-----|--------|
| TRIG | A0 |
| ECHO | A1 |

---

##  Working Logic

###  Line Following

- Center sensor detects line → Move forward  
- Left sensors detect line → Turn left  
- Right sensors detect line → Turn right  
- No sensor detects line → Sharp right (search mode)  
- All sensors detect → Stop  

---

### Obstacle Detection

- Ultrasonic sensor measures distance  
- If object is within **10 cm**:
  - Robot stops  
  - Waits for **3 seconds**  
  - Resumes line following  

---

## Code Structure

### Main Flow

```cpp
void loop() {
    if (detectObstacle()) {
        Stop();
        delay(3000);
    } else {
        followLine();
    }
}


Obstacle Detection
bool detectObstacle() {<img width="704" height="1241" alt="WhatsApp Image 2026-07-10 at 12 27 41 AMs" src="https://github.com/user-attachments/assets/9f01c980-68c7-4154-8be0-4842a13e59c2" />

    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
  
    long duration = pulseIn(ECHO, HIGH);
    int distance = duration * 0.034 / 2;

    return (distance > 0 && distance <= 10);
}


Movement Functions
forword() → Move forward
turnLeft() → Turn left
turnRight() → Turn right
sharpRight() → Sharp turn when line lost
Stop() → Stop all motors

▶️ How to Run
Connect all components as per pin configuration
Upload the code using Arduino IDE
Place robot on a line track
Power ON the robot

## 📸 Demo

<img width="704" height="1241" alt="WhatsApp Image 2026-07-10 at 12 27 41 AMs" src="https://github.com/user-attachments/assets/72f95b30-0480-4add-baeb-cef9d21b40d2" />

<img width="704" height="1360" alt="WhatsApp Image 2026-07-10 at 12 27 41 AM" src="https://github.com/user-attachments/assets/1be8436f-44d2-4ed8-89de-75275db03ede" />
