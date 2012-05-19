#include <stdio.h>
#include "common/common.h"
#if DEBUGGING == 1
FILE debugf = FDEV_SETUP_STREAM(
    (int(*)(char, FILE*))uart_putc,
    NULL,
    _FDEV_SETUP_WRITE);

void debug_init(void) {
    stdout = stderr = &debugf;
}
#endif
