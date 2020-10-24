.text
.global main
main:
  xorb %dl, %dl
  movb $64, %cl
  movq $0xffffffffffffffff, %rax
  
  while:
    cmpb $0, %cl
    je final

    
    rolq $1, %rax
    adcb $0, %dl

    dec %cl
    jmp while

  final:
    ret
  