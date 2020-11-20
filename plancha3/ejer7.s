.text
.global sum

# a_i = a_i + b_i
sum:
    xorq %rcx, %rcx
    while:
        cmpq $0, %rdx
        jz salida

        movss (%rdi, %rcx, 4), %xmm0
        movss (%rsi, %rcx, 4), %xmm1
        addss %xmm1, %xmm0
        movss %xmm0, (%rdi,%rcx,4)

        incq %rcx
        decq %rdx
        jmp while

    salida:
        ret
