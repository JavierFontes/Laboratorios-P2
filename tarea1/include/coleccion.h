/*
  Módulo de definición de 'TColeccion'.

  Los elementos de tipo TColeccion almacenan una colección de elementos de tipo TLibro.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef COLECCION_H
#define COLECCION_H

#include "libro.h"

// Constante para definir el número máximo de libros que mantiene la colección
const int MAX_LIBROS = 20;

// Definición de tipo TColeccion como un puntero a rep_coleccion
typedef struct rep_coleccion* TColeccion;

// Función para crear una TColeccion vacía que puede almacenar hasta MAX_LIBROS libros. 
TColeccion crearTColeccion();

// Función para liberar la memoria asociada a una colección de libros. 
// Recibe una referencia a un elemento de tipo TColeccion y libera su memoria
// Debe liberar además la memoria de cada uno de los libros de la colección. 
void liberarTColeccion(TColeccion& c);

// Función para agregar un nuevo libro 'l' a la colección 'c'
// Recibe un elemento de tipo TColeccion y un elemento de tipo TLibro y lo agrega a la colección en orden por fecha de edición (de menor a mayor)
// Si dos libros tienen la misma fecha de edición, deben ordenarse por orden de ingreso a la colección, 
// quedando antes el último de ellos en ser ingresado (de más reciente a más antiguo). 
// Si la cantidad de libros en la colección es igual a MAX_LIBROS, la función no tiene efecto
void agregarEnTColeccion(TColeccion& c, TLibro l);

// Función para imprimir la información de todos los libros en la colección
// Recibe un elemento de tipo TColeccion e imprime la información de sus libros
// en orden cronológico por fecha de edición (el orden en el que aparecen en la colección). 
// El formato en el que se debe imprimir la información de la colección es utilizando de 
// forma secuencial la función imprimirTLibro
// 
// Libro <isbn 1> 
// Título: <título 1>
// Autor: <nombre autor 1> <apellido autor 1>
// Descripción: <descripcion 1>
// Género: <id género 1>
// Fecha de edición: <fecha de edición 1>
// Libro <isbn 2> 
// Título: <título 2>
// Autor: <nombre autor 2> <apellido autor 2>
// Descripción: <descripcion 2>
// Género: <id género 2>
// Fecha de edición: <fecha de edición 2>
// .... 
// Si la colección está vacía no se imprime nada.
void imprimirTColeccion(TColeccion c);

// Función para verificar si un libro con isbn 'isbn' existe en la colección 'c' 
// Recibe una colección c y un isbn y retorna true si y solo si la colección c contiene
// un libro con isbn 'isbn'
bool estaEnTColeccion(TColeccion c, int isbn);

// Función para obtener un libro de una colección
// Recibe una colección y un isbn y regresa el libro con ese isbn
// El libro retornado comparte memoria con el parámetro. 
// PRE: El libro debe estar en la colección
TLibro obtenerDeTColeccion(TColeccion c, int isbn);

// Función que retorna true si y solo si existe algún libro en la colección editado 
// el día de la fecha pasada por parámetro.
// La función debe ejecutar un algoritmo de búsqueda binaria.
bool existenLibrosFechaTColeccion(TColeccion c, TFecha f);

// Función para imprimir todos los libros de una colección con el género pasado por parámetro.
// Recibe una colección y un género e imprime la información de los libros con dicho género,
// ordenados por orden de inserción en la colección (en el orden en que aparecen en la colección)
// Si no hay libros con dicho género, no imprime nada.
void imprimirLibrosGeneroTColeccion(TColeccion c, int idGenero);

// Función para remover un libro de una colección
// Recibe una coleccón y el isbn del libro y remueve el libro con ese isbn de la colección.
// PRE: El libro debe pertenecer a la colección
void removerDeTColeccion(TColeccion& c, int isbn);

#endif  // COLECCION_H