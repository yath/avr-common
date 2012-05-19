#ifndef _COMMON_BITS_H_
#define _COMMON_BITS_H_
#include <avr/sfr_defs.h> /* for _BV */

#define YES_I_KNOW_WHAT_I_AM_DOING
#include "_pphacks.h"

#define BV(x) _BV(x)

#define OR_BITS(...) (FUNCALL(BV, |, __VA_ARGS__))

#define SET_BITS(reg, ...) (reg) |= OR_BITS(__VA_ARGS__)
#define CLR_BITS(reg, ...) (reg) &= ~(OR_BITS(__VA_ARGS__))
#define TGL_BITS(reg, ...) (reg) ^= OR_BITS(__VA_ARGS__)
#define GET_BITS(reg, ...) ((reg) & (OR_BITS(__VA_ARGS__)))
#define TST_BITS(reg, ...) (GET_BITS(reg, __VA_ARGS__) == OR_BITS(__VA_ARGS__))

#define SET_BIT SET_BITS
#define CLR_BIT CLR_BITS
#define TGL_BIT TGL_BITS
#define GET_BIT GET_BITS
#define TST_BIT TST_BITS

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#define MSB(x) (sizeof(x)*CHAR_BIT-1)
#define LSB(x) 0

#define MSBV(x) BV(MSB(x))
#define LSBV(x) BV(LSB(x))

#endif /* _COMMON_BITS_H_ */
