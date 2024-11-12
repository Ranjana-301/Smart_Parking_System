# Smart Parking System

This project provides a smart, automated system that helps reduce parking congestion by displaying real-time availability of parking slots. It uses **Arduino UNO**, **ultrasonic sensors**, an **LCD display**, and an **ESP8266 Wi-Fi module** to detect open parking slots and make this information easily accessible to drivers, saving time and improving the parking experience.

## Project Overview
The system uses ultrasonic sensors to detect whether a parking slot is occupied or vacant. The Arduino processes the sensor data and displays each slot’s availability status on an LCD. In addition, the ESP8266 module sends slot availability data to ThingSpeak, enabling remote monitoring of parking space availability.

## Hardware Requirements
- Arduino UNO
- 2 x Ultrasonic Sensors (e.g., HC-SR04)
- LCD Display (I2C compatible)
- ESP8266 Wi-Fi Module
- Jumper wires
- Breadboard (optional)

## Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
- [ThingSpeak](https://thingspeak.com/) account for data visualization

## Circuit Diagram
*Include a circuit diagram here if available.*

## Code Explanation

### Arduino Code
- Sets up ultrasonic sensors to measure distances in each slot.
- Checks the slot status based on whether the measured distance is below a set threshold.
- Displays each slot’s status as either "FREE" or "FULL" on the LCD.
- Sends availability data to the ESP8266 module.

### ESP8266 Code
- Connects to the local Wi-Fi network and the specified ThingSpeak channel.
- Receives data from the Arduino and uploads it to ThingSpeak for remote monitoring.

## Installation
1. **Libraries**: Install the following libraries in the Arduino IDE:
   - `LiquidCrystal_I2C` for the LCD
   - `SoftwareSerial` for Arduino-ESP8266 communication
2. **Setup**: Update the ESP8266 code with your Wi-Fi credentials and ThingSpeak channel details.
3. **Upload**: Load the Arduino and ESP8266 code onto their respective boards.

## Usage
1. Power on the Arduino and ESP8266.
2. The LCD displays "SMART PARKING" followed by the status of each slot.
3. The ESP8266 module uploads data to ThingSpeak, making the parking slot availability viewable remotely.

## Demo Video
<video width="600" controls>
  <source src="https://github.com/Ranjana-301/Smart_Parking_System/output.mp4" type="video/mp4">
  Your browser does not support the video tag.
</video>
![Smart Parking System Demo](https://github.com/Ranjana-301/Smart_Parking_System/videos/smart_parking_output.mp4)
![Smart Parking System Result](https://github.com/Ranjana-301/Smart_Parking_System/videos/smart_parking_result.mp4)

Click the link above to view a video demonstration of the Smart Parking System in action.

