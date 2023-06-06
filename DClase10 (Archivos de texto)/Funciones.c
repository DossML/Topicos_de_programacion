#include "Funciones.h"

int trozarAlumnosFijo(const char* arch, char* linea, tAlumno* pAlu)
{
    char *pe = strchr(linea, '\n');
    if(!pe)
        return 1;
    *pe = '\0';
     pe-=sizeof(pAlu->prom);
    sscanf(pe,"%f", &(pAlu->prom));

    *pe = '\0';
    pe-=sizeof(pAlu->NyAp);
    strncpy(pAlu->NyAp, pe, sizeof(pAlu->NyAp));

    *pe = '\0';
    pe-=sizeof(pAlu->dni);
    sscanf(pe, "%d", &pAlu->dni);

    return 0;
}

int trozarAlumnosVariable(char* linea, tAlumno* pAlu)
{
    char *pe = strrchr(linea, '|');
    if(!pe)
        return 1;
    *pe = '\0';
    sscanf(pe+1,"%f", &(pAlu->prom));
    pe = strchr(linea, '|');

    *pe = '\0';
    strcpy(pAlu->NyAp, pe+1);
    pe = strchr(linea, '|');

    *pe = '\0';
    sscanf(pe+1,"%d", &(pAlu->dni));

    return 0;
}

int leerArchTexto(const char* arch)
{
    char linea[10]; //num<=MAXLINE
    FILE *pf = fopen(arch, "wt");
    if(!pf)
        return 1;
    while(fgets(linea, sizeof(linea)-1, pf)) //-1 para no levantar el \0
        puts(linea);
    return 0;
}

int crearLoteCampoVariable(const char* arch){

    FILE *pf = fopen(arch, "wt");

    if(!pf)
        return 1;
    int i;

    tAlumno alu[]={{123,"Pepin Pepon", 7.5},{234,"Pepun Pepan", 9},{789,"Sapin Sapito", 5.7}};
    tAlumno *pAlu = alu;

    for(i=0; i<sizeof(alu)/sizeof(tAlumno); i++){//stdout
        fprintf(pf, "%d|%s|%5.2f\n",pAlu->dni, pAlu->NyAp, pAlu->prom);
        pAlu++;
    }

    fclose(pf);

    return 0;
}

int crearLoteTexto(const char* arch)
{
    int i;
    char mat[][MAXLINE]={"a","b","c","d","e"};
    FILE *pf = fopen(arch,"wt");
    if(!pf)
        return 1;

    for(i=0;i<sizeof(mat)/MAXLINE; i++)
        fputs(mat[i], pf);

    fclose(pf);
    return 0;
}


