#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED1 PE4 // Pin 2
int main(void) {
    // Set PE3, PE4, and PE5 as output (pins 2, 3, and 5)
    DDRE |= (1 << PE3) | (1 << PE4) | (1 << PE5);
    // Set PH3 and PH4 as output (pins 6 and 7)
    DDRH |= (1 << PH3) | (1 << PH4);
    // Set PG5 as output (pin 4)
    DDRG |= (1 << PG5);

    while (1) {
        // Turn ON all pins 2 to 7
        PORTE |= (1 << PE3) | (1 << PE4) | (1 << PE5); // 00000000 and xxxxxxx1
        PORTH |= (1 << PH3) | (1 << PH4);
        PORTG |= (1 << PG5);
        _delay_ms(500);

        // Turn OFF all pins 2 to 7
        PORTE &= ~((1 << PE3) | (1 << PE4) | (1 << PE5));
        PORTH &= ~((1 << PH3) | (1 << PH4));
        PORTG &= ~(1 << PG5);
        _delay_ms(500);
    }
}
