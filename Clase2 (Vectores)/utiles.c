#include "utiles.h"

void intercambioEnt(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}


void mostrarVector(int* vec, int ce){
    int i;
    for(i=0; i<ce; i++){
        printf("\nValor %d: %d", ce, vec[i]);
    }
}

void compararVectores(int* vec1, int* vec2){

}
