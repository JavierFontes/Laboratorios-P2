/*
  Módulo principal de la Tarea 1.

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

#include "include/abbLibros.h"
#include "include/lseSocios.h"
#include "include/ldePrestamos.h"

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


// programa principal que lee comandos de la entrada estándar e invoca a la función de test correspondiente
int main() {
    TFecha fecha = NULL;
    TLibro libro = NULL;
    TSocio socio = NULL;
    TPrestamo prestamo = NULL;
    TLSESocios listaSocios = NULL;
    TLDEPrestamos ldePrestamos = NULL;
    TABBLibros abbLibros = NULL;


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
    printf("El socio tiene %d género/s favorito/s.\n", cant);    
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
