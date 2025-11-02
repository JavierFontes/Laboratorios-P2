/*
  Módulo principal de la Tarea 3.

Intérprete de comandos para probar los módulos implementados.

Cada comando tiene un nombre y una secuencia (posiblemente vacía) de parámetros.
Se asume que los comandos están bien formados. Esto implica que:
- el nombre es uno de los descritos más abajo;
- la cantidad y tipo de los parámetros cumplen con lo requerido.

El comando 'Fin' termina el programa

El comando '# comentario' imprime comentario.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#define cmd_es(nom_comando, cmd) (0 == strcmp(nom_comando, cmd))

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "include/colaReservas.h"
#include "include/ldePrestamos.h"
#include "include/abbLibros.h"
#include "include/lseSocios.h"
#include "include/biblioteca.h"
#include "include/agGeneros.h"

#define MAX_PALABRA 32
#define MAX_LINEA 256

// Lee una fecha de la entrada en formato "dd/mm/aaaa" y la escribe la variable fecha
void leerFecha(TFecha &fecha);

/* La implementación de las funciones de testeo se realiza al final del archivo */

// Funciones para testear fecha
void main_crearFecha(TFecha &fecha);
void main_liberarFecha(TFecha &fecha);
void main_imprimirFecha(TFecha fecha);
void main_copiarFecha(TFecha fecha);
void main_aumentarDias(TFecha &fecha);
void main_compararFechas();

// Funciones para testear libro
void main_crearLibro(TLibro &libro, TFecha &fecha);
void main_liberarLibro(TLibro &libro);
void main_imprimirISBNLibro(TLibro libro);
void main_imprimirTituloLibro(TLibro libro);
void main_imprimirNombreAutorLibro(TLibro libro);
void main_imprimirApellidoAutorLibro(TLibro libro);
void main_imprimirDescripcionLibro(TLibro libro);
void main_imprimirFechaEdicionLibro(TLibro libro);
void main_imprimirIdGeneroLibro(TLibro libro);
void main_imprimirLibro(TLibro libro);
void main_copiarLibro(TLibro libro);


////////////////////////////////////
// Funciones main para Socios  //
////////////////////////////////////
void main_crearSocio(TSocio &socio);
void main_imprimirNombreYApellidoSocio(TSocio socio);
void main_imprimirSocio(TSocio socio);
void main_imprimirCISocio(TSocio socio);
void main_imprimirFechaAltaSocio(TSocio socio);
void main_copiarSocio(TSocio socio);
void main_liberarSocio(TSocio &socio);
void main_agregarGeneroFavoritoSocio(TSocio socio);
void main_tieneGeneroFavoritoSocio(TSocio socio);
void main_cantidadGenerosFavoritosSocio(TSocio socio);

////////////////////////////////////
// Funciones main para Prestamo  //
////////////////////////////////////
void main_crearPrestamo(TPrestamo &prestamo, TSocio &socio, TLibro &libro, TFecha &fecha);
void main_liberarPrestamo(TPrestamo &prestamo);
void main_imprimirPrestamo(TPrestamo prestamo);
void main_imprimirSocioPrestamo(TPrestamo prestamo);
void main_imprimirFechaRetiroPrestamo(TPrestamo prestamo);
void main_imprimirFechaDevolucionPrestamo(TPrestamo prestamo);
void main_imprimirLibroPrestamo(TPrestamo prestamo);
void main_fueRetornadoTPrestamo(TPrestamo prestamo);
void main_actualizarFechaDevolucionPrestamo(TPrestamo prestamo, TFecha &fecha);
void main_copiarPrestamo(TPrestamo prestamo);


//////////////////////////////////////////
//   Funciones main para LSE Socios     //
//////////////////////////////////////////
void main_crearLSESocios(TLSESocios &listaSocios);
void main_insertarLSESocios(TLSESocios &listaSocios, TSocio &socio);
void main_imprimirLSESocios(TLSESocios listaSocios);
void main_liberarLSESocios(TLSESocios &listaSocios);
void main_esVaciaLSESocios(TLSESocios listaSocios);
void main_existeSocioLSESocios(TLSESocios listaSocios);
void main_obtenerSocioLSESocios(TLSESocios listaSocios);
void main_cantidadLSESocios(TLSESocios listaSocios);
void main_obtenerNesimoLSESocios(TLSESocios listaSocios);
void main_removerSocioLSESocios(TLSESocios &listaSocios);


//////////////////////////////////////////
//   Funciones main para LDE Prestamos   //
//////////////////////////////////////////
void main_crearLDEPrestamos(TLDEPrestamos &ldePrestamos);
void main_insertarLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo &prestamo);
void main_liberarLDEPrestamos(TLDEPrestamos &ldePrestamos);
void main_imprimirLDEPrestamos(TLDEPrestamos ldePrestamos);
void main_imprimirInvertidoLDEPrestamos(TLDEPrestamos ldePrestamos);
void main_cantidadLDEPrestamos(TLDEPrestamos ldePrestamos);
void main_obtenerPrimeroLDEPrestamos(TLDEPrestamos ldePrestamos);
void main_obtenerUltimoLDEPrestamos(TLDEPrestamos ldePrestamos);
void main_obtenerNesimoLDEPrestamos(TLDEPrestamos ldePrestamos);
void main_filtrarPrestamosLDEPrestamos(TLDEPrestamos ldePrestamos);


//////////////////////////////////////
//  Funciones main para ABB Libros  //
//////////////////////////////////////
void main_crearABBLibrosVacio(TABBLibros &abbLibros);
void main_insertarLibroABBLibros(TABBLibros &abbLibros, TLibro &libro);
void main_imprimirABBLibros(TABBLibros abbLibros);
void main_liberarABBLibros(TABBLibros &abbLibros);
void main_existeLibroABBLibros(TABBLibros abbLibros);
void main_obtenerLibroABBLibros(TABBLibros abbLibros);
void main_alturaABBLibros(TABBLibros abbLibros);
void main_maxISBNLibroABBLibros(TABBLibros abbLibros);
void main_removerLibroABBLibros(TABBLibros &abbLibros);
void main_cantidadABBLibros(TABBLibros abbLibros);
void main_obtenerNesimoLibroABBLibros(TABBLibros abbLibros);
void main_filtradoPorGeneroABBLibros(TABBLibros abbLibros);
void main_alturaABBLibrosTiempo();
void main_obtenerExisteLibroABBLibrosTiempo();
void main_obtenerNesimoLibroABBLibrosTiempo();


//////////////////////////////////////
//   Funciones main para Reservas   //
//////////////////////////////////////

void main_crearReserva(TReserva &reserva, TSocio &socio, TLibro &libro);
void main_imprimirReserva(TReserva reserva);
void main_liberarReserva(TReserva &reserva);
void main_socioReserva(TReserva reserva);
void main_libroReserva(TReserva reserva);
void main_copiarReserva(TReserva reserva);

///////////////////////////////////////
//   Funciones main para AGGeneros   //
///////////////////////////////////////

void main_crearAGGeneros(TAGGeneros &arbolGeneros);
void main_insertarAGGeneros(TAGGeneros &arbolGeneros);
void main_imprimirAGGeneros(TAGGeneros arbolGeneros);
void main_liberarAGGeneros(TAGGeneros &arbolGeneros);
void main_existeGeneroAGGeneros(TAGGeneros arbolGeneros);
void main_nombreGeneroAGGeneros(TAGGeneros arbolGeneros);
void main_alturaAGGeneros(TAGGeneros arbolGeneros);
void main_cantidadAGGeneros(TAGGeneros arbolGeneros);
void main_removerGeneroAGGeneros(TAGGeneros arbolGeneros);
void main_obtenerSubarbolAGGeneros(TAGGeneros arbolGeneros);
void main_obtenerMaxAGGeneros(TAGGeneros arbolGeneros);
void main_obtenerConjuntoGeneros(TAGGeneros arbolGeneros);


///////////////////////////////////////////
//   Funciones main para Cola Reservas   //
///////////////////////////////////////////
void main_crearColaReservas(TColaReservas &colaReservas);
void main_liberarColaReservas(TColaReservas &colaReservas);
void main_encolarColaReservas(TColaReservas &colaReservas, TReserva &reserva);
void main_imprimirColaReservas(TColaReservas colaReservas);
void main_cantidadColaReservas(TColaReservas colaReservas);
void main_frenteColaReservas(TColaReservas colaReservas);
void main_desencolarColaReservas(TColaReservas colaReservas);

