/*Ejercicio 12
Construir un programa que lea un número natural N y calcule la suma de los números pares
menores que N*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char const *argv[])
{
    int num;
    printf("\nIngrese un numero: ");
    scanf("%d", &num);
    printf("\nResultado de la suma de los numeros pares menores a %d es: %d", num, sumaParesMenoresA(num));
    return 0;
}

