#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#define T_PAR 1
#define T_IMPAR 2
#define NUMELEM 2000000
#define NUMTHREADS 2

typedef struct args
{
    int *v;
    int type;
} Args;

void *conta(void *arguments)
{
    Args *args = (Args *)arguments;
    int t = args->type;
    int *vetor = args->v;
    int total = 0;
    if (t == T_PAR)
    {
        for (int i = 0; i < NUMELEM; i += 1)
        {
            if (vetor[i] % 2 == 0)
                total += 1;
        }
        printf("Total de pares: %d\n", total);
    }
    else
    {
        for (int i = 0; i < NUMELEM; i += 1)
        {
            if (vetor[i] % 2 != 0)
                total += 1;
        }
        printf("Total de impares: %d\n", total);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int i, rc;
    struct timeval tv_ini, tv_fim;
    void *thread_return;
    unsigned long time_diff, sec_diff, usec_diff, msec_diff;
    pthread_t threads[NUMTHREADS];
    int vetor[NUMELEM];
    Args a1, a2;
    srandom(time(NULL));
    for (i = 0; i < NUMELEM; i++)
    {
        vetor[i] = (int)random();
    }

    /* marca o tempo de inicio */
    rc = gettimeofday(&tv_ini, NULL);
    if (rc != 0)
    {
        perror("erro em gettimeofday()");
        exit(1);
    }
    a1.v = vetor;
    a2.v = vetor;
    a1.type = T_PAR;
    a2.type = T_IMPAR;
    /* faz o processamento de interesse */
    rc = pthread_create(&threads[0], NULL, conta, (void *)&a1);
    if (rc)
    {
        printf("ERRO rc=%d\n", rc);
        exit(-1);
    }
    rc = pthread_create(&threads[1], NULL, conta, (void *)&a2);
    if (rc)
    {
        printf("ERRO rc=%d\n", rc);
        exit(-1);
    }
    /*estes pthread_join esperam a thread passada como parametro quittarem, isto eh feito para que o main tenha que esperar
    a conclusao das duas funcoes antes de calcular o tempo tomado para executar todo o codigo*/
    pthread_join(threads[0], &thread_return);
    pthread_join(threads[1], &thread_return);
    /* marca o tempo de final */
    rc = gettimeofday(&tv_fim, NULL);
    if (rc != 0)
    {
        perror("erro em gettimeofday()");
        exit(1);
    }
    /* calcula a diferenca entre os tempos, em usec */
    time_diff = (1000000L * tv_fim.tv_sec + tv_fim.tv_usec) -
                (1000000L * tv_ini.tv_sec + tv_ini.tv_usec);
    /* converte para segundos + microsegundos (parte fracion�ria) */
    sec_diff = time_diff / 1000000L;
    usec_diff = time_diff % 1000000L;

    /* converte para msec */
    msec_diff = time_diff / 1000;
    printf("Tempo de execucao: %lu.%03lu mseg\n", msec_diff, usec_diff % 1000);
    pthread_exit(NULL);
    return 0;
}
