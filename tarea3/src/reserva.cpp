#include "../include/reserva.h"
#include "../include/ldePrestamos.h"
#include "../include/prestamo.h"
#include "../include/socio.h"
#include "../include/libro.h"
#include "../include/fecha.h"

struct rep_reserva {
  TSocio socio;
  TLibro libro;
};

TReserva crearTReserva(TSocio socio, TLibro libro){
  TReserva nuevo = new rep_reserva;
  nuevo->socio = socio;
  nuevo->libro = libro;

  return nuevo;
}

void imprimirTReserva(TReserva reserva){
  printf("Reserva de libro %s por %s %s.\n", tituloTLibro(reserva->libro), 
          nombreTSocio(reserva->socio), apellidoTSocio(reserva->socio));
}

void liberarTReserva(TReserva &reserva){
  liberarTSocio(reserva->socio);
  liberarTLibro(reserva->libro);
  delete reserva;
  reserva = NULL;
}

TSocio socioTReserva(TReserva reserva){
  return reserva->socio;
}

TLibro libroTReserva(TReserva reserva){
  return reserva->libro;
}

TReserva copiarTReserva(TReserva reserva){
  TReserva copia = new rep_reserva;
  copia->libro = copiarTLibro(reserva->libro);
  copia->socio = copiarTSocio(reserva->socio);
  return copia;
}

void liberarTReservaSoloEstructura(TReserva &reserva) {
  if (reserva != NULL){
    delete reserva;
    reserva = NULL;
  }
}
