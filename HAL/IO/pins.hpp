#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <avr/sfr_defs.h>

/// @brief a general purpose io pin class to be used instead of direct register manipulations in the program code
/// this class ensures code readability and allows other classes and drivers to be more readable.
/// this class functions as the base for the HAL.
class pin
{
private:
    volatile uint8_t* _ddr;
    volatile uint8_t* _port;
    volatile uint8_t* _pin;

    uint8_t _pinnr;

public:
    pin(volatile uint8_t* ddr, volatile uint8_t* port, volatile uint8_t* pin, uint8_t pinnr);
    ~pin() = default;
    void init(bool isinput, bool pullup);
    uint8_t get_pin();
    void set_pin(uint8_t state);
    void toggle_pin();
};
