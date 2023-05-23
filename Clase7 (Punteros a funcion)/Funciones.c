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

void reducir(const void* vec, unsigned ce, size_t tam, void* acum, void* acumuladores(void*, const void*))
{
    int i;
    for(i=0; i<ce; i++)
        acumuladores(acum, vec+(i*tam));
}


void* busquedaBinaria(void* vec, void* elem, unsigned ce, size_t tam, int cmp(const void*, const void*)) // Fotitos Karina: https://kpopping.com/kpics/230320-aespa-Weibo-Update-Karina
{

    void* pi = vec;
    void* pf = vec+(tam*ce);
    void* medio = vec+(tam*ce/2);


    while(pi != pf)
    {
        if(cmp(elem, medio) > 0)
        {
            pi = medio+=tam;
        }
        else if(cmp(elem, medio) < 0)
        {
            pf = medio-=tam;
        }
        else
            return medio;

        medio = pi+(((pf-pi)/tam)/2)*tam;

    }

    if(cmp(elem, medio) != 0)
        return NULL;

    return medio;

}

int cmp_int(const void*a, const void*b)
{

    return *(int*)a - *(int*)b;

}

void ordenarSeleccion(void* vec, unsigned ce, size_t tam, void* buscarMenor(const void*, unsigned))
{

    int i;
    void* menor = vec;

    for(i=0; i<ce; i++)
    {

        menor = buscarMenor(vec, ce-i); // Retorno la direccion del menor.

        intercambio(vec, menor, tam); // Intercambio.

        vec+=tam; // Aumento una posicion del principio ya que lo ordene.
    }

}

void* buscarMenorInt(void* vec, unsigned ce)
{
    int i;
    void* menor = vec;

    for(i=0; i<ce; i++)
    {
        if(*(int*)vec < *(int*)menor)
        {
            menor = vec;
        }

        vec+=sizeof(int);
    }

    return menor;

}

void intercambio(void* a, void* b, size_t tam)
{

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
