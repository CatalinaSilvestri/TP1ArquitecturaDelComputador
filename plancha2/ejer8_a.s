.data
  cadena: .asciz "MiCadenaDePrueba"
.text
.global main
main:
  movq $cadena, %rsi
  movb $98, %bl

  buscar:
    cld
    lodsb
    cmpb $0, %al
    jz no_encontrado
    cmpb %bl, %al
    jz encontrado
    jmp buscar

  encontrado:
    movq $1, %rax
    jmp fin

  no_encontrado:
    xorq %rax, %rax
  
  fin:
    ret
  