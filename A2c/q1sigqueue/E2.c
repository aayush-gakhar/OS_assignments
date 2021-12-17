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
#include <signal.h>

#define interval 1000

struct msgbuf {
    long mtype;
    char mtext[100];
};

pid_t pid1;
key_t key;
int msgid;

static void sig_handler3(int signo)
{
    if (signo == SIGALRM)
    {
        printf("SIGALRM received(ST)\n");
        unsigned long long hi, lo;
        asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
        unsigned long long val =lo| hi<<32 ;
        printf("time stamp: %llu\n", val );
        struct msgbuf message;
        message.mtype=1;
        sprintf(message.mtext,"%lld",val);
        msgsnd(msgid, &message, sizeof(message), 0);
        union sigval value;
        value.sival_int = (int) val;
        sigqueue(pid1, SIGTERM, value);
        // kill(pid1, SIGTERM);
    }
}


int main(int argc, char *argv[]){
    struct sigaction action;
	action.sa_handler = &sig_handler3;
    action.sa_flags = SA_RESTART; 
    if(sigaction(SIGALRM, &action, NULL)<0){
        perror("signal");
        exit(1);
    }
    pid1=atoi(argv[0]);
    key = ftok("share", 'a');
    msgid=msgget(key, 0666 | IPC_CREAT);

    struct itimerval it_val;
    it_val.it_value.tv_sec =interval/1000;
    it_val.it_value.tv_usec =(interval*1000)%1000000;
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