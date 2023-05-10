#include "Funciones.h"

void filtrar(void* vec, unsigned* ce, size_t tam, const void *vF, int cmp(const void*, const void*)){ //vF=valorDeFiltrado
    //segun el valor de filtrado ir filtrando los que cumplen las condiciones

    int i;

    for(i=0; i<ce; i++)
    {
        if(cmp((vec+(i*tam)), vF) >= 0)
            printf("\n%d", i);
    }

}
int cmp_int(const void*a, const void*b){

    return *(int*)a - *(int*)b;

}

void reducir(const void* vec, unsigned ce, size_t tam, void* acum, void* acumuladores(void*, const void*))
{
    //SACAR PROMEDIO DE TODOS LOS PROMEDIOS Y GUARDAR EN ACUM;

    int i;

    for(i=0; i<ce; i++)
    {
        acumuladores(acum, vec);
        vec+=tam;
    }


}

void acum_int(void* acum, const void* vec){
    *(int*)acum += *(int*)vec;
}

void acum_float(void* acum, const void* vec){
    *(float*)acum += *(float*)vec;
}


void mostrarVectorAlumnos(tAlu* alu, int ce, int accion(void*)){
    int i;
    for(i=0; i<ce; i++){
       accion(alu+i);
    }
}

void mostrarAlumno(tAlu* alu){
    printf("\n%s\t%f\t%d", (alu)->NyA,(alu)->prom,(alu)->DNI);
}

int sumar(int a, int b){
    return a+b;
}
int restar(int a, int b){
    return a-b;
}
