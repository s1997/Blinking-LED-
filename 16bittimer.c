#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
  
// 16-bit timer

int main()
{
    DDRB = 0xFF ;

    //Set up CTC mode (Clears timer on compare)
    TCCR1B = (1 << WGM12);

    //TIME TICKS
    OCR1A = 31250;

    //Enable overflow interrupt
    TIMSK1 = (1 << OCIE1A);

    sei();

    // Set up timer with prescalar 256
    TCCR1B |= (1 << CS12);
    
    //Initialize the counter 
    // TCNT1=0;
    
    while(1){

    }
}

ISR(TIMER1_COMPA_vect){   
    PORTB ^= (1 << 5); //Toggle LED    
}