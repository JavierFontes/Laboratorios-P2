#include "../include/ldePrestamos.h"
#include "../include/prestamo.h"
#include "../include/socio.h"
#include "../include/libro.h"
#include "../include/fecha.h"

struct nodoDoble{
    TPrestamo prestamo;
    nodoDoble * sig;
    nodoDoble * ant;
};

struct rep_ldePrestamos {
    int cantidad;
    nodoDoble * inicio;
    nodoDoble * final;
};

TLDEPrestamos crearTLDEPrestamosVacia(){
    TLDEPrestamos vacia = new rep_ldePrestamos;
    vacia->inicio = NULL;
    vacia->final = NULL;
    vacia->cantidad = 0;
    return vacia;
}

void insertarTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo){
    nodoDoble * nuevo = new nodoDoble;
    nuevo->prestamo = prestamo;
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    //CASO 1: Lista Vacia (Se inserta al principio)
    if (ldePrestamos->inicio == NULL && ldePrestamos->final == NULL) {
        ldePrestamos->inicio = nuevo;
        ldePrestamos->final = nuevo;
    }
    //CASO 2: Todos los elementos tienen fecha mayor (Se inserta al principio)
    else if (compararTFechas(fechaRetiroTPrestamo(ldePrestamos->inicio->prestamo), fechaRetiroTPrestamo(prestamo)) == 1) {
        nuevo->sig = ldePrestamos->inicio;
        ldePrestamos->inicio->ant = nuevo;
        ldePrestamos->inicio = nuevo;
    }
    else {

        // CASO 3: Insertar en el medio o al final
        nodoDoble *actual = ldePrestamos->final;
        while (actual != NULL && compararTFechas(fechaRetiroTPrestamo(actual->prestamo), fechaRetiroTPrestamo(prestamo)) > 0) {
            actual = actual->ant;
        }
        if (actual == NULL) {
            nuevo->sig = ldePrestamos->inicio;
            ldePrestamos->inicio->ant = nuevo;
            ldePrestamos->inicio = nuevo;
        }
        else {
        nodoDoble *siguiente = actual->sig;
        nuevo->sig = siguiente;
        nuevo->ant = actual;
        actual->sig = nuevo;
        
        if (siguiente != NULL) { siguiente->ant = nuevo;}
        else { ldePrestamos->final = nuevo;}
        }
    }
    ldePrestamos->cantidad++;
}

void liberarTLDEPrestamos(TLDEPrestamos &ldePrestamos) {
    nodoDoble *actual = ldePrestamos->inicio;
    while (actual != NULL) {
        nodoDoble *aBorrar = actual;
        actual = actual->sig;

        liberarTPrestamo(aBorrar->prestamo); 
        delete aBorrar;
    }

    delete ldePrestamos; 
    ldePrestamos = NULL;
}

void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos) {
    printf("LDE Préstamos:\n");
    nodoDoble* aux = ldePrestamos->inicio;  // Usamos auxiliar
    while (aux != NULL) {
        imprimirTPrestamo(aux->prestamo);
        aux = aux->sig;
    }
}

void imprimirInvertidoTLDEPrestamos(TLDEPrestamos ldePrestamos) {
    printf("LDE Préstamos:\n");
    nodoDoble* aux = ldePrestamos->final;  // Usamos auxiliar
    while (aux != NULL) {
        imprimirTPrestamo(aux->prestamo);
        aux = aux->ant;
    }
}


nat cantidadTLDEPrestamos(TLDEPrestamos ldePrestamos){
    return ldePrestamos->cantidad;;
}

TPrestamo obtenerPrimeroTLDEPrestamos(TLDEPrestamos ldePrestamos){
    return ldePrestamos->inicio->prestamo;
}

TPrestamo obtenerUltimoTLDEPrestamos(TLDEPrestamos ldePrestamos){
    return ldePrestamos->final->prestamo;
}

TPrestamo obtenerNesimoTLDEPrestamos(TLDEPrestamos &ldePrestamos, int n){
    nodoDoble * aux = ldePrestamos->inicio;
    int cont = 1;
    while (aux != NULL && cont != n) {
        aux = aux->sig;
        cont++;
    }
    return aux->prestamo;
}

void insertarUltimoTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo){
    nodoDoble * nuevo = new nodoDoble;
    nuevo->prestamo = prestamo;
    nuevo->sig = NULL;
    nuevo->ant = ldePrestamos->final;

    if (ldePrestamos->final != NULL) {
        ldePrestamos->final->sig = nuevo;
    }
    else {
        ldePrestamos->inicio = nuevo;
    }

    ldePrestamos->final = nuevo;
    ldePrestamos->cantidad++;
}

// criterio = 0 -> prestamos retornados
// criterio = 1 -> prestamos no retornados
TLDEPrestamos filtrarPrestamosTLDEPrestamos(TLDEPrestamos &ldePrestamos, int criterio) {
    TLDEPrestamos nueva = new rep_ldePrestamos;
    nueva->inicio = nueva->final = NULL;
    nueva->cantidad = 0;

    nodoDoble *aux = ldePrestamos->inicio;
    while (aux != NULL) {
        bool cumple = false;
        bool fueRet = fueRetornadoTPrestamo(aux->prestamo);

        if ((criterio == 0 && fueRet) || (criterio == 1 && !fueRet)) {
            cumple = true;
        }
        if (cumple) {
            insertarUltimoTLDEPrestamos(nueva, copiarTPrestamo(aux->prestamo));
        }
        aux = aux->sig;
    }
    return nueva;
}

void liberarTLDEPrestamosSoloEstructura(TLDEPrestamos &ldePrestamos){
    if (ldePrestamos != NULL){

    nodoDoble * actual = ldePrestamos->inicio;
    while (actual != NULL) {
        nodoDoble *aBorrar = actual;
        actual = actual->sig;

        liberarTPrestamoSoloEstructura(aBorrar->prestamo);
        delete aBorrar;
    }

    delete ldePrestamos;
    ldePrestamos = NULL;
    }
}