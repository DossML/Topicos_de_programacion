#include "Ej13.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int crearLoteEmpl(const char* nom_archv)
{
    int i;
/*  LOTE DE PRUEBA PARA EL EJERCICIO 13 (PRIMERA PARTE)*/
    tEmpl empl[10] = {{1,"b","a",100},{2,"z","a",200},{3,"c","b",300},{4,"d","b",400},{5,"e","e",500},
                      {6,"f","f",600},{7,"g","g",700},{8,"h","h",800},{9,"i","i",900},{10,"j","j",1000}};

//  LOTE DE PRUEBA PARA EL MERGE (SEGUNDA PARTE)
/*
    tEmpl empl[10] = {{1,"a","a",100},{2,"c","d",100},{3,"e","f",100},{4,"d","b",400},{5,"e","e",500},
                      {6,"f","f",600},{7,"g","g",700},{8,"o","p",100},{9,"q","r",100},{10,"s","t",100}};
*/

    FILE* pf = fopen(nom_archv, "wb");

    if(!pf)
        return 1;
    for(i = 0; i<10; i++)
        fwrite(&empl[i], sizeof(tEmpl), 1, pf);

    fclose(pf);

    return 0;
}

int crearLoteAlu(const char* nom_archv)
{
    int i;

    tAlumno alu[10] = {{1,"a","a",9},{2,"b","a",7.3},{3,"c","b",2.5},{4,"d","b",9.7},{5,"e","e",8}};

    FILE* pf = fopen(nom_archv, "wb");

    if(!pf)
        return 1;
    for(i = 0; i<5; i++)
        fwrite(&alu[i], sizeof(tAlumno), 1, pf);

    fclose(pf);

    return 0;
}

int crearLoteNovedades(const char* nom_archv)
{
    int i;

    tNovedad nov[10] = {{{1,"a","b",100},'a'},{{2,"c","d",100},'b'},{{3,"e","f",300},'m'},{{4,"g","h",100},'b'},{{5,"i","j",400},'m'},       // A = 1,7,10 | B = 2,4,8 | M = 3,5,6,9
                        {{6,"k","l",200},'m'},{{7,"m","n",100},'a'},{{8,"o","p",100},'b'},{{9,"q","r",500},'m'},{{10,"s","t",100},'a'}};

    // 1,2,3,8,7,9 no tienen error.
    // 10,4,5,6 tiene error.

    FILE* pf = fopen(nom_archv, "wb");

    if(!pf)
        return 1;
    for(i = 0; i<10; i++)
        fwrite(&nov[i], sizeof(tNovedad), 1, pf);

    fclose(pf);

    return 0;
}


int actualizarArchivosEmpl(const char* arch1, const char* arch2, int cmp_EmplAlu(void*, void*))
{
    tAlumno alu;
    tEmpl empl;
    int cmp = 0;

    FILE* pEmpl = fopen(arch1, "r+b");

    if(!pEmpl)
        return 1;

    FILE*  pAlu = fopen(arch2, "rb");

    if(!pAlu)
        return 1;


    fread(&alu, sizeof(tAlumno), 1, pAlu);
    fread(&empl, sizeof(tEmpl), 1, pEmpl);

    while(!feof(pAlu))
    {

        cmp = cmp_EmplAlu(&alu,&empl);


        if(cmp == 1)
            fread(&alu, sizeof(tAlumno), 1, pAlu);


        else if(cmp == -1)
            fread(&empl, sizeof(tEmpl), 1, pEmpl);

        else if(cmp == 0)
        {
            empl.sueldo*=1.0728;
            fseek(pEmpl, -1*(int)sizeof(tEmpl), SEEK_CUR);
            fwrite(&empl, sizeof(tEmpl), 1, pEmpl);
            fflush(pEmpl);
            fread(&alu, sizeof(tAlumno), 1, pAlu);
        }

    }

    fclose(pEmpl);
    fclose(pAlu);

    return 0;
}

int cmp_EmplAlu(void* alu, void* empl)
{
    tAlumno* alumno = (tAlumno*)alu;
    tEmpl* empleado = (tEmpl*)empl;

    int cmp=0;

    cmp = strcmp(empleado->apellido, alumno->apellido);
    if(cmp != 0)
        return cmp;

    cmp = strcmp(empleado->nombre, alumno->nombre);
    if((cmp != 0))
        return cmp;

    if(alumno->dni != empleado->dni)
        return -1;

    if(alumno->promedio < 7)
        return 1;

    return 0;
}

