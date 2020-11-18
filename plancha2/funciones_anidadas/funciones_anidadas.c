#include <stdio.h>

//###########################################################################//
//Solucion planteada en clase usando punteros
void pc(int * a, int * b){
  int c = (*a) * (*b);
  printf("%d\n", c);
}

void pb(int * a){
  int b = (*a) + 1;
  pc(a, &b);
}

void pa(){
  int a = 5;
  pb(&a);
}
//###########################################################################//

//Solucion propuesta por nosotros.
//Utiliza la extencion que da gcc para esta clase de funciones.
void p1(){
  int a = 5;
  void p2 (){
    int b = a + 1;
    void p3 (){
      int c = b * a;
      printf("%d\n", c);
    }
    p3();
  }
  p2();
}


int main(){
  printf("Nuestra solucion: ");
  p1();
  printf("Solucion de clases: ");
  pa();     //Solucion planteada en clases unsando punteros
  return 0;
}