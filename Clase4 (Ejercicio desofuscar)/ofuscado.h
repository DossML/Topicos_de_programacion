#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* __desofuscar(char* linea);
char despChr(char c, char* dic, int cant);
char* proximaPalabra(const char* cad, char** ini, char** fin);
void imprimirFragmento(char* ini, char* fin);
size_t obtenerLineaOfuscada(char* linea);
char* desofuscar(char* linea);

//Mis funciones
int isAlpha(const char* cad);
void desofuscar_ALU(char* linea);
char despChr_ALU(char c, char* tool, int cant);
void proximaPalabra_ALU(const char* cad, char** ini, char** fin);


#endif // OFUSCADO_INCLUDED
