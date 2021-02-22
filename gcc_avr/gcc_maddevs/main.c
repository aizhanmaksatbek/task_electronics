#define F_CPU 512000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

/*
#define LED_ON PORTB |= (1<<PORTB0 | 1<<PORTB1 | 1<<PORTB2);
#define LED_OFF PORTB &= ~(1<<PORTB0 | 1<<PORTB1 | 1<<PORTB2);
#define LED_TOGGLE PINB |= ~(1<<PINB0 | 1<<PINB1 | 1<<PINB2);
*/
//***** LED 0 *******
#define LED_ON_0 PORTB |= (PORTB | 1<<PINB0);
#define LED_OFF_0 PORTB &= ~(PORTB | 1<<PINB0);

//***** LED 1 *******
#define LED_ON_1 PORTB |= (PORTB | 1<<PINB1);
#define LED_OFF_1 PORTB &= ~(PORTB | 1<<PINB1);

//***** LED 2 *******
#define LED_ON_2 PORTB |= (PORTB | 1<<PINB2);
#define LED_OFF_2 PORTB &= ~(PORTB | 1<<PINB2);


#define LED_TOGGLE_0 PINB |=  ~(0<<PINB0);

//Interrupt Handlers
//LED 0
ISR(TIMER0_COMPA_vect){
	LED_ON_0;	
}
ISR(TIMER0_COMPB_vect){
	LED_OFF_0;
	//_delay_ms(10);
}

//LED 1
ISR(TIMER1_COMPA_vect){
	LED_ON_1;
}
ISR(TIMER1_COMPB_vect){
	LED_OFF_1;
}

//LED 2
ISR(TIMER2_COMPA_vect){
	LED_ON_2;
}
ISR(TIMER2_COMPB_vect){
	LED_OFF_2;
}

//PWM initializers
//LED 0
void PWM_Init_0()
{
	TCCR0B |= (1<<CS01) | (1<<WGM02);
	TIMSK0 |= (1<<OCIE0A) | (1<<OCIE0B);
	OCR0A = 0.5;
	OCR0B = 2;
}
//LED 1
void PWM_Init_1()
{	
	TCCR1B |= (1<<CS11) | (1<<WGM12);
	TIMSK1 |= (1<<OCIE1A) | (1<<OCIE1B);
	OCR1A = 1.5;
	OCR1B = 2;
}
//LED 2
void PWM_Init_2()
{
	TCCR2B |= (1<<CS21) | (1<<WGM22);
	TIMSK2 |= (1<<OCIE2A) | (1<<OCIE2B);
	OCR2A = 2;
	OCR2B = 5;
}


//Frequency handlers
/*
ISR(TIMER0_COMPAL_vect){
	LED_TOGGLE_0;
}
*/
/*
void Timer_Frequency(uint8_t freq)
{
	TCCR0A |= (1<<CS12) | (1<<WGM12);
	TIMSK0 |= (1<<OCIE0B);
	OCR0B = (F_CPU/(freq*2*256)-1);
}
*/


int main(void)
{
	DDRB |= (1<<DDB0 | 1<<DDB1 | 1<<DDB2);
	
	//Timer_Frequency(1.5);
	PWM_Init_0();
	PWM_Init_1();
	PWM_Init_2();
	
	//Timer_Frequency(0.5);
	
	sei();
	
	while (1)
	{
		
	}
}
