#include <stdio.h>




static __attribute__((always_inline)) void Junk_code_001() {

#ifdef __aarch64__

    __asm__ __volatile__ ("b 0xc\n"
            ".long 12345678\n"
            ".long 12345678\n"
            );

#elif __arm__

    __asm__ __volatile__ (
            "movw r0, #1001 \t\n"
                 "movw r12, #2020 \t\n"
                 "add r0, r0, r12 \t\n"
                 "bx  lr" );

#endif
}

static __attribute__((always_inline)) void Junk_code_002() {
#ifdef __aarch64__
    __asm__ __volatile__(
            "mov x8,#0x1\n"
            "adr x9, #0x10\n"
            "mul x8, x9, x8\n"
            ".long 0x12345678\n"
            "br x8\n"
            );
#endif
}


static __attribute__((always_inline)) void Junk_code_003() {
#ifdef __aarch64__
    __asm__ __volatile__(
         "adr x8,#0xc\n"
         "mov x30,x8\n"
         "ret\n" );
#endif
}



static __attribute__((always_inline))
int count_bits(int x)
{
    register int xx=x;
    xx=xx-((xx>>1)&0x55555555);
    xx=(xx&0x33333333)+((xx>>2)&0x33333333);
    Junk_code_001();
    xx=(xx+(xx>>4))&0x0f0f0f0f;
    xx=xx+(xx>>8);
    return (xx+(xx>>16)) & 0xff;
}



void __attribute__((constructor)) init_function_001(void){

    count_bits(222);


}
