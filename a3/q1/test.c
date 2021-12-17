#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

#define sys_delay_process 448

int main(int argc, char const *argv[])
{
    setpriority(PRIO_PROCESS, 0, 5);

    int res = syscall(sys_delay_process, getpid(), 5);

    printf("process pid: %d syscall returned: %d\n",getpid(), res);
    printf("\nrunning...\n");

    while (1);
    
    return 0;
}
