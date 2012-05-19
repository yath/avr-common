#include <stdio.h>
#include "common/common.h"
#if DEBUGGING == 1

void debug_init(void) {
    fdev_setup_stream(stdout,
    (int(*)(char, FILE*))uart_putc,
    NULL,
    _FDEV_SETUP_WRITE);
}
#endif
