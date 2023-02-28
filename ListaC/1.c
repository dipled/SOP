/*Escreva um programa C que imprima o seu nome e os parametros de linha de comando, um por
linha, na ordem inversa.*/
#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Programa: %s\nParametros:\n",argv[0]);
    for(int i = argc-1; i > 0; i -= 1)
    {
        printf("%s\n",argv[i]);
    }
    
    return 0;
}