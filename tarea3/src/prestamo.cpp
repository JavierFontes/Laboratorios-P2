#include "../include/prestamo.h"
#include "../include/socio.h"
#include "../include/libro.h"
#include "../include/fecha.h"

struct rep_prestamo {
  TSocio socioP;
  TLibro libroP;
  TFecha fechaRetiro;
  TFecha fechaDevolucion;
};

TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro) {
  TPrestamo prestamo = new rep_prestamo;

  prestamo->socioP = socio;
  prestamo->libroP = libro;
  prestamo->fechaRetiro = fechaRetiro;
  prestamo->fechaDevolucion = NULL;

  return prestamo;
}
 
void imprimirTPrestamo(TPrestamo prestamo){
  printf("Préstamo de libro %s a %s %s.\n", tituloTLibro(prestamo->libroP), nombreTSocio(prestamo->socioP), apellidoTSocio(prestamo->socioP));
  
  imprimirTFecha(prestamo->fechaRetiro);

  if (prestamo->fechaDevolucion == NULL) {
    printf("No retornado\n");
  } else {
    imprimirTFecha(prestamo->fechaDevolucion);
  }
}

void liberarTPrestamo(TPrestamo &prestamo){
  liberarTSocio(prestamo->socioP);
  liberarTLibro(prestamo->libroP);
  liberarTFecha(prestamo->fechaRetiro);
  liberarTFecha(prestamo->fechaDevolucion);
  delete prestamo;
  prestamo = NULL;
}

TSocio socioTPrestamo(TPrestamo prestamo){
  return prestamo->socioP;
}
 
TFecha fechaRetiroTPrestamo(TPrestamo prestamo){
  return prestamo->fechaRetiro;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo){
  return prestamo->fechaDevolucion;
}

TLibro libroTPrestamo(TPrestamo prestamo){
  return prestamo->libroP;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo){
  return prestamo->fechaDevolucion != NULL;
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion) {
  if (prestamo->fechaDevolucion != NULL) {
      liberarTFecha(prestamo->fechaDevolucion);
  }
  prestamo->fechaDevolucion = fechaDevolucion;
}


TPrestamo copiarTPrestamo(TPrestamo prestamo){
  TPrestamo copia = new rep_prestamo;
  copia->socioP = copiarTSocio(socioTPrestamo(prestamo));
  copia->libroP = copiarTLibro(libroTPrestamo(prestamo));
  copia->fechaRetiro = copiarTFecha(fechaRetiroTPrestamo(prestamo));
  if (fechaDevolucionTPrestamo(prestamo) != NULL) {
    copia->fechaDevolucion = copiarTFecha(fechaDevolucionTPrestamo(prestamo));
  } else {
    copia->fechaDevolucion = NULL;
  }
  return copia;
}

void liberarTPrestamoSoloEstructura(TPrestamo &prestamo){
  if (prestamo != NULL) {

    if (fechaRetiroTPrestamo(prestamo) != NULL)
      liberarTFecha(prestamo->fechaRetiro);

    if (fechaDevolucionTPrestamo(prestamo) != NULL)
      liberarTFecha(prestamo->fechaDevolucion);
    
    delete prestamo;
    prestamo = NULL;
  }
}