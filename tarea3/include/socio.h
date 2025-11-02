/*
  Módulo de definición de 'TSocio'.

  Los elementos de tipo TSocio son elementos que almacenan una CI, un nombre, un apellido, 
  una fecha de alta como socios en la biblioteca, y una colección de elementos de tipo int, 
  que representan los ids de los géenros favoritos del socio. 

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef TSOCIO_H
#define TSOCIO_H

#include <string.h>

#include "fecha.h"

// Constante para definir el largo máximo del nombre y apellido de un socio
const int MAX_NOMBRE_SOCIO = 20;
const int MAX_APELLIDO_SOCIO = 20;

// Constante para definir la cantidad máxima de géneros favoritos de un socio
const int MAX_GENEROS_FAVORITOS = 20;

// Define el tipo TSocio como un puntero a rep_socio
typedef struct rep_socio *TSocio;

// Función que crea un elemento de tipo TSocio con los valores pasados por parámetro.
// La fecha de alta se pasa como día, mes y anio.
// Se incializa la colección de géneros favoritos vacía.
/* Requisitos específicos de la implementación solicitada: */
// Se recomienda implementar la colección de géneros favoritos como un arreglo con tope de 
// elementos de tipo int.
// Debe ejecutar en O(1) peor caso 
TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta);

// Función que imprime la información del socio en el siguiente formato (donde los géneros favoritos
// se imprimen en el orden en el que fueron agregados):
//
// Socio <CI>: <nombre> <apellido>
// Fecha de alta: <Fecha de Alta>
// Géneros favoritos: <id genero favorito 1> <id genero favorito 2> ... <id genero favorito n> 
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso 
void imprimirTSocio(TSocio socio);

// Función que libera la memoria asignada para un socio, incluída su fecha de alta.
// POST: el puntero socio apunta a NULL
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso 
void liberarTSocio(TSocio &socio);

// Función que retorna la ci del socio.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso 
int ciTSocio(TSocio socio);

// Función que retorna el nombre del socio.
/* Requisitos específicos de la implementación solicitada: */
// El nombre retornado comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso 
char* nombreTSocio(TSocio socio);

// Función que retorna el apellido del socio.
/* Requisitos específicos de la implementación solicitada: */
// El apellido retornado comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso 
char* apellidoTSocio(TSocio socio);

// Función que devuelve la fecha de alta del socio.
/* Requisitos específicos de la implementación solicitada: */
// La fecha retornada comparte memoria con el parámetro.
// Debe ejecutar en O(1) peor caso 
TFecha fechaAltaTSocio(TSocio socio);

// Función que agrega el género 'idGenero' en la colección de géneros favoritos
// del socio.
// En caso de que ya existan MAX_GENEROS_FAVORITOS en la colección, la funcion no tiene efecto.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero);

// Función que indica si el género 'idGenero' es uno de los 
// géneros favoritos del socio
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero);

// Función que devuelve la cantidad de géneros favoritos en la colección
// de géneros del socio.
/* Requisitos específicos de la implementación solicitada: */
// Debe ejecutar en O(1) peor caso
int cantidadGenerosFavoritosTSocio(TSocio socio);

// Función que copia un socio.
/* Requisitos específicos de la implementación solicitada: */
// La copia *no* comparte memoria con el socio pasado por parámetro.
// Debe ejecutar en O(1) peor caso
TSocio copiarTSocio(TSocio socio);

#endif  // TSOCIO_H