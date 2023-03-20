#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 13

void *PrintHello(void *arg)
{
   long tid = (long)arg;
   printf("Alo da thread %ld\n\n",
          tid);
   pthread_exit(NULL);
}
void *PrintQuadrado(void *arg)
{
   long quadrado = (long)arg * (long)arg;
   printf("Quadrado do argumento: %ld\n\n", quadrado);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for (t = 0; t < NUM_THREADS; t++)
   {
      printf("main: criando thread %ld\n", t);
      if (t < NUM_THREADS)
      {
         rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
         if (rc)
         {
            printf("ERRO - rc=%d\n", rc);
            exit(-1);
         }
      }
      rc = pthread_create(&threads[t],NULL, PrintQuadrado, (void*) t);
      if(rc)
      {
         printf("ERRO - tc=%d\n",rc);
         exit(-1);
      }

   }
   /* Ultima coisa que main() deve fazer */
   pthread_exit(NULL);
}
