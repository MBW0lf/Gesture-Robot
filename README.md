# Gesture Robot

This project is a **gesture-controlled robot** that allows interaction between a human and a robot using hand gestures.  
The main idea is to capture hand movements with a sensor glove, process the data, and then control the robot accordingly.

## How it works
- A **glove** equipped with sensors detects hand movements.  
- Data from the sensors is processed via microcontrollers.  
- Commands are transmitted wirelessly (Bluetooth) to the robot.  
- The robot then performs the corresponding motion.  

## Hardware Components
- **MPU-6050 (GY-521)**: 3-axis accelerometer + 3-axis gyroscope  
- **Arduino Micro (ATmega32u4)**: microcontroller for the glove  
- **HC-05 Bluetooth Module**: wireless communication  
- **STM32F103C8T6**: microcontroller for the robot  
- **L6203 Motor Driver**: motor control  
- **K7805 Voltage Regulator**: power management  
- **Robot Body**: made of PCB and mechanical parts  

## Communication
- The glove sends sensor data to Arduino via **I2C**.  
- Arduino transmits commands to the robot through **Bluetooth (HC-05)**.  
- The STM32 board controls the motors based on received commands.  

## Summary
This project demonstrates how gesture recognition can be integrated with robotics. By wearing a sensor glove, users can move their hands and directly control the robot in real time.  

---

✨ *Thanks for checking out this project!*  
