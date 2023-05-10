#include "Funciones.h"

/*  TAREA

1.Usar qsort    
    -> Con vector de enteros
    -> Con vector de alumnos
            
2. Implementar recorrer(map)
    -> Con vector de enteros
    -> Con vector de alumnos

3. Implementar reducir(reduce)
    -> Con vector de enteros
    -> Con vector de alumnos (sumar promedio)

4. Implementar filtrar(filter)
    -> Con vector de enteros
    -> Con vector de alumnos (alumnos con promedio mayor que n)
*/

int main()
{
    //declaraciones
    int i;
    int vec[] = {9,4,6,1,2,7,3,5,8,0};
    int vec2[] = {10,7,5,2,10,9,9,8,10,1};
    int* acum = &i;
    float prom;
    int vF = 7;
    tAlu alu[10];

//PRIMERA PARTE (MUESTRA DE COMO USAR UN PUNTERO A FUNCION) - COMPLETO
/* 
    void *f;
    f=sumar;
    printf("%d",((int(*)(int, int))f)(5,5));
*/

//SEGUNDA PARTE (IMPLEMENTAR PUNTERO A FUNCION EN FUNCIONES) - COMPLETO
/*
    for(i=0; i<10; i++){
        alu[i].DNI = i+1;
        strcpy(alu[i].NyA, "Carlitos");
        alu[i].prom = 0.5+i;
    }
    mostrarVectorAlumnos(alu, 10, (void*)mostrarAlumno);
*/

//TERCERA PARTE (MAP/FILTER/REDUCE) FALTA COMPLETAR FILTER Y MAP!!!!
/*
    i=0;
    reducir(&(alu->prom), 10, sizeof(tAlu), &prom, (void*)acum_float);
    reducir(vec, 10, sizeof(int), acum, (void*)acum_int);
    filtrar(vec2, 10, sizeof(int), &vF, (int*) cmp_int);
*/

    return 0;
}
