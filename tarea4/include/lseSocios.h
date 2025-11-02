/*
  Módulo de definición de 'TLSESocios'.

  Un elemento de tipo TLSESocios es una lista simplemente enlazada, en la que cada elemento 
  contiene un elemento de tipo TSocio.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef LSESOCIOS_H
#define LSESOCIOS_H

#include "socio.h"

// Define el tipo TLSESocios como un puntero a rep_lseSocios
typedef struct rep_lseSocios *TLSESocios;

// Función para crear un elemento de tipo TLSESocios vacío.
// Devuelve una lista sin elementos.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
TLSESocios crearTLSESociosVacia();

// Función para verificar si una lista de socios es vacía, retorna true si y solo si la lista es vacía.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
bool esVaciaTLSESocios(TLSESocios lseSocios);

// Función para imprimir todas los socios de una lista de socios.
// Los socios se imprimen en el orden en que aparecen en la lista de la siguiente manera 
//
// Lista de Socios:
// < invocar sucesivamente la función imprimirTSocio >
//
// Si la lista está vacía solo imprime el primer mensaje.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de socios en la lista. */
void imprimirTLSESocios(TLSESocios lseSocios);

// Función para liberar una lista de socios.
// Recibe un elemento de tipo TLSESocios y libera su memoria.
// Libera además la memoria de cada una de los socios en la lista.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de socios en la lista.
void liberarTLSESocios(TLSESocios &lseSocios);

// Función para agregar una entrada a la lista de socios.
// Inserta el socio, ordenando de menor a mayor por fecha de alta.
// Si existe otro socio que fue dado de alta en la misma fecha, la que se está ingresando 
// aparece después en la lista.
// PRE: no existe una entrada en la lista para la misma CI de socio.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de socios en la lista.
void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio);

// Función para verificar si existe un socio determinado en la lista.
// Recibe una CI de un socio y regresa un booleano indicando si existe dicho
// socio en la lista.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de socios en la lista.
bool existeSocioTLSESocios(TLSESocios lseSocios, int ci);

// Función para obtener un socio determinado de la lista.
// Recibe una CI de un socio y regresa una copia del elemento TSocio con dicha CI.
// PRE: existeSocioTLSESocios(lseSocios, ci) == true
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de socios en la lista.
TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci);

// Función quer retorna la cantidad de socios en la lista.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, donde n es la cantidad de socios en la lista
nat cantidadTLSESocios(TLSESocios lseSocios);

// Función para obtener un socio de la lista de socios. 'n' indica el índice desde el 
// inicio (invocar con n = 1 devuelve el primer elemento). 
// PRE: n > 0
// PRE: n es menor o igual a la cantidad de socios en la lista
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de socios en la lista.
TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n);

// Función para remover uns socio de una lista de socios.
// Recibe una lista de socios y una CI de un socio, elimina la 
// entrada para dicho socio y libera la memoria asociada al socio.
// PRE: existeSocioTLSESocios(lseSocios, ci) == true
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de socios en la lista.
void removerSocioTLSESocios(TLSESocios &lseSocios, int ci);

#endif // LSESOCIOS_H  
