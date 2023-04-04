void esPrimo(int num){
    int i = 1;
    if(num==1 || num ==2)
        i=0;
    do{
        i++;
        if(num % i == 0 && num != i){
            i=0;
            printf("\nNo es primo\n");
        }
        else if(num == i){
            printf("\nEs primo\n");
            i=0;
        }
    }while(i!=0);
}
