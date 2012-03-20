#include <system.h>

void *memcpy(void *dest, void const *src, int count)
{   
    /* Copies memory from src to dest */
    char *d = dest; char const *s = src;
    while (count-- > 0) *d++ = *s++; return dest;    
}

void *memset(void *dest, int val, int count)
{   
    /* Memory set in 32-bytes env */
    register char *d = dest;
    while (count-- > 0) *d++ = val; return dest;   
}


void *memsetw(void *dest, short int val, int count)
{   
    /* Memory set in 16-bytes env */
    register char *d = dest;
    while (count-- > 0) *d++ = val; return dest;   
}

int strlen(const char *s)
{   
    /* Return length of a given string */
    int n; n = 0; while (*s++) n++; return n;    
}

unsigned char inportb(unsigned short _port)
{
    /* Read from I/O ports to get data from devices such as keyboard */
    unsigned char rv;
    asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}


void outportb(unsigned short _port, unsigned char _data)
{
    /* Write into I/O ports e.x. change text-mode cursors pos */
    asm volatile ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

int irqEnabled(void)
{
    /* Return 1 if irq is enabled on current machine
       Rem: i386 ELF testrun on x86_64 will return 0 anyway */    
    int f; 
    asm volatile ("pushf;popl %0":"=g" (f));
    return f & (1<<9);
}

void kmain(void)
{
    /* Handle all major errors like division by 0 */
    gdt_install();
    idt_install();
    isrs_install();

    /* Allowing IRQs to happen */
    irq_install();
    asm volatile ("sti");

    /* Inits graphic layer */
    init_video();

    /* Setup PIT */
    timer_install();

    /* Install keyboard */
    keyboard_install();

    /* Test welcome string */
    kprint("i'm a kernel");

    /* In start.asm there's inf loop 'jmp $' but it's only 
       if that below breaks somehow down */

    for (;;);
}

