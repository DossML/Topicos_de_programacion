#include "Funciones.h"

#define archAluT        "alumno.txt"
#define ArchEmpl        "empleados.dat"
#define ArchAluB        "alumnos.dat"
#define ArchNovedades   "novedades.dat"

/*

IMPORTANTE!!!!!!!!!!
 
LAS COSAS QUE ESTAN HECHAS NI SE SI ANDAN JASHJASH VERIFIQUEN TODO

PD: 
    EL MERGE ANDA PERO HAY QUE HACERLO CON UN VECTOR DE CHAR (VECNOVEDADES)
    EL TROZADO VARIABLE TMB ANDA

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
    crearLoteEmpl(ArchEmpl);
    crearLoteNovedades(ArchNovedades);
    mostrarEmpl(ArchEmpl);
    mostrarNovedades(ArchNovedades);
    printf("\n\nAPLICAMOS MERGE\n\n");
    if(merge_mio(ArchEmpl, ArchNovedades, (void*)cmpEmpNov))
        return 1;
    printf("\n%s actualizado correctamente segun %s\n\n", ArchEmpl, ArchNovedades);
    mostrarEmpl(ArchEmpl);
    return 0;
}


