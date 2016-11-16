#include <pthread.h>
#include <stdio.h>

struct char_print_parm
{   /*character ti print*/
    char character;
    /*the number of times to print*/
    int count;
};

/*Prints a number of characters to stderr, as given by Parameters,
 *which is a pointer to a struct char_print_parms*/

void* char_print(void* parameters)
   {
       /*cast the cookie pointer to the right type */
       struct char_print_parm* p = (struct char_print_parm*)parameters;
       for(int i = 0; i<p->count; ++i)
           fputc(p->character,stderr);
       return NULL;
   }

int main()
{
    pthread_t thread1_id;
    pthread_t thread2_id;
    struct char_print_parm thread1_args;
    struct char_print_parm thread2_args;

    /*Create a nre thread to print "x amount of 'x's */

    thread1_args.character = 'x';
    thread1_args.count = 400;
    pthread_create(&thread1_id,NULL,&char_print, &thread1_args);

    /*Create a new thread to print 400 times 'O'*/

    thread2_args.character = 'o';
    thread2_args.count = 400;
    pthread_create(&thread1_id,NULL,&char_print,&thread2_args);
    
    /*Make sure the first thread has finished */
    pthread_join(thread1_id,NULL);
    /*Make sure the second thread has finished */
    pthread_join(thread2_id,NULL);
    /*now we can safely return */


    return 0;
}
