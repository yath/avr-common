#ifndef _COMMON_DEBUG_H_
#define _COMMON_DEBUG_H_

#if defined(NDEBUG) && defined(DEBUG)
# error "DEBUG and NDEBUG are mutually exclusive"
#endif

#ifdef DEBUG
# include <stdio.h>
# include <avr/pgmspace.h> /* for PSTR() */
# include <util/atomic.h>
  extern FILE debugf;
  void debug_init(void);
# define STR(x) # x
# define ONEZERO(x) ((x)?'1':'0')
# define debug(fmt, ...) _COMMON_DEBUG_H_debug2(__FILE__, __LINE__, fmt, ##__VA_ARGS__)
# define dumpbyte(reg) do { \
    uint8_t __copy = reg; \
    debug("dump of " # reg " (MSB first): %c%c%c%c %c%c%c%c", \
        ONEZERO(GET_BIT(__copy, 7)), ONEZERO(GET_BIT(__copy, 6)), \
        ONEZERO(GET_BIT(__copy, 5)), ONEZERO(GET_BIT(__copy, 4)), \
        ONEZERO(GET_BIT(__copy, 3)), ONEZERO(GET_BIT(__copy, 2)), \
        ONEZERO(GET_BIT(__copy, 1)), ONEZERO(GET_BIT(__copy, 0))); \
    } while(0)

# ifdef ATOMIC_DEBUG
#  define _COMMON_DEBUG_H_ATOMIC_START ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
#  define _COMMON_DEBUG_H_ATOMIC_END   }
# else
#  define _COMMON_DEBUG_H_ATOMIC_START
#  define _COMMON_DEBUG_H_ATOMIC_END
# endif

# define _COMMON_DEBUG_H_debug2(file, line, fmt, ...) do { \
    _COMMON_DEBUG_H_ATOMIC_START \
        printf_P(PSTR(file ":" STR(line) ": " fmt "\n"), ##__VA_ARGS__); \
    _COMMON_DEBUG_H_ATOMIC_END \
  } while(0)
# define DEBUGGING 1 /* for use in _delay_ms(DEBUGGING?23:42) or so */
#else
# define _COMMON_DEBUG_H_NOP do { (void)0; } while(0)
# ifndef NDEBUG
#  define NDEBUG
# endif
# define dumpbyte(reg) _COMMON_DEBUG_H_NOP
# define debug(fmt, args...) _COMMON_DEBUG_H_NOP
# define debug_init(...) _COMMON_DEBUG_H_NOP
# define DEBUGGING 0
#endif

#endif /* _COMMON_DEBUG_H_ */
