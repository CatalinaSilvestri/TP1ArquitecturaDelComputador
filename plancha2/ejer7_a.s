.text
.global main
main:
  movq $0xffffffffeeeeeeee, %rax
  rolq $32, %rax

  ret
  