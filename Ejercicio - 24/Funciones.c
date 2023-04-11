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

void insertarElemOrd(int* v, int num, int ce){
    int i = 0, aux;
    if(*(v+i) > num){
        aux = *(v+i);
        *(v+i) = num;
        num = aux;
    }
    i++;
    do{
        if(*(v+i) > num || *(v+i-1) >= *(v+i)){
            aux = *(v+i);
            *(v+i) = num;
            num = aux;
        }
        i++;
    }while(i < ce);
}

void EliminarElemPorPos(int* v, int pos, int ce){
    while(pos < ce){
            *(v+pos-1) = *(v+pos);
            *(v+pos) = 0;
            pos++;
    }
    if (pos == ce)
            *(v+pos-1) = 0;
}
