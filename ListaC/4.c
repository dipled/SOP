#include <stdio.h>
#include <stdlib.h>
void print_fila(int *fila, int quantidade_lido)
{
    printf("Fila:");
    for (int i = 0; i < quantidade_lido; i += 1)
    {
        printf("%d ", fila[i]);
    }
    printf("\n");
}
void move_para_tras(int *fila, int num, int quantidade)
{
    for (int i = 0; i < quantidade-1; i += 1)
    {
        fila[i] = fila[i+1];
    }
    fila[quantidade-1] = num;
}
int main(int argc, char *argv[])
{
    int quantidade = atoi(argv[1]);
    int fila[quantidade];
    int num;
    int quantidade_lido = 0;
    int posicao;
    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
            return 0;
        if (num == -2)
            print_fila(fila, quantidade_lido);
        else if(quantidade_lido == quantidade)
        {
            
            move_para_tras(fila,num,quantidade);
        }
        else
        {
            fila[quantidade_lido] = num;
            quantidade_lido += 1;
        }
    }
   
}