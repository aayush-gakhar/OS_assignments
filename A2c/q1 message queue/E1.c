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

#define interval 1000

struct msgbuf {
    long mtype;
    char mtext[100];
};

pid_t pid2;
key_t key2;
int msgid2;

static void sig_handler2(int signo)
{
    if (signo == SIGALRM)
    {
        printf("SIGALRM received(SR)\n");
        long num;
        asm( "rdrand %0" : "=r" ( num ));
        printf("Random number: %ld\n", num);
        struct msgbuf message;
        message.mtype=1;
        sprintf(message.mtext,"%ld",num);
        msgsnd(msgid2, &message, sizeof(message), 0);
        kill(pid2, SIGTERM);
    }
}

int main(int argc, char *argv[]){
    if(signal(SIGALRM,sig_handler2)==SIG_ERR){
        perror("signal");
        exit(1);
    }
    pid2=atoi(argv[0]);
    key2 = ftok("share", 'a');
    msgid2=msgget(key2, 0666 | IPC_CREAT);
    
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

