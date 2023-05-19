#include "vector.h"
#include "archivos.h"


int main(){

//PRIMERA PARTE - EJERCICIO DE MAP/FILTER/REDUCE (CREAMOS UN FILTER MEJORADO)

    //MAP/REDUCE/FILTER CON VENTAS
    //Ejercicio: Obtener en una sola pasada el promedio de las ventas de mas de 200.00 dolares

    int i;
    int vectorInt[4] = {1,5,1,6};
    unsigned ce = 3;
    float vF=200, promVentas=0;
    puts("PRIMERA PARTE");
    tVenta vec[3]={{10,{30,10,1960},35.00},{17,{20,5,1981},350.0}, {29,{15,2,1996},900.3}};

    filtrar(vec, &ce, sizeof(tVenta), &vF, (void*)cmp_venta);
    reducir(vec, ce, sizeof(tVenta), &promVentas, (void*)acum_venta);
    map(vec, ce, sizeof(tVenta), (void*)mostrarVenta);
    printf("\nEl promedio de las ventas es: %.2f", promVentas/ce);
    puts("");puts("");puts("");

    //SEGUNDA PARTE - ORDENAMIENTO
    puts("SEGUNDA PARTE");
    printf("\nVector desordenado:\t%d, %d, %d, %d", vectorInt[0], vectorInt[1], vectorInt[2], vectorInt[3]);
    ordenamiento_por_seleccion(vectorInt,4,sizeof(int), (void*)buscar_menor_int);
    printf("\nVector ordenado:\t%d, %d, %d, %d\n", vectorInt[0], vectorInt[1], vectorInt[2], vectorInt[3]);
    puts("");puts("");puts("");
    //TERCERA PARTE - ARCHIVOS
    puts("TERCER PARTE");
    /*
    Modos de apertura
        w   (b/t)
        r   (b/t)
    w=write
    r=read
    b=binary
    t=text
    */

    //WRITE
    FILE *pf = fopen("ventas.dat", "wb");
    if(!pf)
        return 1;   //Si falla la apertura del archivo, retorna 1

    //3 EJEMPLOS DE ESCRITURA DE ARCHIVOS QUE SON VALIDOS
    fwrite(vec, sizeof(tVenta), ce, pf);
    //fwrite(vec, sizeof(vec), sizeof(vec)/sizeof(tVenta), pf);
    //for(i=0; i<ce; i++)
    //    fwrite(vec, sizeof(tVenta), 1, pf);
    fclose(pf);

    //READ
    tVenta vec3[2];
    FILE *pf2 = fopen("ventas.dat", "rb");
    if(!pf2)
        return 1;   //Si falla la apertura del archivo, retorna 1
    fread(vec3, sizeof(tVenta), ce, pf2);
    map(vec3, ce, sizeof(tVenta), (void*)mostrarVenta);
    fclose(pf2);

    return 0;
}
