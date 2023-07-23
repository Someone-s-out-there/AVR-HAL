// #ifndef __AVR_ATmega328P__
// #define __AVR_ATmega328P__
// #endif
#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "HAL/HAL.h"
#include "HAL/IO/pins.hpp"



int main(){
    pin p(&DDRB,&PORTB,&PINB,PB5);
    p.init(false,true);
    while (1)
    {
        // p.toggle_pin();
        p.set_pin(1);
        _delay_ms(500);
        p.set_pin(0);
        _delay_ms(500);

    }
}