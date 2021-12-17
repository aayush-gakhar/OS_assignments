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
#include <stdint.h>
#include <sys/shm.h>

// frequency in GHz
#define frequency 1.2


pid_t pid1;
key_t key;
int shmid;

static void sig_handler3(int signo)
{
    if (signo == SIGALRM)
    {
        printf("SIGALRM received(ST)\n");
        unsigned long long hi, lo;
        asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
        unsigned long long num =lo| hi<<32 ;
        printf("time stamp: %llu\n", num );
        num/=frequency*1000000000;
        
        int hr=num/3600;
        num%=3600;
        
        int min=num/60;
        num%=60;

        int sec=num;

        printf("time: %02d:%02d:%02d\n\n",hr,min,sec);

        char *str = (char*) shmat(shmid,(void*)0,0);
        sprintf(str,"%02d:%02d:%02d",hr,min,sec);
        shmdt(str);
        kill(pid1, SIGTERM);
    }
}


int main(int argc, char *argv[]){
    if(signal(SIGALRM,sig_handler3)==SIG_ERR){
        perror("signal");
        exit(1);
    }
    pid1=atoi(argv[0]);
    key = ftok("shared", 'a');
    shmid=shmget(key,1024, 0666 | IPC_CREAT);

    struct itimerval it_val;
    it_val.it_value.tv_sec =1;
    it_val.it_value.tv_usec =0;
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