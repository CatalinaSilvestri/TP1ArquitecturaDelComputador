.data
  formato: .asciz "%ld\n"
  formato1: .asciz "%lx\n"
  i:
    .quad 0xDEADBEEF
.text
.global main
main:
  movq $formato, %rdi  # El primer argumento es el formato.
  movq $1234, %rsi    # El valor a imprimir.
  xorq %rax, %rax     # Cantidad de valores de punto flotante.
  call printf
  
  # Parte (a)
  movq $formato, %rdi
  movq %rsp, %rsi
  xorq %rax, %rax
  call printf

  # Parte (b) #!
  movq $formato, %rdi
  movq $formato, %rsi
  xorq %rax, %rax
  call printf

  # Parte (c) #!
  movq $formato1, %rdi
  movq $formato, %rsi
  xorq %rax, %rax
  call printf

  # Parte (d)
  movq $formato, %rdi
  movq %rsp, %rsi
  xorq %rax, %rax
  call printf

  # Parte (e)
  movq $formato, %rdi
  movq 8(%rsp), %rsi
  xorq %rax, %rax
  call printf  

  # Parte (f)
  movq $formato, %rdi
  movq i, %rsi
  xorq %rax, %rax
  call printf 

  # Parte (g)
  movq $formato, %rdi
  movq $i, %rsi
  xorq %rax, %rax
  call printf 

  ret
