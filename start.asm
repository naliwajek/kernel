; This is the kernel's entry point. We could either call main here,
; or we can use this to setup the stack or other nice stuff, like
; perhaps setting up the GDT and segments.

[BITS 32]
[section .text]
[global start]
[extern kmain]
start:
    mov esp, sys_stack     ; This points the stack to our new stack area
    call kmain
    jmp $

MULTIBOOT_PAGE_ALIGN	equ 1<<0
MULTIBOOT_MEMORY_INFO	equ 1<<1
MULTIBOOT_AOUT_KLUDGE	equ 1<<16
MULTIBOOT_HEADER_MAGIC	equ 0x1BADB002
MULTIBOOT_HEADER_FLAGS	equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
MULTIBOOT_CHECKSUM		equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

ALIGN 4
multiboot_header:
	EXTERN code, bss, end
	dd MULTIBOOT_HEADER_MAGIC
	dd MULTIBOOT_HEADER_FLAGS
	dd MULTIBOOT_CHECKSUM
        dd multiboot_header
    	dd code
    	dd bss
    	dd end
    	dd start

[global gdt_flush]
[extern gp]
gdt_flush:
	lgdt [gp]         	; Load the GDT with our '_gp' which is a special pointer
    	mov ax, 0x10    ; 0x10 is the offset in the GDT to our data segment
    	mov ds, ax
    	mov es, ax
    	mov fs, ax
    	mov gs, ax
    	mov ss, ax
    	jmp 0x08:flush2   ; 0x08 is the offset to our code segment: Far jump!
flush2:
    	ret

[global idt_load]
[extern idtp]
idt_load:
	lidt [idtp]
	ret

%include "error_codes.inc"

[extern fault_handler]

isr_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10 
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, fault_handler
    call eax
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret

%include "irq_codes.inc"

[extern irq_handler]

irq_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, irq_handler
    call eax
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret

[section .bss]

resb 8192               ; This reserves 8KBytes of memory here
sys_stack:

