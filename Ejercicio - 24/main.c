#include "Funciones.h"
#define TAM 10

int main()
{
    int v[10] = {1,2,3,4,5,6,7,8,9,10}, pos;
    printf("Ejercicio 24 - Eliminar elemento por posicion\n\nPosicion: ");
    scanf("%d", &pos);
    EliminarElemPorPos(v, pos, TAM);
    mostrarVec(v, TAM);
    return 0;
}
