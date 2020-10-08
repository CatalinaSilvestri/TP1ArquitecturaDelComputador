#include <stdio.h>
#include <stdlib.h>

unsigned get_line(char ** destino, int bandera){
  unsigned size = 50; //espacio inicial
  char * palabra = malloc(sizeof(char)*size);
  char c;
  unsigned i;
  for (i = 0;
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

int * encoder(char * palabra, unsigned int size, int clave){
  int * codificado = malloc(sizeof(int)*size);
  for (int i = 0; i < size; i++){
    codificado[i] = (palabra[i] ^ clave);
    printf("%d ", codificado[i]);
    //printf("%c-", (palabra[i] ^ clave) ^ clave); 
  }
  printf("\n");
  return codificado;
}

void decoder(int * palabra, unsigned int size, int clave){
  for (int i = 0; i < size; i++){
    printf("%c", (palabra[i] ^ clave));
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
    int * enCodigo = encoder(linea, n, atoi(argv[1]));
    free(linea);
    decoder(enCodigo, n, atoi(argv[1]));
    free(enCodigo);
  }

  return 0;
}