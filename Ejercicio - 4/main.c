#include "Funciones.h"

/*Desarrollar una funci�n para calcular la ra�z cuadrada de X con una tolerancia
TOL*/

int main()
{
    int num;
    float tol;
    printf("Programa que calcula raiz\n\nIngrese numero: ");
    scanf("%d", &num);
    printf("Ingrese tolerancia: ");
    scanf("%f", &tol);
    printf("La raiz de %d es :%.5f", num, raiz(num, tol));
    return 0;
}
