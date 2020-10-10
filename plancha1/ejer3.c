#include <stdio.h>
#include <stdlib.h>

void printbin(long unsigned int n){
  unsigned size = 63;//sizeof(n);
  for (int i = size; i >= 0; i--){
     //printf("%d ", n & 1);
     //n = n >> 1;
     //(n >> b) & 1;
    printf("%d ", (n >> i) & 1);
  }
  printf("\n");
}

int main (){
  printbin(-2);
  return 0;
}