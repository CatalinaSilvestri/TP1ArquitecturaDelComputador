#include <stdio.h>
#include "guindows.h"

task t1, t2, taskmain;


//Tarea extra para el punto b
/*
	taskmain-> ft3 -> ft1 ->ft2 -> ft3 -> ft4 -> taskmain
*/
task t3;

void ft3(void) {
	char c = 'c';
	printf("ft3: %p\n",&c);
	TRANSFER(t3, taskmain);
}

void ft1(){
	char c = 'c';
	printf("ft1: %p\n",&c);
	TRANSFER(t1,t2);
}

void ft2(){
	char c = 'c';
	printf("ft2: %p\n",&c);
	TRANSFER(t2,t3);
}

int main(){
	stack(t1,ft1);
	stack(t2,ft2);
	stack(t3,ft3);

	TRANSFER(taskmain,t1);
	return 0;
}

/*
	Para simplificar este apartado redujimos el contenido de las funciones a solo
	inicializar la variable c (char) e imprimir su direccion.
	Tras esto vimos que las direcciones devueltas se distancian entre si en 4080
	bytes. Este valor difiere en 16 bytes del valor asignado por TPILA, 8 bytes fueron
	asignados para la variable c (de tipo char), y los otros 8 fueron asignados por el
	push del rbp. Ambas acciones fueron realizadas por nuestras funciones ft1, ft2 y ft3.
	Ademas podemos ver que f1 es la que se encuentra alojada mas abajo y f3 mas arriba.
*/