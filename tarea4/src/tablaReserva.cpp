#include "../include/tablaReserva.h"

// Se debe implementar mediante una tabla de dispersión abierta (hash)

struct nodoHash{
    int isbn; //key
    TColaDePrioridadReservas cp; //valor
    bool ocupado;
};

struct rep_tablaTablaReserva {
    nodoHash* tabla;

    int max; //tamanio estimado
    int cant; //cantidad colas de prioridad
    int maxCola; //cantidad maximas de reservas para cada cola de prioridad
};


TTablaReserva crearTTablaReserva(int max, int N){
    TTablaReserva tabla = new rep_tablaTablaReserva;
    tabla->cant = 0;
    tabla->maxCola = N;
    tabla->max = max;

    //Creamos el array de nodos Hash
    tabla->tabla = new nodoHash[max];

    //Para cada nodo hash: 
    //  -la cola de prioridad se inicializa en NULL
    //  -el isbn se inicializa en 0
    //  -el bool ocupado se inicializa en false.
    for (int i = 0; i < max; i++) {
        tabla->tabla[i].cp = NULL;
        tabla->tabla[i].isbn = 0;
        tabla->tabla[i].ocupado = false;
    }

    return tabla;
}

void insertarTTablaReserva(TTablaReserva &tabla, int isbn, TReserva reserva){
    //Calculamos la pos hash inicial
    int pos = isbn % tabla->max;

    //Mientras la posicion este ocupada y el isbn no coincida actualizamos la pos hash
    while (tabla->tabla[pos].ocupado && tabla->tabla[pos].isbn != isbn){
        pos = (pos + 1) % tabla->max;
    }

    //Si no esta ocupado, entonces debemos crear una cola de prioridad vacia
    if (!tabla->tabla[pos].ocupado)
        tabla->tabla[pos].cp = crearTColaDePrioridadReservas(tabla->maxCola);

    //Insertamos la reserva, asignamos el isbn y marcamos como ocupado.
    insertarTColaDePrioridadReservas(tabla->tabla[pos].cp, reserva);
    tabla->tabla[pos].isbn = isbn;
    tabla->tabla[pos].ocupado = true;
}

bool perteneceTTablaReserva(TTablaReserva tabla, int ciSocio, int isbnLibro) {
    //Calculamos la pos hash inicial
    int pos = isbnLibro % tabla->max;
    
    //Mientras no estemos en una posicion vacia
    while (tabla->tabla[pos].ocupado) {

        //Si el isbn es el mismo, buscamos en esta cola
        if (tabla->tabla[pos].isbn == isbnLibro)
            return estaTColaDePrioridadReservas(tabla->tabla[pos].cp, ciSocio, isbnLibro);

        //Si no coincide el isbn avanzamos la pos hash
        pos = (pos + 1) % tabla->max;
    }

    //Si salimos llegamos a una pos vacia(el libro no esta)
    return false;
}


TColaDePrioridadReservas obtenerReservaTTablaReserva(TTablaReserva tabla, int isbn){
    //Calculamos la pos hash inicial
    int pos = isbn % tabla->max;

    //Si esta ocupado pero el isbn no coincide actualizamos la pos hash
    while (tabla->tabla[pos].ocupado && tabla->tabla[pos].isbn != isbn){
        pos = (pos + 1) % tabla->max;
    }

    //Si llegamos a una pos desocupada no hay cola de prioridad
    if (!tabla->tabla[pos].ocupado)
        return NULL;

    return tabla->tabla[pos].cp;
}

TReserva obtenerSigReservaTTablaReserva(TTablaReserva tabla, int isbn){
    //La primer reserva de una cola de prioridad siempre es la prioritaria.
    return prioritarioTColaDePrioridadReservas(obtenerReservaTTablaReserva(tabla, isbn));
}

void liberarTTablaReserva(TTablaReserva &tabla){
    //Para cada nodo hash de la tabla, si esta ocupado se libera la cola de prioridad
    for (int i = 0; i < tabla->max; i++)
        if (tabla->tabla[i].ocupado)
            liberarTColaDePrioridadReservas(tabla->tabla[i].cp);

    delete [] tabla->tabla;
    delete tabla;
    tabla = NULL;
}
