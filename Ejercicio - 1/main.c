#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
    /* Desarrollar una función para calcular el factorial de un entero */
    int num;
    printf("\nCalculo de factorial\n\nIngrese un numero");
    scanf("%d", &num);
    printf("\nResultado del factorial de %d es: %d", num, factorial(num));
    return 0;
}
