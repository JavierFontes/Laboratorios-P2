#include "../include/colaDePrioridadReservas.h"

// La cola de prioridad debe implementarse con un HEAP.

// NOTA IMPORTANTE: Para evitar diferencias con las salidas esperadas de los tests:
// * El filtrado ascendente debe parar cuando se encuentra un elemento igual o más prioritario que el elemento filtrado.
// * El filtrado descendente debe parar cuando los hijos del elemento filtrado sean igual o menos prioritarios que el.
// * Si se dan empates de prioridad entre los hijos durante el filtrado descendente y corresponde continuar filtrando,
// se debe seguir el filtrado hacia la rama izquierda.

struct rep_colaDePrioridadReservas {
    // heap de hasta N elementos
    int *heap;

    // vector de posiciones;
    TReserva *pos;

    nat max;
    int tope;
    int crit; //0 minHeap, 1 maxHeap.

};

TColaDePrioridadReservas crearTColaDePrioridadReservas(nat N) {
    TColaDePrioridadReservas cp = new rep_colaDePrioridadReservas;
    cp->max = N;
    cp->tope = -1;
    cp->heap = new int[N];
    cp->crit = 0;

    cp->pos = new TReserva[N];
    for (nat i = 0; i < N; i++)
        cp->pos[i] = NULL;
    
    return cp;
}

void maxHeapify(int *heap, TReserva *pos, int i, int tope) {
    int izq = (2 * i) + 1;
    int der = (2 * i) + 2;
    int max = i;

    if (izq <= tope && heap[izq] > heap[max])
        max = izq;

    if (der <= tope && heap[der] > heap[max])
        max = der;

    if (max != i) {
        int aux = heap[i];
        heap[i] = heap[max];
        heap[max] = aux;

        TReserva r = pos[i];
        pos[i] = pos[max];
        pos[max] = r;

        maxHeapify(heap, pos, max, tope);
    }

}

void minHeapify(int *heap, TReserva *pos, int i, int tope) {
    int izq = (2 * i) + 1;
    int der = (2 * i) + 2;
    int min = i;

    if (izq <= tope && heap[izq] < heap[min])
        min = izq;

    if (der <= tope && heap[der] < heap[min])
        min = der;

    if (min != i) {
        int aux = heap[i];
        heap[i] = heap[min];
        heap[min] = aux;

        TReserva r = pos[i];
        pos[i] = pos[min];
        pos[min] = r;   
        
        minHeapify(heap, pos, min, tope);
    }
}

void invertirPrioridadTColaDePrioridadReservas(TColaDePrioridadReservas &cp) {
    //Si esta vacia no hacemos nada
    if (!estaVaciaTColaDePrioridadReservas(cp)){

        //Si es max-heap, lo convertimos en min-heap
        if (cp->crit == 1) {
            
            for (int i = (cp->tope / 2) - 1; i >= 0; i--) {
                minHeapify(cp->heap, cp->pos, i, cp->tope);
            }

            for (int i = cp->tope; i > 0; i--){
                int aux = cp->heap[0];
                cp->heap[0] = cp->heap[i];
                cp->heap[i] = aux;

                TReserva r = cp->pos[0];
                cp->pos[0] = cp->pos[i];
                cp->pos[i] = r;

                minHeapify(cp->heap, cp->pos, 0, i);
            } 
            cp->crit = 0;
        }
        //Si es min-heap, lo convertimos en max-heap
        else {
            for (int i = (cp->tope / 2) - 1; i >= 0; i--) {
                maxHeapify(cp->heap, cp->pos, i, cp->tope);
            }

            for (int i = cp->tope; i > 0; i--){
                int aux = cp->heap[0];
                cp->heap[0] = cp->heap[i];
                cp->heap[i] = aux;
            
                TReserva r = cp->pos[0];
                cp->pos[0] = cp->pos[i];
                cp->pos[i] = r;
                
                maxHeapify(cp->heap, cp->pos, 0, i);
            }

            cp->crit = 1;
        } 
    }
}

void liberarTColaDePrioridadReservas(TColaDePrioridadReservas &cp) {
    //Liberamos las reservas
    for (int i = 0; i <= cp->tope; i++)
        liberarTReserva(cp->pos[i]);

    //Liberamos los arrays
    delete [] cp->heap;
    delete [] cp->pos;

    delete cp;
    cp = NULL;
}

void insMinHeap(TColaDePrioridadReservas &cp, TReserva reserva) {
    //Agregamos la nueva reserva
    cp->tope++;
    cp->pos[cp->tope] = reserva;
    cp->heap[cp->tope] = rangoTSocio(socioTReserva(reserva));
    
    //Hacemos el filtrado ascendente;
    int iter = cp->tope;
    while (iter > 0 && cp->heap[iter] < cp->heap[(iter - 1)/2]){
        //Hacemos swap en Heap []
        int i = cp->heap[(iter - 1)/2];
        cp->heap[(iter - 1)/2] = cp->heap[iter];
        cp->heap[iter] = i;

        //Hacemos swap en Pos []
        TReserva r = cp->pos[(iter - 1)/2];
        cp->pos[(iter - 1)/2] = cp->pos[iter];
        cp->pos[iter] = r;
        
        //Subimos un nivel
        iter = (iter - 1)/2;
    }
}

