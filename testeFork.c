#include <stdio.h>
#include <unistd.h>
int main()
{
    int f;
    f = fork(); //caso seja o processo pai, f vale PID, senao f vale 0
    if(f) printf("Processo pai\tPID: %d\n\n",getpid());
    else printf("Processo filho\tPID: %d\n\n",getpid());
    return 0;
}
