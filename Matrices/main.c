#include "Funciones.h"

#define MAX_COL 20
#define CANTFIL 5
#define CANTCOL 5
#define ABS(x) (x<0)?(-x):(x)

int main()
{
    //int matriz[][MAX_COL]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int matrizIdentidad[][MAX_COL]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
//  mostrarMatriz(matriz,CANTFIL,CANTCOL);
//  printf("\nLa suma de la diagonal es: %d",sumarDiagonal(matriz,CANTFIL));
    esIdentidad(matrizIdentidad,CANTFIL,CANTCOL)?printf("Es Identidad"):printf("No es Identidad");
    return 0;
}
