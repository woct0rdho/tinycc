#include <stdio.h>

#ifndef __STDC_VERSION__
#error "__STDC_VERSION__ must be defined"
#endif

#if __STDC_VERSION__ < 201112L
#error "expected C11 or later"
#endif

#ifdef __STDC_NO_ATOMICS__
#error "TinyCC should advertise atomics support in C11 mode"
#endif

int main(void) {
    printf("__STDC_VERSION__=%ld\n", (long)__STDC_VERSION__);
    puts("__STDC_NO_ATOMICS__ is undefined");
    return 0;
}
