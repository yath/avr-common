#ifndef _COMMON_DEBUG_H_
#define _COMMON_DEBUG_H_

#if defined(NDEBUG) && defined(DEBUG)
# error "NDEBUG and DEBUG are mutually exclusive"
#endif

#ifdef DEBUG
# define DEBUG_BLOCK(...) __VA_ARGS__
# include "common/uart.h"
# include <stdio.h>
# include <avr/pgmspace.h> /* for PSTR() */
# include <util/atomic.h>
  extern FILE debugf;
  void debug_init(void);
# define DEBUGGING 1
# define STR(x) # x
# define debug(fmt, ...) _DEBUG_H_DEBUG2(__FILE__, __LINE__, fmt, ##__VA_ARGS__)
# define DUMPBYTE(reg) do { \
    uint8_t __copy = reg; \
    DEBUG("dump of " # reg " (MSB first): %c%c%c%c %c%c%c%c", \
        ONEZERO(GET_BIT(__copy, 7)), ONEZERO(GET_BIT(__copy, 6)), \
        ONEZERO(GET_BIT(__copy, 5)), ONEZERO(GET_BIT(__copy, 4)), \
        ONEZERO(GET_BIT(__copy, 3)), ONEZERO(GET_BIT(__copy, 2)), \
        ONEZERO(GET_BIT(__copy, 1)), ONEZERO(GET_BIT(__copy, 0))); \
    } while(0)

#define debug_format_d(num) debug_format_C("fixme")
#define debug_format_x(num) debug_format_C("fixme")
#define debug_format_P(str) uart_puts_P(str)
#define debug_format_C(str) debug_format_P(PSTR(str))
#define debug_format_c(c)   uart_putc(c)

# define _DEBUG_H_DEBUG2(file, line, fmt, ...) do { \
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    debug_format_C(file ":" STR(line) ": "); \
    FUNCALL(, ;, PREFIX(debug_format_, __VA_ARGS__)); \
    debug_format_c('\n'); \
    } \
  } while(0)
#else
# ifndef NDEBUG
#  define NDEBUG
# endif
# define DEBUGGING 0
# define DEBUG_BLOCK(x)
# define DEBUG(fmt, args...)
# define debug_init(...)
#endif

#endif /* _COMMON_DEBUG_H_ */
