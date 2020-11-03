#include "lista.h"
#include "pa2m.h"
#include <stdlib.h>

void llenar_lista_con_caracteres (lista_t* lista, char* string) {
    for(int i=0; string[i]!= 0; i++){
        lista_insertar(lista, &string[i]);
    }
}

void probar_lista_crear () {
    pa2m_nuevo_grupo("Pruebas de creacion");
    lista_t* lista = NULL;
    pa2m_afirmar((lista = lista_crear()) != NULL, "Pude crear la lista");
    pa2m_afirmar((*lista).cantidad == 0, "La lista se crea con 0 elementos");
    pa2m_afirmar((*lista).nodo_inicio == NULL && (*lista).nodo_fin == NULL, "Los nodos de la lista se inicializan a NULL");
    lista_destruir(lista);
}

void probar_lista_insertar () {
    pa2m_nuevo_grupo("Pruebas insertar");
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
    pa2m_nuevo_grupo("Pruebas insertando en distintas posiciones");
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

    pa2m_nuevo_grupo("Pruebas borrar");
    
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
    pa2m_nuevo_grupo("Pruebas borrar_en_posicion");
    
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

    pa2m_nuevo_grupo("Pruebas elemento_en_posicion");
    
    lista_t* lista = lista_crear();
    char* letras = "ABCDF";
    pa2m_afirmar(lista_elemento_en_posicion(lista,0) == NULL, "No puedo mirar un elemento en una lista vacia");
    llenar_lista_con_caracteres(lista, letras);
    pa2m_afirmar(lista_elemento_en_posicion(NULL,0) == NULL, "No puedo mirar un elemento en una lista NULL");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 1000) == NULL, "No puedo mirar un elemento en una posicion inexistente");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &letras[0], "Puedo mirar el elemento en primera posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == &letras[4], "Puedo mirar el elemento en ultima posicion");
    pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == &letras[2], "Puedo mirar el elemento en 2º posicion");

    pa2m_nuevo_grupo("Pruebas ultimo");

    pa2m_afirmar(lista_ultimo(NULL) == NULL, "No puedo mirar el ultimo elemento en una lista NULL");
    pa2m_afirmar(lista_ultimo(lista) == &letras[4], "Puedo mirar el ultimo elemento");

    for(int i = 0; i < 6;i++){
        lista_borrar_de_posicion(lista, 0);
    }

    pa2m_afirmar(lista_ultimo(lista) == NULL, "No puedo mirar el ultimo elemento en una lista vacia");

    lista_destruir(lista);

}

void probar_lista_vacia () {

    pa2m_nuevo_grupo("Pruebas lista_vacia");

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
    pa2m_nuevo_grupo("Pruebas borrar_en_posicion");
    
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

void probar_iterador_externo (){

    pa2m_nuevo_grupo("Pruebas iterador externo");
    lista_t* lista = lista_crear();
    lista_iterador_t* iterador = NULL;
    lista_iterador_t* iterador_vacio = NULL;
    char* palabra_de_prueba = "palabra_de_prueba";
    bool todos_correctos = true;
    bool recorrio_todos = false;
    size_t n = 0;

    pa2m_afirmar((iterador_vacio = lista_iterador_crear(NULL)) == NULL, "No puedo crear un iterador externo en una lista invalida");
    pa2m_afirmar((iterador_vacio = lista_iterador_crear(lista)) != NULL, "Puedo crear un iterador externo en una lista vacia");

    for(int i=0; palabra_de_prueba[i]!= 0; i++){
        lista_insertar(lista, &palabra_de_prueba[i]);
    }
    
    pa2m_afirmar((iterador = lista_iterador_crear(lista)) != NULL, "Puedo crear un iterador externo en una lista con elementos");   
    while (lista_iterador_tiene_siguiente(iterador)) {
        if (*(char*)lista_iterador_elemento_actual(iterador) != *(char*)lista_elemento_en_posicion(lista, n))
            todos_correctos = false;
        n++;
        lista_iterador_avanzar(iterador);
    }

    if (n == (*lista).cantidad)
        recorrio_todos = true;

    pa2m_afirmar(recorrio_todos, "El iterador recorrio todos los elementos");
    pa2m_afirmar(todos_correctos, "El iterador obtuvo todo los elementos de manera correcta");
    lista_iterador_destruir(iterador);

    for (int j = 0; j <= 13; j++){
        lista_borrar(lista);
    }

    iterador = lista_iterador_crear(lista);
    pa2m_afirmar(lista_iterador_avanzar(NULL) == false, "No puedo avanzar un iterador invalido");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Puedo avanzar desde la primera posicion");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Puedo avanzar desde la segunda posicion");
    pa2m_afirmar(lista_iterador_avanzar(iterador), "Puedo avanzar desde la ultima posicion");
    pa2m_afirmar(lista_iterador_avanzar(iterador) == false, "No puedo avanzar despues la ultima posicion");
    pa2m_afirmar(lista_iterador_avanzar(iterador_vacio) == false, "No puedo avanzar con un iterador en una lista vacia");
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

void probar_funcionalidades_lista() {
    probar_lista_crear ();
    probar_lista_insertar ();
    probar_lista_insertar_en_posicion ();
    probar_lista_borrar ();
    probar_lista_borrar_en_posicion ();
    probar_lista_elemento_en_posicion_y_ultimo ();
    probar_lista_vacia ();
    probar_lista_elementos ();
}

int main (){
    probar_funcionalidades_lista ();
    //probar_iterador_externo();
    probar_insertar_y_borrar_10000_elementos();
    pa2m_mostrar_reporte();
}