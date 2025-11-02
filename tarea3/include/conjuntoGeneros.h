/*
  Módulo de definición de 'TConjuntoGeneros'.

  Un elemento de tipo TConjuntoGeneros es un conjunto acotado que almacena ids de géneros.

  El conjunto es acotado, y además, la cantidad máxima de elementos define el rango de 
  identificadores que almacena.
  Es decir, los identificadores almacenados por el conjunto cumplen 0 <= id < cantMax
  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef CONJUNTOGENEROS_H
#define CONJUNTOGENEROS_H

#include "utils.h"

// Definición de tipo TConjuntoGeneros como un puntero a rep_conjuntogeneros
typedef struct rep_conjuntogeneros* TConjuntoGeneros;

// Función para crear un nuevo conjunto de géneros.
// Devuelve un conjunto vacío.
/* Debe ejectuar en O(n) peor caso, siendo n la cantidad máxima de elementos del conjunto. */
TConjuntoGeneros crearTConjuntoGeneros(int cantMax);

// Procedimiento para insertar el identificador "id" en el conjunto de géneros "c".
// Si "id" no pertenece al rango válido de ids del conjunto "c" la función no hace nada.
// Si "id" ya pertenece al conjunto, la función no hace nada.
/* Debe ejecutar en O(1) peor caso. */
void insertarTConjuntoGeneros(TConjuntoGeneros &c, int id);

// Procedimiento para imprimir el conjunto de géneros.
// Imprime los ids de los géneros del conjunto ordenado de menor a mayor.
// Deben imprimirse solamente los elementos, separados por un espacio
// (sin espacio después del último), con un salto de línea al final.
// Ejemplo: si el conjunto "c" tiene los elementos 7, 42, 29 y 75 la impresión debe ser "7 29 42 75" 
// y finalmente un salto de línea.
/* Debe ejecutar en O(n) peor caso, siendo "n" la cantidad máxima de elementos de "c". */
void imprimirTConjuntoGeneros(TConjuntoGeneros c);

// Procedimiento para liberar la memoria asignada a un conjunto de géneros.
// Luego de la ejecución deja 'c' apuntando a NULL;
/* Debe ejecutar en O(1) peor caso. */
void liberarTConjuntoGeneros(TConjuntoGeneros &c);

// Función para determinar si un conjunto de géneros es vacío
// Devuelve true si el conjunto es vacío, false en otro caso
/* Debe ejecutar en O(1) peor caso. */
bool esVacioTConjuntoGeneros(TConjuntoGeneros c);

// Función que retorna la cantidad de elementos del conjunto de géneros "c".
/* Debe ejecutar en O(1) peor caso. */
int cardinalTConjuntoGeneros(TConjuntoGeneros c);

// Función que retorna la cantidad máxima de elementos del conjunto de géneros "c".
/* Debe ejecutar en O(1) peor caso. */
int cantMaxTConjuntoGeneros(TConjuntoGeneros c);

// Función para determinar si el identificador "id" pertenece al conjunto "c"
// Devuelve true si pertenece, false en otro caso
/* Debe ejecutar en O(1) peor caso. */
bool perteneceTConjuntoGeneros(TConjuntoGeneros c, int id);

// Procedimiento para borrar al "id" del conjunto de géneros "c"
// Si "id" no pertenece al conjunto "c" o al rango válido, la función no hace nada
/* Debe ejecutar en O(1) peor caso. */
void borrarDeTConjuntoGeneros(TConjuntoGeneros &c, int id);

// Función que retorna la unión entre los conjuntos de géneros "c1" y "c2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// El conjunto resultado debe poder almacenar la misma cantidad máxima de elementos.
/* Debe ejecutar en O(n) peor caso, siendo n la cantidad máxima de elementos permitidos en el conjunto */
TConjuntoGeneros unionTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2);

// Función que retorna la intersección entre los conjuntos de géneros "c1" y "c2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// El conjunto resultado debe poder almacenar la misma cantidad máxima de elementos.
/* Debe ejecutar en O(n) peor caso, siendo n la cantidad máxima de elementos permitidos en el conjunto */
TConjuntoGeneros interseccionTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2);

// Función que retorna la diferencia entre los conjuntos de géneros "c1" y "c2". (c1 - c2)
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// El conjunto resultado debe poder almacenar la misma cantidad máxima de elementos.
/* Debe ejecutar en O(n) peor caso, siendo n la cantidad máxima de elementos permitidos en el conjunto */
TConjuntoGeneros diferenciaTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2);

#endif  // CONJUNTOGENEROS_H
