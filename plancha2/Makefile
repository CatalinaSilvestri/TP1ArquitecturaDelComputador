E_FLAGS = -Wall -Wextra -Werror -g
FLAGS = -g

programa: ejer1 ejer3 ejer4 ejer5

#Eercicio 1

ejer1 : ejer1_a ejer1_b

#Apartado A:
ejer1_a : ejer1_a.c
	gcc -o ejer1_a -g ejer1_a.c
	gcc -o ejer1_a.s -S ejer1_a.c

#Apartado B:
ejer1_b : ejer1_b.c
	gcc -o ejer1_b -g ejer1_b.c
	gcc -o ejer1_b.s -S ejer1_b.c

#Ejercicio 2:
	#No es necesario compilarlo

ejer3 : ejer3.c
	gcc -o ejer3 -g ejer3.c


clear :
	rm ejer1_a ejer1_a.s ejer1_b ejer1_b.s ejer3 ejer4
