#include <stdio.h>
#include <stdlib.h>

void printbin(unsigned int n){
  unsigned size = 31;//sizeof(n);
  for (int i = size; i >= 0; i--){
     //printf("%d ", n & 1);
     //n = n >> 1;
     //(n >> b) & 1;
    printf("%d ", (n >> i) & 1);
  }
  printf("\n");
}

int main (){
  printbin(1);
  return 0;
}