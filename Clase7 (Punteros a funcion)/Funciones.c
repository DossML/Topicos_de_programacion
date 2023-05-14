#include "Funciones.h"

void map(const void* vec, unsigned ce, size_t tam, void* accion(const void*))
{
    int i=0;
    for(i=0; i<ce; i++)
        accion(vec+(i*tam));
}

void filtrar(void* vec, unsigned* ce, size_t tam, const void *vF, int cmp(const void*, const void*)){ //vF=valorDeFiltrado
    //segun el valor de filtrado ir filtrando los que cumplen las condiciones
    int i,j;
    void* encontro = vec;

    for(i=0; i<(*ce); i++)
    {
        if(cmp((vec), vF))
        {
            encontro = vec;
            for(j=i; j<(*ce)-1; j++)
            {
                memcpy(encontro, encontro+tam, tam);
                encontro+=tam;

            }
            (*ce)--;
            i--; // Fotitos Ryujin https://kpopping.com/kpics/230124-ITZY-Instagram-Update-Ryujin
        }
        else
            vec+=tam;
    }
}

int cmp_int(const void*a, const void*b){
    if(*(int*)a - *(int*)b >= 0)
        return 1;
    return 0;
}

int cmp_float(const void*a, const void*b)
{
    if(*(float*)a - *(float*)b >= 0)
        return 1;
    return 0;
}

int cmp_promedio(const void*a, const void*b)
{
    if((*(tAlu*)a).prom - *(float*)b < 0)
        return 1;
    return 0;
}

void reducir(const void* vec, unsigned ce, size_t tam, void* acum, void* acumuladores(void*, const void*))
{
    int i;
    for(i=0; i<ce; i++)
        acumuladores(acum, vec+(i*tam));
}

void acum_int(void* acum, const void* vec){
    *(int*)acum += *(int*)vec;
}

void acum_prom(void* acum, const void* vec){
    *(float*)acum += ((tAlu*)(vec))->prom;
}

void mostrarVectorAlumnos(tAlu* alu, int ce, int accion(void*)){
    int i;
    for(i=0; i<ce; i++)
       accion(alu+i);
}

void mostrarAlumno(tAlu* alu){
    printf("\n%s\t%.2f\t%d", (alu)->NyA,(alu)->prom,(alu)->DNI);
}

int sumar(int a, int b){
    return a+b;
}

int restar(int a, int b){
    return a-b;
}

void mostrarElemInt(const void* ele)
{
    printf("%d\n", *(int*)ele);
}
