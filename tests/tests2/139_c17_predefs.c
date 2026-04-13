#include <stdio.h>

#ifndef __STDC_VERSION__
#error "__STDC_VERSION__ must be defined"
#endif

#if __STDC_VERSION__ != 201710L
#error "expected C17"
#endif

#ifdef __STDC_NO_ATOMICS__
#error "TinyCC should advertise atomics support in C17 mode"
#endif

int main(void) {
    printf("__STDC_VERSION__=%ld\n", (long)__STDC_VERSION__);
    puts("__STDC_NO_ATOMICS__ is undefined");
    return 0;
}
