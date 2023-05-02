#include "Funciones.h"


void mostrarMatriz(int mat[][MAX_COL],int fil,int col)
{
    int i,j;
    for(i=0;i<fil;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

int compararMatriz(int mat1[][MAX_COL],int mat2[][MAX_COL],int fil,int col)
{
    int i,j,comp=1;
    for(i=0;i<fil;i++)
        for(j=0;j<col;j++)
            if(mat1[i][j]!=mat2[i][j])
                comp=0;
    return comp;
}

int sumarDiagonal(int mat[][MAX_COL],int cantElem)
{
    int sum,resu=0;
    for(sum=0;sum<cantElem;sum++)
        resu+=mat[sum][sum];
    return resu;

}

int esIdentidad(int mat[][MAX_COL],int fil,int col)
{
    int i=0,j=0;
    while((j<=i)&&(j<col)&&(i<fil))
    {
        if(j!=i)
        {
            if(mat[i][j]!=0||mat[j][i]!=0)
                return 0;
            j++;
        }
        if(j==i)
        {
            if(mat[i][j]!=1)
                return 0;
            i++;
            j=0;
        }
    }
    return 1;
}

int sumYMosTriInf(int mat[][MAX_COL])
{

}

void mostrarTriSup(int mat[][MAX_COL])
{

}
void mostrarMenosDiagonales(int mat[][MAX_COL])
{

}

void transponerMatriz(int mat[][MAX_COL])
{

}

void rotarEstrella(int mat[][MAX_COL])
{

}


void multiplicarMatrices(int mat1[][MAX_COL],int mat2[][MAX_COL])
{

}

void recorrerEspiral(int mat[][MAX_COL], int f)
{

    int fin_c = f-1;
    int fin_f = f-1;
    int ini_c = 0;
    int ini_f = 0;
    int i;

    while((fin_f-ini_f)>=0)
    {
        for(i = ini_c; i<=fin_c; i++)
        {
            printf("%d", mat[ini_f][i]);
        }

        puts("");

        for(i=ini_f+1; i<=fin_f; i++)
        {
            printf("%d", mat[i][fin_c]);
        }

        puts("");

        for(i=fin_c-1; i>ini_c; i--)
        {
            printf("%d", mat[fin_f][i]);
        }

        ini_f+=1;

        puts("");

        for(i = fin_f; i>=ini_f; i--)
        {
            printf("%d", mat[i][ini_c]);
        }

        ini_c+=1;

        fin_c-=1;
        fin_f-=1;

    }
}
