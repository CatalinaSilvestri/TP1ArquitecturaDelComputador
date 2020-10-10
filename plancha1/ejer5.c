#include <stdio.h>
#include <stdlib.h>

unsigned encoder(char ** destino, char clave){
  unsigned size = 50; //espacio inicial
  char * palabra = malloc(sizeof(char)*size);
  char c;
  unsigned i;
  for (i = 0;
      (c = getchar()) != EOF && c != '\n' && c != '\0';
      i++){
    //Mas espacio
    if (i >= size){
      size += 10;
      palabra = realloc(palabra, sizeof(char) * size);
    }
    //Asignar
    palabra[i] = c ^ clave;
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
  return size;
}

int main(int argc, char ** argv){
  char * linea;
  if (argc >= 2){
    //Obtenemos llave para codificar/decodificar
    char llave = atoi(argv[1]);
    //Leemos y codificamos
    char * linea;
    unsigned n = encoder(&linea, llave);
    //Imprimir palabra codificada
    for (int i = 0; i < n; i++)
      printf("%c", linea[i]);
    printf("\n");
    //Decodificar e imprimir palabra
    for (int i = 0; i < n; i++)
      printf("%c", linea[i] ^ llave);
    printf("\n");
    //libera memoria de la palabra
    free(linea);
  }

  return 0;
}