///////////////////////////////////////////
//  Funciones main para Conjunto Generos  //
///////////////////////////////////////////
void main_crearConjuntoGeneros(TConjuntoGeneros &conjuntoGeneros);
void main_esVacioConjuntoGeneros(TConjuntoGeneros conjuntoGeneros);
void main_insertarConjuntoGeneros(TConjuntoGeneros &conjuntoGeneros);
void main_borrarDeConjuntoGeneros(TConjuntoGeneros &conjuntoGeneros);
void main_perteneceConjuntoGeneros(TConjuntoGeneros conjuntoGeneros);
void main_cardinalConjuntoGeneros(TConjuntoGeneros conjuntoGeneros);
void main_cantMaxConjuntoGeneros(TConjuntoGeneros conjuntoGeneros);
void main_imprimirConjuntoGeneros(TConjuntoGeneros conjuntoGeneros);
void main_liberarConjuntoGeneros(TConjuntoGeneros &conjuntoGeneros);
void main_unionConjuntoGeneros(TConjuntoGeneros conjuntoGeneros);
void main_interseccionConjuntoGeneros(TConjuntoGeneros conjuntoGeneros);
void main_diferenciaConjuntoGeneros(TConjuntoGeneros conjuntoGeneros);
void main_conjuntoGenerosTiempo();


////////////////////////////////////////
//   Funciones main para Biblioteca   //
////////////////////////////////////////
void main_crearBiblioteca(TBiblioteca &biblioteca);
void main_agregarGeneroABiblioteca(TBiblioteca biblioteca);
void main_agregarLibroBiblioteca(TBiblioteca biblioteca, TLibro &libro);
void main_agregarSocioBiblioteca(TBiblioteca &biblioteca, TSocio &socio);
void main_prestarLibroBiblioteca(TBiblioteca biblioteca, TFecha &fecha);
void main_disponibleLibroBiblioteca(TBiblioteca biblioteca);
void main_reservarLibroBiblioteca(TBiblioteca biblioteca);
void main_devolverLibroBiblioteca(TBiblioteca biblioteca, TFecha &fecha);
void main_imprimirSociosBiblioteca(TBiblioteca &biblioteca);
void main_imprimirLibrosBiblioteca(TBiblioteca biblioteca);
void main_imprimirReservasBiblioteca(TBiblioteca &biblioteca);
void main_imprimirPrestamosBiblioteca(TBiblioteca biblioteca);
void main_obtenerLibrosDeGenero(TBiblioteca biblioteca);
void main_liberarBiblioteca(TBiblioteca biblioteca);



