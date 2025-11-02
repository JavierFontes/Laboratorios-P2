/*
Módulo de definición de 'TColaDePrioridadReservas'.

Los elementos de tipo 'TColaDePrioridadReservas' son colas de prioridad cuyos
elementos son de tipo 'Treserva' y cuya prioridad se define por nivel de rango del socio que compone la reserva.

El criterio para establecer la prioridad entre reservas es, de manera
predeterminada, que un socio tiene prioridad ante otro si su rango es menor que el del otro socio.
Este criterio se puede modificar, haciendo que la reserva prioritaria sea la correspondiente al socio de mayor rango.

Si la 'TColaDePrioridadReservas' no es vacía hay una reserva considerada la
prioritaria, según el criterio de prioridad. Si hay más de una reserva con el
mismo rango, cualquiera de ellas es la prioritaria.


Laboratorio de Programación 2.
InCo-FIng-UDELAR
*/

#ifndef _CP_H
#define _CP_H

#include "utils.h"
#include "reserva.h"
#include "socio.h"

//   Representación de 'TColaDePrioridadReservas'
//   Se debe definir en colaDePrioridadReservas.cpp
//   struct _rep_colaDePrioridadReservas;
//   Declaración del tipo 'TColaDePrioridadReservas'
typedef struct rep_colaDePrioridadReservas *TColaDePrioridadReservas;

//   Devuelve una 'TColaDePrioridadReservas' vacía (sin elementos) que puede
//   contener hasta N reservas.
//   La prioridad entre dos reservas se define por el que tenga menor rango
//   El tiempo de ejecución en el peor caso es O(N).
TColaDePrioridadReservas crearTColaDePrioridadReservas(nat N);

//   Modifica el criterio de prioridad: si el prioritario era el socio de menor rango,
//   entonces pasa a ser el de mayor prioridad, y viceversa.
//   Debe modificar la cola de forma de que se respete el nuevo criterio de prioridad.
//   Se pide que el tiempo de ejecución en el peor caso sea O(n*log n), siendo 'n' la cantidad de
//   elementos de 'cp'. Sin embargo, existe una solución que lo hace en O(n).
void invertirPrioridadTColaDePrioridadReservas(TColaDePrioridadReservas &cp);

//   Libera la memoria asignada a 'cp' y a cada uno de sus elementos.
//   Es decir, libera la memoria asociada a todas las reservas que estén en la cola.
//   El tiempo de ejecución en el peor caso es O(N), siendo 'N' el parámetro
//   pasado en crearCP.
void liberarTColaDePrioridadReservas(TColaDePrioridadReservas &cp);

//   Inserta 'reserva' en 'cp'.
//   El tiempo de ejecución en el peor caso es O(log N) siendo 'N' el parámetro pasado en crearCP.
//   PRE: 'reserva' no pertenece a 'cp'
//   PRE: 1 <= rango <= N, siendo 'N' el parámetro pasado en crearTColaDePrioridadReservas.
void insertarTColaDePrioridadReservas(TColaDePrioridadReservas &cp, TReserva reserva);

//   Devuelve 'true' si y solo si en 'cp' no hay elementos.
//   El tiempo de ejecución en el peor caso es O(1).
bool estaVaciaTColaDePrioridadReservas(TColaDePrioridadReservas cp);

//   Devuelve la reserva prioritario de 'cp'.
//   El tiempo de ejecución en el peor caso es O(1).
//   PRE: !estaVaciaTColaDePrioridadReservas(cp).
TReserva prioritarioTColaDePrioridadReservas(TColaDePrioridadReservas cp);

//   Elimina de 'cp' la reserva prioritario y libera la memoria asociada.
//   Si estaVaciaTColaDePrioridadReservas(cp) la operación no tiene efecto.
//   El tiempo de ejecución en el peor caso es O(log N), siendo 'N' el parámetro
//   pasado en crearCP.
void eliminarPrioritarioTColaDePrioridadReservas(TColaDePrioridadReservas &cp);

//   Devuelve 'true' si y solo si la reserva es un elemento de 'cp'.
//   El tiempo de ejecución en el peor caso es O(n).
bool estaTColaDePrioridadReservas(TColaDePrioridadReservas cp, int ciSocio, int isbnLibro);

//   Devuelve el valor de prioridad (el rango) asociado a la reserva con el socio 's'
//   Precondición: existe el socio 's' en alguna reserva de 'cp'
//   El tiempo de ejecución en el peor caso es O(n).
nat prioridadTColaDePrioridadReservas(TColaDePrioridadReservas cp, int ciSocio, int isbnLibro);

//   Hace una copia profunda de la cola de prioridad cp
//   El tiempo de ejecucion en el peor caso es O(n)
TColaDePrioridadReservas copiarTColaDePrioridadReservas(TColaDePrioridadReservas cp);

//   Imprime cada reserva almacenada en la cola de prioridad, segun el orden establecido por la prioridad
void imprimirTColaDePrioridad(TColaDePrioridadReservas cp);

#endif
