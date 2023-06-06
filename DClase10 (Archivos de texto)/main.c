#include "Funciones.h"

#define archAluT        "alumno.txt"
#define ArchEmpl        "empleados.dat"
#define ArchAluB        "alumnos.dat"
#define ArchNovedades   "novedades.dat"

/*

IMPORTANTE!!!!!!!!!!

LAS COSAS QUE ESTAN HECHAS NI SE SI ANDAN JASHJASH VERIFIQUEN TODO

PD:
    EL TROZADO VARIABLE TMB ANDA
    sscanf
    sprintf

fopen/fclose/remove-rename

bin: fread-fwrite-fseek-fflush-ftell
text:   fputs-fprintf-fgets-sscanf-fscanf-sprintf

A texto:
    ->Solo texto
    ->Campo fijo        10      /Maria Pia  /   7,0
    ->Campo variable    20      /Juan Perez /   5,0

Si el archivo de novedades es peque�o crear un vecNovedades

EJEMPLO SSCANF:
sscanf(linea, "%d|%[^|]|%f, &pAlu.dni, pAlu.NyAp, &pAlu.prom); //NO SE PUEDE USAR %S
                Alternativa a %s -> %[^|] (USAR CON CUIDADO)

EJEMPLO DE FSCANF
while(fscanf(pf, "%d|%[^|]|%f", &pAlu.dni, pAlu.NyAp, &pAlu.prom) == CantCampos)

EJEMPLO DE SPRINTF


*/


int main()
{
/*  PRUEBA PARA EL MERGE CON VECTOR DE NOVEDADES
    tNovedad novedad[11] =
    {// A = 1,7,10,11 | B = 2,4,8 | M = 3,5,6,9
        {{1,"a","b",100},'a'},{{2,"c","d",100},'b'},
        {{3,"e","f",300},'m'},{{4,"g","h",100},'b'},
        {{5,"i","j",400},'m'},{{6,"k","l",200},'m'},
        {{7,"m","n",100},'a'},{{8,"o","p",100},'b'},
        {{9,"q","r",500},'m'},{{10,"s","t",100},'a'},
        {{11,"u","v",100},'a'}
    };
    crearLoteEmpl(ArchEmpl);
    crearLoteNovedades(ArchNovedades);
    mostrarEmpl(ArchEmpl);
    mostrarNovedades(ArchNovedades);
    printf("\n\nAPLICAMOS MERGE\n\n");
    if(merge_vecNov(ArchEmpl, novedad, 11, (void*)cmpEmpNov))
        return 1;
    printf("\n%s actualizado correctamente segun %s\n\n", ArchEmpl, ArchNovedades);
    mostrarEmpl(ArchEmpl);
*/


    return 0;


}
//WRZT7WRWUBAJJVWSGK7C



