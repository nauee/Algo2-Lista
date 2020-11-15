#include "lista.h"
#include "pa2m.h"

void llenar_lista_con_caracteres (lista_t* lista, char* string) {
    for(int i=0; string[i]!= 0; i++){
        lista_insertar(lista, &string[i]);
    }
}

void probar_lista_crear () {
    pa2m_nuevo_grupo("  Pruebas lista_crear  ");
    lista_t* lista = NULL;
    pa2m_afirmar((lista = lista_crear()) != NULL, "Puedo crear la lista");
    pa2m_afirmar((*lista).cantidad == 0, "La lista se crea con 0 elementos");
    pa2m_afirmar((*lista).nodo_inicio == NULL && (*lista).nodo_fin == NULL, "Los nodos de la lista apuntan a NULL");
    lista_destruir(lista);
}

void probar_lista_insertar_borrar () {
    pa2m_nuevo_grupo("  Pruebas lista_insertar  ");
    lista_t* lista = NULL;
    lista = lista_crear();
    int elemento1 = 214214;
    int elemento2 = 55000014;
    int elemento3 = 355000041;
    int elemento4 = 5121214;
    pa2m_afirmar(lista_insertar(NULL, NULL) == -1, "No puedo insertar en lista NULL");
    pa2m_afirmar(lista_elementos(lista) == 0, "La lista tiene 0 elementos");

    pa2m_afirmar(lista_insertar(lista, &elemento1) == 0, "Puedo insertar un elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento1, "El 1º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene 1 elementos");

    pa2m_afirmar(lista_insertar(lista, &elemento2) == 0, "Puedo insertar un segundo elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento2, "El 2º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elementos");

    pa2m_afirmar(lista_insertar(lista, &elemento3) == 0, "Puedo insertar un tercer elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento3, "El 3º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista tiene 3 elementos");

    pa2m_afirmar(lista_insertar(lista, &elemento4) == 0, "Puedo insertar un cuarto elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento4, "El 4º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 4, "La lista tiene 4 elementos");

    pa2m_afirmar(lista_insertar(lista, NULL) == 0, "Puedo insertar un elemento NULL");
    pa2m_afirmar(lista_ultimo(lista) == NULL, "El 5º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 5, "La lista tiene 5 elementos");

    pa2m_nuevo_grupo("  Pruebas lista_borrar  ");
    
    pa2m_afirmar(lista_borrar(NULL) == -1, "No puedo borrar en una lista inexistente");

    void* penultimo = lista_elemento_en_posicion(lista, 3);
    pa2m_afirmar(lista_borrar(lista) == 0, "Puedo borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_elementos(lista) == 4, "Quedan 4 elementos en la lista");

    penultimo = lista_elemento_en_posicion(lista, 2);
    pa2m_afirmar(lista_borrar(lista) == 0, "Puedo borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == penultimo, "El antiguo penultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");

    penultimo = lista_elemento_en_posicion(lista, 1);
    pa2m_afirmar(lista_borrar(lista) == 0, "Puedo borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == penultimo, "El antiguo penultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 2, "Quedan 2 elementos en la lista");
    
    penultimo = lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(lista_borrar(lista) == 0, "Puedo borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == penultimo, "El antiguo penultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 1, "Queda 1 elemento en la lista");
    
    pa2m_afirmar(lista_borrar(lista) == 0, "Puedo borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_elementos(lista) == 0, "Quedan 0 elementos en la lista");

    pa2m_afirmar(lista_borrar(lista) == -1, "No puedo borrar en una lista vacia");
    
    lista_destruir(lista);
}

void probar_lista_insertar_borrar_en_posicion () {
    pa2m_nuevo_grupo("  Pruebas lista_insertar_en_posicion  ");
    lista_t* lista;
    lista = lista_crear();
    char* letras = "Hola";

    pa2m_afirmar(lista_insertar_en_posicion(NULL, NULL, 0) == -1, "No puedo insertar en lista inexistente");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &letras[0], 0) == 0, "Puedo insertar un elemento en la primera posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &letras[0], "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene 1 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &letras[1], 1) == 0, "Puedo insertar un elemento en la ultima posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &letras[1], "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &letras[2], 0) == 0, "Puedo insertar un elemento en la primera posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &letras[2], "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista tiene 3 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &letras[3], 2) == 0, "Puedo insertar un elemento en la posicion 2º");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &letras[3], "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 4, "La lista tiene 4 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, NULL, 4) == 0, "Puedo insertar un elemento NULL en la posicion 4º");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == NULL, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 5, "La lista tiene 5 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, NULL, 235) == 0, "Posicion inexistente inserta al final");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 5) == NULL, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 6, "La lista tiene 6 elementos");

    pa2m_nuevo_grupo("  Pruebas lista_borrar_en_posicion  ");
    
    pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) == -1, "No puedo borrar una lista inexistente");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0,"Puedo borrar un elemento en la primera posicion");
    pa2m_afirmar(lista_elementos(lista) == 5, "Quedan 5 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 4) == 0,"Puedo borrar un elemento en la ultima posicion");
    pa2m_afirmar(lista_elementos(lista) == 4, "Quedan 4 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 2) == 0,"Puedo borrar un elemento en la 2º posicion");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 500) == 0, "Posicion inexistente borra al final");
    pa2m_afirmar(lista_elementos(lista) == 2, "Quedan 2 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Puedo borrar un elemento en la primera posicion");
    pa2m_afirmar(lista_elementos(lista) == 1, "Queda 1 elemento en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Puedo borrar el ultimo elemento");
    pa2m_afirmar(lista_elementos(lista) == 0, "Quedan 0 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == -1, "No puedo borrar en una lista vacia");
    
    lista_destruir(lista);
}

void probar_lista_vacia () {

    pa2m_nuevo_grupo("  Pruebas lista_vacia  ");

    lista_t* lista = lista_crear ();
    int elemento = 3;
    lista_insertar(lista, &elemento);

    pa2m_afirmar(lista_vacia(NULL), "Una lista inexistente esta vacia");
    pa2m_afirmar(!lista_vacia(lista), "Una lista con elementos no esta vacia");
    lista_borrar(lista);
    pa2m_afirmar(lista_vacia(lista), "Una lista sin elementos esta vacia");
    lista_destruir(lista);

}

void probar_funcionalidades_lista () {
    printf("\n");
    pa2m_nuevo_grupo("     Funcionalides de lista     ");
    printf("\n");
    probar_lista_crear ();
    probar_lista_insertar_borrar ();
    probar_lista_insertar_borrar_en_posicion ();
    probar_lista_vacia ();
}

void probar_funcionalidades_pila () {
    printf("\n");
    pa2m_nuevo_grupo("     Funcionalides de pila     ");
    printf("\n");
    pa2m_nuevo_grupo("  Pruebas lista_apilar  ");
    lista_t* pila = NULL;
    pila = lista_crear();
    char* letras = "oglA";
    pa2m_afirmar(lista_apilar(NULL, NULL) == -1, "No puedo apilar en lista NULL");
    pa2m_afirmar(lista_elementos(pila) == 0, "La pila tiene 0 elementos");

    pa2m_afirmar(lista_apilar(pila, &letras[0]) == 0, "Puedo apilar un elemento");
    pa2m_afirmar(lista_elementos(pila) == 1, "La pila tiene 1 elementos");

    pa2m_afirmar(lista_apilar(pila, &letras[1]) == 0, "Puedo apilar un segundo elemento");
    pa2m_afirmar(lista_elementos(pila) == 2, "La pila tiene 2 elementos");

    pa2m_afirmar(lista_apilar(pila, &letras[2]) == 0, "Puedo apilar un tercer elemento");
    pa2m_afirmar(lista_elementos(pila) == 3, "La pila tiene 3 elementos");

    pa2m_afirmar(lista_apilar(pila, NULL) == 0, "Puedo apilar un cuarto elemento que sea NULL");
    pa2m_afirmar(lista_elementos(pila) == 4, "La pila tiene 4 elementos");

    pa2m_afirmar(lista_apilar(pila, &letras[3]) == 0, "Puedo apilar un quinto elemento");
    pa2m_afirmar(lista_elementos(pila) == 5, "La pila tiene 5 elementos");

    pa2m_nuevo_grupo("  Pruebas lista_desapilar  ");

    pa2m_afirmar(lista_desapilar(NULL) == -1, "No puedo desapilar en una lista inexistente");
    
    bool mire_elemento_tope = (lista_tope(pila) == &letras[3]);

    pa2m_afirmar(lista_tope(pila) == &letras[3], "El elemento del tope es correcto");

    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el ultimo elemento de la pila");
    pa2m_afirmar(lista_tope(pila) == NULL, "El elemento del tope es correcto");
    pa2m_afirmar(lista_elementos(pila) == 4, "Quedan 4 elementos en la pila");

    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el ultimo elemento de la pila");
    pa2m_afirmar(lista_tope(pila) == &letras[2], "El elemento del tope es correcto");
    pa2m_afirmar(lista_elementos(pila) == 3, "Quedan 3 elementos en la pila");

    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el ultimo elemento de la pila");
    pa2m_afirmar(lista_tope(pila) == &letras[1], "El elemento del tope es correcto");
    pa2m_afirmar(lista_elementos(pila) == 2, "Quedan 2 elementos en la pila");
    
    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el penultimo elemento de la pila");
    pa2m_afirmar(lista_tope(pila) == &letras[0], "El elemento del tope es correcto");
    pa2m_afirmar(lista_elementos(pila) == 1, "Queda 1 elemento en la pila");

    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el ultimo elemento de la pila");
    pa2m_afirmar(lista_elementos(pila) == 0, "Quedan 0 elementos en la pila");

    pa2m_afirmar(lista_desapilar(pila) == -1, "No puedo desapilar en una pila vacia");

    pa2m_nuevo_grupo("  Pruebas lista_tope  ");
    pa2m_afirmar(mire_elemento_tope, "Puedo mirar el tope en una pila con elementos");
    pa2m_afirmar(lista_tope(pila) == NULL, "No puedo mirar el tope en una pila vacia");
    pa2m_afirmar(lista_tope(NULL) == NULL, "No puedo mirar el tope en una pila inexistente");
    
    lista_destruir(pila);
}

void probar_funcionalidades_cola () {
    printf("\n");
    pa2m_nuevo_grupo("     Funcionalides de cola     ");
    printf("\n");
    pa2m_nuevo_grupo("  Pruebas lista_encolar  ");
    lista_t* cola = NULL;
    cola = lista_crear();
    char* letras = "Algo";
    pa2m_afirmar(lista_encolar(NULL, NULL) == -1, "No puedo encolar en lista NULL");
    pa2m_afirmar(lista_elementos(cola) == 0, "La cola tiene 0 elementos");

    pa2m_afirmar(lista_encolar(cola, &letras[0]) == 0, "Puedo encolar un elemento");
    pa2m_afirmar(lista_elementos(cola) == 1, "La cola tiene 1 elementos");

    pa2m_afirmar(lista_encolar(cola, &letras[1]) == 0, "Puedo encolar un segundo elemento");
    pa2m_afirmar(lista_elementos(cola) == 2, "La cola tiene 2 elementos");

    pa2m_afirmar(lista_encolar(cola, &letras[2]) == 0, "Puedo encolar un tercer elemento");
    pa2m_afirmar(lista_elementos(cola) == 3, "La cola tiene 3 elementos");

    pa2m_afirmar(lista_encolar(cola, &letras[3]) == 0, "Puedo encolar un cuarto elemento");
    pa2m_afirmar(lista_elementos(cola) == 4, "La cola tiene 4 elementos");

    pa2m_afirmar(lista_encolar(cola, NULL) == 0, "Puedo encolar un elemento NULL");
    pa2m_afirmar(lista_elementos(cola) == 5, "La cola tiene 5 elementos");

    pa2m_nuevo_grupo("  Pruebas lista_desencolar  ");

    pa2m_afirmar(lista_desencolar(NULL) == -1, "No puedo desencolar en una cola inexistente");
    
    bool mire_elemento_primero = (lista_primero(cola) == &letras[0]);

    pa2m_afirmar(lista_primero(cola) == &letras[0], "El primer elemento es correcto");

    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
    pa2m_afirmar(lista_primero(cola) == &letras[1], "El primer elemento es correcto");
    pa2m_afirmar(lista_elementos(cola) == 4, "Quedan 4 elementos en la cola");

    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
    pa2m_afirmar(lista_primero(cola) == &letras[2], "El primer elemento es correcto");
    pa2m_afirmar(lista_elementos(cola) == 3, "Quedan 3 elementos en la cola");

    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
    pa2m_afirmar(lista_primero(cola) == &letras[3], "El primer elemento es correcto");
    pa2m_afirmar(lista_elementos(cola) == 2, "Quedan 2 elementos en la cola");
    
    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
    pa2m_afirmar(lista_primero(cola) == NULL, "El primer elemento es correcto");
    pa2m_afirmar(lista_elementos(cola) == 1, "Queda 1 elemento en la cola");

    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
    pa2m_afirmar(lista_elementos(cola) == 0, "Quedan 0 elementos en la cola");

    pa2m_afirmar(lista_desencolar(cola) == -1, "No puedo desencolar en una cola vacia");

    pa2m_nuevo_grupo("  Pruebas lista_primero  ");
    pa2m_afirmar(mire_elemento_primero, "Puedo mirar el primero de una cola con elementos");
    pa2m_afirmar(lista_primero(cola) == NULL, "No puedo mirar el primero en una cola vacia");
    pa2m_afirmar(lista_primero(NULL) == NULL, "No puedo mirar el primero en una cola inexistente");
    
    lista_destruir(cola);
}

void probar_lista_iterador_externo(){

    printf("\n");
    pa2m_nuevo_grupo("     Funcionalides de iterador     ");
    printf("\n");

    pa2m_nuevo_grupo("  Pruebas lista_iterador_crear  ");

    char* prueba = "HOLA";
    lista_t* lista = lista_crear ();
    lista_t* lista_vacia = lista_crear ();
    lista_iterador_t* iterador;
    lista_iterador_t* iterador_vacio;
    llenar_lista_con_caracteres(lista, prueba);

    pa2m_afirmar((iterador_vacio = lista_iterador_crear(NULL)) == NULL, "No puedo crear un iterador externo en una lista invalida");
    pa2m_afirmar((iterador_vacio = lista_iterador_crear(lista_vacia)) != NULL, "Puedo crear un iterador externo en una lista vacia");
    pa2m_afirmar((*iterador_vacio).lista == lista_vacia, "El iterador es de la lista correspondiente");
    pa2m_afirmar((*iterador_vacio).corriente == NULL, "El iterador apunta al nodo inicio de la lista (NULL por estar vacia)");
    pa2m_afirmar((iterador = lista_iterador_crear(lista)) != NULL, "Puedo crear un iterador externo en una lista con elementos");   
    pa2m_afirmar((*iterador).lista == lista, "El iterador es de la lista correspondiente");
    pa2m_afirmar((*iterador).corriente == (*lista).nodo_inicio, "El iterador apunta al nodo inicio de la lista");

    pa2m_nuevo_grupo("  Pruebas lista_iterador_avanzar  ");

    pa2m_afirmar(lista_iterador_avanzar(NULL) == false, "No puedo avanzar un iterador invalido");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Avanzar desde la primera posicion devuelve true");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Avanzar desde la segunda posicion devuelve true");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Avanzar desde la tercera posicion devuelve true");
    pa2m_afirmar(lista_iterador_avanzar(iterador) == false, "Avanzar desde la ultima posicion devuelve false");
    pa2m_afirmar(lista_iterador_avanzar(iterador) == false, "No puedo avanzar despues la ultima posicion");
    pa2m_afirmar(lista_iterador_avanzar(iterador_vacio) == false, "No puedo avanzar con un iterador en una lista vacia");
    lista_iterador_destruir (iterador);

    pa2m_nuevo_grupo("  Pruebas lista_iterador_elemento_actual  ");

    iterador = lista_iterador_crear(lista);
    pa2m_afirmar(lista_iterador_elemento_actual(NULL) == NULL, "No puedo ver el elemento en una iterador invalido");
    pa2m_afirmar(lista_iterador_elemento_actual(iterador_vacio) == NULL, "No puedo ver el elemento en un iterador vacio");
    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &prueba[0], "Puedo ver el primer elemento");
    lista_iterador_avanzar(iterador);
    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &prueba[1], "Puedo ver el segundo elemento");
    lista_iterador_avanzar(iterador);
    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &prueba[2], "Puedo ver el tercer elemento");
    lista_iterador_avanzar(iterador);
    pa2m_afirmar(lista_iterador_elemento_actual(iterador) == &prueba[3], "Puedo ver el ultimo elemento");
    lista_iterador_destruir (iterador);

    pa2m_nuevo_grupo("  Pruebas lista_iterador_tiene_siguiente  ");

    iterador = lista_iterador_crear(lista);
    pa2m_afirmar(!lista_iterador_tiene_siguiente(NULL), "No puedo ver el siguiente en una lista NULL");
    pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador_vacio), "No puedo ver el siguiente en una lista vacia");
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador), "El primer elemento tiene siguiente");
    lista_iterador_avanzar(iterador);
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador), "El segundo elemento tiene siguiente");
    lista_iterador_avanzar(iterador);
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador), "El tercer elemento tiene siguiente");
    lista_iterador_avanzar(iterador);
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador), "El cuarto elemento tiene siguiente");
    lista_iterador_avanzar(iterador);
    pa2m_afirmar(!lista_iterador_tiene_siguiente(iterador), "Despues del ultimo elemento no hay siguiente");

    lista_destruir (lista);
    lista_destruir (lista_vacia);
    lista_iterador_destruir (iterador);
    lista_iterador_destruir (iterador_vacio);

}

