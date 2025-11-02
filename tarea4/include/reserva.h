/*
  Módulo de definición de 'TReserva'.

  Los elementos de tipo TReserva representan una reserva de un socio hacia un determinado libro
  de la biblioteca. Cada reserva contiene un elemento de tipo TSocio y un elemento de tipo
  TLibro.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef TRESERVA_H
#define TRESERVA_H

#include <string.h>

#include "socio.h"
#include "libro.h"

// Define el tipo TReserva como un puntero a rep_reserva
typedef struct rep_reserva *TReserva;

// Función que crea un elemento de tipo TReserva con los valores pasados por parámetro.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
TReserva crearTReserva(TSocio socio, TLibro libro);

// Función que imprime la información de la reserva en el siguiente formato:
//
// Reserva de libro <titulo libro> por <nombre socio> <apellido socio>.
//
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
void imprimirTReserva(TReserva reserva);

// Función que libera la memoria asignada para una reserva. También libera
// la memoria del socio y el libro.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
void liberarTReserva(TReserva &reserva);

// Función que retorna el socio de la reserva.
/* Requisitos específicos de la implementación solicitada: */
// El socio retornado comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso
TSocio socioTReserva(TReserva reserva);

// Función que devuelve el libro de la reserva.
/* Requisitos específicos de la implementación solicitada: */
// El libro retornado comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso
TLibro libroTReserva(TReserva reserva);

// Función que copia una reserva.
/* Requisitos específicos de la implementación solicitada: */
// La copia *no* comparte memoria con la reserva pasada por parámetro.
// Debe ejecutar en O(1) peor caso
TReserva copiarTReserva(TReserva reserva);

// Función que libera únicamente la estructura de la reserva, pero NO libera la memoria
// del socio ni del libro a los que apunta.
// Debe ejecutar en O(1) peor caso
void liberarTReservaSoloEstructura(TReserva &reserva);

#endif  // TRESERVA_H
