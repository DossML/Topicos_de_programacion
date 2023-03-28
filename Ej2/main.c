#include <stdio.h>
#include <stdlib.h>
int combinacion (int);
int main()
{
    /*Desarrollar una función para calcular el combinatorio m sobre n
    s m y n (m >= n y n>= 0)*/
    int m, n, resultado1, resultado2, resultado3, fin;
    printf("Ingrese el primer numero para hacer la combinacion (debe ser mayor a cero):");
    do
    {
        scanf("%d",&n);
    }while(n < 0);
    printf("\nIngrese el segundo numero (debe ser mayor al primer numero): ");
    do
    {
        scanf("%d",&m);
    }while(m < n);


    resultado1 = combinacion (m);
    resultado2 = combinacion (n);
    resultado3 = combinacion((m-n));
    fin = resultado1 / (resultado2 * resultado3);
    printf("\n\nCombinacion entre %d y %d es %d", m, n, fin);

    return 0;
}
////////////////////FUNCIONES//////////////////////////////
int combinacion (int nro)
{
    int i, factorial=1;
    for (i=1; i<=nro; i++)
    {
        factorial *= i;
    }

    return factorial;
}
