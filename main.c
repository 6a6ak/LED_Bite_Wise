#define F_CPU 16000000UL  // 16MHz clock speed
#include <avr/io.h> //Rigister sssumption like DDRx, PORTx, PINx
#include <util/delay.h> // For delay functions
#include <stdlib.h> // For itoa function convert integer to string

// UART config
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD - 1)

#define TRIG_PIN PE4  // pin 2 -> Trigger pin -d2-> PORT E 4th bit 
#define ECHO_PIN PE5  // pin 3 -> Echo pin -d3-> PORT E 5th bit
// HC-SR04 pins on Arduino Mega in Microcontroler ATMega 2560 placed on PORT E & not on PORT D
#define TRIG_PIN PE4  // pin 2 -> Trigger pin -d2-> PORT E 4th bit 
#define ECHO_PIN PE5  // pin 3 -> Echo pin -d3-> PORT E 5th bit
int main(void) {
    // تنظیم همه پین‌های PORT E به عنوان خروجی
    DDRE = 0xFF; // همه بیت‌ها خروجی

    while (1) {
        // روشن کردن فقط بیت 0 (PE0)
        PORTE |= (1 << PE0);
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
    }
}
