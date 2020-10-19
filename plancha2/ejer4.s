.text
.global main
    main:
    movl $-1,%eax # Solo para este tamano el mov pone en 0
    # la parte alta del registro.
    movl $2, %ecx
    imull %ecx
    #completar para que el resultado correcto como signed quede en rax
    shlq $32, %rdx
    orq %rdx, %rax

    xorq %rax,%rax
    movw $-1,%ax
    movw $2, %cx
    mulw %cx
    
    #completar para que el resultado correcto como unsigned short
    #quede en eax
    
    shll $16, %edx
    orl %edx, %eax

    ret

    #31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 | 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
    #                dx                                                  ax
    #                                               eax