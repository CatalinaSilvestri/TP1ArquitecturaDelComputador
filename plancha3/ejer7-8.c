#include <stdio.h>

#define BILLION 1E9
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
    //time_t start, finish;
    struct timespec start, finish;
    srand(time(NULL));
    int len = 100000;
    double dif;

    float a[len], b[len], c[len];

    rand_float(a, len);
    copy(a,c, len);
    rand_float(b, len);

    //Caso unitario
    clock_gettime (CLOCK_MONOTONIC_RAW , &start);   //Inico contados
    sum(a, b, len);
    clock_gettime (CLOCK_MONOTONIC_RAW , &finish);  //Fin de contador
    dif = (finish.tv_sec - start.tv_sec ) 
      + (finish.tv_nsec - start.tv_nsec ) / BILLION;
    printf("Tiempo sumas simples: %lf nanoseg;", dif);

    //Caso paquetes
    clock_gettime (CLOCK_MONOTONIC_RAW , &start);   //Inico contados
    sum_simd(c, b, len);
    clock_gettime (CLOCK_MONOTONIC_RAW , &finish);  //Fin de contador
    dif = (finish.tv_sec - start.tv_sec ) 
      + (finish.tv_nsec - start.tv_nsec ) / BILLION;
    printf("Tiempo sumas paquetes: %lf nanoseg\n", dif);
    
    return 0;
}