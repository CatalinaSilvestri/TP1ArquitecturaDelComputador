#include <stdio.h>
#include <math.h>

#define EXP(x) ((* (int *) (&x) >> 23) & 0xff)
#define FRAC(x) ((* (int *) (&x)) & 0xffffff)

//Apartado a
int myIsNaN(float f){
  return ((EXP(f) == 255) && (FRAC(f) != 0));
}

//Apartado b
int myIsNaN2(float f){
  int m;
  m = (* (int *) (&f));
  //printf("%d - %d = %d\n", m, n, m - n);
  if (m < 0)
    return 0 <= m - 0xFF800000;
  return 0 <= m - 0x7F800000;
}


int main(void){
  float g = 0.0;
  float f = 0.0 / g;
  printf("f: %f\n", f);
  // ADVERTENCIA: ‘NaN’ es una extension de GCC.
  if (f == NAN) {
    printf("Es NaN\n");
  }
  if (myIsNaN2(f))
    printf("isNaN dice que si\n");
  else
    printf("NO es Nan\n");

  //printf("Nuestro ->  Exponente: %d, Mantisa: %d\n", EXP(f), FRAC(f));

  return 0;
}
