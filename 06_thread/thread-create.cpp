#include <stdio.h>
#include <pthread.h>

void* print_xs(void* unused)
{
    while (10)
        fputc('x',stderr);
    return NULL;

}

/*THE MAIN PROGRAM*/

int main(){
    pthread_t thread_id;
    /*create a new thread. The new thread will run the print_xs function*/
    pthread_create(&thread_id,NULL,&print_xs,NULL);
    /*print o's continuously to stderr. */ 
    while(1)
        fputc('o',stderr);
    return 0;
}
