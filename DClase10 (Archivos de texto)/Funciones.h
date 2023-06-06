#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 10
#define TamNov
#define TamEmp

typedef struct
{
    int dni;
    char NyAp[40];
    float prom;

} tAlumno;

typedef struct{
    int dni;
    char nombre[20];
    char apellido[20];
    float sueldo;
}tEmpleado;

typedef struct{
    tEmpleado emp;
    char novedad;
}tNovedad;

//PRIMERA PARTE: MERGE
int crearLoteEmpl(const char* nom_archv);
int crearLoteNovedades(const char* nom_archv);
int mostrarEmpl(char* nombreArch);
int mostrarNovedades(char* nombreArch);

void actualizar(tNovedad nov, FILE *pf, int cmp);
int cmpEmpNov(void* emp, void* nov);
int merge_mio(const char* archE, const char* archN, int cmp(void*, void*));
int merge_vecNov(const char* archE, tNovedad* vec, int ce, int compare(void*, void*));

//SEGUNDA PARTE: ARCHIVOS DE TEXTO
int crearLoteTexto(const char* arch);
int leerArchTexto(const char* arch);
int crearLoteCampoVariable(const char* arch);
int trozarAlumnosVariable(char* linea, tAlumno* pAlu);


#endif // FUNCIONES_H_INCLUDED
