#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "interfaz.h"

int factorial(int n){

    return (n == 0 ?/*operador condicional si prueba que es verdadero, si lo es escribe 1 sino sigue con */ 1:n * factorial(n-1));
}



double e(double error){
    double result= 0, term;
    //1/factorial(0)+º/factorial(1)+1/factorial(2)+...
    //1/f(0)+1/f(1)+1/f(2)+1/f(3)+1/f(4)+...
    int i=0;
    for(int i=0;(term= 1./ factorial(i)) > error; i++){ 
        result += term;
    }
    return result;
}

int main(int argc, char *argv[]){
    double error;
    if(argc < 2)
        print_usage(argv[0]);
    error = atof(argv[1]);
    printf("e = %lf",e(error));
    return EXIT_SUCCESS;
}
