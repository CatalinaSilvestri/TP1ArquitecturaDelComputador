#include <stdio.h>
#include "guindows.h"

task t1, t2, taskmain;


//Tarea extra para el punto b
/*
	taskmain-> ft3 -> ft1 ->ft2 -> ft3 -> ... -> taskmain
*/
task t3;
task t4;

void ft4(){
	char c = 'c';
	printf("ft4: %p\n",&c);
	TRANSFER(t4, t3);
}

void ft3(void) {
	char c = 'c';
	printf("ft3: %p\n",&c);
	for (unsigned i = 0; i < 5000; i++) {
	printf("t3: i=%u\n", i);
	TRANSFER(t3, t1);
	}
	TRANSFER(t3, taskmain);	//Return a Main
}

void ft1(){
	char c = 'c';
	printf("ft1: %p\n",&c);
	double d;
	for(d=-1;;d+=0.001) {
		printf("d=%f\n", d);
		TRANSFER(t1,t2);
	}
}

void ft2(){
	char c = 'c';
	printf("ft2: %p\n",&c);
	int i;
	for(i=0;i<10000;i++) {
		printf("i=%d\n", i);
		TRANSFER(t2,t3);
	}
	TRANSFER(t2, taskmain);	//Return a Main
}

int main(){
	stack(t1,ft1);
	stack(t2,ft2);
	stack(t3,ft3);
	stack(t4,ft4);

	TRANSFER(taskmain,t4);
	return 0;
}