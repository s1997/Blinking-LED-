#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRB = 0x20;
	PORTB |= 0;	
	while(1)
	{
		PORTB = 0x00;
		_delay_ms(1000);
		PORTB = 0x20;
		_delay_ms(1000); //1000 milliseconds		
	}
}