// programa principal que lee comandos de la entrada estándar e invoca a la función de test correspondiente
int main() {
    TFecha fecha = NULL;
    TLibro libro = NULL;
    TSocio socio = NULL;
    TPrestamo prestamo = NULL;
    TLSESocios listaSocios = NULL;
    TLDEPrestamos ldePrestamos = NULL;
    TABBLibros abbLibros = NULL;
    TReserva reserva = NULL;
    TColaReservas colaReservas = NULL;
    TConjuntoGeneros conjuntoGeneros = NULL;
    TAGGeneros arbolGeneros = NULL;
    TBiblioteca biblioteca = NULL;


    char restoLinea[MAX_LINEA + 1];
    char cmd[MAX_PALABRA];

    int cont_comandos = 0;
    bool seguir = true;
    while (seguir) {
        // mostrar el prompt
        cont_comandos++;
        printf("%u>", cont_comandos);

        // leer el comando en la variable cmd
        leerChars(cmd);

        // procesar el comando
        if (cmd_es("Fin", cmd)) {  // Termina el programa
            seguir = false;
            printf("Fin.\n");

        } else if (cmd_es("#", cmd)) {  // Imprime el comentario luego del #
            leerRestoLinea(restoLinea);
            printf("# %s.\n", restoLinea);

            //////////////////////////////////////////
            //     Funciones para testear fecha     //
            //////////////////////////////////////////

        } else if (cmd_es("crearFecha", cmd)) {  // Crea una fecha y la almacena en la variable fecha
            main_crearFecha(fecha);
        } else if (cmd_es("imprimirFecha", cmd)) {  // Imprime la fecha almacenada en la variable fecha
            main_imprimirFecha(fecha);
        } else if (cmd_es("copiarFecha", cmd)) { // Copia e imprime la fecha almacenada en la variable fecha
            main_copiarFecha(fecha);
        } else if (cmd_es("liberarFecha", cmd)) {  // Libera la memoria de la variable fecha
            main_liberarFecha(fecha);
        } else if (cmd_es("aumentarDias", cmd)) {  // Aumenta la fecha almacenada en la variable fecha en la cantidad de días indicada
            main_aumentarDias(fecha);
        } else if (cmd_es("compararFechas", cmd)) {  // Compara dos fechas leidas de la entrada
            main_compararFechas();

            //////////////////////////////////////////
            //     Funciones para testear libro     //
            //////////////////////////////////////////

        } else if (cmd_es("crearLibro", cmd)) {
            main_crearLibro(libro, fecha);
        } else if (cmd_es("liberarLibro", cmd)) {
            main_liberarLibro(libro);
        } else if (cmd_es("imprimirISBNLibro", cmd)) {
            main_imprimirISBNLibro(libro);
        } else if (cmd_es("imprimirTituloLibro", cmd)) {
            main_imprimirTituloLibro(libro);
        } else if (cmd_es("imprimirNombreAutorLibro", cmd)) {
            main_imprimirNombreAutorLibro(libro);
        } else if (cmd_es("imprimirApellidoAutorLibro", cmd)) {
            main_imprimirApellidoAutorLibro(libro);
        } else if (cmd_es("imprimirDescripcionLibro", cmd)) {
            main_imprimirDescripcionLibro(libro);
        } else if (cmd_es("imprimirFechaEdicionLibro", cmd)) {
            main_imprimirFechaEdicionLibro(libro);
        } else if (cmd_es("imprimirIdGeneroLibro", cmd)) {
            main_imprimirIdGeneroLibro(libro);
        } else if (cmd_es("imprimirLibro", cmd)) {
            main_imprimirLibro(libro);
        } else if (cmd_es("copiarLibro", cmd)) {
            main_copiarLibro(libro);

            //////////////////////////////////////
            //   Funciones para testear Socio   //
            //////////////////////////////////////

        } else if (cmd_es("crearSocio", cmd)) {
            main_crearSocio(socio);
        } else if (cmd_es("imprimirNombreYApellidoSocio",cmd)){
            main_imprimirNombreYApellidoSocio(socio);
        } else if (cmd_es("imprimirSocio", cmd)){
            main_imprimirSocio(socio);
        } else if (cmd_es("imprimirCISocio", cmd)){
            main_imprimirCISocio(socio);
        } else if (cmd_es("imprimirFechaAltaSocio", cmd)) {
            main_imprimirFechaAltaSocio(socio);
        } else if (cmd_es("copiarSocio",cmd)){
            main_copiarSocio(socio);
        } else if (cmd_es("liberarSocio", cmd)){
            main_liberarSocio(socio);
        } else if (cmd_es("agregarGeneroFavoritoSocio", cmd)) {
            main_agregarGeneroFavoritoSocio(socio);
        } else if (cmd_es("tieneGeneroFavoritoSocio",cmd)){
            main_tieneGeneroFavoritoSocio(socio);
        } else if (cmd_es("cantidadGenerosFavoritosSocio", cmd)) {
            main_cantidadGenerosFavoritosSocio(socio);



            ////////////////////////////////////
            // Funciones main para Prestamo  //
            ////////////////////////////////////
        } else if (cmd_es("crearPrestamo", cmd)) {
            main_crearPrestamo(prestamo, socio, libro, fecha);
        } else if (cmd_es("liberarPrestamo",cmd)){
            main_liberarPrestamo(prestamo);
        } else if (cmd_es("imprimirPrestamo", cmd)){
            main_imprimirPrestamo(prestamo);
        } else if (cmd_es("imprimirSocioPrestamo", cmd)){
            main_imprimirSocioPrestamo(prestamo);
        } else if (cmd_es("imprimirFechaRetiroPrestamo", cmd)) {
            main_imprimirFechaRetiroPrestamo(prestamo);
        } else if (cmd_es("imprimirFechaDevolucionPrestamo",cmd)){
            main_imprimirFechaDevolucionPrestamo(prestamo);
        } else if (cmd_es("imprimirLibroPrestamo", cmd)){
            main_imprimirLibroPrestamo(prestamo);
        } else if (cmd_es("fueRetornadoTPrestamo", cmd)){
            main_fueRetornadoTPrestamo(prestamo);
        } else if (cmd_es("actualizarFechaDevolucionPrestamo", cmd)) {
            main_actualizarFechaDevolucionPrestamo(prestamo, fecha);
        } else if (cmd_es("copiarPrestamo",cmd)){
            main_copiarPrestamo(prestamo);

            //////////////////////////////////////////
            //   Funciones main para LSE Socios     //
            //////////////////////////////////////////
        } else if (cmd_es("crearLSESocios", cmd)) {
            main_crearLSESocios(listaSocios);
        } else if (cmd_es("insertarLSESocios", cmd)) {
            main_insertarLSESocios(listaSocios, socio);
        } else if (cmd_es("imprimirLSESocios", cmd)) {
            main_imprimirLSESocios(listaSocios);
        } else if (cmd_es("liberarLSESocios", cmd)) {
            main_liberarLSESocios(listaSocios);
        } else if (cmd_es("esVaciaLSESocios", cmd)) {
            main_esVaciaLSESocios(listaSocios);
        } else if (cmd_es("existeSocioLSESocios", cmd)){
            main_existeSocioLSESocios(listaSocios);
        } else if (cmd_es("obtenerSocioLSESocios", cmd)) {
            main_obtenerSocioLSESocios(listaSocios);
        } else if (cmd_es("cantidadLSESocios", cmd)) {
            main_cantidadLSESocios(listaSocios);
        } else if (cmd_es("obtenerNesimoLSESocios", cmd)) {
            main_obtenerNesimoLSESocios(listaSocios);
        } else if (cmd_es("removerSocioLSESocios", cmd)) {
            main_removerSocioLSESocios(listaSocios);


            //////////////////////////////////////////
            //   Funciones main para LDEPrestamos   //
            //////////////////////////////////////////
        } else if (cmd_es("crearLDEPrestamos", cmd)) {
            main_crearLDEPrestamos(ldePrestamos);
        } else if (cmd_es("insertarLDEPrestamos", cmd)) {
            main_insertarLDEPrestamos(ldePrestamos, prestamo);
        } else if (cmd_es("liberarLDEPrestamos", cmd)) {
            main_liberarLDEPrestamos(ldePrestamos);
        } else if (cmd_es("imprimirLDEPrestamos", cmd)) {
            main_imprimirLDEPrestamos(ldePrestamos);
        } else if (cmd_es("imprimirInvertidoLDEPrestamos", cmd)) {
            main_imprimirInvertidoLDEPrestamos(ldePrestamos);
        } else if (cmd_es("cantidadLDEPrestamos", cmd)) {
            main_cantidadLDEPrestamos(ldePrestamos);
        } else if (cmd_es("obtenerPrimeroLDEPrestamos", cmd)) {
            main_obtenerPrimeroLDEPrestamos(ldePrestamos);
        } else if (cmd_es("obtenerUltimoLDEPrestamos", cmd)) {
            main_obtenerUltimoLDEPrestamos(ldePrestamos);
        } else if (cmd_es("obtenerNesimoLDEPrestamos", cmd)) {
            main_obtenerNesimoLDEPrestamos(ldePrestamos);
        } else if (cmd_es("filtrarPrestamosLDEPrestamos", cmd)) {
            main_filtrarPrestamosLDEPrestamos(ldePrestamos);


            //////////////////////////////////////
            //  Funciones main para ABB Libros  //
            //////////////////////////////////////
        } else if (cmd_es("crearABBLibrosVacio", cmd)) {
            main_crearABBLibrosVacio(abbLibros);
        } else if (cmd_es("insertarLibroABBLibros", cmd)) {
            main_insertarLibroABBLibros(abbLibros, libro);
        } else if (cmd_es("imprimirABBLibros", cmd)) {
            main_imprimirABBLibros(abbLibros);
        } else if (cmd_es("liberarABBLibros", cmd)) {
            main_liberarABBLibros(abbLibros);
        } else if (cmd_es("existeLibroABBLibros", cmd)) {
            main_existeLibroABBLibros(abbLibros);
        } else if (cmd_es("obtenerLibroABBLibros", cmd)) {
            main_obtenerLibroABBLibros(abbLibros);
        } else if (cmd_es("alturaABBLibros", cmd)) {
            main_alturaABBLibros(abbLibros);
        } else if (cmd_es("maxISBNLibroABBLibros", cmd)) {
            main_maxISBNLibroABBLibros(abbLibros);
        } else if (cmd_es("removerLibroABBLibros", cmd)) {
            main_removerLibroABBLibros(abbLibros);
        } else if (cmd_es("cantidadABBLibros", cmd)) {
            main_cantidadABBLibros(abbLibros);
        } else if (cmd_es("obtenerNesimoLibroABBLibros", cmd)) {
            main_obtenerNesimoLibroABBLibros(abbLibros);
        } else if (cmd_es("filtradoPorGeneroABBLibros", cmd)) {
            main_filtradoPorGeneroABBLibros(abbLibros);
        } else if (cmd_es("alturaABBLibrosTiempo", cmd)) {
            main_alturaABBLibrosTiempo();
        } else if (cmd_es("obtenerExisteLibroABBLibrosTiempo", cmd)) {
            main_obtenerExisteLibroABBLibrosTiempo();
        } else if (cmd_es("obtenerNesimoLibroABBLibrosTiempo", cmd)) {
            main_obtenerNesimoLibroABBLibrosTiempo();


        //////////////////////////////////////
        //   Funciones main para Reservas   //
        //////////////////////////////////////
         } else if (cmd_es("crearReserva", cmd)) {
            main_crearReserva(reserva, socio, libro);
        } else if (cmd_es("imprimirReserva", cmd)) {
            main_imprimirReserva(reserva);
        } else if (cmd_es("liberarReserva", cmd)) {
            main_liberarReserva(reserva);
        } else if (cmd_es("socioReserva", cmd)) {
            main_socioReserva(reserva);
        } else if (cmd_es("libroReserva", cmd)) {
            main_libroReserva(reserva);
        } else if (cmd_es("copiarReserva", cmd)) {
            main_copiarReserva(reserva);

        ///////////////////////////////////////
        //   Funciones main para AGGeneros   //
        ///////////////////////////////////////
        } else if (cmd_es("crearAGGeneros", cmd)) {
            main_crearAGGeneros(arbolGeneros);
        } else if (cmd_es("insertarAGGeneros", cmd)) {
            main_insertarAGGeneros(arbolGeneros);
        } else if (cmd_es("imprimirAGGeneros", cmd)) {
            main_imprimirAGGeneros(arbolGeneros);
        } else if (cmd_es("liberarAGGeneros", cmd)) {
            main_liberarAGGeneros(arbolGeneros);
        } else if (cmd_es("existeGeneroAGGeneros", cmd)) {
            main_existeGeneroAGGeneros(arbolGeneros);
        } else if (cmd_es("nombreGeneroAGGeneros", cmd)) {
            main_nombreGeneroAGGeneros(arbolGeneros);
        } else if (cmd_es("alturaAGGeneros", cmd)) {
            main_alturaAGGeneros(arbolGeneros);
        } else if (cmd_es("cantidadAGGeneros", cmd)) {
            main_cantidadAGGeneros(arbolGeneros);
        } else if (cmd_es("removerGeneroAGGeneros", cmd)) {
            main_removerGeneroAGGeneros(arbolGeneros);
        } else if (cmd_es("obtenerSubarbolAGGeneros", cmd)) {
            main_obtenerSubarbolAGGeneros(arbolGeneros);
        } else if (cmd_es("obtenerMaxAGGeneros", cmd)) {
            main_obtenerMaxAGGeneros(arbolGeneros);
        } else if (cmd_es("obtenerConjuntoGeneros", cmd)) {
            main_obtenerConjuntoGeneros(arbolGeneros);



        ///////////////////////////////////////////
        //   Funciones main para Cola Reservas   //
        ///////////////////////////////////////////
        } else if (cmd_es("crearColaReservas", cmd)) {
            main_crearColaReservas(colaReservas);
        } else if (cmd_es("liberarColaReservas", cmd)) {
            main_liberarColaReservas(colaReservas);
        } else if (cmd_es("encolarColaReservas", cmd)) {
            main_encolarColaReservas(colaReservas, reserva);
        } else if (cmd_es("imprimirColaReservas", cmd)) {
            main_imprimirColaReservas(colaReservas);
        } else if (cmd_es("cantidadColaReservas", cmd)) {
            main_cantidadColaReservas(colaReservas);
        } else if (cmd_es("frenteColaReservas", cmd)) {
            main_frenteColaReservas(colaReservas);
        } else if (cmd_es("desencolarColaReservas", cmd)) {
            main_desencolarColaReservas(colaReservas);

        ///////////////////////////////////////////
        //  Funciones main para Conjunto Generos  //
        ///////////////////////////////////////////
        } else if (cmd_es("crearConjuntoGeneros", cmd)) {
            main_crearConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("esVacioConjuntoGeneros", cmd)) {
            main_esVacioConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("insertarConjuntoGeneros", cmd)) {
            main_insertarConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("borrarDeConjuntoGeneros", cmd)) {
            main_borrarDeConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("perteneceConjuntoGeneros", cmd)) {
            main_perteneceConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("cardinalConjuntoGeneros", cmd)) {
            main_cardinalConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("cantMaxConjuntoGeneros", cmd)) {
            main_cantMaxConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("imprimirConjuntoGeneros", cmd)) {
            main_imprimirConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("liberarConjuntoGeneros", cmd)) {
            main_liberarConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("unionConjuntoGeneros", cmd)) {
            main_unionConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("interseccionConjuntoGeneros", cmd)) {
            main_interseccionConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("diferenciaConjuntoGeneros", cmd)) {
            main_diferenciaConjuntoGeneros(conjuntoGeneros);
        } else if (cmd_es("conjuntoGenerosTiempo", cmd)) {
            main_conjuntoGenerosTiempo();

        ////////////////////////////////////////
        //   Funciones main para Biblioteca   //
        ////////////////////////////////////////
        } else if (cmd_es("crearBiblioteca", cmd)) {
            main_crearBiblioteca(biblioteca);
        } else if (cmd_es("agregarGeneroABiblioteca", cmd)) {
            main_agregarGeneroABiblioteca(biblioteca);
        } else if (cmd_es("agregarLibroBiblioteca", cmd)) {
            main_agregarLibroBiblioteca(biblioteca, libro);
        } else if (cmd_es("agregarSocioBiblioteca", cmd)) {
            main_agregarSocioBiblioteca(biblioteca, socio);
        } else if (cmd_es("prestarLibroBiblioteca", cmd)) {
            main_prestarLibroBiblioteca(biblioteca, fecha);
        } else if (cmd_es("disponibleLibroBiblioteca", cmd)) {
            main_disponibleLibroBiblioteca(biblioteca);
        } else if (cmd_es("reservarLibroBiblioteca", cmd)) {
            main_reservarLibroBiblioteca(biblioteca);
        } else if (cmd_es("devolverLibroBiblioteca", cmd)) {
            main_devolverLibroBiblioteca(biblioteca, fecha);
        } else if (cmd_es("imprimirSociosBiblioteca", cmd)) {
            main_imprimirSociosBiblioteca(biblioteca);
        } else if (cmd_es("imprimirLibrosBiblioteca", cmd)) {
            main_imprimirLibrosBiblioteca(biblioteca);
        } else if (cmd_es("imprimirReservasBiblioteca", cmd)) {
            main_imprimirReservasBiblioteca(biblioteca);
        } else if (cmd_es("imprimirPrestamosBiblioteca", cmd)) {
            main_imprimirPrestamosBiblioteca(biblioteca);
        } else if (cmd_es("obtenerLibrosDeGenero", cmd)) {
            main_obtenerLibrosDeGenero(biblioteca);
        } else if (cmd_es("liberarBiblioteca", cmd)) {
            main_liberarBiblioteca(biblioteca);


        } else {
            printf("Comando no reconocido.\n");  // Comando no reconocido


        }  // if
        fgets(restoLinea, MAX_LINEA + 1, stdin);
    }  // while

    return 0;
}  // main

