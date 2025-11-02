/*
  Módulo de definición de 'TLibro'.

  Los elementos de tipo TLibro son elementos que almacenan un ISBN, un título, un género, una descripción, el nombre y apellido del autor y la fecha de edición.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef LIBRO_H
#define LIBRO_H

#include <string.h>

#include "fecha.h"

// Constantes para definir el largo máximo del título, nombre y apellido del autor y la descripción de un libro
const int MAX_TITULO = 50;
const int MAX_NOMBRE_AUTOR = 20;
const int MAX_APELLIDO_AUTOR = 20;
const int MAX_DESCRIPCION = 200;

// Define el tipo TLibro como un puntero a rep_libro
typedef struct rep_libro *TLibro;

// Crea y retorna un elemento de tipo TLibro con los valores dados
TLibro crearTLibro(int isbn, const char titulo[MAX_TITULO], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], const char descripcion[MAX_DESCRIPCION], int idGeneroLibro, TFecha fechaEdicion);

// Libera la memoria asignada para el libro 'l'
// Debe liberar también la memoria de la fecha asociada
void liberarTLibro(TLibro &l);

// Retorna el isbn del libro 'l'
int isbnTLibro(TLibro l);

// Retorna el titulo del libro 'l'
// El titulo retornado comparte memoria con el parámetro. 
char* tituloTLibro(TLibro l); 

// Retorna la descripción del libro 'l'
// La descripción retornada comparte memoria con el parámetro. 
char* descripcionTLibro(TLibro l); 

// Retorna el nombre del autor del libro 'l'
// El nombre retornado comparte memoria con el parámetro. 
char* nombreAutorTLibro(TLibro l); 

// Retorna el apellido del autor del libro 'l'
// El apellido retornado comparte memoria con el parámetro. 
char* apellidoAutorTLibro(TLibro l); 

// Retorna el id del género del libro 'l'
int idGeneroTLibro(TLibro l); 

// Retorna la fecha de edición del libro 'l'.
// La fecha retornada comparte memoria con el parámetro. 
TFecha fechaEdicionTLibro(TLibro l);

// Imprime la información del libro 'l' en el siguiente formato:
// Libro <isbn> 
// Título: <título>
// Autor: <nombre autor> <apellido autor>
// Descripción: <descripcion>
// Género: <id género>
// Fecha de edición: <fecha de edición>
void imprimirTLibro(TLibro l);

// Retorna una copia del libro 'l' que no comparte memoria con el parámetro.
TLibro copiarTLibro(TLibro l);

#endif  // LIBRO_H