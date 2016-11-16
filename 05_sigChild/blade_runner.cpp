#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 0x1000
#define N 0x100

int main(){
    char buffer [MAX];
    char *command[N];
    char *parse = buffer;
    char *command[N];
    printf("Command: ");
    scanf(" %s", buffer);//sin & porque ya es la direccion de memoria de la reserva
    while ( (command[i++] = strtock(parse, " ")) !=NULL );
        parse = NULL;
    for(int i =0; command[i] != NULL; i++){
        printf(" %s\n", commmand[i]);
    }
    return EXIT_SUCCESS;

}