///////////////////////////////
/* Funciones main para Fecha */
///////////////////////////////

void leerFecha(TFecha &fecha) {
    nat *componentes = new nat[3];
    scanf("%u/%u/%u", &componentes[0], &componentes[1], &componentes[2]);
    fecha = crearTFecha(componentes[0], componentes[1], componentes[2]);
    delete[] componentes;
}

void main_crearFecha(TFecha &fecha) {
    assert(fecha == NULL);
    leerFecha(fecha);
}

void main_liberarFecha(TFecha &fecha) {
    assert(fecha != NULL);
    liberarTFecha(fecha);
}

void main_imprimirFecha(TFecha fecha) {
    assert(fecha != NULL);
    imprimirTFecha(fecha);
}

void main_copiarFecha(TFecha fecha) {
    assert(fecha != NULL);
    TFecha copia = copiarTFecha(fecha);
    imprimirTFecha(copia);
    liberarTFecha(copia);
}

void main_aumentarDias(TFecha &fecha) {
    assert(fecha != NULL);
    nat cantDias = leerNat();
    aumentarTFecha(fecha, cantDias);
    printf("La nueva fecha aplazada %d dias es: ", cantDias);
    imprimirTFecha(fecha);
}

void main_compararFechas() {
    TFecha fecha1 = NULL, fecha2 = NULL;
    leerFecha(fecha1);
    leerFecha(fecha2);
    int comp = compararTFechas(fecha1, fecha2);
    if (comp == 0) {
        printf("Las fechas son iguales.\n");
    } else if (comp == 1) {
        printf("La primera fecha es posterior a la segunda.\n");
    } else if (comp == -1) {
        printf("La primera fecha es anterior a la segunda.\n");
    } else {
        printf("Comparar fechas devolvió algo diferente a 0, 1 o -1.\n");
    }
    liberarTFecha(fecha1);
    liberarTFecha(fecha2);
}

///////////////////////////////
/* Funciones main para Libro */
///////////////////////////////

void main_crearLibro(TLibro &libro, TFecha &fechaEdicion) {
    assert((libro == NULL) && (fechaEdicion) != NULL);
    int isbn = leerNat();
    char titulo[MAX_TITULO];
    leerString(titulo);
    char nombreAutor[MAX_NOMBRE_AUTOR];
    leerString(nombreAutor);
    char apellidoAutor[MAX_APELLIDO_AUTOR];
    leerString(apellidoAutor);
    char desc[MAX_DESCRIPCION];
    leerString(desc);
    int idGenero = leerNat();
    descartarRestoLinea();

    libro = crearTLibro(isbn, titulo, nombreAutor, apellidoAutor, desc, idGenero, fechaEdicion);
    fechaEdicion = NULL;
}

void main_liberarLibro(TLibro &libro) {
    assert(libro != NULL);
    liberarTLibro(libro);
    printf("Función 'liberarTLibro' ejecutada exitosamente.\n");
}

void main_imprimirISBNLibro(TLibro libro) {
    assert(libro != NULL);
    printf("El isbn del libro es: %d\n", isbnTLibro(libro));
}

void main_imprimirTituloLibro(TLibro libro) {
    assert(libro != NULL);
    printf("El título del libro es: %s\n", tituloTLibro(libro));
}

void main_imprimirNombreAutorLibro(TLibro libro){
    assert(libro != NULL);
    printf("El nombre del autor del libro es: %s\n", nombreAutorTLibro(libro));
}

void main_imprimirApellidoAutorLibro(TLibro libro){
    assert(libro != NULL);
    printf("El apellido del autor del libro es: %s\n", apellidoAutorTLibro(libro));
}

void main_imprimirDescripcionLibro(TLibro libro) {
    assert(libro != NULL);
    printf("La descripción del libro es: %s\n", descripcionTLibro(libro));
}

void main_imprimirFechaEdicionLibro(TLibro libro) {
    assert(libro != NULL);
    TFecha fechaEdicion = fechaEdicionTLibro(libro);
    assert(fechaEdicion != NULL);
    printf("La fecha de edición del libro es: ");
    imprimirTFecha(fechaEdicion);
}

void main_imprimirIdGeneroLibro(TLibro libro) {
    assert(libro != NULL);
    printf("El id del género del libro es: %d\n", idGeneroTLibro(libro));
}

void main_imprimirLibro(TLibro libro) {
    assert(libro != NULL);
    imprimirTLibro(libro);
}

void main_copiarLibro(TLibro libro) {
    assert(libro != NULL);
    TLibro copia = copiarTLibro(libro);
    imprimirTLibro(copia);
    liberarTLibro(copia);
}


///////////////////////////////////
//   Funciones main para Socio   //
///////////////////////////////////

void main_crearSocio(TSocio &socio){
    assert(socio == NULL);
    int ci = leerInt();
    char nombre[MAX_NOMBRE_SOCIO];
    leerChars(nombre);
    char apellido[MAX_APELLIDO_SOCIO];
    leerChars(apellido);
    nat diaAlta = leerNat();
    nat mesAlta = leerNat();
    nat anioAlta = leerNat();

    socio = crearTSocio(ci, nombre, apellido, diaAlta, mesAlta, anioAlta);
    printf("Socio de ci %d creado exitosamente.\n", ci);
}

void main_imprimirNombreYApellidoSocio(TSocio socio){
    assert(socio != NULL);
    printf("El nombre del socio es: %s\n", nombreTSocio(socio));
    printf("El apellido del socio es: %s\n", apellidoTSocio(socio));
}

void main_imprimirCISocio(TSocio socio) {
    assert(socio != NULL);
    printf("La CI del socio es: %d\n", ciTSocio(socio));
}

void main_imprimirFechaAltaSocio(TSocio socio){
    assert(socio != NULL);
    TFecha fecha = fechaAltaTSocio(socio);
    printf("La fecha de alta del socio es: ");
    imprimirTFecha(fecha);
}

void main_imprimirSocio(TSocio socio) {
    assert(socio != NULL);
    imprimirTSocio(socio);
}

void main_copiarSocio(TSocio socio){
    TSocio socioCopia = copiarTSocio(socio);
    printf("Socio copiado. Datos de la copia:\n");
    imprimirTSocio(socioCopia);

    liberarTSocio(socioCopia);
    socioCopia = NULL;
}

