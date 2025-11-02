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

#include "include/coleccion.h"

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

// Funciones para testear colección
void main_crearColeccion(TColeccion &coleccion); 
void main_liberarColeccion(TColeccion coleccion);
void main_agregarEnColeccion(TColeccion &coleccion, TLibro &libro); 
void main_imprimirColeccion(TColeccion coleccion); 
void main_estaEnColeccion(TColeccion coleccion);
void main_obtenerDeColeccion(TColeccion coleccion);
void main_existenLibrosFechaColeccion(TColeccion coleccion);
void main_imprimirLibrosGeneroColeccion(TColeccion coleccion); 
void main_removerDeColeccion(TColeccion &coleccion);

// programa principal que lee comandos de la entrada estándar e invoca a la función de test correspondiente
int main() {
    TFecha fecha = NULL;
    TLibro libro = NULL;
    TColeccion coleccion = NULL;

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

        //////////////////////////////////////////////
        //     Funciones para testear coleccion     //
        //////////////////////////////////////////////

        } else if (cmd_es("crearColeccion", cmd)) {  
            main_crearColeccion(coleccion);
        } else if (cmd_es("liberarColeccion", cmd)) { 
            main_liberarColeccion(coleccion); 
        } else if (cmd_es("agregarEnColeccion", cmd)) { 
            main_agregarEnColeccion(coleccion, libro);
        } else if (cmd_es("imprimirColeccion", cmd)) { 
            main_imprimirColeccion(coleccion); 
        } else if (cmd_es("estaEnColeccion", cmd)) { 
            main_estaEnColeccion(coleccion); 
        } else if (cmd_es("obtenerDeColeccion", cmd)) { 
            main_obtenerDeColeccion(coleccion); 
        } else if (cmd_es("existenLibrosFechaColeccion", cmd)) {
            main_existenLibrosFechaColeccion(coleccion); 
        } else if (cmd_es("imprimirLibrosGeneroColeccion", cmd)) { 
            main_imprimirLibrosGeneroColeccion(coleccion); 
        } else if (cmd_es("removerDeColeccion", cmd)) { 
            main_removerDeColeccion(coleccion); 


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

////////////////////////////////////
/*  Funciones main para Coleccion */
////////////////////////////////////

void main_crearColeccion(TColeccion &coleccion) {
    assert(coleccion == NULL);
    coleccion = crearTColeccion(); 
}

void main_liberarColeccion(TColeccion coleccion) {
    assert(coleccion != NULL); 
    liberarTColeccion(coleccion); 
}

void main_agregarEnColeccion(TColeccion &coleccion, TLibro &libro) {
    assert(coleccion != NULL && libro != NULL); 
    agregarEnTColeccion(coleccion, libro);
    libro = NULL; 
}

void main_imprimirColeccion(TColeccion coleccion) {
    assert(coleccion != NULL); 
    imprimirTColeccion(coleccion); 
}

void main_estaEnColeccion(TColeccion coleccion) {
    assert(coleccion != NULL); 
    int isbn = leerNat(); 
    if (estaEnTColeccion(coleccion, isbn)) 
        printf("El libro con isbn %d está en el coleccion.\n", isbn); 
    else 
        printf("El libro con isbn %d NO está en el coleccion.\n", isbn); 
}

void main_obtenerDeColeccion(TColeccion coleccion) {
    assert(coleccion != NULL); 
    int isbn = leerNat(); 
    assert(estaEnTColeccion(coleccion, isbn)); 
    imprimirTLibro(obtenerDeTColeccion(coleccion, isbn));
}

void main_existenLibrosFechaColeccion(TColeccion coleccion) {
    assert(coleccion != NULL);
    TFecha fecha = NULL;
    leerFecha(fecha);

    if (existenLibrosFechaTColeccion(coleccion, fecha)){
        printf("Existen libros en la colección con fecha de edición ");
        imprimirTFecha(fecha);
    }else{
        printf("NO existen libros en la colección con fecha de edición ");
        imprimirTFecha(fecha);
    }
    liberarTFecha(fecha);
}

void main_imprimirLibrosGeneroColeccion(TColeccion coleccion) {
    assert(coleccion != NULL);
    int idGenero = leerNat();
    imprimirLibrosGeneroTColeccion(coleccion, idGenero);
}

void main_removerDeColeccion(TColeccion &coleccion) {
    assert(coleccion != NULL); 
    int isbn = leerNat(); 
    if (estaEnTColeccion(coleccion, isbn)) {
        removerDeTColeccion(coleccion, isbn); 
        printf("El libro con isbn %d se removió de la colección.\n", isbn);
    } else printf("No se puede remover el libro con isbn %d porque NO pertenece a la colección.\n", isbn);
}