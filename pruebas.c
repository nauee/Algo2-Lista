#include "lista.h"
#include "pa2m.h"
#include <stdlib.h>

void llenar_lista_con_caracteres (lista_t* lista, char* string) {
    for(int i=0; string[i]!= 0; i++){
        lista_insertar(lista, &string[i]);
    }
}

void apilar_lista_con_caracteres(lista_t* pila, char* string){
    for(int i=0; string[i]!= 0; i++){
        lista_apilar(pila, &string[i]);
    }
}

void encolar_lista_con_caracteres(lista_t* cola, char* string){
    for(int i=0; string[i]!= 0; i++){
        lista_encolar(cola, &string[i]);
    }
}

void probar_lista_crear () {
    pa2m_nuevo_grupo("  Pruebas lista_crear  ");
    lista_t* lista = NULL;
    pa2m_afirmar((lista = lista_crear()) != NULL, "Pude crear la lista");
    pa2m_afirmar((*lista).cantidad == 0, "La lista se crea con 0 elementos");
    pa2m_afirmar((*lista).nodo_inicio == NULL && (*lista).nodo_fin == NULL, "Los nodos de la lista se inicializan a NULL");
    lista_destruir(lista);
}

void probar_lista_insertar () {
    pa2m_nuevo_grupo("  Pruebas lista_insertar  ");
    lista_t* lista = NULL;
    lista = lista_crear();
    int elemento1 = 214214;
    int elemento2 = 51514;
    int elemento3 = 351541;
    int elemento4 = 5121214;
    pa2m_afirmar(lista_insertar(NULL, NULL) == -1, "No puede insertar en lista NULL");
    pa2m_afirmar(lista_elementos(lista) == 0, "La lista tiene 0 elementos");

    pa2m_afirmar(lista_insertar(lista, &elemento1) == 0, "Pude insertar un elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento1, "El 1º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene 1 elementos");

    pa2m_afirmar(lista_insertar(lista, &elemento2) == 0, "Pude insertar un segundo elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento2, "El 2º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elementos");

    pa2m_afirmar(lista_insertar(lista, &elemento3) == 0, "Pude insertar un tercer elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento3, "El 3º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista tiene 3 elementos");

    pa2m_afirmar(lista_insertar(lista, &elemento4) == 0, "Pude insertar un cuarto elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento4, "El 4º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 4, "La lista tiene 4 elementos");

    pa2m_afirmar(lista_insertar(lista, NULL) == 0, "Pude insertar un elemento NULL");
    pa2m_afirmar(lista_ultimo(lista) == NULL, "El 5º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 5, "La lista tiene 5 elementos");

    for(int i = 0; i < 5; i++) {
        lista_borrar_de_posicion(lista, 0);
    }
    lista_destruir(lista);
}

void probar_lista_insertar_en_posicion () {
    pa2m_nuevo_grupo("  Pruebas lista_insertando_en_posicion  ");
    lista_t* lista;
    lista = lista_crear();
    char* letras = "Hola";

    pa2m_afirmar(lista_insertar_en_posicion(NULL, NULL, 0) == -1, "No puedo insertar en lista inexistente");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &letras[0], 0) == 0, "Pude insertar un elemento en la primera posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &letras[0], "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene 1 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &letras[1], 1) == 0, "Pude insertar un elemento en la ultima posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &letras[1], "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &letras[2], 0) == 0, "Pude insertar un elemento en la primera posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &letras[2], "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista tiene 3 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &letras[3], 2) == 0, "Pude insertar un elemento en la posicion 2º");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &letras[3], "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 4, "La lista tiene 4 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, NULL, 4) == 0, "Pude insertar un elemento NULL en la posicion 4º");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == NULL, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 5, "La lista tiene 5 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, NULL, 235) == 0, "Posicion inexistente inserta al final");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 5) == NULL, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 6, "La lista tiene 6 elementos");

    for (int i = 0; i < 6; i++) {
        lista_borrar_de_posicion (lista, 0);
    }
    lista_destruir(lista);
}

void probar_lista_borrar () {

    pa2m_nuevo_grupo("  Pruebas lista_borrar  ");
    
    lista_t* lista = lista_crear();
    char* letras = "ABCD";
    llenar_lista_con_caracteres(lista, letras);

    pa2m_afirmar(lista_borrar(NULL) == -1, "No puedo borrar en una lista inexistente");

    void* penultimo = lista_elemento_en_posicion(lista, 2);
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == penultimo, "El antiguo penultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");

    penultimo = lista_elemento_en_posicion(lista, 1);
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == penultimo, "El antiguo penultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 2, "Quedan 2 elementos en la lista");

    penultimo = lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == penultimo, "El antiguo penultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 1, "Queda 1 elemento en la lista");
    
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_elementos(lista) == 0, "Quedan 0 elementos en la lista");

    pa2m_afirmar(lista_borrar(lista) == -1, "No puedo borrar en una lista vacia");
    
    lista_destruir(lista);

}

