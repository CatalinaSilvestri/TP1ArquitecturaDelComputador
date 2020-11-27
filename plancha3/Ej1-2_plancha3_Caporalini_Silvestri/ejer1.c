#include <stdio.h>
#include <ieee754.h>
#include <math.h>

#define EXP(x) ((* (int *) (&x) >> 23) & 0xff)
#define FRAC(x) ((* (int *) (&x)) & 0x1FFFFF)

int main (){
  float f = 4.25;

  union ieee754_float u;
  u.f = f; 
  

  printf("Nuestro ->  Exponente: %d, Mantisa: %d\n", EXP(f), FRAC(f));
  printf("IEEE 754 -> Exponente: %d, Mantisa: %d\n", u.ieee.exponent, u.ieee.mantissa);
  return 0;
}