#include <stdio.h>

int is_one(long n, int b){
  return (n >> b) & 1;
}

int main (){
  printf("%d\n", is_one(1, 0));
  return 0;
}