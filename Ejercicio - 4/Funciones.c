#include "Funciones.h"

double raiz(int num,float tol){
    double r1=1, r2=1;
    r2 = 0.5*(r1+(num/r1));

    do{
        r1=r2;
        r2 = 0.5*(r1+(num/r1));
    }while(r1-r2>tol);
    return r2;
}
