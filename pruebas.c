#include "lista.h"
#include "pa2m.h"
#include <stdlib.h>

void probar_crear_lista () {
    pa2m_nuevo_grupo("Pruebas de creacion");
    lista_t* lista = NULL;
    pa2m_afirmar((lista = lista_crear()) != NULL, "Pude crear la lista");
    pa2m_afirmar((*lista).cantidad == 0, "La lista se crea con 0 elementos");
    pa2m_afirmar((*lista).nodo_inicio == NULL && (*lista).nodo_fin == NULL, "Los nodos de la lista se inicializan a NULL");
    free(lista);
}

void probar_insertar_y_borrar_al_final () {
    pa2m_nuevo_grupo("Pruebas insertando y borrando al final");
    lista_t* lista = NULL;
    lista = lista_crear();
    int elemento1 = 1;
    int elemento2 = 2;
    int elemento3 = 3;
    int elemento4 = 4;
    pa2m_afirmar(lista_insertar(NULL, NULL) == -1, "No puede insertar en lista NULL");
    pa2m_afirmar(lista_insertar(lista, &elemento1) == 0, "Pude insertar un elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento1, "El 1º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 1, "Queda 1 elemento en la lista");
    pa2m_afirmar(lista_insertar(lista, &elemento2) == 0, "Pude insertar un segundo elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento2, "El 2º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 2, "Quedan 2 elementos en la lista");
    pa2m_afirmar(lista_insertar(lista, &elemento3) == 0, "Pude insertar un tercer elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento3, "El 3º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");
    pa2m_afirmar(lista_insertar(lista, &elemento4) == 0, "Pude insertar un cuarto elemento");
    pa2m_afirmar(lista_ultimo(lista) == &elemento4, "El 4º elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 4, "Quedan 4 elementos en la lista");
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar de la lista");
    pa2m_afirmar(lista_ultimo(lista) == &elemento3, "Cambio el ultimo elemento");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Pude borrar el 1º elemento");
    pa2m_afirmar(lista_elementos(lista) == 2, "Quedan 2 elementos en la lista");

}

void probar_insertar_y_borrar_en_distintas_pos () {
    pa2m_nuevo_grupo("Pruebas insertando y borrando en distintas posiciones");
    lista_t* lista;
    lista = lista_crear();
    int elemento1 = 1;
    int elemento2 = 2;
    int elemento3 = 3;
    int elemento4 = 4;
    int extra1 = 34;
    int extra2 = 354;
    int extra3 = 999;
    int extra4 = 21321;
    int extra5 = 93213219;
    lista_insertar(lista, &elemento1);
    lista_insertar(lista, &elemento2);
    lista_insertar(lista, &elemento3);
    lista_insertar(lista, &elemento4);
    pa2m_afirmar(lista_insertar_en_posicion(lista, &extra1, 0) == 0, "Inserte un elemento en la posicion 0");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &extra1, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 5, "La lista tiene 5 elementos");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &extra2, 3) == 0, "Inserte un elemento en la posicion 3");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == &extra2, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 6, "La lista tiene 6 elementos");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &extra3, 4) == 0, "Inserte un elemento en la posicion 4");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == &extra3, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 7, "La lista tiene 7 elementos");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &extra4, 2) == 0, "Inserte un elemento en la posicion 2");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &extra4, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 8, "La lista tiene 8 elementos");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &extra5, 8) == 0, "Inserte un elemento en la posicion 8");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 8) == &extra5, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 9, "La lista tiene 9 elementos");
    pa2m_afirmar(lista_insertar_en_posicion(lista, NULL, 6) == 0, "Inserte un elemento en la posicion 6");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 6) == NULL, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 10, "La lista tiene 10 elementos");
    pa2m_afirmar(lista_insertar_en_posicion(NULL, NULL, 6) == -1, "No puedo insertar en lista inexistente");
    pa2m_afirmar(lista_insertar_en_posicion(lista, NULL, 235) == 0, "Posicion invalida inserta al final");
    pa2m_afirmar(lista_ultimo(lista) == NULL, "El ultimo elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 11, "La lista tiene 11 elementos");
}

void probar_insertar_y_borrar_10000_elementos () {
    
    pa2m_nuevo_grupo("Pruebas insertando y borrando 10000 elementos");

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
    free(lista);
}

int main (){
    probar_crear_lista ();
    probar_insertar_y_borrar_al_final ();
    probar_insertar_y_borrar_en_distintas_pos();
    probar_insertar_y_borrar_10000_elementos();
    pa2m_mostrar_reporte();
}