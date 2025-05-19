#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED1 PE5
 // Pin 2
int main(void) {
    // Set PE5 as output
    DDRE |= (1 << LED1);


    while (1) {
        // Turn ON all pins 2 to 7
        PORTE |= (1 << LED1);
        _delay_ms(500);

        // Turn OFF all pins 2 to 7
        PORTE &= ~(1 << LED1);
        _delay_ms(500);
    }
}
