FLAGS = -Wall -Wextra -Werror -g

programa: ejer1 ejer3 ejer4 ejer6 ejer7 ejer8

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

#Ejercicio 3
ejer3 : ejer3_a ejer3_b ejer3_c ejer3_d ejer3_e ejer3_f ejer3_g ejer3_h

#Apartado A
ejer3_a : ejer3_a.s
	gcc -o ejer3_a -g ejer3_a.s

#Apartado B
ejer3_b : ejer3_b.s
	gcc -o ejer3_b -g ejer3_b.s

#Apartado C
ejer3_c : ejer3_c.s
	gcc -o ejer3_c -g ejer3_c.s

#Apartado D
ejer3_d : ejer3_d.s
	gcc -o ejer3_d -g ejer3_d.s

#Apartado E
ejer3_e : ejer3_e.s
	gcc -o ejer3_e -g ejer3_e.s

#Apartado F
ejer3_f : ejer3_f.s
	gcc -o ejer3_f -g ejer3_f.s

#Apartado G
ejer3_g : ejer3_g.s
	gcc -o ejer3_g -g ejer3_g.s

#Apartado H
ejer3_h : ejer3_h.s
	gcc -o ejer3_h -g ejer3_h.s

#Ejercicio 4:
ejer4 : ejer4.s
	gcc -o ejer4 -g ejer4.s

#Ejercicio 6:
ejer6 : ejer6.s
	gcc -o ejer6 -g ejer6.s -no-pie

#Ejercicio 7:
ejer7 : ejer7.s 
	gcc -o ejer7 -g ejer7.s

#Ejercicio 8:
ejer8: ejer8_a ejer8_b

#Apartado A
ejer8_a : ejer8_a.s 
	gcc -o ejer8_a -g ejer8_a.s

#Apartado B
ejer8_b : ejer8_b.s 
	gcc -o ejer8_b -g ejer8_b.s

clear :
	rm -f ejer1_a ejer1_a.s ejer1_b ejer1_b.s
	rm -f ejer3_a ejer3_b ejer3_c ejer3_d ejer3_e ejer3_f ejer3_g ejer3_h
	rm -f ejer4
	rm -f ejer6
	rm -f ejer7
	rm -f ejer8_a ejer8_b

