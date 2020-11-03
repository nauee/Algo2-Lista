CFLAGS=-g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

lista_se: lista.c pruebas.c
	gcc lista.c pruebas.c $(CFLAGS) -o lista_se

ejecutar: lista_se
	clear
	./lista_se

debug: lista_se
	clear
	gdb ./lista_se

probar: lista_se
	clear
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se

minipruebas: lista.c lista_minipruebas.c
	gcc lista.c lista_minipruebas.c $(CFLAGS) -o minipruebas

ejecutar_minipruebas: minipruebas
	clear
	./minipruebas

debug_minipruebas: minipruebas
	clear
	gdb ./minipruebas

probar_minipruebas: minipruebas
	clear
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./minipruebas