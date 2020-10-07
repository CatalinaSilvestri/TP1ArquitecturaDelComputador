#include <stdio.h>

/*
a ^ b = c
c ^ b = a
me escuchas?
c = a ^ b

b ^ a = b
b ^ a = a
b ^ a = b
*/
void swap3 (int * a, int * b, int * c){
  //swap a <-> b
  *b = *b ^ *a;
  *a = *b ^ *a;
  *b = *b ^ *a;
  //swap a <-> c
  *c = *c ^ *a;
  *a = *c ^ *a;
  *c = *c ^ *a;
}


int main (){
  int a = -1;
  int b = 2;
  int c = -32768;
  swap3(&a, &b, &c);
  printf("%d %d %d\n",a,b,c);
  return 0;
}

