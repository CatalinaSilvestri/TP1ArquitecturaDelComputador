#include <stdio.h>

int main(){
  int a = (1 << 31);
  int b = (1 << 31) | (1 << 15);
  int c = (-1 & (0b11111111111111111111111100000000));
  int d = (0xAA | (0xAA << 24));
  int e = (5 << 8);
  int f = (-1 & (~ (1 << 8)));
  int g = 0 - 1; 
  int h = (0x80000000) + (0x80000000);

  if (a == (0b10000000000000000000000000000000))
    printf("Son iguales -> a\n");
  if (b == (0b10000000000000001000000000000000))
    printf("Son iguales -> b\n");
  if (c == (0b11111111111111111111111100000000))
    printf("Son iguales -> c\n");
  if (d == (0b10101010000000000000000010101010))
    printf("Son iguales -> d\n");
  if (e == (0b00000000000000000000010100000000))
    printf("Son iguales -> e\n");
  if (f == (0b11111111111111111111111011111111))
    printf("Son iguales -> f\n");
  if (g == (0b11111111111111111111111111111111))
    printf("Son iguales -> g\n");
  if (h == (0b00000000000000000000000000000000))
    printf("Son iguales -> h\n");

  return 0;
}