/*
  Módulo de definición de 'TLDEPrestamos'.

  Un elemento de tipo TLDEPrestamos es una lista doblemente encadenada donde cada nodo representa
  un préstamo. Cada nodo contiene un elemento de tipo TPrestamo (además de los campos necesarios
  para mantener la lista doblemente encadenada). Además, la estructura cuenta con un cabezal
  con puntero al inicio y al final de la lista.

  Laboratorio de Programación 2. InCo-FIng-UDELAR
 */
#ifndef TLDEPRESTAMOS_H
#define TLDEPRESTAMOS_H

#include "prestamo.h"

// Define el tipo TLDEPrestamos como un puntero a rep_ldePrestamos
typedef struct rep_ldePrestamos *TLDEPrestamos;

/* ********** FUNCIONES NUEVAS TAREA 3 ********** */
// Función que elimina la ldePrestamos de forma segura.
// Libera la memoria asociada a todos los nodos y a los préstamos que contienen,
// llamando a una función de liberación para cada préstamo que NO libera la memoria de
// los socios ni los libros asociados al nodo.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) en el peor caso.
void liberarTLDEPrestamosSoloEstructura(TLDEPrestamos &ldePrestamos);

/* ********** FUNCIONES TAREA 2 ********** */

// Función para crear una nueva TLDEPrestamos vacía
// Devuelve una instancia de TLDEPrestamos vacía.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(1) peor caso.
TLDEPrestamos crearTLDEPrestamosVacia();

// Función para insertar ordenadamente de menor a mayor un préstamo en la lista de préstamos,
// según la fecha de préstamo (fecha de retiro). Si ya existe uno o más préstamos para la misma fecha,
// el nuevo preéstamo es agregado al final de los demás préstamos con la misma fecha.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de préstamos en la lista
void insertarTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo);

// Función que elimina la ldePrestamos. También libera
// la memoria asociada a todos los préstamos.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, donde n es la cantidad de préstamos en la lista.
void liberarTLDEPrestamos(TLDEPrestamos &ldePrestamos);

// Función para imprimir secuencialmente los préstamos de menor a mayor, según su fecha de préstamo (fecha de retiro).
// El formato de impresión es:
// LDE Préstamos:
//     <y luego para cada préstamo se repite>
//     <imprimir con función imprimirTPrestamo>
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, donde n es la cantdiad de préstamos en la lista.
void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos);

// Función para imprimir secuencialmente los préstamos de mayor a menor, según su fecha de préstamo (fecha de retiro).
// El formato de impresión es:
// LDE Préstamos:
//     <y luego para cada préstamo se repite>
//     <imprimir con función imprimirTPrestamo>
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, donde n es la cantdiad de préstamos en la lista.
void imprimirInvertidoTLDEPrestamos(TLDEPrestamos ldePrestamos);

// Función quer retorna la cantidad de préstamos en la lista.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(1) peor caso, donde n es la cantidad de préstamos en la lista
nat cantidadTLDEPrestamos(TLDEPrestamos ldePrestamos);

// Función para obtener el primer préstamo en la lista de préstamos (el préstamo con menor
// fecha de retiro).
// PRE: la lista no es vacía
/* Requisitos específicos de la implementación solicitada: */
// La función es O(1) peor caso.
TPrestamo obtenerPrimeroTLDEPrestamos(TLDEPrestamos ldePrestamos);

// Función para obtener el último préstamo en la lista de préstamos (el préstamo con mayor fecha de retiro).
// PRE: la lista no es vacía
/* Requisitos específicos de la implementación solicitada: */
// La función es O(1) peor caso.
TPrestamo obtenerUltimoTLDEPrestamos(TLDEPrestamos ldePrestamos);

// Función para obtener un préstamo de la lista de préstamos. 'n' indica el índice desde el
// inicio (invocar con n = 1 devuelve el primer elemento).
// PRE: n > 0
// PRE: n es menor o igual a la cantidad de préstamos en la lista
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, siendo n la cantidad de préstamos en la lista.
TPrestamo obtenerNesimoTLDEPrestamos(TLDEPrestamos &ldePrestamo, int n);

// criterio = 0 -> prestamos retornados
// criterio = 1 -> prestamos no retornados
TLDEPrestamos filtrarPrestamosTLDEPrestamos(TLDEPrestamos &ldePrestamos, int criterio);



#endif // TLDEPRESTAMOS_H

