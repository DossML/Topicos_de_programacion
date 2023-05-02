#include "ofuscado.h"
#define MAXLINE 512

int main()
{
    /*
    Ejercicio tipo examen
    ----------------------
    Mediante el metodo obtenerLineaOfuscada adquiera una cita en texto afuscada que impide
    su lectura. Cada palabra de las citas se ha ofuscado tomando cada letra y si la misma se
    encuentra en el grupo "abcdghijkoqtuv" se remplaza por la letra que esta hacia la izquierda
    tantos lugares como posicion en la palabra ocupa. Una palabra es un conjunto contiguo de
    caracteres considerados por la funcion isalpha.
    Ejemplo:
    Si la palabra es hola
    "h":un lugar atras porque es la primera letra de la palabra, quedaria "g"
    "o":dos lugares atras, quedaria "j"
    "l":No figura en grupo, no se modifica, queda "l"
    "a":cuatro lugares hacia atras, queda "q".
    Resultado esperado: hola => gjlq
    Sabiendo como se ha ofuscado implemente un algoritmo que le muestre la frase desofuscada.
    Nota: Las frases estan en espanol y son varias, en cada ejecucion puede obtener cualquiera
    aleatoriamente.

    Consejos: Antes de escribir codigo entienda el problema y establezca una estrategia de
    solucion. Establezca tambien las divisiones y pruebe individualmente que funcionen con
    pequeños ejemplos.

    Disclaimer: Las citas no representan las opiniones de quien formulo el ejercicio :)
    */

    char linea[1024];
    int i = 0;
    //char msj[]="gjlq vbdhs";

    do{
    obtenerLineaOfuscada(linea);
    printf("%s\n", linea);
    desofuscar_ALU(linea);
    printf("\nMensaje desofuscado:\n%s\n",linea);
    system("PAUSE()");
    system("CLS()");
    }while(i == 0);


    return 0;
}

