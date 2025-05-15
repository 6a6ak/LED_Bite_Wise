#define F_CPU 16000000UL  // 16MHz clock speed
#include <avr/io.h> //Rigister sssumption like DDRx, PORTx, PINx
#include <util/delay.h> // For delay functions
#include <stdlib.h> // For itoa function convert integer to string

// UART config
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD - 1)

#define PIN2 PE4  // pin 2 -> Trigger pin -d2-> PORT E 4th bit 
#define PIN3 PE5  // pin 3 -> Echo pin -d3-> PORT E 5th bit

int main(void) {
    // تنظیم همه پین‌های PORT E به عنوان خروجی
    DDRE = 0xFF; // همه بیت‌ها خروجی

    // Set PE3 and PE5 as output (LED3 and LED1)
    DDRE |= (1 << PE3) | (1 << PE5);
    // Set PH4 as output (LED2)
    DDRH |= (1 << PH4);

    while (1) {
        // روشن کردن فقط بیت 0 (PE0)
        PORTE |= (1 << PE0);
        _delay_ms(500);

            // روشن کردن فقط بیت 0 (PE0)
        PORTE |= (1 << PE7);
        _delay_ms(500);

        // خاموش کردن فقط بیت 0 (PE0)
        PORTE &= ~(1 << PE0);
        _delay_ms(500);

        // روشن کردن همه بیت‌ها
        PORTE = 0xFF;
        _delay_ms(500);

        // خاموش کردن همه بیت‌ها
        PORTE = 0x00;
        _delay_ms(500);

        // روشن و خاموش کردن بیت 4 و 5 (مثلاً برای TRIG و ECHO)
        PORTE |= (1 << PE4); // روشن کردن PE4
        PORTE &= ~(1 << PE5); // خاموش کردن PE5
        _delay_ms(500);

        PORTE &= ~(1 << PE4); // خاموش کردن PE4
        PORTE |= (1 << PE5); // روشن کردن PE5
        _delay_ms(500);

        // فقط روشن و خاموش کردن PE7
        PORTE |= (1 << PH4); // روشن کردن PE7
        _delay_ms(1000);
        PORTE &= ~(1 << PH4); // خاموش کردن PE7
        _delay_ms(1000);

        // Turn ON all LEDs
        PORTE |= (1 << PE3) | (1 << PE5);
        PORTH |= (1 << PH4);
        _delay_ms(500);

        // Turn OFF all LEDs
        PORTE &= ~((1 << PE3) | (1 << PE5));
        PORTH &= ~(1 << PH4);
        _delay_ms(500);
    }
}
