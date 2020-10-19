.data
  format: .asciz "%ld\n"
  i:
    .quad 0xDEADBEEF
.text
.global main
main:
  movq $format, %rdi
  movq $1234, %rsi
  xorq %rax, %rax
  call printf
  # El primer argumento es el formato.
  # El valor a imprimir.
  # Cantidad de valores de punto flotante.
  ret
