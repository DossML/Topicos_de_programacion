#include "Funciones.h"

/*  TAREA

1.Usar qsort                                (No hecho!!!)
    -> Con vector de enteros
    -> Con vector de alumnos

2. Implementar recorrer(map)                (Hecho!!!)
    -> Con vector de enteros
    -> Con vector de alumnos

3. Implementar reducir(reduce)              (Hecho!!!)
    -> Con vector de enteros
    -> Con vector de alumnos (sumar promedio)

4. Implementar filtrar(filter)              (Hecho!!!)
    -> Con vector de enteros
    -> Con vector de alumnos (alumnos con promedio mayor que n)
*/

int main()
{
    //DECLARACIONES
    int i;
    float promTotal = 0, vF = 7;
    tAlu alu[10];
    unsigned cant = 10;
    int vec[] = {8,3,1,5,2,9,4,6};
    int elem = 1;

// PRIMERA PARTE (MUESTRA DE COMO USAR UN PUNTERO A FUNCION)
    void *f;
    f=sumar;
    printf("\nPrimera parte:\n5+5 = %d",((int(*)(int, int))f)(5,5));
    puts("");puts("");puts("");

//SEGUNDA PARTE (IMPLEMENTAR PUNTERO A FUNCION EN FUNCIONES)
    for(i=0; i<10; i++){
        alu[i].DNI = i+1;
        strcpy(alu[i].NyA, "Carlitos");
        alu[i].prom = 0.5+i;
    }
    printf("\nSegunda parte:\n\nAlumnos:\tProm\tDNI\n");
    mostrarVectorAlumnos(alu, 10, (void*)mostrarAlumno);
    puts("");puts("");puts("");

//TERCERA PARTE (MAP/FILTER/REDUCE)
    printf("Tercera parte:\n\n");
    //Ejemplo de REDUCE
    reducir(&alu, cant, sizeof(tAlu), &promTotal, (void*)acum_prom);
    printf("Suma total de los promedios: %.2f", promTotal);
    //Ejemplo de FILTER
    filtrar(&alu, &cant, sizeof(tAlu), &vF, cmp_promedio);
    puts("");puts("");puts("");
    printf("Alumnos con promedio mayor a %.2f:\n\nAlumnos:\tProm\tDNI\n", vF);
    //Ejemplo de MAP
    map(alu, cant, sizeof(tAlu), (void*) mostrarAlumno);

    puts("");

    for(i=0; i<8; i++)
    {
        printf("%d ", vec[i]);
    }

    ordenarSeleccion(vec, 8, sizeof(int), (void*) buscarMenorInt);

    puts("\nVector Ordenado: ");

    for(i=0; i<8; i++)
    {
        printf("%d ", vec[i]);
    }

    //busquedaBinaria(vec, &elem, 8, sizeof(int), cmp_int);

    printf("\nElemento Encontrado: %d", *(int*)busquedaBinaria(vec, &elem, 8, sizeof(int), cmp_int)); // Explota si encuentra un elemento que no esta porque retorna NULL, no lo puedo mostrar.



    return 0;
}
