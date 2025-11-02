#include "../include/biblioteca.h"
#include "../include/abbLibros.h"
#include "../include/lseSocios.h"
#include "../include/ldePrestamos.h"
#include "../include/agGeneros.h"
#include "../include/colaReservas.h"
#include <assert.h>

struct rep_biblioteca {
  TABBLibros Libros;
  TLSESocios Socios;
  TLDEPrestamos Prestamos;
  TAGGeneros ArbolGeneros;
  TColaReservas Reservas;

};

TBiblioteca crearTBiblioteca(){
  TBiblioteca biblioteca = new rep_biblioteca;
  biblioteca->Libros = crearTABBLibrosVacio();
  biblioteca->Socios = crearTLSESociosVacia();
  biblioteca->Prestamos = crearTLDEPrestamosVacia();
  biblioteca->ArbolGeneros = NULL;
  biblioteca->Reservas = crearTColaReservas();
  return biblioteca;
}

void agregarGeneroABiblioteca(TBiblioteca biblioteca, int idGeneroPadre, int idGenero, const char nombreGenero[MAX_NOMBRE]) {
  if (biblioteca != NULL){
      insertarGeneroTAGGeneros(biblioteca->ArbolGeneros, idGeneroPadre, idGenero, nombreGenero);
  }
}

void agregarLibroTBiblioteca(TBiblioteca biblioteca, TLibro libro) {
    if (biblioteca != NULL){
    insertarLibroTABBLibros(biblioteca->Libros, libro);
    }
}


void agregarSocioTBiblioteca(TBiblioteca biblioteca, TSocio socio){
  if (biblioteca != NULL){
    insertarTLSESocios(biblioteca->Socios, socio);
  }
}

void prestarLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro, TFecha fechaPrestamo) {
  if (biblioteca != NULL) {

    TSocio socio = obtenerSocioTLSESocios(biblioteca->Socios, ciSocio);
    TLibro libro = obtenerLibroTABBLibros(biblioteca->Libros, isbnLibro);

    if (socio != NULL && libro != NULL) {
        TPrestamo prestamo = crearTPrestamo(socio, libro, fechaPrestamo);

        if (biblioteca->Prestamos == NULL){
          biblioteca->Prestamos = crearTLDEPrestamosVacia();
        }

        insertarTLDEPrestamos(biblioteca->Prestamos, prestamo);
    }
  }
}

bool disponibleLibroTBiblioteca(TBiblioteca biblioteca, int isbnLibro) {
  if (biblioteca == NULL)
    return false;

  if (obtenerLibroTABBLibros(biblioteca->Libros, isbnLibro) == NULL)
    return false;

  if (biblioteca->Prestamos == NULL)
    return false;

  nat cant = cantidadTLDEPrestamos(biblioteca->Prestamos); 
  TLDEPrestamos prestamos = biblioteca->Prestamos;

  for (nat i = 1; i <= cant; i++){
    TPrestamo p = obtenerNesimoTLDEPrestamos(prestamos, i);

    if (p != NULL){
      TLibro libroPrestado = libroTPrestamo(p);
      if (isbnTLibro(libroPrestado) == isbnLibro && !fueRetornadoTPrestamo(p)) {
        return false;
      }
    }
  }

  return true;
}

void reservarLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro){
  TSocio socio = obtenerSocioTLSESocios(biblioteca->Socios, ciSocio);
  TLibro libro = obtenerLibroTABBLibros(biblioteca->Libros, isbnLibro);
      
  TReserva nuevaReserva = crearTReserva(socio, libro);
  encolarTColaReservas(biblioteca->Reservas, nuevaReserva);
}


void devolverLibroTBiblioteca(TBiblioteca biblioteca, int ciSocio, int isbnLibro, TFecha fechaPrestamo, TFecha fechaDevolucion){
  if (biblioteca != NULL && biblioteca->Prestamos != NULL){
    nat cant = cantidadTLDEPrestamos(biblioteca->Prestamos);
    TLDEPrestamos prestamos = biblioteca->Prestamos;

    for (nat i = 1; i <= cant; i++){
      TPrestamo p = obtenerNesimoTLDEPrestamos(prestamos, i);

      if (p != NULL){
        if ((isbnTLibro(libroTPrestamo(p)) == isbnLibro) && 
            (ciTSocio(socioTPrestamo(p)) == ciSocio) &&
            (compararTFechas(fechaRetiroTPrestamo(p), fechaPrestamo) == 0)) {
          
          actualizarFechaDevolucionTPrestamo(p, fechaDevolucion);
          break;
        }
      }
    }
  }
}

void imprimirSociosTBiblioteca(TBiblioteca biblioteca){
  if (biblioteca != NULL){
    imprimirTLSESocios(biblioteca->Socios);
  }
}

void imprimirLibrosTBiblioteca(TBiblioteca biblioteca){
  if (biblioteca != NULL){
    imprimirTABBLibros(biblioteca->Libros);
  }
}

void imprimirReservasTBiblioteca(TBiblioteca biblioteca){
  if (biblioteca != NULL){
    imprimirTColaReservas(biblioteca->Reservas);
  }
}

void imprimirPrestamosTBiblioteca(TBiblioteca biblioteca){
  if (biblioteca != NULL){
    imprimirTLDEPrestamos(biblioteca->Prestamos);
  }
}

int obtenerMin(TConjuntoGeneros c) {
  int n = cantMaxTConjuntoGeneros(c);
  if (n == 0)
      return -1;

  for (int i = 0; i < n; i++) {
      if (perteneceTConjuntoGeneros(c, i)) {
          return i;
      }
  }
  return -1;
}

TABBLibros obtenerLibrosDeGenero(TBiblioteca biblioteca, int idGenero) {
  TConjuntoGeneros conjuntoGeneros = obtenerConjuntoGeneros(biblioteca->ArbolGeneros, idGenero);
  TABBLibros res = crearTABBLibrosVacio();
  int cant = cantidadTABBLibros(biblioteca->Libros);

  for (int i = 1; i <= cant; i++){
    TLibro libro = obtenerNesimoLibroTABBLibros(biblioteca->Libros, i);
    int idGeneroLibro = idGeneroTLibro(libro);

    if (perteneceTConjuntoGeneros(conjuntoGeneros, idGeneroLibro)) {
      TLibro copia = copiarTLibro(libro);
      insertarLibroTABBLibros(res, copia);
    }
  }
  liberarTConjuntoGeneros(conjuntoGeneros);
  return res;
}

void liberarTBiblioteca(TBiblioteca &biblioteca) {
  if (biblioteca != NULL) {
    liberarTABBLibros(biblioteca->Libros);
    liberarTAGGeneros(biblioteca->ArbolGeneros); 
    if (biblioteca->Reservas != NULL) {
        liberarTColaReservasSoloEstructura(biblioteca->Reservas); 
    }
    if (biblioteca->Prestamos != NULL) {
        liberarTLDEPrestamosSoloEstructura(biblioteca->Prestamos); 
    }
    liberarTLSESocios(biblioteca->Socios);

    delete biblioteca;
    biblioteca = NULL;
  }
}

