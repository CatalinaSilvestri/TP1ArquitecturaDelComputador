.text
.global main
main:
  movl $-1, %eax
  andl $0b11111111111111111111111100000000, %eax
  ret
