#include "common/common.h"

static unsigned long seed;

void srand(unsigned long s) {
     seed = s;
 } 

int rand(void) {
    seed = seed * 1664525L + 1013904223L;   
    return ((int)((seed>> 17) & 0x7fff));
}
