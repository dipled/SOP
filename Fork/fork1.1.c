#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("pai: %d\n", getpid());
    int f = fork();
    if (!f)
        printf("filho do %d: %d\n", getppid(), getpid());
    else
    {
        f = fork();
        if (!f)
            printf("filho do %d: %d\n", getppid(), getpid());
        else
        {
            f = fork();
            if (!f)
                printf("filho do %d: %d\n", getppid(), getpid());
        }
    }
}