void main_liberarSocio(TSocio &socio) {
    assert(socio != NULL);
    liberarTSocio(socio);
    assert(socio == NULL);
    printf("Se ejecutó 'liberarTSocio' exitosamente.\n");
}

void main_agregarGeneroFavoritoSocio(TSocio socio){
    assert(socio != NULL);
    int idGenero = leerInt();
    agregarGeneroFavoritoTSocio(socio, idGenero);
    printf("Se ejecutó 'agregarGeneroFavoritoTSocio' con idGenero %d exitosamente.\n", idGenero);
}

void main_tieneGeneroFavoritoSocio(TSocio socio){
    assert(socio != NULL);
    int idGenero = leerInt();
    bool existe = tieneGeneroFavoritoTSocio(socio, idGenero);
    if (existe){
        printf("El género de id %d es uno de los favoritos del socio.\n", idGenero);
    } else {
        printf("El género de id %d NO es uno de los favoritos del socio.\n", idGenero);
    }
}

void main_cantidadGenerosFavoritosSocio(TSocio socio){
    assert(socio != NULL);
    int cant = cantidadGenerosFavoritosTSocio(socio);
    printf("El socio tiene %d géneros favoritos/s.\n", cant);
}


////////////////////////////////////
// Funciones main para Prestamo  //
////////////////////////////////////
void main_crearPrestamo(TPrestamo &prestamo, TSocio &socio, TLibro &libro, TFecha &fechaRetiro){
    prestamo = crearTPrestamo(socio, libro, fechaRetiro);
    printf("Préstamo de libro de isbn %d a socio %d creado exitosamente.\n", isbnTLibro(libro), ciTSocio(socio));
    socio = NULL;
    libro = NULL;
    fechaRetiro = NULL;
}

void main_liberarPrestamo(TPrestamo &prestamo){
    assert(prestamo != NULL);
    liberarTPrestamo(prestamo);
    assert(prestamo == NULL);
    printf("Se ejecutó 'liberarTPrestamo' exitosamente.\n");
}

void main_imprimirPrestamo(TPrestamo prestamo){
    imprimirTPrestamo(prestamo);
}

void main_imprimirSocioPrestamo(TPrestamo prestamo){
    TSocio socio = socioTPrestamo(prestamo);
    printf("Socio del préstamo:\n");
    imprimirTSocio(socio);
}

void main_imprimirFechaRetiroPrestamo(TPrestamo prestamo){
    TFecha fecha = fechaRetiroTPrestamo(prestamo);
    printf("Fecha de retiro del préstamo:\n");
    imprimirTFecha(fecha);
}

void main_imprimirFechaDevolucionPrestamo(TPrestamo prestamo){
    TFecha fecha = fechaDevolucionTPrestamo(prestamo);
    printf("Fecha de devolución del préstamo:\n");
    imprimirTFecha(fecha);
}

void main_imprimirLibroPrestamo(TPrestamo prestamo){
    TLibro libro = libroTPrestamo(prestamo);
    printf("Libro del préstamo:\n");
    imprimirTLibro(libro);
}

void main_fueRetornadoTPrestamo(TPrestamo prestamo){
    bool fueRetornado = fueRetornadoTPrestamo(prestamo);
    if (fueRetornado){
        printf("El préstamo fue retornado.\n");
    }else{
        printf("El préstamo NO fue retornado.\n");
    }
}

void main_actualizarFechaDevolucionPrestamo(TPrestamo prestamo, TFecha &fecha){
    actualizarFechaDevolucionTPrestamo(prestamo, fecha);
    fecha = NULL;
    printf("Se actualizó la fecha de devolución del préstamo.\n");
}

void main_copiarPrestamo(TPrestamo prestamo){
    TPrestamo prestamoCopia = copiarTPrestamo(prestamo);
    printf("Préstamo copiado. Datos de la copia:\n");
    imprimirTPrestamo(prestamoCopia);

    liberarTPrestamo(prestamoCopia);
}

//////////////////////////////////////////////
//      Funciones main para LSE Socios      //
//////////////////////////////////////////////

void main_crearLSESocios(TLSESocios &listaSocios){
    assert(listaSocios == NULL);
    listaSocios = crearTLSESociosVacia();
    printf("Se ejecutó crearTLSESocios exitosamente.\n");
}

void main_insertarLSESocios(TLSESocios &listaSocios, TSocio &socio){
    insertarTLSESocios(listaSocios, socio);
    printf("Socio de CI %d agregado a la lista de socios de forma exitosa.\n", ciTSocio(socio));
    socio = NULL;
}

void main_imprimirLSESocios(TLSESocios listaSocios){
    imprimirTLSESocios(listaSocios);
}

void main_liberarLSESocios(TLSESocios &listaSocios){
    liberarTLSESocios(listaSocios);
}

void main_esVaciaLSESocios(TLSESocios listaSocios){
    bool esVacia = esVaciaTLSESocios(listaSocios);
    if (esVacia){
        printf("La lista de socios es vacía.\n");
    } else {
        printf("La lista de socios NO es vacía.\n");
    }
}

void main_existeSocioLSESocios(TLSESocios listaSocios){
    int ciSocio = leerInt();
    bool existe = existeSocioTLSESocios(listaSocios, ciSocio);
    if (existe){
        printf("El socio de CI %d pertenece a la lista.\n", ciSocio);
    } else {
        printf("El socio de CI %d NO pertenece a la lista.\n", ciSocio);
    }
}

void main_obtenerSocioLSESocios(TLSESocios listaSocios){
    int ciSocio = leerInt();
    assert(existeSocioTLSESocios(listaSocios, ciSocio));
    TSocio socio = obtenerSocioTLSESocios(listaSocios, ciSocio);
    printf("El socio pertenece a la lista:\n");
    imprimirTSocio(socio);
}

void main_cantidadLSESocios(TLSESocios listaSocios){
    nat cantidad = cantidadTLSESocios(listaSocios);
    printf("Existen %d socios en la lista.\n", cantidad);
}

void main_obtenerNesimoLSESocios(TLSESocios listaSocios){
    int n = leerInt();
    TSocio socio = obtenerNesimoTLSESocios(listaSocios, n);
    printf("Socio %d de la lista:\n", n);
    imprimirTSocio(socio);
}

void main_removerSocioLSESocios(TLSESocios &listaSocios){
    int ciSocio = leerInt();
    assert(existeSocioTLSESocios(listaSocios, ciSocio));
    removerSocioTLSESocios(listaSocios, ciSocio);
    printf("Se removió el socio de CI %d de la lista.\n", ciSocio);
}

//////////////////////////////////////
//  Funciones main para ABB Libros  //
//////////////////////////////////////

void main_crearABBLibrosVacio(TABBLibros &abbLibros){
    assert(abbLibros == NULL);
    abbLibros = crearTABBLibrosVacio();
    printf("Se ejecutó crearTABBLibrosVacio exitosamente.\n");
}

void main_insertarLibroABBLibros(TABBLibros &abbLibros, TLibro &libro){
    assert(libro != NULL);
    insertarLibroTABBLibros(abbLibros, libro);
    printf("Se insertó el libro con ISBN %d al árbol.\n", isbnTLibro(libro));
    libro = NULL;
}

void main_imprimirABBLibros(TABBLibros abbLibros){
    imprimirTABBLibros(abbLibros);
}

void main_existeLibroABBLibros(TABBLibros abbLibros){
    int isbn = leerInt();
    if (existeLibroTABBLibros(abbLibros, isbn)){
        printf("El libro con ISBN %d pertenece al árbol.\n", isbn);
    }else{
        printf("El libro con ISBN %d NO pertenece al árbol.\n", isbn);
    }
}

void main_liberarABBLibros(TABBLibros &abbLibros){
    liberarTABBLibros(abbLibros);
}

void main_obtenerLibroABBLibros(TABBLibros abbLibros){
    int isbn = leerInt();
    TLibro libro = obtenerLibroTABBLibros(abbLibros, isbn);
    if (libro == NULL){
        printf("El libro con ISBN %d no se puede imprimir pues NO pertenece al árbol.\n", isbn);
    }else{
        imprimirTLibro(libro);
    }
}

void main_alturaABBLibros(TABBLibros abbLibros){
    nat altura = alturaTABBLibros(abbLibros);
    printf("La altura del arbol es %d.\n", altura);
}

void main_maxISBNLibroABBLibros(TABBLibros abbLibros){
    TLibro libroMaxISBN = maxISBNLibroTABBLibros(abbLibros);
    printf("El mayor ISBN en el árbol es %d.\n", isbnTLibro(libroMaxISBN));
}

void main_removerLibroABBLibros(TABBLibros &abbLibros){
    int isbn = leerInt();
    if (existeLibroTABBLibros(abbLibros, isbn)) {
        removerLibroTABBLibros(abbLibros, isbn);
        printf("El libro con ISBN %d se removió del árbol.\n", isbn);
    } else {
        printf("El libro con ISBN %d no se puede remover porque NO pertenece al árbol.\n", isbn);
    }
}

