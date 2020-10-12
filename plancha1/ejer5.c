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
    printf("Codificacion: ");
    for (int i = 0; i < n; i++)
      printf("%c", linea[i]);
    printf("\n");
    //Decodificar e imprimir palabra
    printf("Decodificacion: ");
    for (int i = 0; i < n; i++)
      printf("%c", linea[i] ^ llave);
    printf("\n");
    //libera memoria de la palabra
    free(linea);
  }

  return 0;
}

/*
+Se gana algo si codificamos mas de una vez?
  Podemos ver que se genera el siguiente comporamiento al encriptar una misma
  palabra con distintos numeros:
  Mostraremos el caso con tres numeros distintos, aunque por propiedad asociativa, 
  vale para dos o mas iteraciones:

  (((palabra ^ a) ^ b) ^ c) = palabra ^ (a ^ b ^ c) y (a ^ b ^ c) 

  tambien es un numero con el que podemos encriptar en un primer lugar
  
*/
