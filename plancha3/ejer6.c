#include <stdio.h>

int solver
  (float a, float b, float c, float d,  float e,  float f, float* x, float* y);

int main(){
  float x,y;
  /*
  printf("caso 1 (paralelos secantes): \n");
  if (!solver(1, 1, 1, 1, 1, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");

  printf("caso 2 (paralenos no secantes 1): \n");
  if (!solver(1, 1, 1, 1, 1, 2, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");

  printf("caso 2 (paralenos no secantes 2): \n");
  if (!solver(1, 1, 2, 1, 1, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");
  
  printf("caso 3 (y = 0 1): \n");
  if (!solver(1, 1, 1, 1, 0, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");

  printf("caso 3 (y = 0 2): \n");
  if (!solver(1, 0, 1, 1, 1, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");
  
  printf("caso 4 (x = 0 1): \n");
  if (!solver(0, 1, 1, 1, 1, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");

  printf("caso 4 (x = 0 2): \n");
  if (!solver(1, 1, 1, 0, 1, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");
  
  printf("caso 5 (doble 0): \n");
  if (!solver(1, 1, 1, 0, 0, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");
  */
  printf("caso 6 (doble 0): \n");
  if (!solver(0, 0 , 1, 1, 0, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");
  
  printf("caso 6 (libres 1): \n");
  if (!solver(1, 0, 50, 0, 1, 100, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");

  printf("caso 6 (libre 2): \n");
  if (!solver(5, -2, -5, 2, -1, 1, &x, &y))
    printf("El par( %f, %f) es solucion.\n", x, y);
  else
    printf("No hay solucion\n");
  
  return 0;
}