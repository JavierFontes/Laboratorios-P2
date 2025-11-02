/*
Módulo de definición de 'TTablaReserva'.


  Los elementos de tipo TTablaReserva almacenan la información necesaria para las reservas de los distintos libros.

  El objetivo de este moodulo es el de alamacenar las reservas de los libros de la biblioteca,
  de forma tal que se pueda acceder a las reservas de un libro en particular, a partir de su isbn.
  Para ello, se utiliza un hash, donde cada posición de la tabla
  contiene una cola de prioridad con las reservas del libro asociado a esa posición.

    Un elemento de tipo TTablaReserva debe mantener:

        - Un hash que asocia a cada isbn de libro a su cola de prioridad de reservas.

Laboratorio de Programación 2.
InCo-FIng-UDELAR
*/
#ifndef TABLA_TABLA_RESERVA_H
#define TABLA_TABLA_RESERVA_H

#include "utils.h"
#include "colaDePrioridadReservas.h"

//  Definición de tipo TTablaReserva como un puntero a rep_tablaTablaReserva
typedef struct rep_tablaTablaReserva *TTablaReserva;

//  Función para crear una nueva Tabla vacía,
//  en la que se estima que se insertarán max entradas.
//  La función es O(max) peor caso.
TTablaReserva crearTTablaReserva(int max, int N);

//  Función para insertar una asociación (isbn, reserva) en la tabla de reservas.
//  La función asocia el isbn de un libro con su reserva.
//  PRE: !perteneceTTablaReserva(tabla, reserva)
//  La funcion es O(N + l) peor caso, siendo:
//    N: el parametro N usado al crear la tabla
//    l: la cantidad de libros para los cuales hay reservas en la tabla
void insertarTTablaReserva(TTablaReserva &tabla, int isbn, TReserva reserva);

//  Función para verificar si en una TTablaReserva "tabla"
//  existe una asociación que representa la reserva del libro con el isbn dado.
//  Devuelve true si existe, false en caso contrario.
//  La funcion es O(N + l) peor caso, siendo:
//    N: el parametro N usado al crear la tabla
//    l: la cantidad de libros para los cuales hay reservas en la tabla
bool perteneceTTablaReserva(TTablaReserva tabla, int ciSocio, int isbnLibro);

//  Función para obtener toda la cola de reservas del libro asociado
//  al isbn dado.
//  PRE: perteneceTTablaReserva(tabla, isbn)
//  La función es O(1) promedio.
TColaDePrioridadReservas obtenerReservaTTablaReserva(TTablaReserva tabla, int isbn);

// Funcion que devuelve la primer reserva de la cola de reservas del libro con isbn dado.
// Pre: perteneceTTablaReserva(tabla, isbn)
// La función es O(1) promedio.
TReserva obtenerSigReservaTTablaReserva(TTablaReserva tabla, int isbn);

//  Función para liberar la memoria asignada a una TTablaReserva.
//  La función es O(n + max) peor caso, donde n es la cantidad actual de reservas en la tabla
//  y max la cantidad esperada de reservas en la tabla.
void liberarTTablaReserva(TTablaReserva &tabla);

// IMPORTANTE: Los requisitos de tiempo de ejecución y de memoria específicos para
// la implementación solicitada se encuentran en tablaFichaVacunacion.cpp

#endif  // TABLA_TABLA_RESERVA_H
