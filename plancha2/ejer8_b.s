.data
  cadena1: .asciz "MiCadenaDePrueba"
  cadena2: .asciz "MiCadenaDePrueva"
.text
.global main
main:
  movq $cadena1, %rdi
  movq $cadena2, %rsi
  movq $16, %rcx

  buscar:
    cld
    cmpsb
    jnz distinto
    loop buscar

  iguales:
    movq $1, %rax
    jmp fin

  distinto:
    xorq %rax, %rax
  
  fin:
    ret
  