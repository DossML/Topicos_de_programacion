#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t strlen_mia(const char *cad);
char *strcpy_mia(char *cad1, const char *cad2);
int strcmp_mia(const char *cad1, const char *cad2);
int strcmpi_mia(const char *cad1, const char *cad2);
int strncmp_mia(const char *s1, const char *s2, size_t n);
char *strcat_mia(char*s1, const char *s2);
char* strstr_mia(const char *s1, const char *s2);

int main()
{
    char s1[2] = {"b"};
    char s2[30] = {"aaaaaaaabcaaaaade"};
    printf("%s", strstr_mia(s1,s2));
    char s3[2] = {"b"};
    char s4[6] = {"abcde"};
    printf("\n\n%s", strstr(s3,s4));


    return 0;
}

size_t strlen_mia(const char *cad)
{
    size_t i=0;

    while(*cad)
    {
        i++;
        cad++;
    }

    return i;
}

char *strcpy_mia(char *cad1, const char *cad2)
{
    char *pi = cad1;

    while(*cad2)
    {
        *cad1 = *cad2;
        cad1++;
        cad2++;
    }

    *cad1 = '\0';

    return pi;
}

int strcmp_mia(const char *cad1, const char *cad2)
{
    int cmp = 0;

    while(*cad1 && *cad2)
    {
        if((*cad2)-(*cad1) < 0)
            return cmp=1;

        else if((*cad2)-(*cad1) > 0)
            return cmp = -1;

        cad1++;
        cad2++;
    }

    return cmp;
}

int strcmpi_mia(const char *cad1, const char *cad2)
{
    int cmp = 0;

    while(*cad1 && *cad2)
    {
        if((*cad2)-(*cad1) < 0 && (*cad2)-(*cad1) != 32 && (*cad2)-(*cad1) != -32)
            return cmp=1;

        else if((*cad2)-(*cad1) > 0 && (*cad2)-(*cad1) != 32 && (*cad2)-(*cad1) != -32)
            return cmp = -1;

        cad1++;
        cad2++;
    }

    return cmp;
}

int strncmp_mia(const char *cad1, const char *cad2, size_t n){
    int cmp = 0;

    while(n)
    {
        if((*cad2)-(*cad1) < 0)
            return cmp=1;

        else if((*cad2)-(*cad1) > 0)
            return cmp = -1;

        cad1++;
        cad2++;
        n--;
    }
    return cmp;
}

char *strcat_mia(char*s1, const char *s2){
    char* inicio = s1;
    s1 += strlen_mia(s1);
    while(*s2){
        *s1 = *s2;
        s1++;
        s2++;
    }
    return inicio;
}

char *strstr_mia(const char *cad1, const char *cad2){

    int pos = 0;

    while(*cad2 && *cad1)
    {
        if((*cad2)==(*cad1)){
            cad1++;
            pos++;
        }

        else{
            cad1 -= pos;
            pos = 0;
        }
        cad2++;
    }

    return cad2 - strlen_mia(cad1)-1;
}