void insMaxHeap(TColaDePrioridadReservas &cp, TReserva reserva) {
    //Agregamos la nueva reserva
    cp->tope++;
    cp->pos[cp->tope] = reserva;
    cp->heap[cp->tope] = rangoTSocio(socioTReserva(reserva));
    
    //Hacemos el filtrado ascendente:
    int iter = cp->tope;
    while (iter > 0 && cp->heap[iter] > cp->heap[(iter - 1)/2]){
        //Hacemos swap en Heap []
        int i = cp->heap[(iter - 1)/2];
        cp->heap[(iter - 1)/2] = cp->heap[iter];
        cp->heap[iter] = i;

        //Hacemos swap en Pos []
        TReserva r = cp->pos[(iter - 1)/2];
        cp->pos[(iter - 1)/2] = cp->pos[iter];
        cp->pos[iter] = r;
        
        //Subimos un nivel
        iter = (iter - 1)/2;
    }
}

void insertarTColaDePrioridadReservas(TColaDePrioridadReservas &cp, TReserva reserva) {
    //Si nos pasamos del maximo, no insertamos
    int max = cp->max;
    if (cp->tope + 1 < max){

        //Si el criterio es 0, se inserta como min heap
        if (cp->crit == 0)
            insMinHeap(cp, reserva);

        //Si el criterio es 1, se inserta como max heap
        else
            insMaxHeap(cp, reserva);
    }
}

bool estaVaciaTColaDePrioridadReservas(TColaDePrioridadReservas cp) {
    return (cp->tope == -1);
}

TReserva prioritarioTColaDePrioridadReservas(TColaDePrioridadReservas cp) {
    //El prioritario en cualquier heap es el que esta en la primera posicion.
    return cp->pos[0];
}

void eliminarPrioritarioTColaDePrioridadReservas(TColaDePrioridadReservas &cp) {
    if (!estaVaciaTColaDePrioridadReservas(cp)){
    //Hacemos swap entre el primer y ultimo elemento de ambos arrays:
        //Para [] heap
        int intAux = cp->heap[cp->tope];
        cp->heap[cp->tope] = cp->heap[0];
        cp->heap[0] = intAux;

        //Para [] pos
        TReserva rAux = cp->pos[cp->tope];
        cp->pos[cp->tope] = cp->pos[0];
        cp->pos[0] = rAux;

        //Borramos el ultimo
        liberarTReserva(cp->pos[cp->tope]);
        cp->tope--;

        //Si es min-heap, llamamos a minHeapify para reordenar
        if (cp->crit == 0)
            minHeapify(cp->heap, cp->pos, 0, cp->tope);

        //Analogo para max-heap
        else
            maxHeapify(cp->heap, cp->pos, 0 , cp->tope);
    }
}

bool auxEstaTColaDePrioridadReservas(TColaDePrioridadReservas cp, int ciSocio, int isbnLibro, int tope){
    //Si nos pasamos del tope de la cola de prioridad, no esta la reserva
    if (tope > cp->tope)
        return false;

    //Si coincide el ci y el isbn se devuelve true, sino se llama nuevamente sumando 1 al tope
    else {
        return ((ciTSocio(socioTReserva(cp->pos[tope])) == ciSocio) &&
                (isbnTLibro(libroTReserva(cp->pos[tope])) == isbnLibro)) ||
               auxEstaTColaDePrioridadReservas(cp, ciSocio, isbnLibro, tope + 1);
    }
}

bool estaTColaDePrioridadReservas(TColaDePrioridadReservas cp, int ciSocio, int isbnLibro) {
    return auxEstaTColaDePrioridadReservas(cp, ciSocio, isbnLibro, 0);
}

nat auxPrioridadTColaDePrioridadReservas(TColaDePrioridadReservas cp, int ciSocio, int isbnLibro, nat tope) {
    //Si coincide el ci y el isbn con la reserva, se retorna el rango del socio asociada dicha reserva
    if ((ciTSocio(socioTReserva(cp->pos[tope])) == ciSocio) && (isbnTLibro(libroTReserva(cp->pos[tope])) == isbnLibro))
        return rangoTSocio(socioTReserva(cp->pos[tope]));

    //Si no, se llama nuevamente aumentando el tope en 1
    else
        return auxPrioridadTColaDePrioridadReservas(cp, ciSocio, isbnLibro, tope + 1);
}

nat prioridadTColaDePrioridadReservas(TColaDePrioridadReservas cp, int ciSocio, int isbnLibro) {
    return auxPrioridadTColaDePrioridadReservas(cp, ciSocio, isbnLibro, 0);
}

TColaDePrioridadReservas copiarTColaDePrioridadReservas(TColaDePrioridadReservas cp) {
    TColaDePrioridadReservas copia = new rep_colaDePrioridadReservas;
    copia->max = cp->max;
    copia->tope = cp->tope;
    copia->crit = cp->crit;

    // Creamos arrays del mismo tamanio que los arrays de cp
    copia->heap = new int[cp->max];
    copia->pos = new TReserva[cp->max];

    // Copiar TODO el array pos (tamaño N)
    for (int i = 0; i <= cp->tope; i++) {
        copia->pos[i] = copiarTReserva(cp->pos[i]);
    }

    int max = cp->max;
    for (int i = cp->tope + 1; i < max; i++)
        copia->pos[i] = NULL;
    
    // Copiar el heap (elementos de 0 a tope)
    for (int i = 0; i <= copia->tope; i++) {
        copia->heap[i] = cp->heap[i];
    }
    
    return copia;
}   

void imprimirTColaDePrioridad(TColaDePrioridadReservas cp) {
    //Trabajamos sobre una copia de 'cp'
    TColaDePrioridadReservas copia = copiarTColaDePrioridadReservas(cp);

    //Mientras queden elementos por imprimir
    while (!estaVaciaTColaDePrioridadReservas(copia)){

        //Imprimimos el prioritario (la raiz)
        imprimirTReserva(prioritarioTColaDePrioridadReservas(copia));

        //Borramos el prioritario (la raiz)
        eliminarPrioritarioTColaDePrioridadReservas(copia);
    }

    //Liberamos la copia
    liberarTColaDePrioridadReservas(copia);
}


