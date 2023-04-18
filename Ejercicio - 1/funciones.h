int factorial(int num){
    int i;
    for(i=num; i>0; i--){
        num *= i;
    }
    return num;
}