#include "../include/agGeneros.h"
#include "../include/conjuntoGeneros.h"
#include <assert.h>


struct rep_agGeneros {
  int idGenero;
  char nombreGenero[MAX_NOMBRE];
  rep_agGeneros *sH;
  rep_agGeneros *pH;
};

TAGGeneros crearTAGGeneros(){
  return NULL;
}

TAGGeneros buscar(TAGGeneros arbolGeneros, int idGenero) {
  if (arbolGeneros == NULL)
    return NULL;

  if (arbolGeneros->idGenero == idGenero)
    return arbolGeneros;

  TAGGeneros estapH = buscar(arbolGeneros->pH, idGenero);
  if (estapH != NULL)
    return estapH;

  return buscar(arbolGeneros->sH, idGenero);
}


void insertarGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGeneroPadre, int idGenero, const char nombreGenero[MAX_NOMBRE] ){
  TAGGeneros nuevo = new rep_agGeneros;
    nuevo->idGenero = idGenero;
    strcpy(nuevo->nombreGenero, nombreGenero);
    nuevo->pH = NULL;
    nuevo->sH = NULL;
    
  if (idGeneroPadre != -1){
    TAGGeneros nodoPadre = buscar(arbolGeneros, idGeneroPadre);
    if (nodoPadre != NULL) {
      nuevo->sH = nodoPadre->pH;
      nodoPadre->pH = nuevo;
    }
    else {
      delete nuevo;
    }
  } 
  else {
    arbolGeneros = nuevo;
  }
}

void imprimirTAGGenerosAux(TAGGeneros arbolGeneros, int nivel) {
  if (arbolGeneros != NULL){
    for (int i = 0; i < nivel; i++)
      printf("    ");
    
    printf("%d - %s\n", arbolGeneros->idGenero, arbolGeneros->nombreGenero);
    
    imprimirTAGGenerosAux(arbolGeneros->pH, nivel + 1);
    imprimirTAGGenerosAux(arbolGeneros->sH, nivel);
  }

}
void imprimirTAGGeneros(TAGGeneros arbolGeneros){
  printf("Árbol de géneros:\n");
  imprimirTAGGenerosAux(arbolGeneros, 0);
}

void liberarTAGGenerosAux(TAGGeneros arbolGeneros){
  if (arbolGeneros != NULL){
    liberarTAGGenerosAux(arbolGeneros->sH);
    liberarTAGGenerosAux(arbolGeneros->pH);
    delete arbolGeneros;
    arbolGeneros = NULL;
  }
}

void liberarTAGGeneros(TAGGeneros &arbolGeneros){
  liberarTAGGenerosAux(arbolGeneros);
  arbolGeneros = NULL;
}

bool existeGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero){
  if (arbolGeneros == NULL){
    return false;
  }
  else {

    if (arbolGeneros->idGenero == idGenero){
      return true;
    }
    else {
      return existeGeneroTAGGeneros(arbolGeneros->pH, idGenero) || 
             existeGeneroTAGGeneros(arbolGeneros->sH, idGenero);
    }
  }
}

char* nombreGeneroTAGGeneros(TAGGeneros arbolGeneros, int idGenero){
  TAGGeneros aux = buscar(arbolGeneros, idGenero);
  return aux->nombreGenero;
}

nat max(int a, int b){
  if (a >= b)
    return a;
  else 
    return b;
}

nat min(int a, int b){
  if (a <= b)
    return a;
  else
    return b;
}

nat alturaTAGGeneros(TAGGeneros arbolGeneros){
  if (arbolGeneros == NULL){
    return 0;
  }
  else {
    return max(1+ alturaTAGGeneros(arbolGeneros->pH), alturaTAGGeneros(arbolGeneros->sH));
  }
}

nat cantidadTAGGeneros(TAGGeneros arbolGeneros){
  if (arbolGeneros == NULL){
    return 0;
  }
  else {
  return 1 + cantidadTAGGeneros(arbolGeneros->pH) + cantidadTAGGeneros(arbolGeneros->sH);
  }
}

TAGGeneros obtenerSubarbolTAGGeneros(TAGGeneros arbolGeneros, int idGenero) {
  if (arbolGeneros == NULL)
    return NULL;

  if (arbolGeneros->idGenero == idGenero)
    return arbolGeneros;

  TAGGeneros aux = obtenerSubarbolTAGGeneros(arbolGeneros->pH, idGenero);
  if (aux != NULL)
    return aux;

  return obtenerSubarbolTAGGeneros(arbolGeneros->sH, idGenero);
}



void obtenerConjuntoGenerosAux(TAGGeneros arbolGeneros, TConjuntoGeneros &c) {
  if (arbolGeneros != NULL) {
    insertarTConjuntoGeneros(c, arbolGeneros->idGenero);
    obtenerConjuntoGenerosAux(arbolGeneros->pH, c);
    obtenerConjuntoGenerosAux(arbolGeneros->sH, c);

  }
}

TConjuntoGeneros obtenerConjuntoGeneros(TAGGeneros arbolGeneros, int idGenero) {
  TAGGeneros aux = obtenerSubarbolTAGGeneros(arbolGeneros, idGenero);
  TConjuntoGeneros c = crearTConjuntoGeneros(obtenerMaxTAGGeneros(aux) + 1);
  obtenerConjuntoGenerosAux(aux, c);

  return c;
}

int obtenerMaxTAGGenerosAux(TAGGeneros arbolGeneros) {
  if (arbolGeneros == NULL) {
    return 0;
  } 
  else {
    int maxPH = obtenerMaxTAGGenerosAux(arbolGeneros->pH);
    int maxSH = obtenerMaxTAGGenerosAux(arbolGeneros->sH);
    
    return max(arbolGeneros->idGenero, max(maxPH, maxSH));
  }
}

int obtenerMaxTAGGeneros(TAGGeneros arbolGeneros) {
  return obtenerMaxTAGGenerosAux(arbolGeneros);
}

void removerGeneroTAGGeneros(TAGGeneros &arbolGeneros, int idGenero) {
  if (arbolGeneros != NULL && arbolGeneros->idGenero == idGenero) {
      TAGGeneros aBorrar = arbolGeneros;
      arbolGeneros = arbolGeneros->sH;
      aBorrar->sH = NULL; 
      liberarTAGGeneros(aBorrar);

      return;
  }
  
  if (arbolGeneros != NULL) {
    removerGeneroTAGGeneros(arbolGeneros->pH, idGenero);
    TAGGeneros actual = arbolGeneros;
      
    while (actual->sH != NULL) {
      if (actual->sH->idGenero == idGenero) {
        TAGGeneros aBorrar = actual->sH;
        actual->sH = aBorrar->sH;
        aBorrar->sH = NULL; 
        liberarTAGGeneros(aBorrar);

        return; 
      }
      
      removerGeneroTAGGeneros(actual->sH, idGenero);
      actual = actual->sH;
    }
  }
}

