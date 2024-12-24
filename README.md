This project demonstrates a motor and servo control system using an Arduino Uno, L293D motor driver, LEDs, and a potentiometer.
The motor's speed and servo angle are controlled based on the potentiometer's input. Additionally, LEDs provide visual feedback on the motor's speed range (low, medium, or high).
The project can be used for learning purposes, showcasing basic motor and servo control, and understanding how to interact with external components like LEDs, potentiometers, and motor drivers.

Features
Motor Speed Control: Adjust the speed of the motor using a potentiometer.
Servo Angle Control: Adjust the servo's position based on the same potentiometer input.
LED Indicators: Indicate motor speed range:
Red LED for low speed.
Yellow LED for medium speed.
Green LED for high speed.
Debugging Output: Serial monitor displays the potentiometer value, motor speed, and servo angle for easy debugging.

Components Required
1 × Arduino Uno
1 × L293D Motor Driver IC
1 × DC Motor
1 × Servo Motor
1 × Potentiometer
1 × Red LED
1 × Yellow LED
1 × Green LED
3 × 220Ω Resistors (for LEDs)
1 × Breadboard
Jumper Wires
1 × 9V Battery (for motor power)

Circuit Diagram
The circuit is constructed as follows:

L293D Connections:
Pin 1 (Enable1): Arduino PWM pin 5
Pin 2 (Input1): Arduino pin 6
Pin 7 (Input2): Arduino pin 7
Pin 8 (Vcc2): 9V battery positive terminal
Pin 4, Pin 5 (GND): Common ground with Arduino and 9V battery
Pins 3, 6: DC motor terminals
Servo Motor:
Signal wire to Arduino pin 3
Power (Vcc) and Ground to the Arduino.
Potentiometer:
One end to 5V, the other to GND
Middle pin to Arduino A1.
LEDs:
Red LED: Arduino pin 10 with a 220Ω resistor.
Yellow LED: Arduino pin 9 with a 220Ω resistor.
Green LED: Arduino pin 8 with a 220Ω resistor.

How It Works
The potentiometer reads an analog value (0–1023).
The value is mapped to control:
Motor speed (0–255).
Servo angle (0–180°).
Based on the motor speed, LEDs indicate the range:
Low speed: Red LED ON.
Medium speed: Yellow LED ON.
High speed: Green LED ON.
The Serial Monitor prints debugging information about the potentiometer value, motor speed, and servo angle.

Code
The project code initializes the components and manages the control logic in the loop() function. Here is the main flow of the code:

Read potentiometer value.
Map the value to motor speed and servo angle.
Control motor direction, speed, and servo position.
Light up the appropriate LED based on motor speed.

Setup Instructions
Assemble the circuit as per the provided instructions and diagram.
Upload the code to your Arduino Uno using the Arduino IDE.
Open the Serial Monitor for debugging information.
Power the Arduino and motor driver. Rotate the potentiometer to control the motor speed and servo angle while observing the LED indicators.

Applications
Educational tool for understanding motor and servo control.
Visualizing the effect of potentiometer adjustments on various outputs.
Basic automation projects requiring simultaneous control of multiple actuators.

Troubleshooting
Motor not spinning: Check the motor driver connections, Vcc2 pin, and ensure the motor has a sufficient power supply.
Servo not moving: Verify the servo connections and ensure it’s not overloaded.
LEDs not lighting up: Confirm the connections and ensure the correct pins are used.
No serial output: Ensure the baud rate in the Serial Monitor matches the code.
