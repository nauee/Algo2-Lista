#include "lista.h"
#include "pa2m.h"

void probar_crear_lista () {
    lista_t* lista = NULL;
    pa2m_afirmar((lista = lista_crear()) != NULL, "Pude crear la lista");
    pa2m_afirmar((*lista).cantidad == 0, "La lista se crea con 0 elementos");
    pa2m_afirmar((*lista).nodo_inicio == NULL && (*lista).nodo_fin == NULL, "Los nodos de la lista se inicializan a NULL");
}

void probar_insertar () {
    lista_t* lista = NULL;
    lista = lista_crear();
    int elemento1 = 1;
    int elemento2 = 2;
    int elemento3 = 3;
    int elemento4 = 4;
    pa2m_afirmar(lista_insertar(NULL, NULL) == -1, "No puede insertar en lista NULL");
    pa2m_afirmar(lista_insertar(lista, &elemento1) == 0, "Pude insertar 1 elemento");
    pa2m_afirmar(*((int*)(*(*lista).nodo_fin).elemento) == 1, "El elemento insertado es el correcto");
    pa2m_afirmar(lista_insertar(lista, &elemento2) == 0, "Pude insertar un segundo elemento");
    pa2m_afirmar(lista_insertar(lista, &elemento3) == 0, "Pude insertar un tercer elemento");
    pa2m_afirmar(lista_insertar(lista, &elemento4) == 0, "Pude insertar un cuarto elemento");
    pa2m_afirmar(*((int*)(*(*(*lista).nodo_inicio).siguiente).elemento) == 2, "El segundo elemento insertado es el correcto");
    pa2m_afirmar(*((int*)(*(*(*(*lista).nodo_inicio).siguiente).siguiente).elemento) == 3, "El tercer elemento insertado es el correcto");
    pa2m_afirmar(*((int*)(*(*(*(*(*lista).nodo_inicio).siguiente).siguiente).siguiente).elemento) == 4, "El cuarto elemento insertado es el correcto");
    //*((int*)(*(*(*lista).nodo_inicio).siguiente).elemento) == 2
}

int main (){
    pa2m_nuevo_grupo("Pruebas de creacion");
    probar_crear_lista ();
    pa2m_nuevo_grupo("Pruebas de insercion");
    probar_insertar ();

    pa2m_mostrar_reporte();
}