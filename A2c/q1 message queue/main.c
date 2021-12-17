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

struct msgbuf {
    long mtype;
    char mtext[100];
};

pid_t pid1;
key_t key;
int msgid;


static void sig_handler1(int signo)
{
    if (signo == SIGTERM)
    {
        printf("SIGTERM received(S1)\n");
        struct msgbuf message;
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("message: %s\n\n", message.mtext);
    }
}



int main(int argc, char const *argv[]){
    key = ftok("share", 'a');
    printf("key: %d\n", key);
    msgid=msgget(key, 0666 | IPC_CREAT);
    msgctl(msgid, IPC_RMID, NULL);
    msgid=msgget(key, 0666 | IPC_CREAT);
    printf("msgid: %d\n", msgid);

    pid1=fork();
    if(pid1<0){
        perror("S1 error");
		return EXIT_FAILURE;
    }
    if(pid1==0){ // S1
        if(signal(SIGTERM,sig_handler1)==SIG_ERR){
            perror("signal");
            return EXIT_FAILURE;
        }
        while(1) {
            pause();
        }
    }else{
        printf("pid1: %d\n\n", pid1);
        char str[20];
        sprintf(str, "%d", pid1);
        char* argv2[]={str, NULL};
        pid_t pid2=fork();
        if(pid2<0){
            perror("SR error");
            return EXIT_FAILURE;
        }
        if(pid2==0){ // SR
            execv("./E1",argv2);
        }else{
            pid_t pid3=fork();
            if(pid3<0){
                perror("ST error");
                return EXIT_FAILURE;
            }
            if(pid3==0){ // ST
                execv("./E2",argv2);
            }
            waitpid(pid2, NULL, 0);
            waitpid(pid3, NULL, 0);
            kill(pid1, SIGKILL);
            msgctl(msgid, IPC_RMID, NULL);
            printf("Done\n");
        }
    }
    return 0;
}
