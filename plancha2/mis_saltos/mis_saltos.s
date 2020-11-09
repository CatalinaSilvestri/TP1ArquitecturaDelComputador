.data
  format: formato: .asciz "%ld\n"

.text

.global set_jump2
set_jump2:

  #Salvando registros "callee safe"

  #Stack y situacion
  movq %rbp,8(%rdi)    #rbp ->El solo echo de descomentarlo genera un seg fault.
  movq (%rsp), %rax     #Evitar doble lectura a mem.    
  movq %rax, 16(%rdi)  #rsp    
  
  #Proposito general "callee safe"
  movq %rbx,  (%rdi)    #rbx
  movq %r10, 24(%rdi)  #r10
  movq %r11, 32(%rdi)  #r11
  movq %r12, 40(%rdi)  #r12
  movq %r13, 48(%rdi)  #r13
  movq %r14, 54(%rdi)  #r14
  movq %r15, 64(%rdi)  #r15

  xorq %rax, %rax
  
  movq %rax, 72(%rdi)  #Estado del salto inicial

  movq $format, %rdi
  movq $125, %rsi
  xorq %rax, %rax

  call printf

  xorq %rax, %rax

  ret 

.global long_jump2
long_jump2:

  #restaurando registros
  
  movq  8(%rdi), %rbp  #rpb

  movq 16(%rdi), %rax           #temp
  movq %rax, (%rsp)           #temp
  #movq -16(%rdi), %rsp  #rsp
  
  #Proposito general "callee safe"
  movq    (%rdi), %rbx  #rbp
  movq 24(%rdi), %r10  #r10
  movq 32(%rdi), %r11  #r11
  movq 40(%rdi), %r12  #r12
  movq 48(%rdi), %r13  #r13
  movq 54(%rdi), %r14  #r14
  movq 64(%rdi), %r15  #r15
  
  #retorno del salto (No debe de ser 0)
  
  cmp $0, %rsi; 
  jnz noCero
  decq %rsi
  noCero:
    movq %rsi, %rax

  movq %rax, 72(%rdi) #Estado del salto inicial
  ret 
