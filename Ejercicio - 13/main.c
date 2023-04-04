#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
    /*Ejercicio 13
    Desarrollar una función que determine si un número natural es primo*/
    int num;
    printf("\nPrograma para determinar si un numero es primo\n\nIngrese un numero: ");
    do{
    scanf("%d", &num);
    esPrimo(num);
    }while(num!=333333);
    return 0;
}
