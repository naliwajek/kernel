[global irq0]    ; 32: IRQ0
[global irq1]    ; 33: IRQ0
[global irq2]    ; 34: IRQ0
[global irq3]    ; 35: IRQ0
[global irq4]    ; 36: IRQ0
[global irq5]    ; 37: IRQ0
[global irq6]    ; 38: IRQ0
[global irq7]    ; 39: IRQ0
[global irq8]    ; 40: IRQ0
[global irq9]    ; 41: IRQ0
[global irq10]   ; 42: IRQ0
[global irq11]   ; 43: IRQ0
[global irq12]   ; 44: IRQ0
[global irq13]   ; 45: IRQ0
[global irq14]   ; 46: IRQ0
[global irq15]   ; 47: IRQ0

irq0:
    cli
    push byte 0
    push byte 32
    jmp irq_common_stub

irq1:
    cli
    push byte 0
    push byte 33
    jmp irq_common_stub

irq2:
    cli
    push byte 0
    push byte 34
    jmp irq_common_stub

irq3:
    cli
    push byte 0
    push byte 35
    jmp irq_common_stub

irq4:
    cli
    push byte 0
    push byte 36
    jmp irq_common_stub

irq5:
    cli
    push byte 0
    push byte 37
    jmp irq_common_stub


irq6:
    cli
    push byte 0
    push byte 38
    jmp irq_common_stub

irq7:
    cli
    push byte 0
    push byte 39
    jmp irq_common_stub

irq8:
    cli
    push byte 0
    push byte 40
    jmp irq_common_stub

irq9:
    cli
    push byte 0
    push byte 41
    jmp irq_common_stub

irq10:
    cli
    push byte 0
    push byte 42
    jmp irq_common_stub

irq11:
    cli
    push byte 0
    push byte 43
    jmp irq_common_stub

irq12:
    cli
    push byte 0
    push byte 44
    jmp irq_common_stub

irq13:
    cli
    push byte 0
    push byte 45
    jmp irq_common_stub

irq14:
    cli
    push byte 0
    push byte 46
    jmp irq_common_stub

irq15:
    cli
    push byte 0
    push byte 47
    jmp irq_common_stub