void probar_lista_borrar_en_posicion () {
    pa2m_nuevo_grupo("  Pruebas lista_borrar_en_posicion  ");
    
    lista_t* lista = lista_crear();
    char* letras = "ABCDF";
    llenar_lista_con_caracteres(lista, letras);

    pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) == -1, "No puedo borrar una lista inexistente");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0,"Puedo borrar un elemento en la primera posicion");
    pa2m_afirmar(lista_elementos(lista) == 4, "Quedan 4 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 4) == 0,"Puedo borrar un elemento en la ultima posicion");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 2) == 0,"Puedo borrar un elemento en la 2º posicion");
    pa2m_afirmar(lista_elementos(lista) == 2, "Quedan 2 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 500) == 0, "Posicion inexistente borra al final");
    pa2m_afirmar(lista_elementos(lista) == 1, "Quedan 1 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Puedo borrar un elemento en la primera posicion");
    pa2m_afirmar(lista_elementos(lista) == 0, "Quedan 0 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == -1, "No puedo borrar en una lista vacia");
    
    lista_destruir(lista);
}

void probar_lista_elemento_en_posicion_y_ultimo () {

    pa2m_nuevo_grupo("  Pruebas lista_elemento_en_posicion  ");
    
    lista_t* lista = lista_crear();
    char* letras = "ABCDF";
    pa2m_afirmar(lista_elemento_en_posicion(lista,0) == NULL, "No puedo mirar un elemento en una lista vacia");
    llenar_lista_con_caracteres(lista, letras);
    pa2m_afirmar(lista_elemento_en_posicion(NULL,0) == NULL, "No puedo mirar un elemento en una lista NULL");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1000) == NULL, "No puedo mirar un elemento en una posicion inexistente");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &letras[0], "Puedo mirar el elemento en primera posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == &letras[4], "Puedo mirar el elemento en ultima posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &letras[2], "Puedo mirar el elemento en 2º posicion");

    pa2m_nuevo_grupo("  Pruebas lista_ultimo   ");

    pa2m_afirmar(lista_ultimo(NULL) == NULL, "No puedo mirar el ultimo elemento en una lista NULL");
    pa2m_afirmar(lista_ultimo(lista) == &letras[4], "Puedo mirar el ultimo elemento");

    for(int i = 0; i < 6;i++){
        lista_borrar_de_posicion(lista, 0);
    }

    pa2m_afirmar(lista_ultimo(lista) == NULL, "No puedo mirar el ultimo elemento en una lista vacia");

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

void probar_lista_elementos () {
    pa2m_nuevo_grupo("  Pruebas lista_elementos  ");
    
    lista_t* lista = lista_crear();
    char* letras = "ABCDF";

    pa2m_afirmar(lista_elementos(NULL) == 0, "Una lista inexistente tiene 0 elementos");
    pa2m_afirmar(lista_elementos(lista) == 0, "Una lista vacia tiene 0 elementos");
    lista_insertar(lista, letras);
    pa2m_afirmar(lista_elementos(lista) == 1, "Lista con un elemento");
    llenar_lista_con_caracteres(lista, letras+1);
    pa2m_afirmar(lista_elementos(lista) == 5, "Lista con varios elementos");

    for(int i = 0; i < 5; i++) {
        lista_borrar_de_posicion(lista, 0);
    }

    lista_destruir(lista);

}

