#include <intrin.h>
#include <stdio.h>

int main(void) {
    printf("%d\n", __readgsqword(48) != 0);
    return 0;
}
