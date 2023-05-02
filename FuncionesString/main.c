#include "Funciones.h"

int main()
{
    int i;
    char oracion[]={"Hola, buenos dias Gustavo. Te gusta tocar la guitarra? Si es asi hagamos una banda"};
    char oracionNeeko[]={"guitarra"};
    char* oracionDesde;
    int cantCaracteres=strlen(oracion);
    printf("La oracion: %s\nTiene %d caracteres\n",oracion,cantCaracteres);
    strcpy(oracionNeeko,oracion);
    printf("\nOracion copiada:%s\n",oracionNeeko);
    i=strncmp(oracion,oracionNeeko,17);
    printf("\nOrdenando oraciones:\n");
    if(i>0)
    {
        printf("%s\n",oracion);
        printf("%s\n",oracionNeeko);
    }
    if(i<0)
    {
        printf("%s\n",oracionNeeko);
        printf("%s\n",oracion);
    }
    if(i==0)
    {
        printf("\nOracion repetida\n");
    }
    strcat(oracion,oracionNeeko);
    printf("\nOraciones concatenadas:\n%s\n",oracion);

    oracionDesde=strstr(oracion,oracionNeeko);

    printf("\n\nOracion desde la palabra '%s' encontrada:\n%s\n",oracionNeeko,oracionDesde);
    return 0;
}
