/*
  Módulo de definición de 'TGenero'.

  Los elementos de tipo TGenero son elementos que almacenan un id de género y un nombre.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef GENERO_H
#define GENERO_HS

#include <string.h>

#include "fecha.h"

// Constante para definir el largo máximo del nombre del género
const int MAX_NOMBRE_GENERO = 50;

// Define el tipo TGenero como un puntero a rep_genero
typedef struct rep_genero *TGenero;

// Crea y retorna un elemento de tipo TGenero con los valores dados
TGenero crearTGenero(int id, const char nombre[MAX_NOMBRE_GENERO]);

// Libera la memoria asignada para el género 'gen'
void liberarTGenero(TGenero &gen);

// Retorna el id del género 'gen'
int idTGenero(TGenero gen);

// Retorna el nombre del género 'gen'
// El nombre retornado comparte memoria con el parámetro. 
char* nombreTGenero(TGenero gen); 

// Imprime la información del género 'gen' en el siguiente formato:
// Género <id> - <nombre>
void imprimirTGenero(TGenero gen);

// Retorna una copia del género 'gen' que no comparte memoria con el parámetro.
TGenero copiarTGenero(TGenero gen);

#endif  // GENERO_H