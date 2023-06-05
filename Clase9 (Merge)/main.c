#include <stdio.h>
#include <stdlib.h>
#include "Ej13.h"

#define ArchEmpl "empleados.dat"
#define ArchAlu "alumnos.dat"
#define ArchNovedades "novedades.dat"

/*  ANOTACIONES DE LA CLASE!
    Comandos FILE:
    fopen/fclose

    Modos de apertura
        w   (b/t) -> wb/wt
        r   (b/t) -> rb/rt
        w=write
        r=read
        b=binary
        t=text

    Comandos de archivos binarios: fwrite/fread/

    ejemplos de fopen:
        fopen("empleados.dat", "rb"); //Si no lo encuentra deja el puntero en null
        fopen("C:\midesc\empleados.dat", "rb");
        fopen("..\empleados.dat", "rb");

        fopen("empleados.dat", "wb"); //Si lo encuentra pisa el anterior archivo
        fopen("C:\midesc\empleados.dat", "wb");
        fopen("..\empleados.dat", "wb");

        fseek(pf,sizeof(emp), seek_set);    Inicio
        fseek(pf,sizeof(emp), seek_end);    Fin
        fseek(pf,sizeof(emp), seek_cur);    Actual al final del dato

        fflush(pf); or fseek(pf, 0, seek_cur);
        Limpia la basura ya que se usa el mismo buffer para escribir y leer

        Hacer ejercicio 13:

        Subir 7.28% el sueldo de los empleados que esten registrados como estudiantes y tengan promedio mayor a 7

        MERGE:
            a=alta          -> Si encuentro entonces error      /Si no encuentro lo agrego a temp
            b=baja          -> Si encuentro entonces lo borro   /Si no lo encuentro error
            m=modificacion  -> Si encuentro entonces modifico   /Si no encuentro error

            Para los errores usar printf (Temporalmente)

            Condicion de corte -> Hasta que termine el archivo de novedades, recorrer en simultaneo.
            Remove "Archivo.dat" -> Rename "Temporal.dat"
*/

int main()
//IMPORTANTE!!!
//  Para una mejor experiencia, elegir en la funcion "crearLoteEmpl" el lote de pruebas correspondiente
{
//  PRIMERA PARTE (EJERCICIO 13 (ARCHIVOS))
/*    crearLoteAlu(ArchAlu);
    crearLoteEmpl(ArchEmpl);
    mostrarEmpl(ArchEmpl);
    mostrarAlumno(ArchAlu);
    if(actualizarArchivosEmpl(ArchEmpl, ArchAlu, cmp_EmplAlu))
        return 1;
    printf("\n%s actualizado correctamente\n\n", ArchEmpl);
    mostrarEmpl(ArchEmpl);*/

//  SEGUNDA PARTE (MERGE)

    crearLoteEmpl(ArchEmpl);
    crearLoteNovedades(ArchNovedades);
    mostrarEmpl(ArchEmpl);
    mostrarNovedades(ArchNovedades);
    printf("\n\nAPLICAMOS MERGE\n\n");
    if(mergeEmpleadosNovedades(ArchEmpl, ArchNovedades, cmp_NovEmpl))
        return 1;
    printf("\n%s actualizado correctamente segun %s\n\n", ArchEmpl, ArchNovedades);
    mostrarEmpl(ArchEmpl);

    return 0;
}
