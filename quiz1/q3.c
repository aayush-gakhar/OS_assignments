#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>

int main()
{
    pid_t pid1;
    printf("before fork()\n");
    if((pid1=fork())>0)
    {
        waitpid(pid1,NULL,0);
    }
    else if(pid1==0){
        execl("/usr/bin/bash","bash",NULL);
        printf("done launching the shell\n");
        exit(0);
    }
    else{
        perror("fork()");
    }
}