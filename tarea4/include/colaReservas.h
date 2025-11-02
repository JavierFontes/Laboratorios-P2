/*
  Módulo de definición de 'TColaReservas'.

  Un elemento de tipo TColaReservas almacena una colección de
  elementos de tipo TReserva y ofrece operaciones del TAD Cola.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/
#ifndef COLARESERVAS_H
#define COLARESERVAS_H

#include "reserva.h"

// Define el tipo TColaReservas como un puntero a rep_colaReservas
typedef struct rep_colaReservas *TColaReservas;

// Función para crear un elemento de tipo TColaReservas vacío.
// Debe ejecutar en O(1) peor caso.
TColaReservas crearTColaReservas();

// Función que libera la memoria asignada para la cola de reservas.
// Debe ejecutar en O(n) peor caso, donde n es la cantidad de reservas en la cola.
void liberarTColaReservas(TColaReservas &colaReservas);

// Función que elimina la colaReservas de forma segura.
// Libera la memoria asociada a todos los nodos y a las reservas que contienen,
// llamando a una función de liberación para cada reserva que NO libera
// los socios ni los libros asociados a la reserva.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) en el peor caso, donde n es la cantidad de reservas en la cola.
void liberarTColaReservasSoloEstructura(TColaReservas &colaReservas);

// Agrega una reserva a la cola de reservas.
// Debe ejecutar en 0(1) peor caso
void encolarTColaReservas(TColaReservas &colaReservas, TReserva reserva);

// Imprime la cola de reservas con el siguiente formato:
//   Cola de Reservas:
//   <imprimir imprimirTReserva en cada reserva>
// El orden de impresión es el que resultaría de desencolar
// sucesivamente las reservas e imprimirlos (orden de llegada).
// Debe ejecutar en O(n) peor caso, donde n es el numero de reservas en la cola
void imprimirTColaReservas(TColaReservas colaReservas);

// Devuelve la cantidad de reservas en la cola de reservas.
// Debe ejecutar en O(1) peor caso.
nat cantidadTColaReservas(TColaReservas colaReservas);

// Retorna la reserva más antigua de la cola.
// PRE: cantidadTColaReservas(colaReservas) > 0
// Debe ejecutar en O(1) peor caso.
TReserva frenteTColaReservas(TColaReservas colaReservas);

// Remueve la reserva más antiguo de la cola.
// Libera la memoria asignada a la reserva.
// PRE: cantidadTColaReservas(colaReservas) > 0
// Debe ejecutar en O(1) peor caso.
void desencolarTColaReservas(TColaReservas &colaReservas);


// Función que quita el nodo del frente de la cola (el último) y devuelve el TReserva que contenía,
// liberando únicamente la memoria del nodo. A diferencia de 'desencolarTColaReservas', esta función
// no libera la reserva.
// Debe ejecutar en O(1) peor caso.
TReserva extraerFrenteTColaReservas(TColaReservas &colaReservas);

#endif // COLARESERVAS_H
