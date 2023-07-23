#include "util.hpp"

/// @brief 
/// @return uint8_t bitmask to set the bit
inline uint8_t utils::setbit_m(uint8_t postoset)
{

    return (1<<postoset);
}

/// @brief 
/// @return uint8_t bitmask to clear the bit
inline uint8_t utils::clearbit_m(uint8_t postoclear)
{
    return ~(1<<postoclear);
}
