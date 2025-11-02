/*
  Módulo de definición de 'TBiblioteca'.

  Los elementos de tipo TBiblioteca almacenan la información necesaria para gestionar la Bibiloteca.

  Un elemento de tipo TBiblioteca debe mantener:

    - Un elemento de tipo ABBLibros para registrar todos los libros de la biblioteca.
    - Un elemento de tipo lseSocios para mantener los socios de la biblioteca.
    - Un elemento de tipo ldePrestamos para llevar constancia de los préstamos.
    - Un elemento de tipo agGeneros para indicar las relaciones entre géneros y subgéneros, así como
    para almacenar los nombres de los géneros.
    - Un elemento de tipo colaReservas, para guardar las reservas realizadas.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef TBIBLIOTECA_H
#define TBIBLIOTECA_H

#include <string.h>

#include "colaReservas.h"
#include "ldePrestamos.h"
#include "abbLibros.h"
#include "lseSocios.h"
#include "agGeneros.h"
#include "conjuntoGeneros.h"

// Define el tipo TBiblioteca como un puntero a rep_biblioteca
typedef struct rep_biblioteca *TBiblioteca;

// Función que crea un elemento de tipo TBiblioteca.
TBiblioteca crearTBiblioteca();

// Función que agrega un género a una biblioteca
// Pre: no existe en la biblioteca otro género con el mismo id
// Debe ejecutar en O(g) peor caso, siendo g la cantidad de géneros en la biblioteca
void agregarGeneroABiblioteca(TBiblioteca biblioteca, int idGeneroPadre, int idGenero, const char nombreGenero[MAX_NOMBRE]);

// Función que agrega un libro a la biblioteca
//  - Agrega al libro al árbol de libros de la biblioteca.
// PRE: no existe un libro en la biblioteca con el mismo ISBN que el libro parámetro.
// Debe ejecutar en O(l) peor caso, siendo l la cantidad de libros en la biblioteca.
void agregarLibroTBiblioteca(TBiblioteca biblioteca, TLibro libro);

// Registra un socio en la biblioteca.
//  - Agrega al socio a la lista de socios de la biblioteca.
// PRE: no existe un socio de la biblioteca con el mismo ID que el socio parámetro.
// Debe ejecutar en O(s) peor caso, siendo s la cantidad de socios en la biblioteca.
void agregarSocioTBiblioteca(TBiblioteca biblioteca, TSocio socio);

// Función para prestar un libro en la biblioteca. Realiza las acciones necesarias para gestionar un
// préstamo:
//   - Crea una préstamo para el socio 'socio' y el libro 'isbnLibro' y la inserta en la lista de préstamos.
// PRE: existe un socio de id 'ciSocio' registrado en la biblioteca.
// PRE: existe un libro de isbn 'isbnLibro' en el árbol de libros de la biblioteca.
// Debe ejecutar en O(max(s, l, p)), siendo:
//   - s la cantidad de socios en la biblioteca.
//   - l la cantidad de libros en la biblioteca.
//   - p la cantidad de prestamos en la biblioteca.
void prestarLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro, TFecha fechaPrestamo);

// Indica si un libro está disponible para ser prestado. Un libro se considera disponible
// si lo tiene la biblioteca y no se encuentra prestado.
// Debe ejecutar en O(l + p^2)), siendo:
//  - l la cantidad de libros en la biblioteca.
//  - p la cantidad de prestamos en la biblioteca.
bool disponibleLibroTBiblioteca(TBiblioteca biblioteca, int isbnLibro);

// Función para reservar un libro en la biblioteca. Realiza las acciones necesarias para gestionar una
// reserva:
//    - Crea una reserva para el socio 'socio' y el libro 'isbnLibro' y la inserta en al cola de reservas.
// PRE: el libro de isbn 'isbnLibro' se encuentra prestado.
// Debe ejecutar en O(max(s, l)), siendo:
//  - s la cantidad de socios en la biblioteca.
//  - l la cantidad de libros en la biblioteca.
void reservarLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro);

// Realiza las acciones necesarias para devolver un libro:
//  - Marca el préstamo como retornado, actualizando la fecha de devolución. El préstamo
//    se identifica por socio, libro y fecha de préstamo. Se asume que no puede existir un préstamo del mismo libro
//    para la misma persona en la misma fecha.
// PRE: existe un socio de id 'ciSocio' registrado en la biblioteca.
// PRE: existe un libro de isbn 'isbnLibro' en el árbol de libros de la biblioteca.
// PRE: el libro de isbn 'isbnLibro' se encuentra actualmente prestado al socio de id 'ciSocio'
// Debe ejecutar en O(p), siendo p la cantidad de prestamos en la biblioteca.
void devolverLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro, TFecha fechaPrestamo, TFecha fechaDevolucion);

// Función que obtiene todos los libros de la biblioteca que pertenecen a un género y
// a sus respectivos sub-géneros.
// Debe ejecutar en O(g*l*l) siendo:
//  - g la cantidad de géneros en la biblioteca.
//  - l la cantidad de libros en la biblioteca.
TABBLibros obtenerLibrosDeGenero(TBiblioteca biblioteca, int idGenero);

// Imprime los socios de la biblioteca según el formato de la función 'imprimirTLSESocios'
// Debe ejecutar en O(s), siendo s la cantidad de socios de la biblioteca.
void imprimirSociosTBiblioteca(TBiblioteca biblioteca);

// Imprime los libros de la biblioteca según el formato de la función 'imprimprimirTABBLibrosimr'
// Debe ejecutar en O(l), siendo l la cantidad de socios de la biblioteca.
void imprimirLibrosTBiblioteca(TBiblioteca biblioteca);

// Imprime los libros de la biblioteca según el formato de la función 'imprimirTColaReservas'
// Debe ejecutar en O(r), siendo r la cantidad de reservas de la biblioteca.
void imprimirReservasTBiblioteca(TBiblioteca biblioteca);

// Imprime los libros de la biblioteca según el formato de la función 'imprimirTLDEPrestamos'
// Debe ejecutar en O(p), siendo p la cantidad de reservas de la biblioteca.
void imprimirPrestamosTBiblioteca(TBiblioteca biblioteca);

// Función que libera la memoria asignada para la biblioteca.
// POST: el puntero biblioteca apunta a NULL.
// Debe ejecutar en O(max(s, l, p, g, r)), siendo:
//   - s la cantidad de socios en la biblioteca.
//   - l la cantidad de libros en la biblioteca.
//   - p la cantidad de prestamos en la biblioteca.
//   - g la cantidad de géneros en la biblioteca.
//   - r la cantidad de reservas en la biblioteca.
void liberarTBiblioteca(TBiblioteca &biblioteca);


#endif  // TBIBLIOTECA_H
