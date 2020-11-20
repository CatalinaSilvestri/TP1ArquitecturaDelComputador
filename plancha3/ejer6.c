#include <stdio.h>

int solver
  (float a, float b, float c, float d,  float e,  float f, float* x, float* y);

int main(){
  float x,y;

  printf("EJEMPLO: Resultado esperado (50,100)\n");
  if (!solver(1, 0, 50, 0, 1, 100, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");
  
  return 0;
}