#include <stdio.h>
#include <stdlib.h>

void intercambio(void* a, void* b, size_t tam);

int main()
{
    int a[] = {1,2,3,4};
    int b[] = {5,6,7,8};
    void* pa = &a;
    void* pb = &b;
    intercambio(pa, pb, sizeof(int)*4);

    // No se puede desreferenciar ===>   int c = *pa + *pb;
    int c = *((int*)pa) + *((int*)pb);

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
    char aux;
    for(i=0; i<=tam; i++){
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
        a++;
        b++;
    }
}
