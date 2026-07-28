#include <intrin.h>
#include <stdio.h>

int main(void)
{
#if defined(_M_X64) || defined(_M_AMD64)
    unsigned long long tid = __readgsqword(48);
#elif defined(_M_IX86)
    unsigned long long tid = __readfsdword(24);
#elif defined(_M_ARM64)
    unsigned long long tid = __getReg(18);
#else
#error Unsupported Windows architecture
#endif

    printf("%d\n", tid != 0);
    return 0;
}
