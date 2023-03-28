#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Ejemplo: 5! = 5. 4. 3. 2. 1 = 120
    Desarrollar una función para calcular el factorial de un entero.*/

    unsigned long long int nro;
    int i, factorial=1;
    printf("Ingrese numero a factorizar: ");
    scanf("%d", &nro);
    for (i=1; i<=nro; i++)
    {
        factorial *= i;
    }
    printf("%d", factorial);

    return 0;
}
