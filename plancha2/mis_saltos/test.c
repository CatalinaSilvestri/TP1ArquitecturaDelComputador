typedef struct _test
{
  int hola;
  int chau;
}test;

typedef test saludo[1];

void f (saludo s){
  s->hola = 5;
  s->chau = 5;
}

#include "mis_saltos.h"
#include <stdio.h>

miBuf_jump b;

int div(int numerador, int denominador){
  if (denominador == 0)
    long_jump2(b, 1);
  return numerador / denominador;
}

int main(){
  
  int ret=0;
  ret = set_jump2(b);
  printf("Vamo a laburar\n");
  if (ret == 0){
    printf("calculo muy complicado\n");
    div(1, 0);
    long_jump2(b, 2);
  }
  else if (ret == 1)
    printf("Paparulo, no se divide por 0\n");
  else 
    printf("soy un vago y por ello no hago calculos complicados\n");
  return 0;
}

/*
  saludo s1;
  s1->hola = 1;
  s1->chau = 1;
  saludo s2;
  s2->hola = 2;
  s2->chau = 2;
  f(s1);
  return s1->hola - s1->chau + s2->hola - s2->chau;
  */