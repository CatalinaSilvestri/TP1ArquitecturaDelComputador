.data
  format: .asciz "%ld\n"
  format1: .asciz "%lx\n"
  i:
    .quad 0xDEADBEEF
.text
.global main
main:
  movq $format, %rdi  # El primer argumento es el formato.
  movq $1234, %rsi    # El valor a imprimir.
  xorq %rax, %rax     # Cantidad de valores de punto flotante.
  call printf
  
  # Parte (a)
  movq $format, %rdi
  movq %rsp, %rsi
  xorq %rax, %rax
  call printf

  # Parte (b) #!
  movq $format, %rdi
  movq $format, %rsi
  xorq %rax, %rax
  call printf

  # Parte (c) #!
  movq $format1, %rdi
  movq $format, %rsi
  xorq %rax, %rax
  call printf

  # Parte (d)
  movq $format, %rdi
  movq %rsp, %rsi
  xorq %rax, %rax
  call printf

  # Parte (e)
  movq $format, %rdi
  movq 8(%rsp), %rsi
  xorq %rax, %rax
  call printf  

  # Parte (f)
  movq $format, %rdi
  movq i, %rsi
  xorq %rax, %rax
  call printf 

  # Parte (g)
  movq $format, %rdi
  movq i, %rsi
  xorq %rax, %rax
  call printf 

  ret
