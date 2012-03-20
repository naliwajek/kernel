; Table for ISRs error codes

[global isr0]   ;  0: Divide By Zero Exception
[global isr1]   ;  1: Debug Exception
[global isr2]   ;  2: Non Maskable Interrupt Exception
[global isr3]   ;  3: Int 3 Exception
[global isr4]   ;  4: INTO Exception
[global isr5]   ;  5: Out of Bounds Exception
[global isr6]   ;  6: Invalid Opcode Exception
[global isr7]   ;  7: Coprocessor Not Available Exception
[global isr8]   ;  8: Double Fault Exception (With Error Code!)
[global isr9]   ;  9: Coprocessor Segment Overrun Exception
[global isr10]  ; 10: Bad TSS Exception (With Error Code!)
[global isr11]  ; 11: Segment Not Present Exception (With Error Code!)
[global isr12]  ; 12: Stack Fault Exception (With Error Code!)
[global isr13]  ; 13: General Protection Fault Exception (With Error Code!)
[global isr14]  ; 14: Page Fault Exception (With Error Code!)
[global isr15]  ; 15: Reserved Exception
[global isr16]  ; 16: Floating Point Exception
[global isr17]  ; 17: Alignment Check Exception
[global isr18]  ; 18: Machine Check Exception
[global isr19]  ; 19: Reserved
[global isr20]  ; 20: Reserved
[global isr21]  ; 21: Reserved
[global isr22]  ; 22: Reserved
[global isr23]  ; 23: Reserved
[global isr24]  ; 24: Reserved
[global isr25]  ; 25: Reserved
[global isr26]  ; 26: Reserved
[global isr27]  ; 27: Reserved
[global isr28]  ; 28: Reserved
[global isr29]  ; 29: Reserved
[global isr30]  ; 30: Reserved
[global isr31]  ; 31: Reserved

isr0:
    cli
    push byte 0
    push byte 0
    jmp isr_common_stub

isr1:
    cli
    push byte 0
    push byte 1
    jmp isr_common_stub

isr2:
    cli
    push byte 0
    push byte 2
    jmp isr_common_stub

isr3:
    cli
    push byte 0
    push byte 3
    jmp isr_common_stub

isr4:
    cli
    push byte 0
    push byte 4
    jmp isr_common_stub

isr5:
    cli
    push byte 0
    push byte 5
    jmp isr_common_stub

isr6:
    cli
    push byte 0
    push byte 6
    jmp isr_common_stub

isr7:
    cli
    push byte 0
    push byte 7
    jmp isr_common_stub

isr8:
    cli
    push byte 8
    jmp isr_common_stub

isr9:
    cli
    push byte 0
    push byte 9
    jmp isr_common_stub

isr10:
    cli
    push byte 10
    jmp isr_common_stub

isr11:
    cli
    push byte 11
    jmp isr_common_stub

isr12:
    cli
    push byte 12
    jmp isr_common_stub

isr13:
    cli
    push byte 13
    jmp isr_common_stub

isr14:
    cli
    push byte 14
    jmp isr_common_stub

isr15:
    cli
    push byte 0
    push byte 15
    jmp isr_common_stub

isr16:
    cli
    push byte 0
    push byte 16
    jmp isr_common_stub

isr17:
    cli
    push byte 0
    push byte 17
    jmp isr_common_stub

isr18:
    cli
    push byte 0
    push byte 18
    jmp isr_common_stub

isr19:
    cli
    push byte 0
    push byte 19
    jmp isr_common_stub

isr20:
    cli
    push byte 0
    push byte 20
    jmp isr_common_stub

isr21:
    cli
    push byte 0
    push byte 21
    jmp isr_common_stub

isr22:
    cli
    push byte 0
    push byte 22
    jmp isr_common_stub

isr23:
    cli
    push byte 0
    push byte 23
    jmp isr_common_stub

isr24:
    cli
    push byte 0
    push byte 24
    jmp isr_common_stub

isr25:
    cli
    push byte 0
    push byte 25
    jmp isr_common_stub

isr26:
    cli
    push byte 0
    push byte 26
    jmp isr_common_stub

isr27:
    cli
    push byte 0
    push byte 27
    jmp isr_common_stub

isr28:
    cli
    push byte 0
    push byte 28
    jmp isr_common_stub

isr29:
    cli
    push byte 0
    push byte 29
    jmp isr_common_stub

isr30:
    cli
    push byte 0
    push byte 30
    jmp isr_common_stub

isr31:
    cli
    push byte 0
    push byte 31
    jmp isr_common_stub
