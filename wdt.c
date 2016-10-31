#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

// Watch dog timer

int main()
{
    DDRB = 0xFF ;
    
    cli(); //disabling all interrupts
    
    WDTCSR =0x00;
    WDTCSR |= (1 << WDCE) |(1 << WDE);//interrupt mode   
    WDTCSR = (1 << WDIE) |(1 << WDE) |(1 << WDP2) |(1 << WDP0); //Set Prescalar 0.5s
        
    //set global interrupt enable
    sei();
	while(5){

    }
}

ISR(WDT_vect)
{	 
	PORTB ^= (1 << 5); //Toggle LED
}