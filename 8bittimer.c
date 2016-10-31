#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
  
// 8 bit timer

long long int overflow;

int main()
{
    DDRB = 0xFF ;
    overflow=0;
    //Set up CTC mode (Clears timer on compare)
    TCCR0A |= (1 << WGM01);

    //TIME TICKS
    OCR0A = 156;

    //Enable overflow interrupt
    // TIMSK1 |= (1 << TOIE1);
    TIMSK0 |= (1 << OCIE0A);

    sei();

    // Set up timer with prescalar 1024
    TCCR0B |= (1 << CS02) | (1 << CS00);
    
    while(1){

    }
}

ISR(TIMER0_COMPA_vect){
    overflow++;
    if(overflow > 50){
        PORTB ^= (1 << 5); //Toggle LED
        overflow=0;
    }
}