bool avanzar_con_iterador (void* elemento, void* contador) {
    if(elemento && contador)
        (*(int*)contador)++;
    return true;
}

bool avanzar_con_iterador_hasta_la_mitad (void* elemento, void* contador) {
    if(elemento && contador)
        (*(int*)contador)++;
    if((*(int*)contador) == 5)
        return false;
    else
        return true;
}

void probar_lista_iterador_interno () {

    pa2m_nuevo_grupo("  Pruebas lista_con_cada_elemento  ");

    lista_t* lista = lista_crear ();
    char* prueba = "Algoritmos";
    int n = 0;

    pa2m_afirmar(lista_con_cada_elemento (NULL, avanzar_con_iterador, &n) == 0, "No puedo recorrer con un iterador interno una lista invalida");
    pa2m_afirmar(lista_con_cada_elemento (lista, avanzar_con_iterador, &n) == 0, "Recorrer una lista vacia me devuelve 0");
    pa2m_afirmar(lista_con_cada_elemento (lista, NULL, NULL) == 0, "No puedo iterar sin una funcion de iteracion");
    llenar_lista_con_caracteres (lista, prueba);
    pa2m_afirmar(lista_con_cada_elemento (lista, avanzar_con_iterador, &n) == 10, "Recorrer una lista con 10 elementos me devuelve 10");
    n = 0;
    pa2m_afirmar(lista_con_cada_elemento (lista, avanzar_con_iterador_hasta_la_mitad, &n) == 5, "Recorrer una lista con 10 elementos hasta la mitad me devuelve 5");
    lista_destruir(lista);
}

