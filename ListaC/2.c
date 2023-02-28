/*Escreva um programa C que receba um inteiro como parametro na linha de comando, e mostre quan-
tos bits 1 tem a representacao bin ́aria desse numero.*/
#include <stdio.h>
#include <stdlib.h>
int count_ones(int num);
int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    printf("%d", count_ones(num));
    return 0;
}
int count_ones(int num)
{
    int q_1 = 0;
    while (num > 0)
    {
        if (num % 2 != 0)
        {
            q_1 += 1;
        }
        num /= 2;
    }
    return q_1;
}