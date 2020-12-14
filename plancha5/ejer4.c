#include <stdio.h>

unsigned int campesino_ruso(unsigned int i, unsigned int j);

unsigned int campesino_ruso_c(unsigned int i, unsigned int j) {
  unsigned int res = 0;
  while (j > 1) {
    if (j & 1) {
      res += i;
      j -= 1;
    } else {
      i *= 2;
      j /= 2;
    }
  }
  return res + i;
}

int main(){
  unsigned a[] = {9,9,8,8, 7, 9, 0};
  unsigned b[] = {7,8,13,2, 1, 0, 0};
  for (int i = 0; i < 6; i++)
    printf("Original: %u Nuesto: %u\n",campesino_ruso_c(a[i],b[i]), campesino_ruso(a[i],b[i]));
  return 0;
}