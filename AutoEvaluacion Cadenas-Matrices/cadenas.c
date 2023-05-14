#define isAlpha(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z')) ? 1 : 0
#define mitoLower(x)  ((x >= 'A' && x <= 'Z') ? x+32 : x)

#include <string.h>


int longitudCadena(const char* cad);


int __esAnagrama(const char* cad1, const char* cad2)
{

    int vec[25] = {0};
    int pos = 0, i;


    if(longitudCadena(cad1) != longitudCadena(cad2))
        return 0;

    while(*cad1)
    {

        while(mitoLower(*cad1) != (pos+97) && isAlpha(*cad1))
        {
            pos++;
        }

        if(isAlpha(*cad1))
            vec[pos]++;

        pos = 0;
        cad1++;
    }

    while(*cad2)
    {

        while(mitoLower(*cad2) != (pos+97) && isAlpha(*cad2))
        {
            pos++;
        }

        if(isAlpha(*cad2))
            vec[pos]--;
        pos = 0;
        cad2++;
    }

    for(i=0; i<=25; i ++)
    {
        if(vec[i] != 0)
            return 0;
        i++;
    }

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


