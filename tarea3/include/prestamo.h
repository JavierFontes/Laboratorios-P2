/*
  Módulo de definición de 'TPrestamo'.

  Los elementos de tipo TPrestamo representan un préstamo de un libro a un socio
  de la biblioteca. Cada nodo contiene un elemento de tipo TSocio, un elemento de tipo
  TLibro, una fecha de retiro y una fecha de devolución.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef TPRESTAMO_H
#define TPRESTAMO_H

#include <string.h>

#include "socio.h"
#include "libro.h"

// Define el tipo TPrestamo como un puntero a rep_prestamo
typedef struct rep_prestamo *TPrestamo;

// Función que crea un elemento de tipo TPrestamo con los valores pasados por parámetro.
// Al momento de su creación, un elemento de tipo TPrestamo no está retornado.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro);

// Función que imprime la información del préstamo en el siguiente formato:
//
// Préstamo de libro <titulo libro> a <nombre socio> <apellido socio>. Desde <fecha retiro> - Hasta <fecha devolución>
//
// Si la fecha de devolución es NULL, en lugar de 'Hasta <fecha devolución>' se imprime 'No Retornado'.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
void imprimirTPrestamo(TPrestamo prestamo);

// Función que libera la memoria asignada para un préstamo. También libera
// la memoria del socio, el libro y las fechas asociadas.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
void liberarTPrestamo(TPrestamo &prestamo);

// Función que retorna el socio del préstamo.
/* Requisitos específicos de la implementación solicitada: */
// El socio retornado comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso
TSocio socioTPrestamo(TPrestamo prestamo);

// Función que retorna la fecha de retiro del préstamo.
/* Requisitos específicos de la implementación solicitada: */
// La fecha retornada comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso
TFecha fechaRetiroTPrestamo(TPrestamo prestamo);

// Función que retorna la fecha de devolución del préstamo.
/* Requisitos específicos de la implementación solicitada: */
// La fecha retornada comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso
TFecha fechaDevolucionTPrestamo(TPrestamo prestamo);

// Función que devuelve el libro del prestamo.
/* Requisitos específicos de la implementación solicitada: */
// El libro retornado comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso
TLibro libroTPrestamo(TPrestamo prestamo);

// Función que indica si un préstamo fue retornado.
// Si tiene fecha de devolución, se considera retornado.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
bool fueRetornadoTPrestamo(TPrestamo prestamo);

// Función que actualiza la fecha de devolución del préstamo.
// Si existe, libera la memoria de la antigua fecha de devolución.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
// PRE: fechaDevolucion != NULL;
void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion);

// Función que copia un préstamo.
/* Requisitos específicos de la implementación solicitada: */
// La copia *no* comparte memoria con el préstamo pasado por parámetro.
// Debe ejecutar en O(1) peor caso
TPrestamo copiarTPrestamo(TPrestamo prestamo);


/* ********** FUNCIONES NUEVAS TAREA 3 ********** */
// Libera la memoria asignada para un préstamo y sus fechas asociadas.
// IMPORTANTE: Esta función NO libera la memoria del socio ni del libro apuntados por el préstamo,
// evitando así problemas de doble liberación.
// PRE: prestamo != NULL
/* Requisitos específicos de la implementación solicitada: */
// La función es O(1) en el peor caso.
void liberarTPrestamoSoloEstructura(TPrestamo &prestamo);

#endif  // TPRESTAMO_H
