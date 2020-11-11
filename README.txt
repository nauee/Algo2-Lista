**************************************************************************************** Nahuel Castro 106551 *****************************************************************************************

Acerca de la entrega:
    La entrega consiste en una implementacion de una lista de nodos simplemente enlazados. 
    Ademas puede ser utilizado como pila o cola si es que asi se lo desea.

Linea de compilacion:
    Puede compilarse escribiendo make (compila con mis pruebas) o make_minipruebas (compila con las minipruebas).
    En caso de querer ingresar la linea completa, es la siguiente:
    -> gcc lista.c pruebas.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 (para compilar con mis pruebas).
    -> gcc lista.c lista_minipruebas.c -o minipruebas -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 (para compilar con las minipruebas).

Linea de ejecucion:
    Puede ejecutarse escribiendo make ejecutar (ejecuta con mis pruebas) o make ejecutar_minipruebas (ejecuta con las minipruebas).
    En caso de querer ingresar la linea completa, es la siguiente:
    -> ./lista_se (ejecuta con mis pruebas).
    -> ./minipruebas (ejecuta con las minipruebas).

Lineas extras:
    -> Utilizando make probar o make probar_minipruebas puede ejecutar valgrind con mis pruebas o las minipruebas respectivamente.
    -> Utilizando make debug o make debug_minipruebas puede ejecutar gdb con mis pruebas o las minipruebas respectivamente.

Funcionamiento:
    La implementacion realizada es mediante nodos simplemente enlazados, esta cuenta con una gran ventaja y es que no existe la necesidad de que
    la memoria necesaria para la lista sea contigua, lo que nos permite almacenar mas datos y es mas eficiente ya que no necesitamos hacer
    reallocs (esto hace aumentar la complejidad algoritmica ya que en el peor de los casos realloc copiara todos los elementos a una nueva posicion
    lo que genera una complejidad de O(n)).
    En mi caso puntual, decidi no utilizar ninguna funcionalidad recursiva, ya que creo que los metodos iterativos son mas que suficientes para
    llevar a cabo la funcionalidad completa de una lista. Por lo que en su gran mayoria use ciclos whiles y en algunos casos puntuales como para
    lista_destruir use ciclos for.

Explicaciones:
    ¿Qué es lo que entendés por una lista? ¿Cuáles son las diferencias entre ser simple o doblemente enlazada?
        Una lista es una estructura lineal que almacena elementos, en este caso almacena nodos, en donde cada nodo puede
        almacenar datos y punteros a otros nodos. De esta manera los nodos quedan relacionados y no se necesita que la memoria
        reservada para la lista sea contigua. La lista tiene ciertas funcionalidades como crear, destruir, insertar en cualquier posicion, 
        borrar de cualquier posicion y obtener el elemento de cualquier posicion. 
        La diferencia entre ser simple o doblemente enlazada es que en el primero de los casos cada nodo contiene un puntero que apunta
        al siguiente nodo de la lista; en el caso de las listas doblemente enlazadas, cada nodo contiene ademas otro puntero que 
        apunta al nodo anterior de la lista.
    ¿Cuáles son las características fundamentales de las Pilas? ¿Y de las Colas?
        Pilas: la pila es una estructura lineal que contiene elementos, en este caso nodos, cada nodo esta relacionado con su siguiente.
        Tiene ciertas funcionalidades como : crear, destruir, ver_tope, apilar, desapilar. A diferencia de la lista, solo podemos insertar
        elementos en el tope, y sacar elementos del tope. Lo que nos limita a que el ultimo elemento insertado sea el primero en salir (LIFO).
        Colas: la cola es una estructura lineal que contiene elementos, en este caso nodos, cada nodo esta relacionado con su siguiente.
        Tiene ciertas funcionalidades como : crear, destruir, ver_primero, encolar, desencolar. A diferencia de la lista, solo podemos insertar
        elementos en el final, y sacar elementos del principio. Lo que nos limita a que el primer elemento insertado sea el primero en salir (FIFO).
    ¿Qué es un iterador? ¿Cuál es su función?
        Es un elemento que nos permite recorrer secuencialmente un contenedor de datos, en este caso una lista. La ventaja principal es poder
        guardar "por donde" vamos recorriendo el contenedor lo que hace que sea mas rapido recorrer todos los elementos del vector.
    ¿En qué se diferencia un iterador interno de uno externo?
        En el caso de un iterador interno, este realiza todo el ciclo sin que el usuario pueda controlarlo manualmente. En cambio un iterador
        externo provee funcionalidades para que el usuario pueda manejar el ciclo de recorrido del iterador y pueda decidir cuando avanzar, cuando
        ver el elemento o cuando dejar de recorrer y destruir el iterador.

*******************************************************************************************************************************************************************************************************