.text
.global solver
# Argumento:
# xmm0 = a ; xmm1 = b ; xmm2 = c ; xmm3 = d ; xmm4 = e ; xmm5 = f
  solver:
    #Transformo el 0 en un float
    movq $0, %rax
    cvtsi2ssq %rax, %xmm9

    #Verifico que a lo sumo alla un 0 por ecuacion.
    primera_cond:
      ucomiss %xmm9,%xmm0
      jnz segunda_cond
      ucomiss %xmm9,%xmm1
      jz no_sol

    segunda_cond:
      ucomiss %xmm9,%xmm3
      jnz buscar_sol
      ucomiss %xmm9,%xmm4
      jz no_sol

    #si pasamos la verificacion
    buscar_sol:
      a_dist0:
        ucomiss %xmm9,%xmm0
        jz d_dist0
        
        movss %xmm0, %xmm6
        mulss %xmm4, %xmm6
        movss %xmm1, %xmm7
        mulss %xmm3, %xmm7

        subss %xmm7, %xmm6

        #if (ae - bd) != 0)
        ucomiss %xmm9,%xmm6
        jz no_sol

        mulss %xmm0, %xmm5
        mulss %xmm2, %xmm3
        subss %xmm3, %xmm5

        divss %xmm6, %xmm5

        #guardo y 
        
        movss %xmm5, (%rsi)

        #llego a x

        mulss %xmm1, %xmm5
        subss %xmm5, %xmm2
        divss %xmm0, %xmm2

        #guardo x
        movss %xmm2, (%rdi) #xmm2 pasa a ser x
        jmp sol

      d_dist0:
        ucomiss %xmm9,%xmm3
        jz no_sol

        divss %xmm1, %xmm2  #c = c / b
        movss %xmm2, (%rsi) #y = c

        mulss %xmm4, %xmm2
        subss %xmm2, %xmm5
        divss %xmm3, %xmm5

        movss %xmm5, (%rdi)

        jmp sol

    no_sol:
      movl $-1, %eax
      ret
    
    sol:
      xorl %eax, %eax
      ret
