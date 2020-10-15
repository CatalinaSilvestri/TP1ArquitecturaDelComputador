.text
.global main
main:
  movl $1, %eax
  shll $16, %eax
  orl $1, %eax
  shll $15, %eax
  ret
