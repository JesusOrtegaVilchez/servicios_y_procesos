#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void* compute_prime (void* arg)
{
    int candidate = 2;
    int n = *((int*) arg);
    while (1) {
        int factor;
        int is_prime = 1;
        /* Test primality by successive division. */
        for (factor = 2; factor < candidate; ++factor)
            if (candidate % factor == 0) {
                is_prime = 0;
                break;
            }
        /* Is this the prime number we’re looking for? */
        if (is_prime) {
            if (--n == 0)
                /// Return the desired prime number as the thread return value.
                return (void*) candidate;
        }
        ++candidate;
    }
    return NULL;
}
void* crono(void* arg){

}

int main(){
    pthread_t thread;
    pthread_t thread1;
    int which_prime = 5000;
    int which_number=5000;
    int prime;
    /* Start the computing thread, up to the 5,000th prime number. */
    pthread_create (&thread, NULL, &compute_prime, &which_prime);
    pthread_create(&thread1,NULL,&crono,&wich_number);
    /* Do some other work here... */
    /* Wait for the prime number thread to complete, and get the result.*/
    pthread_join (thread, (void*) &prime);
    pthread_join(thread1,(void*) &number);
    /* Print the largest prime it computed. */
    printf("The %i prime number is %i.\n", which_prime, prime);
    printf("crono is: %i",which_number,number);
    return 0;

}
