#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*WRITE COUNT copies of MESSAGE to STREAM, pausing for a second*/

void writer(const char* message, int count, FILE* stream)
{
        for(;count >0; --count){
            /*write the message to the stream, and send it off inmediately*/
            fprintf(stream, "%s\n",message);
            fflush(stream);
            /*snooze a while*/
            sleep(1);
        }    
}
/*Read random strings from the stream as long as possible*/

void reader (FILE* stream)
{
    char buffer[1024];
    /*Read until we hit the end of the stream. fgets reads until
     * either a newline or the end-of-file*/
    /*Lee hasta que llegamos al final de stream. fgets lee hasta una nueva linea o el final de fichero*/
    while(!feof (stream)
        && !ferror (stream)
        && fgets (buffer,sizeof(buffer),stream) !=NULL)
       fputs(buffer,stdout);
}

int main()
{
   int fds[2];
   pid_t pid;

   /*Create a pipe. FIle descriptors for the two of the pipe are
    * placed in fds*/
   pipe (fds);
   /*Fork a child process*/
   pid = fork();
   if(pid == (pid_t) 0 ){
       FILE* stream;
   /*This is child process. Close our copy of the write end of the file descriptor*/
   close(fds[1]);
   /*Convert the read file descriptor to a FILE object, and read from it*/
   stream = fdopen(fds[0],"r");
   reader(stream);
   close(fds[0]);
   }
   else{
       /*this is the parent process */
       FILE* stream;
       /*Close our copy of the read end of the file descriptor*/
       close(fds[0]);
       /*Converte the write file descriptor to a FILE object, and write to it*/
       stream = fdopen(fds[1],"w");
       writer("What's my nameeeee!!",5,stream);
       close(fds[1]);
   }
   return 0;
}
