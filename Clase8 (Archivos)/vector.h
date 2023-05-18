#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int dia;
    int mes;
    int anio;
}tFecha;

typedef struct{
    int id;
    tFecha date;
    float costo;
}tVenta;

//Genericos
void map(const void* vec, unsigned ce, size_t tam, void* accion(const void*));
void reducir(const void* vec, unsigned ce, size_t tam, void* acum, void* acumuladores(void*, const void*));
void filtrar(void* vec, unsigned* ce, size_t tam, const void *vF, int cmp(const void*, const void*));
void intercambio(const void* a, const void* b, size_t tam);

//Extras de Venta
int cmp_venta(const void*a, const void*b);
void acum_venta(void* acum, const void* vec);
void mostrarVenta(const void* a);

//Extras de ordenamiento
void ordenamiento_por_seleccion(const void* vec, unsigned ce, size_t tam, void* buscar_menor(const void*, unsigned));
const void* buscar_menor_int(const void* vec, unsigned ce);

#endif // VECTOR_H_INCLUDED
