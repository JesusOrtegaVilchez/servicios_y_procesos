#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semaforo;

void* primer_proceso(void* arg)
{
    
    for(int i=0; i<20; i++){
        printf(" %i hilo 1",i);
        sem_post(&semaforo);
    }
}
void* segundo_proceso(void* arg){
    int seg = 20;
            for(int i = 0; i< seg; i++)
                printf(" %i hilo2",i);
        
}

int main(){
    pthread_t thread;
    pthread_t thread1;
    sem_init(&semaforo,0,0);
    /* Start the computing thread, up to the 5,000th prime number. */
    pthread_create (&thread, NULL,&primer_proceso,NULL);
    sem_wait(&semaforo);
    pthread_create(&thread1,NULL,&segundo_proceso,NULL);
    /* Do some other work here... */
    /* Wait for the prime number thread to complete, and get the result.*/
    pthread_join (thread,NULL);
    pthread_join(thread1,NULL);
    /* Print the largest prime it computed. */
    printf("/n"); 
    return 0;

}
