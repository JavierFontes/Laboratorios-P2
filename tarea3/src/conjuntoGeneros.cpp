#include "../include/conjuntoGeneros.h"

struct rep_conjuntogeneros{
  int cantMax;
  int cantActual;
  bool *elems;
};

TConjuntoGeneros crearTConjuntoGeneros(int cantMax){
  TConjuntoGeneros ConjuntoGeneros = new rep_conjuntogeneros;
  ConjuntoGeneros->cantMax = cantMax;
  ConjuntoGeneros->cantActual = 0;

  ConjuntoGeneros->elems = new bool[cantMax];
  for (int i = 0; i < cantMax; i++)
    ConjuntoGeneros->elems[i] = false;

  return ConjuntoGeneros;    
}

bool esVacioTConjuntoGeneros(TConjuntoGeneros c){
  return (c->cantActual == 0);
}

void insertarTConjuntoGeneros(TConjuntoGeneros &c, int id){
  if (id >= 0 && id < c->cantMax){
    if (!c->elems[id]){
      c->elems[id] = true;
      c->cantActual++;
    }
  }
}

void borrarDeTConjuntoGeneros(TConjuntoGeneros &c, int id){
  if (id >= 0 && id < c->cantMax) {
    if (c->elems[id]) {
      c->elems[id] = false; 
      c->cantActual--;
    }
  }
}

bool perteneceTConjuntoGeneros(TConjuntoGeneros c, int id){
  bool aux;
  if (id >= 0 && id < c->cantMax)
    aux = c->elems[id];
  else
    aux = false;
  
  return aux;
}

int cardinalTConjuntoGeneros(TConjuntoGeneros c){
  return c->cantActual;
}

int cantMaxTConjuntoGeneros(TConjuntoGeneros c){
  return c->cantMax;
}

void imprimirTConjuntoGeneros(TConjuntoGeneros c) {
    bool primero = true;  // para controlar el espacio entre elementos
    for (int i = 0; i < c->cantMax; i++) {
        if (c->elems[i]) {
            if (!primero) {
                printf(" ");  // imprime espacio solo después del primer elemento
            }
            printf("%d", i);
            primero = false;
        }
    }
    printf("\n");  // salto de línea al final
}


void liberarTConjuntoGeneros(TConjuntoGeneros &c){
  delete [] c->elems;
  c->cantActual = 0;
  delete c;
  c = NULL;
}

TConjuntoGeneros unionTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2){
  TConjuntoGeneros unionC = new rep_conjuntogeneros;
  unionC->cantMax = c1->cantMax;
  unionC->cantActual = 0;
  unionC->elems = new bool[unionC->cantMax];
  for (int i = 0; i < unionC->cantMax; i++) 
    unionC->elems[i] = false;

  for (int i = 0; i < unionC->cantMax; i++) {
    if (c1->elems[i] || c2->elems[i]) {
      unionC->elems[i] = true;
      unionC->cantActual++;
    }
  }
  return unionC;
}

TConjuntoGeneros interseccionTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2){
  TConjuntoGeneros intersecC = new rep_conjuntogeneros;
  intersecC->cantMax = c1->cantMax;
  intersecC->cantActual = 0;
  intersecC->elems = new bool[intersecC->cantMax];
  for (int i = 0; i < intersecC->cantMax; i++) 
    intersecC->elems[i] = false;

  for (int i = 0; i < intersecC->cantMax; i++) {
    if (c1->elems[i] && c2->elems[i]) {
      intersecC->elems[i] = true;
      intersecC->cantActual++;
    }
  }
  return intersecC;
}

TConjuntoGeneros diferenciaTConjuntoGeneros(TConjuntoGeneros c1, TConjuntoGeneros c2){
  TConjuntoGeneros difC = new rep_conjuntogeneros;
  difC->cantMax = c1->cantMax;
  difC->cantActual = 0;
  difC->elems = new bool[difC->cantMax];
  for (int i = 0; i < difC->cantMax; i++) 
    difC->elems[i] = false;

  for (int i = 0; i < difC->cantMax; i++) {
    if ((c1->elems[i] && (c2->elems[i] == false))) {
      difC->elems[i] = true;
      difC->cantActual++;
    }
  }
  return difC;
}

