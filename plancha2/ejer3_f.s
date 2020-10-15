.text
.global main
main:
  movl $1, %eax
  shll $8, %eax
  notl %eax
  andl $-1, %eax
  ret
