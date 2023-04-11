#include "Funciones.h"
#define TAM 10

int main()
{
    int v[10] = {0,10,20,30,40,50,60,70,80,90}, num;
    printf("Ejercicio 23 - Insertar elemento ordenado\n\nElemento: ");
    scanf("%d", &num);
    insertarElemOrd(v, num, TAM);
    mostrarVec(v, TAM);
    return 0;
}
