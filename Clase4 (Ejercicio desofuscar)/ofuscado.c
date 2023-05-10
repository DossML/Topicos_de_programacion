#include "ofuscado.h"
char* __desofuscar(char* linea){
    return NULL;
}

int isAlpha(const char* cad){
    if((*cad > 65 && *cad < 90) || (*cad > 97 && *cad < 122))
        return 1;
    return 0;
}

void proximaPalabra_ALU(const char* cad, char** ini, char** fin)
{
    if(*cad > 0){
        while(isAlpha(cad) == 0){
            *ini = *ini + 1;
            *fin = *fin + 1;
            cad++;
        }
        while(isAlpha(cad+1)){
            *fin = *fin + 1;
            cad++;
        }
    }
}

char despChr_ALU(char letra, char* tool, int cant)
{
    int pos = 0;
    while(pos<14)
    {
        if(letra==*tool)
        {
            letra = *(tool - pos + (pos + cant)%14);
            return letra;
        }

        tool++;
        pos++;
    }

    return letra;
}


void desofuscar_ALU(char* linea){
    char* ini = linea, *fin = linea;
    char tool[15]={'a','b','c','d','g','h','i','j','k','o','q','t','u','v'};
    int cantDesp=1;
    proximaPalabra_ALU(linea,&ini,&fin);
    while(*ini > 0){
        while(ini<=fin)
        {
            *ini=despChr_ALU(*ini,tool,cantDesp++);
            ini++;
        }
        cantDesp=1;
        proximaPalabra_ALU(ini,&ini,&fin);
    }
}
