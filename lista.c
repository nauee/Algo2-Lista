#include "lista.h"
#include <stdlib.h>

/*

    typedef struct nodo{
        void* elemento;
        struct nodo* siguiente;
    }nodo_t;

    typedef struct lista{
        nodo_t* nodo_inicio;
        nodo_t* nodo_fin;
        size_t cantidad;
    }lista_t;

    typedef struct lista_iterador{
        nodo_t* corriente;
        lista_t* lista;
    }lista_iterador_t;

*/

/******************************************************************************************** Lista crear ********************************************************************************************/

lista_t* lista_crear(){
    lista_t* lista = malloc (sizeof(lista_t));
    if (lista != NULL) {
        (*lista).cantidad = 0;
        (*lista).nodo_fin = NULL;
        (*lista).nodo_inicio = NULL;
    }
    return lista;
}

/****************************************************************************************** Lista insertar *******************************************************************************************/

int lista_insertar(lista_t* lista, void* elemento){
    
    if (lista == NULL){
        return -1;
    }

    nodo_t* nodo = malloc (sizeof(nodo_t));
    if (nodo == NULL) {
            return -1;
    }
    
    (*nodo).elemento = elemento;
    (*nodo).siguiente = NULL;

    if ((*lista).cantidad == 0) {  
        (*lista).nodo_fin = nodo;
        (*lista).nodo_inicio = nodo;
    } else {
        (*(*lista).nodo_fin).siguiente = nodo;
        (*lista).nodo_fin = nodo;
    }
    (*lista).cantidad ++;
    return 0;
}

/*****************************************************************************************************************************************************************************************************/