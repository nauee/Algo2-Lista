CFLAGS=-g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

lista_se: lista.c pruebas.c
	gcc lista.c pruebas.c $(CFLAGS) -o lista_se

ejecutar: lista_se
	clear
	./lista_se

debug: lista_se
	gdb ./lista_se

probar: lista_se
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se