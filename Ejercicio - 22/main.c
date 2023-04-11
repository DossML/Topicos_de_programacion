#include "Funciones.h"
#define TAM 10
int main()
{
    int v[10] = {0,1,2,3,4,5,6,7,8,9}, pos, num;
    printf("Ejercicio 22 - Insertar elemento\n\nElemento: ");
    scanf("%d", &num);
    printf("\nPosicion: ");
    scanf("%d", &pos);
    insertarElem(v, pos, num);
    mostrarVec(v, TAM);
    return 0;
}
