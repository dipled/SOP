#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX 2147483648
#define NUM_THREADS 8

void* conta(void* start)
{
    long contador = 0;
    for(long i = (long)start; i < (long)start + MAX/NUM_THREADS; i += 1)
    {
        contador += 1;
    }
    pthread_exit((void*) contador);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    long start;
    void* retorno;
    long contador;
    for(int i = 0; i < NUM_THREADS; i += 1)
    {
        start = i*MAX/NUM_THREADS;
        pthread_create(&threads[i],NULL,conta,(void*)start);
    }
    for(int i = 0; i < NUM_THREADS; i += 1)
    {
        pthread_join(threads[i],&retorno);
        contador += (long) retorno;
    }
    printf("total: %ld\n",contador);
    pthread_exit(NULL);

}