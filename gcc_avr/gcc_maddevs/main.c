#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

//turn on/off PortB0, PortB1, PortB2 pin outputs, which are connected to leds
//***** LED 0 *******
#define LED_ON_0 PORTB |= (PORTB | 1<<PINB0);
#define LED_OFF_0 PORTB &= ~(PORTB | 1<<PINB0);

//***** LED 1 *******
#define LED_ON_1 PORTB |= (PORTB | 1<<PINB1);
#define LED_OFF_1 PORTB &= ~(PORTB | 1<<PINB1);

//***** LED 2 *******
#define LED_ON_2 PORTB |= (PORTB | 1<<PINB2);
#define LED_OFF_2 PORTB &= ~(PORTB | 1<<PINB2);


//Timer Interrupt Handlers for PWM
//***** LED 0 *******
ISR(TIMER0_COMPA_vect){
	LED_ON_0;	//turn on led0
}
ISR(TIMER0_COMPB_vect){
	LED_OFF_0; //turn off led0
}

//***** LED 1 *******
ISR(TIMER1_COMPA_vect){
	LED_ON_1; //turn on led1
}
ISR(TIMER1_COMPB_vect){
	LED_OFF_1; //turn off led1
}

//***** LED 2 *******
ISR(TIMER2_COMPA_vect){
	LED_ON_2; //turn on led2
}
ISR(TIMER2_COMPB_vect){
	LED_OFF_2; //turn off led2
}

//Timer initialization for PWM
//***** LED 0 *******
//set Timer0 for f=0.5Hz, duty_cycle=2
void PWM_Init_0()
{
	// Set the Timer Mode to CTC
	TCCR0B |= (1<<CS01) | (1<<WGM02); //Set the ISR COMPB vect
	TIMSK0 |= (1<<OCIE0A) | (1<<OCIE0B);// set prescalers and start the timer
	//set the register values to count to
	OCR0A = 0.5; //frequency=0.5Hz
	OCR0B = 2; //duty cycle = 2
}
//***** LED 1 *******
//set Timer0 for f=1.5Hz, duty_cycle=2
void PWM_Init_1()
{	
	// Set the Timer Mode to CTC
	TCCR1B |= (1<<CS11) | (1<<WGM12); //Set the ISR COMPB vect
	TIMSK1 |= (1<<OCIE1A) | (1<<OCIE1B); // set prescalers and start the timer
	//set the register values to count to
	OCR1A = 1.5; //frequency=1.5Hz
	OCR1B = 2; //duty cycle = 2
}
//***** LED 2 *******
//set Timer0 for f=2Hz, duty_cycle=5
void PWM_Init_2()
{
	// Set the Timer Mode to CTC
	TCCR2B |= (1<<CS21) | (1<<WGM22); //Set the ISR COMPB vect
	TIMSK2 |= (1<<OCIE2A) | (1<<OCIE2B); // set prescalers and start the timer
	//set the register values to count to
	OCR2A = 2; //frequency=2Hz
	OCR2B = 5; //duty cycle = 5
}


int main(void)
{
	//set port B pin0, pin1, pin2 pins as output
	DDRB |= (1<<DDB0 | 1<<DDB1 | 1<<DDB2);
	
	//call functions for led1, led2, led3
	//interrupts are handled concurrently with 3 different timers (Timer0, Timer1, Timer2)
	PWM_Init_0(); //led0
	PWM_Init_1(); //led1
	PWM_Init_2(); //led2
	
	//enable interrupts
	sei();
	
	//run the code infinitely until the MCU unit is feeded with Power Supply
	while (1)
	{
	}
	
	return 0;
}
