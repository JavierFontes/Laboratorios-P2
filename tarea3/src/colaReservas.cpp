#include "../include/colaReservas.h"
#include "../include/reserva.h"

struct nodoCola {
  TReserva reserva;
  nodoCola *sig;
};

struct rep_colaReservas {
  nodoCola * primero, * ultimo;
  nat cantidad;
};

TColaReservas crearTColaReservas() {
  TColaReservas cola = new rep_colaReservas;
  cola->primero = NULL;
  cola->ultimo = NULL;
  cola->cantidad = 0;
  return cola;
}


void encolarTColaReservas(TColaReservas &colaReservas, TReserva reserva){
  if (colaReservas == NULL )
    return;
  nodoCola *nuevo = new nodoCola;
  nuevo->reserva = reserva;
  nuevo->sig = NULL;
  if (colaReservas->primero == NULL) {
    colaReservas->primero = nuevo;
  } else {
    colaReservas->ultimo->sig = nuevo;
  }
  colaReservas->ultimo = nuevo;
  colaReservas->cantidad++;
}


void desencolarTColaReservas(TColaReservas &colaReservas) {
  if (colaReservas != NULL){
    nodoCola *aBorrar = colaReservas->primero;
    colaReservas->primero = colaReservas->primero->sig;

    if (colaReservas->primero == NULL)
      colaReservas->ultimo = NULL;
    colaReservas->cantidad--;

    liberarTReserva(aBorrar->reserva);
    delete aBorrar;
    aBorrar = NULL;
  }
}

TReserva frenteTColaReservas(TColaReservas colaReservas) {
    if (colaReservas == NULL)
      return NULL;
    else
      return colaReservas->primero->reserva;
}

nat cantidadTColaReservas(TColaReservas colaReservas){
  if (colaReservas == NULL) {
    return 0;
  }
  else {
    return colaReservas->cantidad;
  }
}

void imprimirTColaReservas(TColaReservas colaReservas){
  printf("Cola de Reservas:\n");
  if (colaReservas != NULL){
    nodoCola *aux = colaReservas->primero;
    while (aux != NULL){
      imprimirTReserva(aux->reserva);
      aux = aux->sig;
    }
  }
}

void liberarTColaReservas(TColaReservas &colaReservas) {
  if (colaReservas != NULL){
    while (colaReservas->primero != NULL){
      nodoCola *aBorrar = colaReservas->primero;
      liberarTReserva(aBorrar->reserva);
      
      colaReservas->primero = colaReservas->primero->sig;
      delete aBorrar;
      aBorrar = NULL;
    }
    colaReservas->ultimo = NULL;
    delete colaReservas;
    colaReservas = NULL;
  }
}

void liberarTColaReservasSoloEstructura(TColaReservas &colaReservas) {
  if (colaReservas != NULL){
    while (colaReservas->primero != NULL) {
      nodoCola *aBorrar = colaReservas->primero;
      colaReservas->primero = colaReservas->primero->sig;
      colaReservas->cantidad--;

      liberarTReservaSoloEstructura(aBorrar->reserva);
      delete aBorrar;
      aBorrar = NULL;
    }
    delete colaReservas;
    colaReservas = NULL;
  }
}

TReserva extraerFrenteTColaReservas(TColaReservas &colaReservas) {
  if (colaReservas == NULL || colaReservas->primero == NULL){
    return NULL;
  }
  else {
    nodoCola *aBorrar = colaReservas->primero;
    TReserva frente = aBorrar->reserva;

    colaReservas->primero = aBorrar->sig;
    if (colaReservas->primero == NULL)
      colaReservas->ultimo = NULL;
    
    colaReservas->cantidad--;
    delete aBorrar;
    
    return frente;
  }
}
