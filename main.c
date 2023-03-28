#include <stdio.h>
#include <stdlib.h>

int factorial(int);
//Desarrollar una función para calcular el ex, dados X y TOL


int main()
{

    int TOL=0, x, ex=0;
    printf("Ingrese numero entero: ");
    do{
        scanf("%d", &x);
    }while(x<0);

    printf("\nIngrese tolerancia minima (mayor a cero): ");
     do{
        scanf("%d", &TOL);
    }while(TOL<0);


    return 0;
}

///////////////////////FUNCIONES///////////////////////////////
int factorial (int nro)  //factorial de la potencia de x
{
    int i, factorial=1;
    for (i=1; i<=nro; i++)
    {
        factorial *= i;
    }

    return factorial;
}

int funcionEx (int x, int TOL)
{

}
