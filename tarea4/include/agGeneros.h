/*
  Módulo de definición de 'TAGGeneros'.

  Un elemento de tipo TAGGeneros es un árbol general que permite representar
  la estructura y jerarquía de géneros y subgéneros literarios.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
 #ifndef AGGENEROS_H
 #define AGGENEROS_H

 #include "utils.h"
 #include <string.h>
 #include "conjuntoGeneros.h"

// Constantes para definir el largo máximo del nombre del género.
const int MAX_NOMBRE = 50;

 // Define el tipo TAGGeneros como un puntero a rep_agGeneros.
 typedef struct rep_agGeneros *TAGGeneros;

// Función para crear un nuevo arbol general
// Devuelve un nuevo árbol general vacío
// Debe ejecutar en O(1) peor caso.
TAGGeneros crearTAGGeneros();

// Función para insertar un nuevo género idGenero en el árbol general,
// como primer hijo del nodo que representa el idGenero 'idGeneroPadre'. Si
// idGeneroPadre == '-1', idGenero se almacena como nodo raíz.
// PRE: El género con cod 'idGenero' no está en el árbol.
// PRE: Si el árbol es vacío, la primer inserción será con idGeneroPadre = -1
// PRE: Si el árbol no es vacío, el género con idGeneroPadre pertenece al árbol
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
void insertarGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGeneroPadre, int idGenero, const char nombreGenero[MAX_NOMBRE] );

// Función para imprimir el árbol general. Los hermanos se imprimen según
// el orden inverso de creación (el último hermano en ser agregado se imprime primero).
// La impresión de cada género debe tener el siguiente formato:
// <cod género> - <nombre género>
// Este formato debe ser usado para imprimir el árbol completo de la siguiente forma:
// Árbol de géneros:
// <género raíz>
//     <género hijo 1 (primer nivel)>
//         <género hijo 1 (segundo nivel)>
//         <género hijo 2 (segundo nivel)>
//             <género hijo 1 (tercer nivel)>
//             ...
//         <género hijo 3 (segundo nivel)>
//         ...
//     <género hijo 2 (primer nivel)>
//     ...
// Notar que la separación entre niveles se realiza con 4 espacios en blanco ('    ')
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
void imprimirTAGGeneros(TAGGeneros arbolGeneros);

// Función para liberar la memoria asignada a un árbol de géneros.
// Luego de la función, el puntero arbolGeneros debe apuntar NULL.
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
void liberarTAGGeneros(TAGGeneros &arbolGeneros);

// Función que determina si un género idGenero está en el árbol de géneros.
// Devuelve true si el género está en el árbol, false en caso contrario.
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
bool existeGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero);

// Función que devuelve el nombre de un género dado su id.
// En caso de que el género no pertenezca al árbol, devuelve NULL.
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
char* nombreGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero);

// Función para obtener la altura del árbol general.
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
nat alturaTAGGeneros(TAGGeneros arbolGeneros);

// Función para obtener la cantidad de géneros en el árbol de géneros.
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
nat cantidadTAGGeneros(TAGGeneros arbolGeneros);

// Función para eliminar un género del árbol de géneros.
// En caso de el género tenga hijos, estos también son eliminados.
// PRE: existeGeneroTAGGeneros(arbolGeneros, idGenero) == true
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
void removerGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGenero);

// Función para obtener un subarbol de géneros dado.
// Retorna el subárbol cuya raíz tiene el idGenero pasado por parámetro
// PRE: existeGeneroTAGGeneros(arbolGeneros, idGenero) == true
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
TAGGeneros obtenerSubarbolTAGGeneros(TAGGeneros arbolGeneros, int idGenero);

// Función para obtener el mayor idGenero de un árbol de géneros
// Debe ejecutar en O(n) peor caso, siendo n la cantidad de géneros en el árbol.
int obtenerMaxTAGGeneros(TAGGeneros arbolGeneros);

// Función para obtener un conjunto de géneros a partir de árbol de géneros.
// El conjunto de géneros retornado esta formado por los géneros que pertenecen al 
// subarbol cuya raíz tiene el idGenero pasado por parámetro
TConjuntoGeneros obtenerConjuntoGeneros(TAGGeneros arbolGeneros, int idGenero);

 #endif // AGGENEROS_H
