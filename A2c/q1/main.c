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
#include <string.h>
#include <sys/shm.h>


pid_t pid1;
key_t key;
int shmid;


static void sig_handler1(int signo)
{
    if (signo == SIGTERM)
    {
        printf("SIGTERM received(S1)\n");
        
        char *str = (char*) shmat(shmid,(void*)0,0);
        printf("message: %s\n----------\n\n", str);
        shmdt(str);
    }
}



int main(int argc, char const *argv[]){
    key = ftok("shared", 'a');
    shmid=shmget(key,1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid,(void*)0,0);
    printf("NOTE: CHANGE CPU FREQUENCY DEFINED IN E2 TO GET ACCURATE CONVERSION FROM TIME\nSTAMP TO HUMAN READABLE TIME.\n>>>#define frequency 1.2\nORIGINALLY SET TO 1.2 Ghz.\n\n");

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
                usleep(500000);
                execv("./E2",argv2);
            }
            waitpid(pid2, NULL, 0);
            waitpid(pid3, NULL, 0);
            kill(pid1, SIGKILL);
            shmctl(shmid,IPC_RMID,NULL);
            printf("Done\n");
        }
    }
    return 0;
}
