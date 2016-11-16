#include <stdio.h>

/*The ENVIRON variable contain the enviaronment.  */

extern char** environ;

int main(int argc, char** argv[]){

    char ** var;
    for(var = environ; *var != NULL; var++)
        printf("%s\n", *var);
    return 0;

}