void main_cantidadABBLibros(TABBLibros abbLibros){
    int cantidad = cantidadTABBLibros(abbLibros);
    printf("La cantidad de libros en el árbol es %d.\n", cantidad);
}

void main_obtenerNesimoLibroABBLibros(TABBLibros abbLibros){
    int n = leerInt();
    int cantEnArbol = cantidadTABBLibros(abbLibros);
    if (cantEnArbol >= n) {
        TLibro libro = obtenerNesimoLibroTABBLibros(abbLibros, n);
        printf("Libro nro %d del abb libros:\n", n);
        imprimirTLibro(libro);
    } else {
        printf("No se puede imprimir el libro nro %d del árbol porque solo hay %d.\n", n, cantEnArbol);
    }
}

void main_filtradoPorGeneroABBLibros(TABBLibros abbLibros){
    int idGenero = leerInt();
    TABBLibros filtrado = filtradoPorGeneroTABBLibros(abbLibros, idGenero);
    imprimirTABBLibros(filtrado);
    liberarTABBLibros(filtrado);
}

void insertarEnArbolDesdeArreglo(TABBLibros &abbLibros, TLibro *arreglo, int inicio, int final){
    if (inicio <= final){
        int mid = (inicio + final) / 2;
        insertarLibroTABBLibros(abbLibros, arreglo[mid]);
        insertarEnArbolDesdeArreglo(abbLibros, arreglo, inicio, mid - 1);
        insertarEnArbolDesdeArreglo(abbLibros, arreglo, mid + 1, final);
    }
}

void main_alturaABBLibrosTiempo(){
    TABBLibros abbLibros = crearTABBLibrosVacio();

    nat tamanio = leerNat();
    nat timeout = leerNat();

    TLibro *arreglo = new TLibro[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTLibro(i, "Estructuras de datos y algoritmos", "Carlos", "Luna", "Drama sobre dos estructuras que comparten memoria incorrectamente", 3, crearTFecha(9, 9, 1999));
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(abbLibros, arreglo, inicio, final);
    clock_t tm = clock();
    nat altura = alturaTABBLibros(abbLibros);
    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout){
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    }else{
        printf("La altura del arbol es %d. Calculado correctamente en menos de %ds.\n", altura, timeout);
    }

    liberarTABBLibros(abbLibros);
    delete[] arreglo;
}

