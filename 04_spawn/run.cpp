#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int spawn(char* program, char** argv)
{
    pid_t child_pid;
    /*Duplicate the process*/
    child_pid = fork();
    if(child_pid!=0)
        /*This is the parent process*/
        return child_pid;
    else{
        /*Now execute PROGRAM, searching for in the path. */ 
        execvp(program,argv);
        /*The execvp function return only if an error occurs. */
        fprintf(stderr, "an error ocurred in execvp\n");
        abort();
    }
}

int main(int argc, char *argv[])
{
    /*Spawn a child process running the "ls" command. Ignore the 
     * returned child process ID. */
   int salida;
    spawn("ls",argv);
    printf("done woth main program\n");
    wait(&salida);
    printf("Game over\n");

    return 0;

}
