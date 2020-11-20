.text
.global sum_simd

# a_i = a_i + b_i
sum_simd:
    xorq %rcx, %rcx
    movq %rdx, %rax
    xorq %rdx, %rdx
    movq $4, %r8
    idivq %r8

    while_1:
        cmpq $0, %rax
        jz while_2

        movaps (%rdi, %rcx, 4), %xmm0
        movaps (%rsi, %rcx, 4), %xmm1
        addps %xmm1, %xmm0
        movaps %xmm0, (%rdi,%rcx,4)

        addq $4, %rcx
        decq %rax
        jmp while_1

    while_2:
        cmpq $0, %rdx
        jz salida

        movss (%rdi, %rcx, 4), %xmm0
        movss (%rsi, %rcx, 4), %xmm1
        addss %xmm1, %xmm0
        movss %xmm0, (%rdi,%rcx,4)

        incq %rcx
        decq %rdx
        jmp while_2

    salida:
        ret
