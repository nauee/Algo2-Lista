CFLAGS=-g -std=c99 -Wall -Werror -Wconversion

pruebas: lista.c pruebas.c
	gcc lista.c pruebas.c $(CFLAGS) -o pruebas

ejecutar: pruebas
	clear
	./pruebas

debug: pruebas
	gdb ./pruebas

probar: pruebas
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas