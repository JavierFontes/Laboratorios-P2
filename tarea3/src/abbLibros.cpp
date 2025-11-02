#include "../include/abbLibros.h"
#include "../include/ldePrestamos.h"
#include "../include/prestamo.h"
#include "../include/socio.h"
#include "../include/libro.h"
#include "../include/fecha.h"

struct rep_abbLibros {
    TLibro libro;
    rep_abbLibros * izq, * der;
};

TABBLibros crearTABBLibrosVacio(){
    return NULL;
}

void insertarLibroTABBLibros(TABBLibros &abbLibros, TLibro libro){
    if (abbLibros == NULL) {
        abbLibros = new rep_abbLibros;
        abbLibros->libro = libro;
        abbLibros->izq = abbLibros->der = NULL;
    }
    else if (isbnTLibro(abbLibros->libro) < isbnTLibro(libro))
        insertarLibroTABBLibros(abbLibros->der, libro);
    else if (isbnTLibro(abbLibros->libro) > isbnTLibro(libro))
        insertarLibroTABBLibros(abbLibros->izq, libro);
}

void imprimirTABBLibros(TABBLibros abbLibros){
    if (abbLibros != NULL) {
        imprimirTABBLibros(abbLibros->izq);
        imprimirTLibro(abbLibros->libro);
        imprimirTABBLibros(abbLibros->der);
    }
}

void liberarTABBLibros(TABBLibros &abbLibros){
    if (abbLibros != NULL) {
        liberarTABBLibros(abbLibros->izq);
        liberarTABBLibros(abbLibros->der);

        liberarTLibro(abbLibros->libro);
        delete abbLibros;
        abbLibros = NULL;
    }
}

bool existeLibroTABBLibros(TABBLibros abbLibros, int isbn){
    if (abbLibros == NULL) {
        return false;
    }
    else if (isbnTLibro(abbLibros->libro) == isbn) {
        return true;
    }
    else if (isbnTLibro(abbLibros->libro) < isbn) {
        return existeLibroTABBLibros(abbLibros->der, isbn);
    }
    else {
        return existeLibroTABBLibros(abbLibros->izq, isbn);
    }
}

TLibro obtenerLibroTABBLibros(TABBLibros abbLibros, int isbn){
    if (isbnTLibro(abbLibros->libro) == isbn)
        return abbLibros->libro;
    else if (isbnTLibro(abbLibros->libro) < isbn) 
        return obtenerLibroTABBLibros(abbLibros->der, isbn);
    else 
        return obtenerLibroTABBLibros(abbLibros->izq, isbn);

}

nat max(nat num1, nat num2) {
    if (num1 > num2 || num1 == num2) 
        return num1;
    else
        return num2;
}
nat alturaTABBLibros(TABBLibros abbLibros){
    if (abbLibros == NULL) 
        return 0;
    else 
        return 1 + max(alturaTABBLibros(abbLibros->izq), alturaTABBLibros(abbLibros->der)); 
}

TLibro maxISBNLibroTABBLibros(TABBLibros abbLibros){
    if (abbLibros->der == NULL) 
        return abbLibros->libro;
    else 
        return maxISBNLibroTABBLibros(abbLibros->der);
}

void removerLibroTABBLibros(TABBLibros &abbLibros, int isbn){
    if (abbLibros != NULL) {
        if (isbn < isbnTLibro(abbLibros->libro))
            removerLibroTABBLibros(abbLibros->izq, isbn);
        else if (isbn > isbnTLibro(abbLibros->libro))
            removerLibroTABBLibros(abbLibros->der, isbn);
        else {
            if (abbLibros->der == NULL) {
                TABBLibros aBorrar = abbLibros;
                abbLibros = abbLibros->izq;
                liberarTLibro(aBorrar->libro);
                delete aBorrar;
            }
            else if (abbLibros->izq == NULL) {
                TABBLibros aBorrar = abbLibros;
                abbLibros = abbLibros->der;
                liberarTLibro(aBorrar->libro);
                delete aBorrar;
            }
            else {
                TABBLibros minDer = abbLibros->der;
                while (minDer->izq != NULL) {
                    minDer = minDer->izq;
                }
                liberarTLibro(abbLibros->libro);
                abbLibros->libro = copiarTLibro(minDer->libro);

                removerLibroTABBLibros(abbLibros->der, isbnTLibro(minDer->libro));
                
            }
        }
    }
}

int cantidadTABBLibros(TABBLibros abbLibros){
    if (abbLibros == NULL) 
        return 0;
    else {
        return 1 + cantidadTABBLibros(abbLibros->izq) + cantidadTABBLibros(abbLibros->der);
    }
}

void obtenerNesimoLibroTABBLibrosAux(TABBLibros abbLibros, int n, int &k, TLibro &res){
    if (abbLibros != NULL && k != n) {
        obtenerNesimoLibroTABBLibrosAux(abbLibros->izq, n, k, res);
        k++;
        if (k == n) {
            res = abbLibros->libro;
        }
        obtenerNesimoLibroTABBLibrosAux(abbLibros->der, n, k, res);
    }
}

TLibro obtenerNesimoLibroTABBLibros(TABBLibros abbLibros, int n){
    int k = 0;
    TLibro res = NULL;
    obtenerNesimoLibroTABBLibrosAux(abbLibros, n, k, res);
    return res;
}

void filtradoPorGeneroTABBLibrosAux(TABBLibros abbLibros, TABBLibros &nuevo, int genero) {
    if (abbLibros != NULL) {
        filtradoPorGeneroTABBLibrosAux(abbLibros->izq, nuevo, genero);
        if (idGeneroTLibro(abbLibros->libro) == genero) {
            TLibro copia = copiarTLibro(abbLibros->libro);
            insertarLibroTABBLibros(nuevo, copia);
        }
        filtradoPorGeneroTABBLibrosAux(abbLibros->der, nuevo, genero);
    }
}

TABBLibros filtradoPorGeneroTABBLibros(TABBLibros abbLibros, int genero) {
    TABBLibros copiaGenero = NULL;
    filtradoPorGeneroTABBLibrosAux(abbLibros, copiaGenero, genero);
    return copiaGenero;
}