int mergeEmpleadosNovedades(const char* arch1, const char* arch2, int cmp_NovEmpl(void*, void*))
{
    tEmpl empl;
    tNovedad nov;
    tEmpl temp;

    int cmp = 0;

    FILE* pEmpl = fopen(arch1, "rb");

    if(!pEmpl)
        return 1;

    FILE*  pNov = fopen(arch2, "rb");

    if(!pNov)
        return 1;

    FILE*  pTemp = fopen("temporal.dat", "wb");

    if(!pTemp)
        return 1;

    fread(&nov, sizeof(tNovedad), 1, pNov);
    fread(&empl, sizeof(tEmpl), 1, pEmpl);

    while(!feof(pNov))
    {

        cmp = cmp_NovEmpl(&nov, &empl);

        if(nov.tipo == 'a' && cmp != 0)
        {
            temp.dni = nov.empleado.dni;
            strcpy(temp.nombre,nov.empleado.nombre);
            strcpy(temp.apellido,nov.empleado.apellido);
            temp.sueldo = nov.empleado.sueldo;

            fwrite(&temp, sizeof(tEmpl), 1, pTemp);
            fflush(pTemp);
        }
        else if(nov.tipo == 'm' && cmp == 0)
        {
            temp.dni = nov.empleado.dni;
            strcpy(temp.nombre,nov.empleado.nombre);
            strcpy(temp.apellido,nov.empleado.apellido);
            temp.sueldo = nov.empleado.sueldo;

            fwrite(&temp, sizeof(tEmpl), 1, pTemp);
            fflush(pTemp);
        }
        else if(nov.tipo == 'b' && cmp == 0)
        {
            fflush(pTemp);
        }
        else
        {
            printf("Error.\t");
        }

        fread(&nov, sizeof(tNovedad), 1, pNov);
        fread(&empl, sizeof(tEmpl), 1, pEmpl);
    }

    fclose(pNov);
    fclose(pTemp);
    fclose(pEmpl);

    remove(arch1);

    rename("temporal.dat", arch1);

    return 0;

}

int cmp_NovEmpl(void* nov, void* empl)
{
    tNovedad* novedad= (tNovedad*)nov;
    tEmpl* empleado= (tEmpl*)empl;

    int cmp = 1;

    cmp = strcmp(empleado->apellido, novedad->empleado.apellido);
    if(cmp != 0)
        return cmp;

    cmp = strcmp(empleado->nombre, novedad->empleado.nombre);
    if((cmp != 0))
        return cmp;

    if(novedad->empleado.dni != empleado->dni)
        return cmp;

    return 0;
}


int mostrarEmpl(char* nombreArch)
{
    FILE* archBin=fopen(nombreArch,"rb");
    if(!archBin)
        return 1;

    tEmpl emp;
    printf("\nArchivo leido: %s\n", nombreArch);
    fread(&emp,sizeof(tEmpl),1,archBin);
    while(!feof(archBin))
    {
        printf("DNI: %d\t\tNombre: %s\tApellido: %s\tSueldo: %.2f\n",emp.dni, emp.nombre, emp.apellido, emp.sueldo);
        fread(&emp,sizeof(tEmpl),1,archBin);

    }

    fclose(archBin);
    return 0;
}

int mostrarAlumno(char* nombreArch)
{
    FILE* archBin=fopen(nombreArch,"rb");
    if(!archBin)
        return 1;

    tAlumno alu;
    printf("\nArchivo leido: %s\n", nombreArch);
    fread(&alu,sizeof(tAlumno),1,archBin);
    while(!feof(archBin))
    {
        printf("DNI: %d\t\tNombre: %s\tApellido: %s\tPromedio: %.1f\n",alu.dni, alu.nombre, alu.apellido, alu.promedio);
        fread(&alu,sizeof(tAlumno),1,archBin);

    }

    fclose(archBin);
    return 0;
}

int mostrarNovedades(char* nombreArch)
{
    FILE* archBin=fopen(nombreArch,"rb");
    if(!archBin)
        return 1;

    tNovedad nov;
    printf("\nArchivo leido: %s\n", nombreArch);
    fread(&nov,sizeof(tNovedad),1,archBin);
    while(!feof(archBin))
    {
        printf("DNI: %d\t\tNombre: %s\tApellido: %s\tSueldo: %.2f\tTipo: %c\n", nov.empleado.dni, nov.empleado.nombre, nov.empleado.apellido, nov.empleado.sueldo, nov.tipo);
        fread(&nov,sizeof(tNovedad),1,archBin);

    }

    fclose(archBin);
    return 0;
}
