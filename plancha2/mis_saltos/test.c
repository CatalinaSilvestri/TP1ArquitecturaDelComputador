#include "mis_saltos.h"
#include <stdio.h>

miBuf_jump b;

int div(int numerador, int denominador){
  if (denominador == 0)
    longjmp2(b, 1);
  return numerador / denominador;
}

int main(){
  int ret=0;
  ret = setjmp2(b);
  if (ret == 0){
    div(1, 1);
    longjmp2(b, 2);
  }
  else if (ret == 1)
    printf("No se divide por 0\n");
  else 
    printf("Calculo realizado con EXITO!\n");
  return 0;
}
