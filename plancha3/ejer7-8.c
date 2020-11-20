#include <stdio.h>

#include <stdlib.h>
#include <time.h>

void rand_float(float * a, int cant){
  float n,m;
  for (int i = 0; i < cant; i++){
    n = (float) random();
    m = (float) random();
    if (m == 0)
      i--;
    else
      a[i] = n / m;
  }
}

void copy(float *a, float *b, int len){
  for (int i = 0; i < len; i++)
    b[i] = a[i];
}

void sum(float *a, float *b, int len);

void sum_simd(float *a, float *b, int len);

int main(){
    time_t start, finish;
    srand(time(NULL));
    int len = 10000;

    float a[len], b[len], c[len];

    rand_float(a, len);
    copy(a,c, len);
    rand_float(b, len);

    start = clock();
    sum(a, b, len);
    finish = clock();
    printf("Tiempo sumas simples: %lf;", difftime(finish, start));

    start = clock();
    sum_simd(c, b, len);
    finish = clock();
    printf("Tiempo sumas paquetes: %lf\n", difftime(finish, start));
    
    return 0;
}