#ifndef __SYSTEM_H
#define __SYSTEM_H

/* MAIN.C */
extern void *memcpy(void *dest, const void *src, int count);
extern void *memset(void *dest, int val, int count);
extern void *memsetw(void *dest, short int val, int count);
extern int strlen(const char *str);
extern unsigned char inportb(unsigned short _port);
extern void outportb(unsigned short _port, unsigned char _data);
extern int irqEnabled(void);

/* SCRN.C */
extern void cls(void);
extern void putch(char c);
extern void kprint(char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video(void);

/* GDT.C && IDT.C */
extern void gdt_install(void);
extern void idt_install(void);
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

/* ISRS.C */
extern void isrs_install(void);
struct regs
{
    unsigned int gs, fs, es, ds;      				/* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;   	/* pushed by 'pusha' */
    unsigned int int_no, err_code;   			 	/* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   		/* pushed by the processor automatically */ 
};

/* IRQ.C */
extern void irq_handler(struct regs *r);
extern void irq_install_handler(int irq, void (*handler)(struct regs *r));
extern void irq_uninstall_handler(int irq);
extern void irq_install(void);
extern void irq_remap(void);

/* TIME.C */
extern void timer_handler(struct regs *r);
extern void timer_install(void);
extern void timer_wait(int ticks);
extern void timer_phase(int hz);
extern unsigned long uptime(void);

/* KB.C */
extern void keyboard_handler(struct regs *r);
extern void keyboard_install(void);

#endif
