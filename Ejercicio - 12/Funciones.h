/*Ejercicio 12
Construir un programa que lea un número natural N y calcule la suma de los números pares
menores que N*/
int sumaParesMenoresA(int num){
    int i = 2, sum=0;
    while(i<num){
        sum += i;
        i+=2;
    }
    return sum;
}