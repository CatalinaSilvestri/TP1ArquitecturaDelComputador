.text
.global main
main:
  xorb %dl, %dl
  movb $64, %cl				#Contador
  movq $0xffffffffffffffff, %rax	#Numero a Contar
  
  while:
    #Condicion de Parada
    cmpb $0, %cl
    je final

    #Cuerpo del while
    rolq $1, %rax
    adcb $0, %dl

    #Reinicio del buble
    dec %cl     #decremento del contador
    jmp while   #salta al inicio del loop

  final:
    xorq %rax, %rax
    movb %dl, %al	#retornar 1's contados
    ret
  
