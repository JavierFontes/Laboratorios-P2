
#include "../include/lseSocios.h"
#include "../include/socio.h"
#include "../include/libro.h"
#include "../include/fecha.h"

struct rep_lseSocios {
	TSocio socio;
	rep_lseSocios * sig;
};

TLSESocios crearTLSESociosVacia(){
	return NULL;
}

bool esVaciaTLSESocios(TLSESocios lseSocios){
	return (lseSocios == NULL);
}

void imprimirTLSESocios(TLSESocios lseSocios){
	printf("Lista de Socios:\n");
	while (lseSocios != NULL) {
		imprimirTSocio(lseSocios->socio);
		lseSocios = lseSocios->sig;
	}
}


void liberarTLSESocios(TLSESocios &lseSocios){
	while (lseSocios != NULL) {
		TLSESocios aux = lseSocios->sig;
		liberarTSocio(lseSocios->socio);
		delete(lseSocios);
		lseSocios = aux;
	}
}



void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){
	if (lseSocios == NULL || compararTFechas(fechaAltaTSocio(lseSocios->socio), fechaAltaTSocio(socio)) == 1) {
		TLSESocios aux = new rep_lseSocios;
		aux->socio = socio;
		aux->sig = lseSocios;
		lseSocios = aux;
	} else {
		TLSESocios auxlst = lseSocios;
		while (auxlst->sig != NULL && compararTFechas(fechaAltaTSocio(auxlst->sig->socio), fechaAltaTSocio(socio)) <= 0) {
			auxlst = auxlst->sig;

		}
		TLSESocios aux = new rep_lseSocios;
		aux->socio = socio;

		if (auxlst->sig != NULL) {
			aux->sig = auxlst->sig;
			auxlst->sig = aux;
		} else {
			aux->sig = NULL;
			auxlst->sig = aux;
		}
	
	}
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	bool existe = false;
	while (lseSocios != NULL && !existe) {
		existe = ciTSocio(lseSocios->socio) == ci;
		lseSocios = lseSocios->sig;
	}
	return existe;
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci) {
    // Buscar el socio con la CI indicada
    while (lseSocios != NULL && ciTSocio(lseSocios->socio) != ci) {
        lseSocios = lseSocios->sig;
    }

    return lseSocios->socio;
}


TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n){
	int cont = 1;
	while (lseSocios != NULL && cont != n) {
		cont++;
		lseSocios = lseSocios->sig;
	}
	return lseSocios->socio;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	int cont = 0;
	while (lseSocios != NULL) {
		cont++;
		lseSocios = lseSocios->sig;
	}
	return cont;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
	//CASO 1: El socio a remover es el primero
	if (ciTSocio(lseSocios->socio) == ci) {
			TLSESocios aux = lseSocios;
			lseSocios = lseSocios->sig;

			liberarTSocio(aux->socio);
			delete(aux);
			aux = NULL;
			return;
	}	 

	TLSESocios aux = lseSocios;
	while (aux->sig != NULL && ciTSocio(aux->sig->socio) != ci)
		aux = aux->sig;
	
	
	//CASO 2: El socio a remover esta en el medio
	if (aux->sig != NULL) {
		TLSESocios borrar = aux->sig;
		aux->sig = borrar->sig;

		liberarTSocio(borrar->socio);
		delete(borrar);
		borrar = NULL;
	
	//CASO 3: El socio a remover esta al final
	} else {
		liberarTSocio(aux->socio);
		delete(aux->sig);
		aux->sig = NULL;
	}
}