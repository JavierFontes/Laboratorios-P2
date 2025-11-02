/*
  Módulo de definición de 'TFecha'.

  Los elementos de tipo TFecha son elementos que almacenan una fecha.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef _FECHA_H_
#define _FECHA_H_

#include "utils.h"

// Definición de tipo TFecha como puntero a una estructura rep_fecha
typedef struct rep_fecha *TFecha;

// Crea y retorna un nuevo elemento de tipo TFecha con dia 'd', mes 'm' y año 'a'. 
TFecha crearTFecha(nat d, nat m, nat a);

// Libera la memoria asociada a la fecha 'f'
void liberarTFecha(TFecha &f);

// Imprime la fecha 'f' en el formato "dd/mm/aaaa", con un salto de línea al final. 
void imprimirTFecha(TFecha f);

// Retorna una copia de la fecha 'f' que no comparte memoria con el parámetro. 
TFecha copiarTFecha(TFecha f); 

// Aumenta la fecha 'f' en una cantidad 'd' de días
// Pre: d >= 0
void aumentarTFecha(TFecha &f, nat d);

// Compara dos fechas representadas por elementos de tipo TFecha
// Si 'f1' es mayor que 'f2' (más reciente) retorna 1, si es menor (más antigua) retorna -1,
// En caso de ser iguales retorna 0. 
int compararTFechas(TFecha f1, TFecha f2);


#endif  // _FECHA_H_