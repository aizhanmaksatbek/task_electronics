# task_electronics

# Problem Description:
Control of 3 individual leds with different blinking frequency and dimming ratio parameters.\
The project schematics simulation and physical layout models are implemented.

# Solution
ATMega328p(Arduino) MCU is feeded with +5V Power Supply. 
PortB0, PortB1, PortB2 pins are set as an output.\
PINB0 = redLed 5mm \
PINB1 = yellowLed 5mm \
PINB2 = greenLed 5mm

The given duty cycle values are used to controll the led dimming ratios.
The both led blinking frequency and pwm parameters are handled using Timer0, Timer1, Timer2 timers for each led relatively.
Each timer uses 2 prescaler register(OCRxA, OCRxB) with frequency and duty cycle values.

# Requirements
1) Proteus 8 Professional\
schematics: /Proteus_Atmega328p
3) Microchip Studio 7 (Version: 7.0.2542), AVR package\
C-code: /gcc_avr/gcc_maddevs/main.c
4) Arduino Software (IDE) 1.8.42.0\
Arduino UNO layout:  /physical_layout/

* Project Schematics\
![alt text](Proteus_Atmega328p/schematics_colored.png)
* ATMega328p(Arduino) MCU schematics is driven using .hex compilation result of AVR C-code\
![alt text](atmega328p.png)

# The Simulation Demo
https://www.youtube.com/watch?v=Blmsg7yWJyE


# 2) Supplementary Contribution: Layout using Arduino UNO board, 5mm red,green,yellow leds
https://www.youtube.com/watch?v=jdcnLiJXwA0
