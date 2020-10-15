.text
.global main
main:
  movl $0xAA, %eax
  shll $24, %eax
  orl $0xAA, %eax
  ret
