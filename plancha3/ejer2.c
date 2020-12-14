#include <stdio.h>
#include <math.h>
#include <ieee754.h>

#define EXP(x) ((* (int *) (&x) >> 23) & 0xff)
#define FRAC(x) ((* (int *) (&x)) & 0x1FFFFF)

//Apartado a
int myIsNaN(float f){
  return ((EXP(f) == 255) && (FRAC(f) != 0));
}

//Apartado b
int myIsNaN2(float f){
  return !(f == f);
}


//Apartado c

void infComp(){
  if (INFINITY == INFINITY)
    printf("La comparacion entre INF e INF es valida\n");
  else
    printf("La comparacion entre INF e INF es invalida\n");
}

//exp = 255 y fraccion = 0
int myIsInf(float f){
  return ((EXP(f) == 255) && (FRAC(f) == 0));
}


//Apartado d
//Vemos que si sumamos un escalar a INF Seguimos obteniendo INF
float sum_scalar_inf(float f){
  printf("INF + %f = %f\n", f, INFINITY+f);
  return (INFINITY + f);
}


int main(void){
  float g = 0.0;
  float f = 0.0 / g;
  float h = -4.35;
  printf("f: %f\n", f);
  
  // ADVERTENCIA: ‘NaN’ es una extension de GCC.
  if (f == NAN) {
    printf("Es NaN\n");
  }
  if (myIsNaN2(f))
    printf("isNaN dice que si\n");
  else
    printf("NO es Nan\n");  
  //printf("Nuestro ->  Exponente: %d, Mantisa: %d\n", EXP(h), FRAC(h));
  infComp();
  sum_scalar_inf(h);

  return 0;
}
