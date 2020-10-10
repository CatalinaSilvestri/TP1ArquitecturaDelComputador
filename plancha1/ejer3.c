#include <stdio.h>
#include <stdlib.h>

void printbin(long unsigned int n){
  unsigned size = 63;
  for (int i = size; i >= 0; i--){
    printf("%lu ", (n >> i) & 1);
  }
  printf("\n");
}

int main (){
  printbin(-2);
  return 0;
}