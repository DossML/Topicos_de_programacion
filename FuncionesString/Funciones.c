#include "Funciones.h"

size_t strlen(const char *string)
{
    size_t numCarac=0;
    while(*string)
    {
        numCarac++;
        string++;
    }
    return numCarac;
}

char* strcpy(char *s1, const char *s2)
{
    while(*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1=*s2;
    return s1;
}

int strcmp(const char *s1, const char *s2)
{
    int comp=0;
    while(*s1||*s2)
    {
        while((*s1==*s2)&&(*s1&&*s2))
        {
            if(*s1>*s2)
                return ++comp;
            if(*s1<*s2)
                return --comp;
            s1++;
            s2++;
        }
        if(*s1>*s2)
            return ++comp;
        if(*s1<*s2)
            return --comp;
    }
    return comp;
}

int strcmpi(const char *s1, const char *s2)
{
    int comp=0;
    while(*s1||*s2)
    {
        while((tolower(*s1)==tolower(*s2))&&(tolower(*s1)&&tolower(*s2)))
        {
            if(tolower(*s1)>tolower(*s2))
                return ++comp;
            if(tolower(*s1)<tolower(*s2))
                return --comp;
            s1++;
            s2++;
        }
        if(tolower(*s1)>tolower(*s2))
            return ++comp;
        if(tolower(*s1)<tolower(*s2))
            return --comp;
    }
    return comp;
}

int strncmp(const char *s1, const char *s2, size_t num)
{
    int comp=0,flag=0;
    while(*s1||*s2)
    {
        while((*s1==*s2)&&(*s1&&*s2)&&(flag<=num))
        {
            if(*s1>*s2)
                return ++comp;
            if(*s1<*s2)
                return --comp;
            s1++;
            s2++;
            flag++;
        }
        if(*s1==*s2)
            return comp;
        if(*s1>*s2)
            return ++comp;
        if(*s1<*s2)
            return --comp;
    }
    return comp;
}

char *strcat(char*s1, const char *s2)
{
    while(*s1)
        s1++; // *s1=\0
    while(*s2)
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1=*s2;
    return s1;
}

char* strstr(char *s1,char *s2)
{
    char* primeraLetraEncontrada;
    char* origS2=s2;
    while(*s1)
    {
        s1++;
        if(*s1==*s2)
        {
            primeraLetraEncontrada=s1;
            while((*s1==*s2)&&(*s2))
            {
                s1++;
                s2++;
            }
        }
        if(!*s2)
            return primeraLetraEncontrada;
        if(s2!=origS2)
            s2=origS2;
    }
    return s1;
}
