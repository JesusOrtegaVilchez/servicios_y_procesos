#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* print(void *parameter)
{
    char *caracter = (char *) parameter;
    for(int i = 0; i<40000;i++)
        fputc(*caracter,stderr);
    return NULL;

}

/*THE MAIN PROGRAM*/

int main(){
    pthread_t thread_id1, thread_id2;
    char x = 'x';
    char o = 'o';
    /*create a new thread. The new thread will run the print_xs function*/

    pthread_create(&thread_id1,NULL, &print, &x);
    pthread_create(&thread_id2,NULL, &print, &o);

    pthread_join(thread_id1,NULL);
    pthread_join(thread_id2,NULL);
    /*print o's continuously to stderr. */ 
    return 0;
}
