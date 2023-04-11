#include "Funciones.h"
#define TAM 10

int main()
{
    int v[10] = {1,2,3,4,5,6,7,8,9,10}, num;
    mostrarVec(v, TAM);
    printf("\n\nEjercicio 24 - Eliminar 1 elemento por valor\n\nValor: ");
    scanf("%d", &num);
    EliminarPrimerElemPorValor(v, num, TAM);
    mostrarVec(v, TAM);
    return 0;
}
