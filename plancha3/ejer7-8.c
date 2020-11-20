#include <stdio.h>

#include <stdlib.h>
#include <time.h>

void rand_float(float * a, int cant){
  //time_t t;
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


void sum(float *a, float *b, int len);

int main(){
    srand(time(NULL));
    int len = 3;
    float a[len], b[len];

    rand_float(a, len);
    rand_float(b, len);

    for(int i=0; i<len; i++)
        printf("a[%d]: %f, b[%d]: %f\n", i, a[i], i, b[i]);

    sum(a, b, len);
    for(int i=0; i<len; i++)
        printf("a[%d]: %f\n", i, a[i]);

    return 0;
}