#include <stdio.h>
#include <math.h>
int main()
{
    double media;
    int sum = 0;
    int sum_pow = 0;
    int quantidade = 0;
    double desvio_padrao;
    int num;
    while(1){
        scanf("%d",&num);
        if(num == -1)
            break;
        sum += num;
        sum_pow += num*num;
        quantidade += 1;
    }
    media = sum/(double)quantidade;
    desvio_padrao = sqrt((sum_pow-(2*media*sum)+quantidade*media*media)/(double)quantidade);
    printf("Media = %lf\nDesvio padrao = %.2lf",sum,media,desvio_padrao);
    return 0;
}