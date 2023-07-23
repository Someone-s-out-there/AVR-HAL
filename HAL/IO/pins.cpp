#include <pins.hpp>

/// @brief set the DDRX and PORTX var in the class
/// @param ddr
/// @param port
/// @param pinnr
pin::pin(volatile uint8_t* ddr, volatile uint8_t* port, volatile uint8_t* pin, uint8_t pinnr) : _ddr(ddr), _port(port), _pin(pin), _pinnr(pinnr)
{
}

/// @brief initializes pin to either input or output with the pull up defining pull up or tri state or high low output
/// @param isinput
/// @param pullup
void pin::init(bool isinput, bool pullup)
{
    *_ddr |= (!isinput << _pinnr);
    *_port |= (pullup << _pinnr);
}

/// @brief get the pin state from the Register given to the constructor
/// @return
inline uint8_t pin::get_pin()
{
    return bit_is_set(_pin, _pinnr);
}

/// @brief set pin with state
/// @param state
inline void pin::set_pin(uint8_t state)
{
    if (state)
    {
        *_port |= (1 << _pinnr);
    }else{
        *_port &=~(1 << _pinnr);
    }
    
}


/// @brief toggles pin
inline void pin::toggle_pin()
{
    *_port ^= (1 << _pinnr);
}