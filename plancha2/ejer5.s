.text
.global fact1
.global fact2

fact1:
  cmpq $1,%rdi          
  jns caso_recursivo    #if 1 <= rdi  

  caso_base:
    movq $1,%rax
    ret
  caso_recursivo:
    decq %rdi       #decremento para siguiente llamada
    call fact1      #espero resultados anteriores
    inc %rdi        #restauro al valor actual
    mulq %rdi
    ret 

fact2:
  movq $1, %rax
  bucle:
    cmpq $1,%rdi
    js fin
    
    mulq %rdi       #Multiplicacion
    decq %rdi       #decremento
    
    jmp bucle
  fin:
    ret
    
