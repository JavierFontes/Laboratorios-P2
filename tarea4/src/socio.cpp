#include "../include/socio.h"
#include "../include/libro.h"
#include "../include/fecha.h"

struct rep_socio {
    int ci;
    char nombre[MAX_NOMBRE_SOCIO];
    char apellido[MAX_APELLIDO_SOCIO];
    TFecha fechaAlta;
    int generosFav[MAX_GENEROS_FAVORITOS];
    int tope;
    int rango;
};

TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta, nat rango){
    TSocio nuevoSocio = new rep_socio;
    nuevoSocio->ci = ci;
    strcpy(nuevoSocio->nombre,nombre);
    strcpy(nuevoSocio->apellido, apellido);
    nuevoSocio->fechaAlta = crearTFecha(diaAlta, mesAlta, anioAlta);
    nuevoSocio->tope = 0;
    nuevoSocio->rango = rango;
    
    return nuevoSocio;
}

void imprimirTSocio(TSocio socio){
    printf("Socio %d: %s %s\n", socio->ci, socio->nombre, socio->apellido);
    printf("Fecha de alta: ");
    imprimirTFecha(socio->fechaAlta);
    
    printf("Géneros favoritos: ");
    for (int i = 0; i < socio->tope; i++) {
        printf("%d ", socio->generosFav[i]);
    }
    printf("\n");
}

void liberarTSocio(TSocio &socio){
    liberarTFecha(socio->fechaAlta);
    delete socio;
    socio = NULL;
}

int ciTSocio(TSocio socio){
    return socio->ci;
}

char* nombreTSocio(TSocio socio){
    return socio->nombre;
}

char* apellidoTSocio(TSocio socio){
    return socio->apellido;
}

TFecha fechaAltaTSocio(TSocio socio){
    return socio->fechaAlta;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero){
    if (socio->tope < MAX_GENEROS_FAVORITOS) {
        socio->generosFav[socio->tope] = idGenero;
        socio->tope++;
    }
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero){
    if (socio->tope == 0) {
        return false;
    }
    int i = 0;
    while (i < socio->tope && socio->generosFav[i] != idGenero) {
        i++;
    }
    return i < socio->tope;
}

int cantidadGenerosFavoritosTSocio(TSocio socio){
    int cont = 0;
    int i = 0;
    while (i < socio->tope) {
        cont++;
        i++;
    }
    return cont;
}

TSocio copiarTSocio(TSocio socio){
    TSocio copiaSocio = new rep_socio;
    strcpy(copiaSocio->nombre, socio->nombre);
    strcpy(copiaSocio->apellido, socio->apellido);
    copiaSocio->ci = socio->ci;
    copiaSocio->tope = socio->tope;
    copiaSocio->rango = socio->rango;

    int i = 0;
    while(i < socio->tope) {
        copiaSocio->generosFav[i] = socio->generosFav[i];
        i++;
    }

    copiaSocio->fechaAlta = copiarTFecha(socio->fechaAlta);

    return copiaSocio;
}

nat rangoTSocio(TSocio socio) {
    return socio->rango;
  }
