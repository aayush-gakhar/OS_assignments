#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    setpriority(PRIO_PROCESS, 0, 5);

    printf("process pid: %d\n",getpid());
    printf("\nrunning...\n");

    while (1);
    
    return 0;
}