void main_obtenerExisteLibroABBLibrosTiempo(){
    TABBLibros abbLibros = crearTABBLibrosVacio();

    nat tamanio = leerNat();
    double timeout = leerDouble();

    TLibro *arreglo = new TLibro[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTLibro(i, "Estructuras de datos y algoritmos", "Carlos", "Luna", "Drama sobre dos estructuras que comparten memoria incorrectamente", 3, crearTFecha(9, 9, 1999));
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(abbLibros, arreglo, inicio, final);
    clock_t tm = clock();

    bool existeLibro1 = existeLibroTABBLibros(abbLibros, 0);
    bool existeLibro2 = existeLibroTABBLibros(abbLibros, tamanio - 1);
    bool existeLibro3 = existeLibroTABBLibros(abbLibros, tamanio / 3);
    bool existeLibro4 = existeLibroTABBLibros(abbLibros, (2 * tamanio) / 3);
    TLibro libro1 = obtenerLibroTABBLibros(abbLibros, 0);
    TLibro libro2 = obtenerLibroTABBLibros(abbLibros, tamanio - 1);
    TLibro libro3 = obtenerLibroTABBLibros(abbLibros, tamanio / 3);
    TLibro libro4 = obtenerLibroTABBLibros(abbLibros, (2 * tamanio) / 3);
    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;

    if (tiempo > timeout){
        printf("ERROR, tiempo excedido: %.3f > %.3f \n", tiempo, timeout);
    }else{
        printf("Se obtuvieron los libros %d %d %d %d con ISBNS respectivos %d %d %d %d\n", existeLibro1, existeLibro2, existeLibro3, existeLibro4, isbnTLibro(libro1), isbnTLibro(libro2), isbnTLibro(libro3), isbnTLibro(libro4));
        printf("Calculado correctamente en menos de %.3fs.\n", timeout);
    }

    liberarTABBLibros(abbLibros);
    delete[] arreglo;
}

void main_obtenerNesimoLibroABBLibrosTiempo(){
    TABBLibros abbLibros = crearTABBLibrosVacio();

    nat tamanio = leerNat();
    double timeout = leerDouble();

    TLibro *arreglo = new TLibro[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTLibro(i, "Estructuras de datos y algoritmos", "Carlos", "Luna", "Drama sobre dos estructuras que comparten memoria incorrectamente", 3, crearTFecha(9, 9, 1999));
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(abbLibros, arreglo, inicio, final);

    clock_t tm = clock();

    // Test obtenerNesimoLibroTABBLibros
    TLibro libro1 = obtenerNesimoLibroTABBLibros(abbLibros, 1);
    TLibro libro2 = obtenerNesimoLibroTABBLibros(abbLibros, tamanio);
    TLibro libro3 = obtenerNesimoLibroTABBLibros(abbLibros, tamanio / 3);
    TLibro libro4 = obtenerNesimoLibroTABBLibros(abbLibros, 2 * tamanio / 3);

    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;

    if (tiempo > timeout) {
        printf("ERROR, tiempo excedido: %.3f > %.3f \n", tiempo, timeout);
    } else {
        printf("Se obtuvieron los libros en posiciones 1, %d, %d, %d con ISBNs respectivos %d %d %d %d\n",
               tamanio, tamanio / 3, 2 * tamanio / 3,
               isbnTLibro(libro1), isbnTLibro(libro2), isbnTLibro(libro3), isbnTLibro(libro4));
        printf("Calculado correctamente en menos de %.3fs.\n", timeout);
    }

    liberarTABBLibros(abbLibros);
    delete[] arreglo;
}


////////////////////////////////////////////
//    Funciones main para LDE Prestamos   //
////////////////////////////////////////////


void main_crearLDEPrestamos(TLDEPrestamos &ldePrestamos){
    assert(ldePrestamos == NULL);
    ldePrestamos = crearTLDEPrestamosVacia();
}

void main_insertarLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo &prestamo){
    assert(prestamo != NULL);
    insertarTLDEPrestamos(ldePrestamos, prestamo);
    prestamo = NULL;
}

void main_liberarLDEPrestamos(TLDEPrestamos &ldePrestamos){
    assert(ldePrestamos != NULL);
    liberarTLDEPrestamos(ldePrestamos);
    ldePrestamos = NULL;
}

void main_imprimirLDEPrestamos(TLDEPrestamos ldePrestamos){
    imprimirTLDEPrestamos(ldePrestamos);
}

void main_imprimirInvertidoLDEPrestamos(TLDEPrestamos ldePrestamos){
    imprimirInvertidoTLDEPrestamos(ldePrestamos);
}

void main_cantidadLDEPrestamos(TLDEPrestamos ldePrestamos){
    nat cant = cantidadTLDEPrestamos(ldePrestamos);
    printf("La cantidad de préstamos en la lista es %d\n", cant);
}

void main_obtenerPrimeroLDEPrestamos(TLDEPrestamos ldePrestamos){
    nat cant = cantidadTLDEPrestamos(ldePrestamos);
    if (cant > 0){
        TPrestamo prestamo = obtenerPrimeroTLDEPrestamos(ldePrestamos);
        assert(prestamo != NULL);
        printf("Primer préstamo:\n");
        imprimirTPrestamo(prestamo);
    }else{
        printf("No se puede obtener el primero de la LDE de préstamos porque es vacía\n");
    }
}


void main_obtenerUltimoLDEPrestamos(TLDEPrestamos ldePrestamos){
    nat cant = cantidadTLDEPrestamos(ldePrestamos);
    if (cant > 0){
        TPrestamo prestamo = obtenerUltimoTLDEPrestamos(ldePrestamos);
        assert(prestamo != NULL);
        printf("Ultimo préstamo:\n");
        imprimirTPrestamo(prestamo);
    }else{
        printf("No se puede obtener el último de la LDE de préstamos porque es vacía\n");
    }
}

void main_obtenerNesimoLDEPrestamos(TLDEPrestamos ldePrestamos){
    nat n = leerNat();
    nat cant = cantidadTLDEPrestamos(ldePrestamos);
    if (cant < n){
        printf("No se puede invocar obtenerNesimoTLDEPrestamos con n = %d porque la cantidad de elementos en la lista es %d.\n", n, cant);
    }else{
        TPrestamo prestamo = obtenerNesimoTLDEPrestamos(ldePrestamos, n);
        assert(prestamo != NULL);

        printf("Préstamo en la posición %d:\n", n);
        imprimirTPrestamo(prestamo);
    }
}

void main_filtrarPrestamosLDEPrestamos(TLDEPrestamos ldePrestamos){
    int criterio = leerInt();
    if (criterio != 0 && criterio != 1){
        printf("El criterio para el filtrado debe ser 0 o 1.\n");
    }else{
        TLDEPrestamos filtrado = filtrarPrestamosTLDEPrestamos(ldePrestamos, criterio);
        imprimirTLDEPrestamos(filtrado);
        liberarTLDEPrestamos(filtrado);
    }
}


//////////////////////////////////////
//   Funciones main para Reservas   //
//////////////////////////////////////

void main_crearReserva(TReserva &reserva, TSocio &socio, TLibro &libro){
    reserva = crearTReserva(socio, libro);
    printf("Reserva de libro de isbn %d a socio %d creada exitosamente.\n", isbnTLibro(libro), ciTSocio(socio));
    socio = NULL;
    libro = NULL;
}

void main_imprimirReserva(TReserva reserva){
    imprimirTReserva(reserva);
}

void main_liberarReserva(TReserva &reserva){
    assert(reserva != NULL);
    liberarTReserva(reserva);
    assert(reserva == NULL);
    printf("Se ejecutó 'liberarTReserva' exitosamente.\n");
}

void main_socioReserva(TReserva reserva){
    TSocio socio = socioTReserva(reserva);
    printf("Socio de la reserva:\n");
    imprimirTSocio(socio);
}

void main_libroReserva(TReserva reserva){
    TLibro libro = libroTReserva(reserva);
    printf("Libro de la reserva:\n");
    imprimirTLibro(libro);
}

void main_copiarReserva(TReserva reserva){
    TReserva reservaCopia = copiarTReserva(reserva);
    printf("Reserva copiada. Datos de la copia:\n");
    imprimirTReserva(reservaCopia);

    liberarTReserva(reservaCopia);
}


///////////////////////////////////////
//   Funciones main para AGGeneros   //
///////////////////////////////////////

void main_crearAGGeneros(TAGGeneros &arbolGeneros){
    assert(arbolGeneros == NULL);
    arbolGeneros = crearTAGGeneros();
    printf("Se ejecutó 'crearTAGGeneros' exitosamente.\n");

}

void main_insertarAGGeneros(TAGGeneros &arbolGeneros){
    int idGeneroPadre = leerInt();
    int idGenero = leerInt();
    char nombreGenero[50];
    leerChars(nombreGenero);
    insertarGeneroTAGGeneros(arbolGeneros, idGeneroPadre, idGenero, nombreGenero);
    printf("Se ejecutó 'insertarGeneroTAGGeneros' con idGeneroPadre %d e idGenero %d.\n", idGeneroPadre, idGenero);
}

void main_imprimirAGGeneros(TAGGeneros arbolGeneros){
    imprimirTAGGeneros(arbolGeneros);
}

void main_liberarAGGeneros(TAGGeneros &arbolGeneros){
    liberarTAGGeneros(arbolGeneros);
    printf("Se ejecutó 'liberarTAGGeneros' exitosamente.\n");
}

void main_existeGeneroAGGeneros(TAGGeneros arbolGeneros){
    int idGenero = leerInt();
    bool existe = existeGeneroTAGGeneros(arbolGeneros, idGenero);
    if (existe){
        printf("El género de id %d está incluído en el árbol de géneros.\n", idGenero);
    } else {
        printf("El género de id %d NO está incluído en el árbol de géneros.\n", idGenero);
    }
}

void main_nombreGeneroAGGeneros(TAGGeneros arbolGeneros){
    int idGenero = leerInt();
    char* nombreGenero = nombreGeneroTAGGeneros(arbolGeneros, idGenero);
    printf("El nombre del género de id %d es %s.\n", idGenero, nombreGenero);
}

void main_alturaAGGeneros(TAGGeneros arbolGeneros){
    nat altura = alturaTAGGeneros(arbolGeneros);
    printf("La altura de del árbol general es: %d.\n", altura);
}

void main_cantidadAGGeneros(TAGGeneros arbolGeneros){
    nat cantidad = cantidadTAGGeneros(arbolGeneros);
    printf("Existen %d géneros en el árbol de géneros.\n", cantidad);
}

void main_removerGeneroAGGeneros(TAGGeneros arbolGeneros){
    int idGenero = leerInt();
    assert(existeGeneroTAGGeneros(arbolGeneros, idGenero));
    removerGeneroTAGGeneros(arbolGeneros, idGenero);
    bool existe = existeGeneroTAGGeneros(arbolGeneros, idGenero);
    if (existe){
        printf("El género de id %d no fue removido.\n", idGenero);
    }else{
        printf("El género de id %d fue removido.\n", idGenero);
    }
}

void main_obtenerSubarbolAGGeneros(TAGGeneros arbolGeneros) {
  int idGenero = leerInt();
  assert(existeGeneroTAGGeneros(arbolGeneros, idGenero));
  TAGGeneros resultado = obtenerSubarbolTAGGeneros(arbolGeneros, idGenero);
  imprimirTAGGeneros(resultado);
}


void main_obtenerMaxAGGeneros(TAGGeneros arbolGeneros) {
  int resultado = obtenerMaxTAGGeneros(arbolGeneros);
  printf("El maximo genero es: %d.\n", resultado);
}


void main_obtenerConjuntoGeneros(TAGGeneros arbolGeneros) {
  int idGenero = leerInt();
  assert(existeGeneroTAGGeneros(arbolGeneros, idGenero));
  TConjuntoGeneros resultado = obtenerConjuntoGeneros(arbolGeneros, idGenero);
  printf("El conjunto de generos es: ");
  imprimirTConjuntoGeneros(resultado);
  liberarTConjuntoGeneros(resultado);
}

///////////////////////////////////////////
//   Funciones main para Cola Reservas   //
///////////////////////////////////////////
void main_crearColaReservas(TColaReservas &colaReservas){
    assert(colaReservas == NULL);
    colaReservas = crearTColaReservas();
    printf("Se ejecutó 'crearTColaReservas' exitosamente\n");
}

void main_liberarColaReservas(TColaReservas &colaReservas){
    liberarTColaReservas(colaReservas);
    assert(colaReservas == NULL);
    printf("Se ejecutó 'liberarTColaReservas' exitosamente\n");
}

void main_encolarColaReservas(TColaReservas &colaReservas, TReserva &reserva){
    encolarTColaReservas(colaReservas, reserva);
    reserva = NULL;
    printf("Se ejecutó 'encolarTColaReservas' exitosamente.\n");
}

void main_imprimirColaReservas(TColaReservas colaReservas){
    imprimirTColaReservas(colaReservas);
}

void main_cantidadColaReservas(TColaReservas colaReservas){
    int cant = cantidadTColaReservas(colaReservas);
    printf("La cantidad de reservas en la cola es %d\n", cant);
}

void main_frenteColaReservas(TColaReservas colaReservas){
    assert(cantidadTColaReservas(colaReservas) > 0);
    TReserva reserva = frenteTColaReservas(colaReservas);
    printf("Reserva obtenida al ejecutar frente:\n");
    imprimirTReserva(reserva);
}

void main_desencolarColaReservas(TColaReservas colaReservas){
    assert(cantidadTColaReservas(colaReservas) > 0);
    desencolarTColaReservas(colaReservas);
    printf("Se ejecutó 'desencolarTColaReservas' exitosamente\n");
}

///////////////////////////////////////////
//  Funciones main para Conjunto Generos  //
///////////////////////////////////////////

void main_crearConjuntoGeneros(TConjuntoGeneros &conjuntoGeneros){
    assert(conjuntoGeneros == NULL);

    int cantMax = leerInt();
    conjuntoGeneros = crearTConjuntoGeneros(cantMax);
    printf("Se creó conjunto generos con cantMax %d exitosamente.\n", cantMax);
}

void main_esVacioConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    bool esVacia = esVacioTConjuntoGeneros(conjuntoGeneros);
    if (esVacia){
        printf("El conjunto de generos es vacío.\n");
    } else {
        printf("La conjunto de generos NO es vacío.\n");
    }
}

void main_insertarConjuntoGeneros(TConjuntoGeneros &conjuntoGeneros){
    int idGenero = leerInt();
    insertarTConjuntoGeneros(conjuntoGeneros, idGenero);
    printf("Se ejecutó 'insertarTConjuntoGeneros con genero de id %d exitosamente.\n", idGenero);
}

void main_borrarDeConjuntoGeneros(TConjuntoGeneros &conjuntoGeneros){
    int idGenero = leerInt();
    borrarDeTConjuntoGeneros(conjuntoGeneros, idGenero);
    printf("Se ejecutó 'borrarDeTConjuntoGeneros con genero de id %d exitosamente.\n", idGenero);
}

