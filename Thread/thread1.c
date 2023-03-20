#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 3
void *func(void *x)
{
    long *y = (long *)x;
    *y = 32;
    printf("Thread x = %ld\n",*y);
    pthread_exit(NULL);
}
int main(int argc, char **argv)
{
    long x = 1;
    printf("Inicial x = %ld\n", x);
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, func, (void *)&x);
    }
    printf("Final x = %ld\n", x);
    
    pthread_exit(NULL);
}