void probar_lista_apilar () {
    pa2m_nuevo_grupo("  Pruebas lista_insertar  ");
    lista_t* lista = NULL;
    lista = lista_crear();
    int elemento1 = 1;
    int elemento2 = 2;
    int elemento3 = 3;
    int elemento4 = 4;
    pa2m_afirmar(lista_apilar(NULL, NULL) == -1, "No puedo apilar en lista NULL");
    pa2m_afirmar(lista_elementos(lista) == 0, "La pila tiene 0 elementos");

    pa2m_afirmar(lista_apilar(lista, &elemento1) == 0, "Puedo apilar un elemento");
    pa2m_afirmar(lista_tope(lista) == &elemento1, "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(lista) == 1, "La pila tiene 1 elementos");

    pa2m_afirmar(lista_apilar(lista, &elemento2) == 0, "Puedo apilar un segundo elemento");
    pa2m_afirmar(lista_tope(lista) == &elemento2, "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(lista) == 2, "La pila tiene 2 elementos");

    pa2m_afirmar(lista_apilar(lista, &elemento3) == 0, "Puedo apilar un tercer elemento");
    pa2m_afirmar(lista_tope(lista) == &elemento3, "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(lista) == 3, "La pila tiene 3 elementos");

    pa2m_afirmar(lista_apilar(lista, &elemento4) == 0, "Puedo apilar un cuarto elemento");
    pa2m_afirmar(lista_tope(lista) == &elemento4, "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(lista) == 4, "La pila tiene 4 elementos");

    pa2m_afirmar(lista_apilar(lista, NULL) == 0, "Puedo apilar un elemento NULL");
    pa2m_afirmar(lista_tope(lista) == NULL, "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(lista) == 5, "La pila tiene 5 elementos");

    for(int i = 0; i < 5; i++) {
        lista_borrar_de_posicion(lista, 0);
    }
    lista_destruir(lista);
}

void probar_lista_desapilar_y_tope () {

    pa2m_nuevo_grupo("  Pruebas lista_borrar  ");
    
    lista_t* lista = lista_crear();
    char* letras = "oglA";
    apilar_lista_con_caracteres(lista, letras);

    pa2m_afirmar(lista_desapilar(NULL) == -1, "No puedo desapilar en una lista inexistente");
    
    bool mire_elemento_tope = (lista_tope(lista) == &letras[3]);

    void* penultimo = lista_elemento_en_posicion(lista, 1);
    pa2m_afirmar(lista_desapilar(lista) == 0, "Pude desapilar el ultimo elemento de la lista");
    pa2m_afirmar(lista_tope(lista) == penultimo, "El elemento siguiente al tope ahora esta en el tope");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");

    penultimo = lista_elemento_en_posicion(lista, 1);
    pa2m_afirmar(lista_desapilar(lista) == 0, "Pude desapilar el ultimo elemento de la lista");
    pa2m_afirmar(lista_tope(lista) == penultimo, "El elemento siguiente al tope ahora esta en el tope");
    pa2m_afirmar(lista_elementos(lista) == 2, "Quedan 2 elementos en la lista");

    penultimo = lista_elemento_en_posicion(lista, 1);
    pa2m_afirmar(lista_desapilar(lista) == 0, "Pude desapilar el ultimo elemento de la lista");
    pa2m_afirmar(lista_tope(lista) == penultimo, "El elemento siguiente al tope ahora esta en el tope");
    pa2m_afirmar(lista_elementos(lista) == 1, "Queda 1 elemento en la lista");
    
    pa2m_afirmar(lista_desapilar(lista) == 0, "Pude desapilar el ultimo elemento de la lista");
    pa2m_afirmar(lista_elementos(lista) == 0, "Quedan 0 elementos en la lista");

    pa2m_afirmar(lista_desapilar(lista) == -1, "No puedo desapilar en una lista vacia");

    pa2m_nuevo_grupo("  Pruebas lista_tope  ");
    pa2m_afirmar(mire_elemento_tope, "Puedo mirar el tope en una pila con elementos");
    pa2m_afirmar(lista_tope(lista) == NULL, "No puedo mirar el tope en una pila vacia");
    pa2m_afirmar(lista_tope(NULL) == NULL, "No puedo mirar el tope en una pila inexistente");
    
    lista_destruir(lista);

}

void probar_funcionalidades_lista () {
    printf("\n");
    pa2m_nuevo_grupo("     Funcionalides de lista     ");
    printf("\n");
    probar_lista_crear ();
    probar_lista_insertar ();
    probar_lista_insertar_en_posicion ();
    probar_lista_borrar ();
    probar_lista_borrar_en_posicion ();
    probar_lista_elemento_en_posicion_y_ultimo ();
    probar_lista_vacia ();
    probar_lista_elementos ();
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
    pa2m_afirmar(lista_tope(pila) == &letras[0], "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(pila) == 1, "La pila tiene 1 elementos");

    pa2m_afirmar(lista_apilar(pila, &letras[1]) == 0, "Puedo apilar un segundo elemento");
    pa2m_afirmar(lista_tope(pila) == &letras[1], "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(pila) == 2, "La pila tiene 2 elementos");

    pa2m_afirmar(lista_apilar(pila, &letras[2]) == 0, "Puedo apilar un tercer elemento");
    pa2m_afirmar(lista_tope(pila) == &letras[2], "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(pila) == 3, "La pila tiene 3 elementos");

    pa2m_afirmar(lista_apilar(pila, NULL) == 0, "Puedo apilar un elemento NULL");
    pa2m_afirmar(lista_tope(pila) == NULL, "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(pila) == 4, "La pila tiene 4 elementos");

    pa2m_afirmar(lista_apilar(pila, &letras[3]) == 0, "Puedo apilar un cuarto elemento");
    pa2m_afirmar(lista_tope(pila) == &letras[3], "El elemento del tope es el que acabo de ingresar");
    pa2m_afirmar(lista_elementos(pila) == 5, "La pila tiene 5 elementos");

    pa2m_nuevo_grupo("  Pruebas lista_desapilar  ");

    pa2m_afirmar(lista_desapilar(NULL) == -1, "No puedo desapilar en una lista inexistente");
    
    bool mire_elemento_tope = (lista_tope(pila) == &letras[3]);

    void* penultimo = lista_elemento_en_posicion(pila, 1);
    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el ultimo elemento de la pila");
    pa2m_afirmar(lista_tope(pila) == penultimo, "El elemento siguiente al tope ahora esta en el tope");
    pa2m_afirmar(lista_elementos(pila) == 4, "Quedan 4 elementos en la pila");

    penultimo = lista_elemento_en_posicion(pila, 1);
    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el ultimo elemento de la pila");
    pa2m_afirmar(lista_tope(pila) == penultimo, "El elemento siguiente al tope ahora esta en el tope");
    pa2m_afirmar(lista_elementos(pila) == 3, "Quedan 3 elementos en la pila");

    penultimo = lista_elemento_en_posicion(pila, 1);
    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el ultimo elemento de la pila");
    pa2m_afirmar(lista_tope(pila) == penultimo, "El elemento siguiente al tope ahora esta en el tope");
    pa2m_afirmar(lista_elementos(pila) == 2, "Quedan 2 elementos en la pila");
    
    pa2m_afirmar(lista_desapilar(pila) == 0, "Pude desapilar el penultimo elemento de la pila");
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
    pa2m_afirmar(lista_ultimo(cola) == &letras[0], "El ultimo elemento es el que acaba de ingresar");
    pa2m_afirmar(lista_elementos(cola) == 1, "La cola tiene 1 elementos");

    pa2m_afirmar(lista_encolar(cola, &letras[1]) == 0, "Puedo encolar un segundo elemento");
    pa2m_afirmar(lista_ultimo(cola) == &letras[1], "El ultimo elemento es el que acaba de ingresar");
    pa2m_afirmar(lista_elementos(cola) == 2, "La cola tiene 2 elementos");

    pa2m_afirmar(lista_encolar(cola, &letras[2]) == 0, "Puedo encolar un tercer elemento");
    pa2m_afirmar(lista_ultimo(cola) == &letras[2], "El ultimo elemento es el que acaba de ingresar");
    pa2m_afirmar(lista_elementos(cola) == 3, "La cola tiene 3 elementos");

    pa2m_afirmar(lista_encolar(cola, &letras[3]) == 0, "Puedo encolar un cuarto elemento");
    pa2m_afirmar(lista_ultimo(cola) == &letras[3], "El ultimo elemento es el que acaba de ingresar");
    pa2m_afirmar(lista_elementos(cola) == 4, "La cola tiene 4 elementos");

    pa2m_afirmar(lista_encolar(cola, NULL) == 0, "Puedo encolar un elemento NULL");
    pa2m_afirmar(lista_ultimo(cola) == NULL, "El ultimo elemento es el que acaba de ingresar");
    pa2m_afirmar(lista_elementos(cola) == 5, "La cola tiene 5 elementos");

    pa2m_nuevo_grupo("  Pruebas lista_desencolar  ");

    pa2m_afirmar(lista_desencolar(NULL) == -1, "No puedo desencolar en una cola inexistente");
    
    bool mire_elemento_primero = (lista_primero(cola) == &letras[0]);

    void* segundo = lista_elemento_en_posicion(cola, 1);
    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
    pa2m_afirmar(lista_primero(cola) == segundo, "El segundo elemento ahora esta primero");
    pa2m_afirmar(lista_elementos(cola) == 4, "Quedan 4 elementos en la cola");

    segundo = lista_elemento_en_posicion(cola, 1);
    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
    pa2m_afirmar(lista_primero(cola) == segundo, "El segundo elemento ahora esta primero");
    pa2m_afirmar(lista_elementos(cola) == 3, "Quedan 3 elementos en la cola");

    segundo = lista_elemento_en_posicion(cola, 1);
    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
    pa2m_afirmar(lista_primero(cola) == segundo, "El segundo elemento ahora esta primero");
    pa2m_afirmar(lista_elementos(cola) == 2, "Quedan 2 elementos en la cola");
    
    pa2m_afirmar(lista_desencolar(cola) == 0, "Pude desencolar el ultimo elemento de la cola");
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

    pa2m_nuevo_grupo("  Pruebas lista_iterador_crear  ");

    char* prueba = "HOLA";
    lista_t* lista = lista_crear ();
    lista_t* lista_vacia = lista_crear ();
    lista_iterador_t* iterador;
    lista_iterador_t* iterador_vacio;
    llenar_lista_con_caracteres(lista, prueba);

    pa2m_afirmar((iterador_vacio = lista_iterador_crear(NULL)) == NULL, "No puedo crear un iterador externo en una lista invalida");
    pa2m_afirmar((iterador_vacio = lista_iterador_crear(lista_vacia)) != NULL, "Puedo crear un iterador externo en una lista vacia");
    pa2m_afirmar((iterador = lista_iterador_crear(lista)) != NULL, "Puedo crear un iterador externo en una lista con elementos");   

    pa2m_nuevo_grupo("  Pruebas lista_iterador_avanzar  ");

    pa2m_afirmar(lista_iterador_avanzar(NULL) == false, "No puedo avanzar un iterador invalido");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Puedo avanzar desde la primera posicion");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Puedo avanzar desde la segunda posicion");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Puedo avanzar desde la tercera posicion");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Puedo avanzar desde la ultima posicion");
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

    pa2m_nuevo_grupo("  Pruebas lista_iterador_elemento_actual  ");

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

bool mostrar_elemento(void* elemento, void* contador){
    if(elemento && contador)
        printf("Elemento %i: %c \n", (*(int*)contador)++, *(char*)elemento);
    return true;
}

bool avanzar_con_iterador (void* elemento, void* contador) {
    if(elemento && contador)
        (*(int*)contador)++;
    return true;
}

void probar_lista_iterador_interno () {

    pa2m_nuevo_grupo("  Pruebas lista_con_cada_elemento  ");

    lista_t* lista = lista_crear ();
    char* prueba = "Algoritmos";
    int n = 0;

    pa2m_afirmar(lista_con_cada_elemento (NULL, avanzar_con_iterador, &n) == 0, "No puedo recorrer con un iterador interno una lista invalida");
    pa2m_afirmar(lista_con_cada_elemento (lista, avanzar_con_iterador, &n) == 0, "Recorrer una lista vacia me devuelve 0");
    llenar_lista_con_caracteres (lista, prueba);
    pa2m_afirmar(lista_con_cada_elemento (lista, avanzar_con_iterador, &n) == 10, "Recorrer una lista con 10 elementos me devuelve 10");
    lista_destruir(lista);
}

void probar_insertar_y_borrar_10000_elementos () {
    
    pa2m_nuevo_grupo("  Pruebas insertando y borrando 10000 elementos  ");

    lista_t* lista = lista_crear();

    bool pude_insertar_todo = true;
    for (unsigned long i = 0; i < 10000; i++) {
        if (lista_insertar_en_posicion(lista, (void*)i, i) == -1){
            pude_insertar_todo = false;
        }
    }
    pa2m_afirmar(pude_insertar_todo, "Pude insertar 10000 elementos");
    pa2m_afirmar(lista_elementos(lista) == 10000, "La lista tiene 10000 elementos");
    bool son_todos_validos = true;
    for (unsigned long i = 0; i < 10000; i++) {
        if (lista_elemento_en_posicion(lista, i) != (void*)i){
            son_todos_validos = false;
        }
    }
    pa2m_afirmar(son_todos_validos, "Los 10000 elementos de la lista son validos");
    bool pude_borrar_todos = true;
    for (unsigned long i = 0; i < 10000; i++) {
        if(lista_borrar_de_posicion(lista,0) == -1) {
            pude_borrar_todos = false;
        }
    }
    pa2m_afirmar(pude_borrar_todos, "Pude borrar los 10000 elementos de la lista");
    pa2m_afirmar(lista_vacia(lista), "La lista esta vacia");
    lista_destruir(lista);
}

int main (){
    probar_funcionalidades_lista ();
    probar_funcionalidades_pila ();
    probar_funcionalidades_cola ();
    probar_lista_iterador_externo ();
    probar_lista_iterador_interno ();
    probar_insertar_y_borrar_10000_elementos();
    pa2m_mostrar_reporte();
}