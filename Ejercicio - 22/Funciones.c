#include "Funciones.h"

void insertarElem(int* v, int pos, int num){
    *(v+pos-1) = num;
}


void mostrarVec(int* vec, int ce){
    int i;
    for(i=0; i<ce; i++){
        printf("\nPosicion %d: %d", i+1, vec[i]);
    }
}
