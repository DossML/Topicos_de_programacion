#include <stdio.h>
#include <stdlib.h>

void intercambio(void* a, void* b, size_t tam);

int main()
{
    int a[] = {1,2,3,4}; // Vec enteros
    int b[] = {5,6,7,8};
    void* pa = &a; // Puntero a void que coniente la direccion de a.
    void* pb = &b; // Puntero a void que coniente la direccion de b.

    intercambio(pa, pb, sizeof(int)*4);

    // No se puede desreferenciar ===>   int c = *pa + *pb;
    //int c = *((int*)pa) + *((int*)pb);

    for(int i = 0; i<4; i++)
    {

        puts("");
        printf("%d", a[i]);
        puts("");
        printf("%d", b[i]);
    }
    return 0;
}

void intercambio(void* a, void* b, size_t tam){

    int i;
    char aux; // Uso char porque es el tipo de dato mas barato (1 byte)

    for(i=0; i<tam; i++){

        aux = *(char*)a;            // aux = el contenido de a, casteado a un puntero a char.
        *(char*)a = *(char*)b;
        *(char*)b = aux;

        a++;
        b++;
    }
}
