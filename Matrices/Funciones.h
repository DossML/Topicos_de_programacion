#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

void mostrarMatriz(int[][MAX_COL],int fil,int col);
int compararMatriz(int[][MAX_COL],int[][MAX_COL],int fil,int col);
int sumarDiagonal(int[][MAX_COL],int);
int esIdentidad(int[][MAX_COL],int fil,int col);
int sumYMosTriInf(int[][MAX_COL]);
void mostrarTriSup(int[][MAX_COL]);
void mostrarMenosDiagonales(int[][MAX_COL]);
void transponerMatriz(int[][MAX_COL]);
void rotarEstrella(int[][MAX_COL]);
void recorrerEspiral(int mat[][MAX_COL], int f);
void multiplicarMatrices(int[][MAX_COL],int[][MAX_COL]);


#endif // FUNCIONES_H_INCLUDED
