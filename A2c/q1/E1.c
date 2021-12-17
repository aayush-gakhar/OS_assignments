#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <sys/signal.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/time.h>
#include <sys/shm.h>

#define interval 1000


pid_t pid1;
key_t key;
int shmid;

static void sig_handler2(int signo)
{
    if (signo == SIGALRM)
    {
        printf("SIGALRM received(SR)\n");
        unsigned long long num;
        asm( "rdrand %0" : "=r" ( num ));
        printf("Random number: %llu\n\n", num);
        char *str = (char*) shmat(shmid,(void*)0,0);
        sprintf(str,"%llu",num);
        shmdt(str);
        kill(pid1, SIGTERM);
    }
}

int main(int argc, char *argv[]){
    if(signal(SIGALRM,sig_handler2)==SIG_ERR){
        perror("signal");
        exit(1);
    }
    pid1=atoi(argv[0]);
    key = ftok("shared", 'a');
    shmid=shmget(key,1024, 0666 | IPC_CREAT);

    struct itimerval it_val;
    it_val.it_value.tv_sec =interval/1000;
    it_val.it_value.tv_usec =(interval*1000) % 1000000;
    it_val.it_interval = it_val.it_value;
    if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
        perror("error calling setitimer()");
        exit(1);
    }
    pause();
    int x=5;
    while (x) 
        pause();
}

