# ComSciDrone
arduino drone for com sci

This branch is to test moving void setup to another function
ONLY ADD TO MASTER AFTER TESTING

to do/ideas
--------
- MAKE A FUNCTION TO STOP THE DRONE FROM SPINNING
- make my own ish version of the getYPR.h file
- make my own ish version of the void setup() in the main file
- make a header file for rf or wifi communication
    - either way I could make a python executable for raspberry pi to send wifi or rf
- datalogging on an sd card for debugging
- datalogging on an sd card for gps
- gps route retracing
- proximity sensor for collision avoidance/smart landing
- 3d print landing gear switches to turn off props
- figure out batteries to order/use
- why is M4 always zero?


setup

MPU6050
- vdd --------------------5v
- gnd---------------------gnd
- int ----------------------D2
- sda---------------------A2
- scl----------------------A1

MOTORS
M1---------------------D3
M2---------------------D5
M3---------------------D6
M4---------------------D9