void main_perteneceConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    int idGenero = leerInt();
    bool pertenece = perteneceTConjuntoGeneros(conjuntoGeneros, idGenero);
    if (pertenece){
        printf("El genero de id %d pertenece al conjunto.\n", idGenero);
    }else{
        printf("El genero de id %d NO pertenece al conjunto.\n", idGenero);
    }
}

void main_cardinalConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    int cardinal = cardinalTConjuntoGeneros(conjuntoGeneros);
    printf("El cardinal del conjunto es: %d.\n", cardinal);
}

void main_cantMaxConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    int cantMax = cantMaxTConjuntoGeneros(conjuntoGeneros);
    printf("La cantidad máxima del conjunto es: %d.\n", cantMax);
}

void main_imprimirConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    printf("Conjunto de generos:\n");
    imprimirTConjuntoGeneros(conjuntoGeneros);
}

void main_liberarConjuntoGeneros(TConjuntoGeneros &conjuntoGeneros){
    liberarTConjuntoGeneros(conjuntoGeneros);
    assert(conjuntoGeneros == NULL);
    printf("Se ejecutó 'liberarTConjuntoGeneros' exitosamente.\n");
}

TConjuntoGeneros aux_crearConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    int cantMax = cantMaxTConjuntoGeneros(conjuntoGeneros);
    TConjuntoGeneros otroConjunto = crearTConjuntoGeneros(cantMax);

    int cant = leerInt();
    for (int i = 0; i < cant; i++){
        int id = leerInt();
        insertarTConjuntoGeneros(otroConjunto, id);
    }

    return otroConjunto;
}

void main_unionConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    TConjuntoGeneros otroConjunto = aux_crearConjuntoGeneros(conjuntoGeneros);

    TConjuntoGeneros unionConjuntoGeneros = unionTConjuntoGeneros(conjuntoGeneros, otroConjunto);
    printf("Conjunto de generos unión:\n");
    imprimirTConjuntoGeneros(unionConjuntoGeneros);

    liberarTConjuntoGeneros(unionConjuntoGeneros);
    liberarTConjuntoGeneros(otroConjunto);
}

void main_interseccionConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    TConjuntoGeneros otroConjunto = aux_crearConjuntoGeneros(conjuntoGeneros);

    TConjuntoGeneros interseccion = interseccionTConjuntoGeneros(conjuntoGeneros, otroConjunto);
    printf("Conjunto de generos intersección:\n");
    imprimirTConjuntoGeneros(interseccion);

    liberarTConjuntoGeneros(interseccion);
    liberarTConjuntoGeneros(otroConjunto);
}

void main_diferenciaConjuntoGeneros(TConjuntoGeneros conjuntoGeneros){
    TConjuntoGeneros otroConjunto = aux_crearConjuntoGeneros(conjuntoGeneros);

    TConjuntoGeneros diferencia = diferenciaTConjuntoGeneros(conjuntoGeneros, otroConjunto);
    printf("Conjunto de generos diferencia:\n");
    imprimirTConjuntoGeneros(diferencia);

    liberarTConjuntoGeneros(diferencia);
    liberarTConjuntoGeneros(otroConjunto);
}

void main_conjuntoGenerosTiempo(){
    int cantMax = leerInt();
    TConjuntoGeneros unConjunto = crearTConjuntoGeneros(cantMax);
    TConjuntoGeneros otroConjunto = crearTConjuntoGeneros(cantMax);
    nat timeout = leerNat();

    clock_t tm = clock();

    bool uno = false;
    for (int i = 0; i < cantMax; i++){
        if (uno){
            insertarTConjuntoGeneros(unConjunto, i);
        }else{
            insertarTConjuntoGeneros(otroConjunto, i);
        }
        uno = !uno;
    }

    TConjuntoGeneros uniCP = unionTConjuntoGeneros(unConjunto, otroConjunto);
    TConjuntoGeneros intCP = interseccionTConjuntoGeneros(unConjunto, otroConjunto);
    TConjuntoGeneros difCP = diferenciaTConjuntoGeneros(unConjunto, otroConjunto);

    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout){
        printf("ERROR, tiempo excedido; %.3f > %d \n", tiempo, timeout);
    }else{
        printf("Prueba de conjunto generos (insertar, union, intersección, diferencia) para %d entradas. Calculado correctamente en menos de %ds.\n", cantMax, timeout);
    }

    liberarTConjuntoGeneros(uniCP);
    liberarTConjuntoGeneros(intCP);
    liberarTConjuntoGeneros(difCP);
    liberarTConjuntoGeneros(unConjunto);
    liberarTConjuntoGeneros(otroConjunto);
}

////////////////////////////////////////
//   Funciones main para Biblioteca   //
////////////////////////////////////////
void main_crearBiblioteca(TBiblioteca &biblioteca){
    assert(biblioteca == NULL);
    biblioteca = crearTBiblioteca();
    printf("Biblioteca creada exitosamente.\n");
}

void main_agregarGeneroABiblioteca(TBiblioteca biblioteca) {
  int idGeneroPadre = leerInt();
  int idGenero = leerInt();
  char nombreGenero[50];
  leerChars(nombreGenero);
  agregarGeneroABiblioteca(biblioteca, idGeneroPadre, idGenero, nombreGenero);
  printf("Genero agregado a la biblioteca");
}

void main_agregarLibroBiblioteca(TBiblioteca biblioteca, TLibro &libro){
    assert(biblioteca != NULL && libro != NULL);
    agregarLibroTBiblioteca(biblioteca, libro);
    printf("Libro de ISBN %d agregado a la biblioteca.\n", isbnTLibro(libro));
    libro = NULL;
}

void main_agregarSocioBiblioteca(TBiblioteca &biblioteca, TSocio &socio){
    assert(biblioteca != NULL && socio != NULL);
    agregarSocioTBiblioteca(biblioteca, socio);
    printf("Socio de CI %d agregado a la biblioteca.\n", ciTSocio(socio));
    socio = NULL;
}

void main_prestarLibroBiblioteca(TBiblioteca biblioteca, TFecha &fechaPrestamo){
    assert(biblioteca != NULL && fechaPrestamo != NULL);
    int ciSocio = leerInt();
    int isbnLibro = leerInt();
    prestarLibroTBiblioteca(biblioteca, ciSocio, isbnLibro, fechaPrestamo);
    printf("Préstamo del libro %d al socio %d registrado.\n", isbnLibro, ciSocio);
    fechaPrestamo = NULL;
}

void main_disponibleLibroBiblioteca(TBiblioteca biblioteca){
    int isbnLibro = leerInt();
    bool disponible = disponibleLibroTBiblioteca(biblioteca, isbnLibro);
    if (disponible) {
        printf("El libro de ISBN %d está disponible.\n", isbnLibro);
    } else {
        printf("El libro de ISBN %d NO está disponible.\n", isbnLibro);
    }
}

void main_reservarLibroBiblioteca(TBiblioteca biblioteca){
    assert(biblioteca != NULL);
    int ciSocio = leerInt();
    int isbnLibro = leerInt();
    reservarLibroTBiblioteca(biblioteca, ciSocio, isbnLibro);
    printf("Reserva del libro %d para el socio %d registrada.\n", isbnLibro, ciSocio);
}

void main_devolverLibroBiblioteca(TBiblioteca biblioteca,TFecha &fechaDevolucion){
    assert(biblioteca != NULL && fechaDevolucion != NULL);
    int ciSocio = leerInt();
    int isbnLibro = leerInt();
    TFecha fechaPrestamo = NULL;
    leerFecha(fechaPrestamo);
    devolverLibroTBiblioteca(biblioteca, ciSocio, isbnLibro, fechaPrestamo, fechaDevolucion);
    printf("Devolución del libro %d por el socio %d registrada.\n", isbnLibro, ciSocio);
    liberarTFecha(fechaPrestamo);
    fechaDevolucion = NULL;
}

void main_imprimirSociosBiblioteca(TBiblioteca &biblioteca){
    imprimirSociosTBiblioteca(biblioteca);
}

void main_imprimirLibrosBiblioteca(TBiblioteca biblioteca){
    imprimirLibrosTBiblioteca(biblioteca);
}

void main_imprimirReservasBiblioteca(TBiblioteca &biblioteca){
    imprimirReservasTBiblioteca(biblioteca);
}

void main_imprimirPrestamosBiblioteca(TBiblioteca biblioteca){
    imprimirPrestamosTBiblioteca(biblioteca);
}

void main_obtenerLibrosDeGenero(TBiblioteca biblioteca) {
  int idGenero = leerInt();
  TABBLibros resultado = obtenerLibrosDeGenero(biblioteca, idGenero);
  imprimirTABBLibros(resultado);
  liberarTABBLibros(resultado);
}

void main_liberarBiblioteca(TBiblioteca biblioteca){
    assert(biblioteca != NULL);
    liberarTBiblioteca(biblioteca);
    biblioteca = NULL;
    printf("Biblioteca liberada exitosamente.\n");
}





