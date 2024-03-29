#ifndef __PA2M_H_
#define __PA2M_H_

#include <stdio.h>

#define BLANCO "\033[37;1m"
#define VERDE "\033[32;1m"
#define ROJO "\033[31;1m"
#define AMARILLO "\033[33;1m"
#define NORMAL "\033[0m"

#define TILDE "✓"
#define CRUZ "✗"

int __pa2m_cantidad_de_pruebas_corridas = 0;
int __pa2m_cantidad_de_pruebas_fallidas = 0;

void pa2m_afirmar(int afirmacion, const char *descripcion) {
  if (afirmacion) {
    printf(VERDE TILDE " ");
  } else {
    __pa2m_cantidad_de_pruebas_fallidas++;
    printf(ROJO CRUZ " ");
  }
  printf(BLANCO "%s\n", descripcion);
  __pa2m_cantidad_de_pruebas_corridas++;
}

void pa2m_nuevo_grupo(const char* descripcion) {
  printf(AMARILLO "\n%s\n", descripcion);
  while(*(descripcion++)) printf("=");
  printf(BLANCO "\n");
}

int pa2m_mostrar_reporte() {
  printf("\n---------------------------------\n"
         "%i pruebas corridas, %i errores - %s\n" NORMAL,
         __pa2m_cantidad_de_pruebas_corridas,
         __pa2m_cantidad_de_pruebas_fallidas,
         __pa2m_cantidad_de_pruebas_fallidas == 0 ? "OK" : "D:");
  return __pa2m_cantidad_de_pruebas_fallidas;
}

#endif // __PA2M_H_
