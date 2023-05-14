#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int DNI;
    float prom;
    char NyA[20];
}tAlu;

int sumar (int a, int b);
int restar (int a, int b);
void mostrarVectorAlumnos(tAlu* alu, int ce, int accion(void*));
void mostrarAlumno(tAlu* alu);
void acum_int(void* acum, const void* vec);
void acum_prom(void* acum, const void* vec);

void map(const void* vec, unsigned ce, size_t tam, void* accion(const void*));
void reducir(const void* vec, unsigned ce, size_t tam, void* acum, void* acumuladores(void*, const void*));
void filtrar(void* vec, unsigned* ce, size_t tam, const void *vF, int cmp(const void*, const void*));
int cmp_int(const void*a, const void*b);
int cmp_float(const void*a, const void*b);
int cmp_promedio(const void*a, const void*b);
void mostrarElemInt(const void* ele);
//void qsort(void *base, size_t nmemb, size_t tam, int (*comparar)(const void *, const void *)); // Parametros del qsort


#endif // FUNCIONES_H_INCLUDED

