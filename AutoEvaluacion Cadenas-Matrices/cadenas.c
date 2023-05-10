#define isAlpha(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z')) ? 1 : 0
#include <memory.h>


int longitudCadena(const char* cad);


int __esAnagrama(const char* cad1,  char* cad2){


    char* ini = cad2;

    if(longitudCadena(cad1) != longitudCadena(cad2))
        return 0;

    while(*cad1)
    {

        if(!isAlpha(*cad1))
            cad1++;

        if(*cad1 != *cad2)
            cad2++;
        else
        {
            cad1++;
            while(*cad2 != '\0')
            {
                *cad2 = *(cad2+1);
                cad2++;
            }
            cad2 = ini;
        }
    }

    /*while(*cad2)
    {
        if(isAlpha(*cad2))
            return 0;

        cad2++;
    }*/

    return 1;
}

int longitudCadena(const char* cad)
{

    int i=0;

    while(*cad)
    {

        if(isAlpha(*cad))
            i++;

        cad++;
    }

    return i;

}
