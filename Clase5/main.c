#include "Funciones.h"
#define TAM 10
int main()
{
    int i;
    int *vec = NULL;
    vec = (int*) crearVector(vec, TAM);
    for(i=0; i<TAM; i++){
        *(vec+i)= i;
        printf("\nPos : %d", *(vec+i));
    }
    return 0;
}
