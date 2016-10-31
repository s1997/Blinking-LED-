#define F_CPU 16000000UL
#define DDRB *((volatile unsigned int *)0x24)
#define PORTB *((volatile unsigned int *)0x25)

volatile unsigned long i;


int main(void) 
	{

    DDRB |= 0x20;
    PORTB = 0;
    while(1) 
    {
        PORTB ^= 0x20;
        for(i=0; i < 634920; i++);
    }
}