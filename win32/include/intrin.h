#ifndef _INTRIN_H_INCLUDED
#define _INTRIN_H_INCLUDED

#include <_mingw.h>

#ifndef __CRT_INLINE
#define __CRT_INLINE static __inline__
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WINNT_
#if defined(_M_X64) || defined(_M_AMD64)
__CRT_INLINE unsigned long long __readgsqword(unsigned long Offset) {
    void *ret;
    __asm__ volatile ("movq\t%%gs:%1,%0"
        : "=r" (ret), "=m" ((*(volatile long *) (unsigned long long) Offset)));
    return (unsigned long long)ret;
}
#endif

#if defined(_M_IX86)
__CRT_INLINE unsigned long __readfsdword(unsigned long Offset) {
    unsigned long ret;
    __asm__ volatile ("movl\t%%fs:%1,%0"
        : "=r" (ret), "=m" ((*(volatile long *) (unsigned long long) Offset)));
    return ret;
}
#endif

#if defined(_M_ARM64)
__CRT_INLINE unsigned long long __getReg(int reg) {
    unsigned long long ret = 0;
    if (reg == 18) {
        __asm__ volatile ("mov %0, x18" : "=r" (ret));
    }
    return ret;
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
