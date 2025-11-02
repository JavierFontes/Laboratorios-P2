/*
  Módulo de definición de 'TABBLibros'.

  Un elemento de tipo TABBLibros es un árbol binario de búsqueda que almacena una coleccion de elementos 
  de tipo TLibro ordenado por ISBN. 

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef ABBLIBROS_H
#define ABBLIBROS_H

#include "libro.h"

// Define el tipo TABBLibros como un puntero a rep_abbrep_abbLibros.
typedef struct rep_abbLibros *TABBLibros;

// Función para crear un nuevo abb de libros vacío.
// Devuelve un nuevo árbol binario de búsqueda vacío.
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(1) peor caso.
TABBLibros crearTABBLibrosVacio();

// Función para insertar un libro en el árbol, ordenado por ISBN.
// PRE: El libro con ese isbn no está en el árbol.
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(n) peor caso, siendo n la cantidad de libros en el árbol.
void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro);

// Función para imprimir los libros del árbol en orden, según su ISBN. La impresión
// de los libros se realiza con la función 'imprimirTLibro'.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, donde n es la cantidad de libros en el árbol.
void imprimirTABBLibros(TABBLibros abbLibros);

// Función para liberar la memoria asignada a un árbol de libros.
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, donde n es la cantidad de libros en el árbol.
void liberarTABBLibros(TABBLibros &abbLibros);

// Función que determina si un libro está en el árbol.
// Devuelve true si el libro está en el árbol, false en caso contrario.
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(log(n)) caso promedio, siendo n la cantidad de libros en el árbol.
bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn);

// Función para obtener una libro del árbol.
// PRE: el libro está en el árbol
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(log(n)) caso promedio, siendo n la cantidad de libros en el árbol.
TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn);

// Funcion para obtener la altura del árbol.
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(n) peor caso, siendo n la cantidad de libros en el árbol.
nat alturaTABBLibros(TABBLibros abbLibros);

// Función para obtener el libro con el ISBN más grande del árbol.
// PRE: el árbol no es vacío
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(n) peor caso, siendo n la cantidad de libros en el árbol.
TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros);

// Función para eliminar un libro del árbol.
// En caso de que el nodo a remover tenga ambos subárboles no vacíos, se
// reemplaza por el libro con el ISBN más grande del subárbol izquierdo. 
// PRE: El árbol está en el árbol
/* Requisitos específicos de la implementación solicitada: */
// La función es O(n) peor caso, donde n es la cantidad de libros en el árbol.
void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn);

// Función para obtener la cantidad de libros en el árbol.
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(n) peor caso, siendo n la cantidad de libros en el árbol.
int cantidadTABBLibros(TABBLibros abbLibros);

// Función para obtener el libro Nésimo del árbol. 
// La numeración de los libros se considera por orden de 'ISBN', iniciando en 1.
// Ejemplos:  
//  obtenerNesimoLibroTABBLibros(abbLibros, 1) devuelve el libro con menor ISBN
//  obtenerNesimoLibroTABBLibros(abbLibros, 2) devuelve el segundo libro con menor ISBN
//  obtenerNesimoLibroTABBLibros(abbLibros, cantidadTABBLibros(abbLibros)) devuelve el 
//  libro con mayor ISBN.
// PRE: cantidadTABBLibros(abbLibros) >= n
// PRE: n > 0 
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(m) peor caso, siendo m la cantidad de libros en el árbol.
TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n);

// Función que retorna un nuevo árbol únicamente con los libros sobre el género pasado
// por parámetro.
// El árbol filtrado no comparte memoria con el árbol original.
// Los libros retornados en el nuevo árbol son copias limpias de los que pertenecen al árbol parámetro.
// 
/* Requisitos específicos de la implementación solicitada: */
// La funcion es O(n) peor caso, siendo n la cantidad de libros en el árbol.
TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero);

#endif // ABBLIBROS_H  

