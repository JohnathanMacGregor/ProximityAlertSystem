# Arduino Proximity Alert System

## Overview
This project is an Aruduino-based proximity alert system that uses an ultrasonic sensor,
LEDs, a passive buzzer, and an LCD screen to detect objects and alert users when objects
are approaching. 

## Features 
- **Distance Detection**: Measures distance using an ultrasonic sensor.
- **Visual Alerts**: LEDs indicate proximity to an object.
- **Audio Alerts**: A buzzer sounds with increasing intesnity based on distance.
- **LCD Display**: Shows the distance measured in real time.

## Tech Stack
- **Hardware**: Elegoo UNO R3, Ultrasonic Sensor (HC-SR04), Passive Buzzer, LEDs, LCD.
- **Software**: Arduino IDE, LiquidCrystal library.

## Circuit Diagram
![proximity_alert_system](https://github.com/user-attachments/assets/b55b9d41-44bd-4e96-95ad-ec7201576f83)

## Demo Video
[download the video here](media/ProximityAlertSystemDemo.mp4).

## Setup and Usage
1. **Hardware Setup**:
   - Follow the circuit diagram to connect the necessary components to the Arduino.
2. **Upload Code**:
   - Open the `proximity_alret.ino` file in the Arduino IDE.
   - Upload the code to the Arduino.
3. **Power On**:
   - Power on the Arduino and observe the system in action.

## Future Enhancements
- Use a rechargeable battery for portability. 
