#include "vector.h"

//FUNCIONES PARA VENTAS

int cmp_venta(const void*a, const void*b)
{
    if((*(tVenta*)a).costo - *(float*)b <= 0)
        return 1;
    return 0;
}

void acum_venta(void* acum, const void* vec){
    *(float*)acum += ((tVenta*)(vec))->costo;
}
void mostrarVenta(const void* a)
{
    printf("\nID: %d\tFecha: %d/%d/%d \tValor: %.2f\n",((tVenta*)a)->id , ((tVenta*)a)->date.dia ,  ((tVenta*)a)->date.mes ,  ((tVenta*)a)->date.anio ,  ((tVenta*)a)->costo);
           //((tVenta*)a)->id = *(*((tVenta*)a).id)
}

//FUNCIONES DE ORDENAMIENTO

void ordenamiento_por_seleccion(const void* vec, unsigned ce, size_t tam, void* buscar_menor(const void*, unsigned)){
    int i;
    for(i=0; i<ce; i++)
        intercambio(vec+(i*tam), buscar_menor(vec+(i*tam), ce-i), tam);
}

const void* buscar_menor_int(const void* vec, unsigned ce){
    int menor = 0, i;
    for(i=0; i<ce; i++)
        if(*(int*)(vec+(i*sizeof(int)))<*(int*)(vec+(menor*sizeof(int))))
            menor = i;
    return vec+(menor*sizeof(int));
}

//FUNCIONES GENERICAS

void intercambio(const void* a, const void* b, size_t tam){
    int i;
    char aux;
    for(i=0; i<tam; i++){
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
        a++;
        b++;
    }
}

void filtrar(void* vec, unsigned* ce, size_t tam, const void *vF, int cmp(const void*, const void*)){ //vF=valorDeFiltrado
    //segun el valor de filtrado ir filtrando los que cumplen las condiciones
    int i;
    void *pL = vec, *pE = vec;

    for(i=0; i<*ce; i++){
        if(cmp(pL, vF)){
            pL+=tam;
            (*ce)--;
        }
        if(pE != pL)
            memcpy(pE, pL, tam);
        pE+=tam;
        pL+=tam;
    }
            // Fotitos Ryujin https://kpopping.com/kpics/230124-ITZY-Instagram-Update-Ryujin
}

void map(const void* vec, unsigned ce, size_t tam, void* accion(const void*))
{
    int i=0;
    for(i=0; i<ce; i++)
        accion(vec+(i*tam));
}

void reducir(const void* vec, unsigned ce, size_t tam, void* acum, void* acumuladores(void*, const void*))
{
    int i;
    for(i=0; i<ce; i++)
        acumuladores(acum, vec+(i*tam));
}
