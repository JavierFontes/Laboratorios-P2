/*
  Módulo de definición de 'utils'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>  // printf, scanf, sprintf

// tipo para los enteros no negativos
typedef unsigned int nat;

// tipos para arreglos
// typedef nat *ArregloNats;       // arreglo de nat
// typedef char *ArregloChars;     // arreglo de char
// typedef bool *ArregloBools;     // arreglo de bool
// typedef double *ArregloDoubles; // arreglo de double

// leen desde la entrada estándar y devuelven el elemento leído
nat leerNat();
char leerChar();
double leerDouble();

/*
  Lee en 'cs' desde la entrada estándar.
 */
void leerChars(char* cs);

/*
  Lee en 'cs' desde la entrada estándar. El formato de cs debe ser texto entrecomillado ("   "). 
  También lee los espacios en el texto entrecomillado. 
 */
void leerString(char* cs);

/*
  Lee en 'cs' el resto de la línea de la entrada estandar sin consumir
  el cambio de línea.
 */
void leerRestoLinea(char* cs);

/*
  Descarta resto de la línea de la entrada estandar sin consumir
  el cambio de línea.
 */
void descartarRestoLinea();

#endif