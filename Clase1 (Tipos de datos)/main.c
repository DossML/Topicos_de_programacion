#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a;              //entero hasta 2147 millones
    char b;             //1 caracter
    unsigned int c;     //entero sin negativo (este caso 4294 millones)
    long int d;         //entero hasta
    long long int e;    //entero muy largo
    float f;
    double g;
    long double h;
    short i;

    printf("\nTamanio de int: %d bytes", sizeof(int));
    printf("\nTamanio de char: %d byte", sizeof(char));
    printf("\nTamanio de short: %d bytes", sizeof(short));
    printf("\nTamanio de long int: %d bytes", sizeof(long int));
    printf("\nTamanio de long long int: %d bytes", sizeof(long long int));
    printf("\nTamanio de float: %d bytes", sizeof(float));
    printf("\nTamanio de double: %d bytes", sizeof(double));
    printf("\nTamanio de long double: %d bytes", sizeof(long double));

    int dni=99999999;
    //repeticion por condicional
    for(i=0; i<5; i++){
    //condicional
    if(dni==99999999)
    {
        printf("\nDNI: %d", dni);
    }
    else
        printf("\n\nFijate, hubo un error");
    }

    int num;    /*repeticion por condicionales*/
    do{
        printf("\nIgrese un numero: ");
        scanf("%d", &num);
    } while(num!=3);

    int x=5, y=2, r=x/y; //int redondea para abajo y solo imprime el entero
    printf("5/2 = %d", r);

    int w=7;
    x=++w; // preincremento. Si pongo ++ despues de w => x=7 y w=8
    printf("\n%d", x);

    return 0;
}
