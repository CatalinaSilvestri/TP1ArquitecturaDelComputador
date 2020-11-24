#include <stdio.h>
#include <ieee754.h>

#define EXP(x) ((* (int *) (&x) >> 23) & 0xff)
#define FRAC(x) ((* (int *) (&x)) & 0xffffff)

int main (){
  float f = 3.14;

  union ieee754_float u;
  u.f = f; 
  

  printf("Nuestro ->  Exponente: %d, Mantisa: %d\n", EXP(f), FRAC(f));
  printf("IEEE 754 -> Exponente: %d, Mantisa: %d\n", u.ieee.exponent, u.ieee.mantissa);
  return 0;
}