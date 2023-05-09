#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"
#include "Matrices.h"
#include "minunit.h"

///Decida que ejercicio va a hacer, comente lo que no haga
#define HAGOCADENAS
//#define HAGOMATRIZ


///Si ALUMNO esta comentado se ejecutan la version en biblioteca (Solo W64).
///Si no esta comentado se remplaza por el mismo nombre con "__" como prefijo.
///Implemente esas funciones.
#define SOYALUMNO



#ifdef SOYALUMNO
    #define esAnagrama                      __esAnagrama
    #define cargarMatrizEspiralCentroAIAD   __cargarMatrizEspiralCentroAIAD
#endif // ALUMNO

#ifdef HAGOCADENAS


MU_TEST(test_esAnagrama_01){
    char cad1[] = "Roma";
    char cad2[] = "Amor";
    mu_assert(esAnagrama(cad1, cad2)==1, "Las cadenas son anagramas");
}

MU_TEST(test_esAnagrama_02){
    char cad1[] = "Istmo de Panama";
    char cad2[] = "Tio Sam, me da pan";

    mu_assert(esAnagrama(cad1, cad2)==1, "Las cadenas son anagramas");

}

MU_TEST(test_esAnagrama_03){
    char cad1[] = "Istmos de Panama";
    char cad2[] = "Tio Sam, me da pan";

    mu_assert(esAnagrama(cad1, cad2)==0, "Las cadenas no son anagramas");

}

MU_TEST(test_esAnagrama_04){
    char cad1[] = "";
    char cad2[] = "";

    mu_assert(esAnagrama(cad1, cad2)==1, "Las cadenas son anagramas");
}
#endif // HAGOCADENAS

#ifdef HAGOMATRIZ
MU_TEST(test_cargarMatrizEspiralDesdeCentro_01){
    int mat[][MAX_COL] = {
        {13, 12, 11, 10, 25},
        {14,  3,  2,  9, 24},
        {15,  4,  1,  8, 23},
        {16,  5,  6,  7, 22},
        {17, 18, 19, 20, 21},
    };
    //Filas utiles
    int f = 5;
    //Columas utiles
    int c = 5;
    //Vector resultado
    int vecR[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    //Vector a cargar...
    int vecD[sizeof(vecR)/sizeof(vecR[0])]; //Esto se resuelve en tiempo de compilacion no es VLA
    cargarMatrizEspiralCentroAIAD(mat, f, c, vecD);//Arriba, izquierda, abajo, derecha

    //Comparo byte a byte la memoria y tiene que ser igual
    mu_assert(memcmp(vecR, vecD, sizeof(vecR))==0, "No se cargo el vector en espiral antihorario");




}


MU_TEST(test_cargarMatrizEspiralDesdeCentro_02){
    int mat[][MAX_COL] = {
        {13, 12, 11,  10},
        {14,  3,  2,   9},
        {15,  4,  1,   8},
        {16,  5,  6,   7},
        {17, 18, 19,   20}
    };
    //Filas utiles
    int f = 5;
    //Columas utiles
    int c = 4;
    //Vector resultado
    int vecR[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    //Vector a cargar...
    int vecD[sizeof(vecR)/sizeof(vecR[0])]; //Esto se resuelve en tiempo de compilacion no es VLA
    cargarMatrizEspiralCentroAIAD(mat, f, c, vecD);//Arriba, izquierda, abajo, derecha

    //Comparo byte a byte la memoria y tiene que ser igual
    mu_assert(memcmp(vecR, vecD, sizeof(vecR))==0, "No se cargo el vector en espiral antihorario");
}

MU_TEST(test_cargarMatrizEspiralDesdeCentro_03){
    int mat[][MAX_COL] = {
        {3,2},
        {4,1}
    };
    //Filas utiles
    int f = 2;
    //Columas utiles
    int c = 2;
    //Vector resultado
    int vecR[] = {1,2,3,4};
    //Vector a cargar...
    int vecD[sizeof(vecR)/sizeof(vecR[0])]; //Esto se resuelve en tiempo de compilacion no es VLA

    cargarMatrizEspiralCentroAIAD(mat, f, c, vecD);//Arriba, izquierda, abajo, derecha

    //Comparo byte a byte la memoria y tiene que ser igual
    mu_assert(memcmp(vecR, vecD, sizeof(vecR))==0, "No se cargo el vector en espiral antihorario");


}

MU_TEST(test_cargarMatrizEspiralDesdeCentro_04){
    int mat[][MAX_COL] = {
        {1},
    };
    //Filas utiles
    int f = 1;
    //Columas utiles
    int c = 1;
    //Vector resultado
    int vecR[] = {1};
    //Vector a cargar...
    int vecD[sizeof(vecR)/sizeof(vecR[0])]; //Esto se resuelve en tiempo de compilacion no es VLA

    cargarMatrizEspiralCentroAIAD(mat, f, c, vecD);//Arriba, izquierda, abajo, derecha
    //Comparo byte a byte la memoria y tiene que ser igual
    mu_assert(memcmp(vecR, vecD, sizeof(vecR))==0, "No se cargo el vector en espiral antihorario");


}
#endif // HAGOMATRIZ


MU_TEST_SUITE(test_suite) {
	//MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	#ifdef HAGOCADENAS
        MU_RUN_TEST(test_esAnagrama_01);
        MU_RUN_TEST(test_esAnagrama_02);
        MU_RUN_TEST(test_esAnagrama_03);
        MU_RUN_TEST(test_esAnagrama_04);

    #endif

    #ifdef HAGOMATRIZ
        ///Solo para matrices donde la cantidad de filas es la misma que de columnas o
        ///la cantidad de filas es una mas que columnos ej 5x5 o 5x4
        MU_RUN_TEST(test_cargarMatrizEspiralDesdeCentro_01);
        MU_RUN_TEST(test_cargarMatrizEspiralDesdeCentro_02);
        MU_RUN_TEST(test_cargarMatrizEspiralDesdeCentro_03);
        MU_RUN_TEST(test_cargarMatrizEspiralDesdeCentro_04);
    #endif
}



int main()
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();

	return MU_EXIT_CODE;
}
