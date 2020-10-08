#include <stdio.h>
#include <stdlib.h>

unsigned get_line(char ** destino, int bandera){
  unsigned size = 50; //espacio inicial
  char * palabra = malloc(sizeof(char)*size);
  char c;
  unsigned i;
  for (i = 0;                     //0            //1           //1
      (c = getchar()) != EOF && ((!bandera) || (c != '\n' && c != '\0'));//b | (a & c)
      i++){
    printf("%d ", i);
    //Mas espacio
    if (i >= size){
      size += 10;
      palabra = realloc(palabra, sizeof(char) * size);
    }
    //Asignar
    palabra[i] = c;
  }
  //Final de la linea
  if (i > size){
    size++;
    palabra = realloc(palabra, sizeof(char) * (size));
  }
  palabra[i] = '\0';
  //Espacio sobrante
  if (size > i){
    size = i;
    palabra = realloc(palabra, sizeof(char) * (size + 1));
  }
  //Salida
  * destino = palabra;
  printf("\n");
  return size;
}

void encoder(char * palabra, unsigned int size, int clave){
  for (int i = 0; i < size; i++){
    printf("%d ", (palabra[i] ^ clave));
    //printf("%c-", (palabra[i] ^ clave) ^ clave); 
  }
  printf("\n");
}

int main(int argc, char ** argv){
  char * linea;
  if (argc >= 2){
    char * linea;
    printf("%d\n", argc);
    unsigned n = get_line(&linea, argc <= 2);
    encoder(linea, n, atoi(argv[1]));
  }

  return 0;
}