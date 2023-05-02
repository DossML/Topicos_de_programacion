#include "Funciones.h"

void* crearVector(void* pV, int tam){
    pV = malloc(sizeof(*pV)*tam);
    if(!pV){
        printf("\nError al crear vector\n");
        exit(1);
    }

    return pV;
}

void modificarElem(int* pV, int pos, int elem){
    *(pV+pos) = elem;
}

void agregarElem(int* pV, int tam){

}
void borrarElem(int*  pV, int tam, int pos){}
void borrarVector(int* pV){}
