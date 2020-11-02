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
    void* anteultimo = lista_elemento_en_posicion(lista, 2);
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == anteultimo, "El anteultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");
    anteultimo = lista_elemento_en_posicion(lista, 1);
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == anteultimo, "El anteultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 2, "Quedan 2 elementos en la lista");
    anteultimo = lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_ultimo(lista) == anteultimo, "El anteultimo elemento ahora es el ultimo");
    pa2m_afirmar(lista_elementos(lista) == 1, "Queda 1 elemento en la lista");
    
    pa2m_afirmar(lista_borrar(lista) == 0, "Pude borrar el ultimo elemento de la lista");
    pa2m_afirmar(lista_elementos(lista) == 0, "Quedan 0 elementos en la lista");
    pa2m_afirmar(lista_vacia(lista), "La lista esta vacia");
    
    free(lista);

}

void probar_insertar_y_borrar_en_distintas_pos () {
    pa2m_nuevo_grupo("Pruebas insertando y borrando en distintas posiciones");
    lista_t* lista;
    lista = lista_crear();
    int elemento_1 = 34;
    int elemento_2 = 354;
    int elemento_3 = 999;
    int elemento_4 = 21321;
    pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento_1, 0) == 0, "Inserte un elemento en la posicion 0");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &elemento_1, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene 1 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento_2, 1) == 0, "Inserte un elemento en la posicion 1");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &elemento_2, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene 2 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento_3, 2) == 0, "Inserte un elemento en la posicion 2");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &elemento_3, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista tiene 3 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento_4, 1) == 0, "Inserte un elemento en la posicion 1");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == &elemento_4, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 4, "La lista tiene 4 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(lista, NULL, 4) == 0, "Inserte un elemento en la posicion 4");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == NULL, "El elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 5, "La lista tiene 5 elementos");

    pa2m_afirmar(lista_insertar_en_posicion(NULL, NULL, 6) == -1, "No puedo insertar en lista inexistente");

    pa2m_afirmar(lista_insertar_en_posicion(lista, NULL, 235) == 0, "Posicion invalida inserta al final");
    pa2m_afirmar(lista_ultimo(lista) == NULL, "El ultimo elemento es correcto");
    pa2m_afirmar(lista_elementos(lista) == 6, "La lista tiene 6 elementos");

    pa2m_afirmar(lista_borrar_de_posicion(lista, 2) == 0,"Borro un elemento en la 2º posicion");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 4) == 0,"Borro un elemento en la ultima posicion");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0,"Borro un elemento en la primera posicion");
    pa2m_afirmar(lista_elementos(lista) == 3, "Quedan 3 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) == -1, "No puedo borrar una lista inexistente");
    pa2m_afirmar(lista_elementos(lista) == 3, "Siguen quedando 3 elementos en la lista");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 500) == 0, "Borro un elemento en la ultima posicion por poner una posicion inexistente");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 1) == 0, "Borro un elemento de la ultima posicion");
    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Borro un elemento en la primera posicion");
    pa2m_afirmar(lista_vacia(lista), "La lista esta vacia");
    free (lista);

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