void probar_insertar_y_borrar_50000_elementos () {
    
    pa2m_nuevo_grupo("  Pruebas insertando y borrando 50.000 elementos  ");

    lista_t* lista = lista_crear();

    bool pude_insertar_todo = true;
    for (unsigned long i = 0; i < 50000; i++) {
        if (lista_insertar_en_posicion(lista, (void*)i, i) == -1){
            pude_insertar_todo = false;
        }
    }
    pa2m_afirmar(pude_insertar_todo, "Pude insertar 50.000 elementos");
    pa2m_afirmar(lista_elementos(lista) == 50000, "La lista tiene 50.000 elementos");
    bool son_todos_validos = true;
    lista_iterador_t* iterador = lista_iterador_crear (lista);
    for (unsigned long i = 0; i < 50000; i++) {
        if (lista_iterador_elemento_actual(iterador) != (void*)i){
            son_todos_validos = false;
        }
        lista_iterador_avanzar (iterador);
    }
    lista_iterador_destruir (iterador);
    pa2m_afirmar(son_todos_validos, "Los 50.000 elementos de la lista son validos");
    bool pude_borrar_todos = true;
    for (unsigned long i = 0; i < 50000; i++) {
        if(lista_borrar_de_posicion(lista,0) == -1) {
            pude_borrar_todos = false;
        }
    }
    pa2m_afirmar(pude_borrar_todos, "Pude borrar los 50.000 elementos de la lista");
    pa2m_afirmar(lista_vacia(lista), "La lista esta vacia");
    lista_destruir(lista);
}

int main (){
    probar_funcionalidades_lista ();
    probar_funcionalidades_pila ();
    probar_funcionalidades_cola ();
    probar_lista_iterador_externo ();
    probar_lista_iterador_interno ();
    probar_insertar_y_borrar_50000_elementos();
    pa2m_mostrar_reporte();
}