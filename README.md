# Line Follower Robot 🤖

## Project Overview

The Line Follower Robot is an Arduino-based mobile robot designed to follow a predefined path using three IR sensors positioned on the left, middle, and right sides of the robot. It uses sensor readings to determine the robot's movement and adjusts the motor outputs to follow the line and respond to turns and intersections.

The project demonstrates the practical application of embedded programming, digital sensor interfacing, and motor control in a simple autonomous robotic system.

## Key Features

- **Three-sensor line detection:** Reads digital inputs from left, middle, and right IR sensors to identify the robot's position relative to the track.
- **Directional movement:** Implements forward movement and left/right turning through dedicated motor-control functions.
- **Condition-based navigation:** Uses conditional logic to respond to different combinations of sensor readings.
- **Intersection handling:** Includes predefined movement responses for selected T-intersections and junction patterns.
- **PWM motor control:** Uses adjustable output values to control motor drive signals.
- **Microcontroller-based control:** Uses an Arduino-compatible controller to process sensor inputs and execute movement commands.

## Working Principle

1. The three IR sensors continuously detect the surface beneath the robot.
2. The Arduino reads the sensor signals and evaluates their combinations.
3. Based on the programmed conditions, it selects the appropriate movement function.
4. Motor-control outputs drive the robot forward or turn it to follow the path.

## Technologies Used

- Arduino C/C++
- Arduino-compatible microcontroller
- IR sensors
- Motor driver and DC motor control
- Digital input/output and PWM signals

## Learning Outcomes

This project provides practical exposure to sensor interfacing, embedded programming, conditional decision-making, and motor control. It also demonstrates how hardware inputs and software logic can work together to guide a mobile robot along a predefined path.
