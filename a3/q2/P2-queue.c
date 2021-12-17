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


struct msgbuffer {
    long msgtype;
    char msgtext[100];
} msg,msg2;

int main(){
    key_t key;
    int msgid;
    key = ftok("share", 'a');
    printf("key: %d\n", key);
    msgid=msgget(key, 0666 | IPC_CREAT);
    printf("msgid: %d\n", msgid);
    char *ID, *str, *lID;
    int maxID = 0;
    for (int i = 0; i < 10; i++){
        printf("\n--------------------\n");
        msgrcv(msgid, &msg, sizeof(msg.msgtext), 1, 0);
        printf("Message number %d recieved\n", i+1);
        ID = strtok(msg.msgtext, " ");
        str = strtok(NULL, " ");
        while (ID != NULL){
            lID=ID;
            maxID = atoi(ID)>maxID?atoi(ID):maxID;
            printf("ID: %s, String: %s\n", ID, str);
            ID = strtok(NULL, " ");
            str = strtok(NULL, " ");
        }
        sprintf(msg2.msgtext,"%d",maxID);
        msg2.msgtype = 4;
        msgsnd(msgid, &msg2, sizeof(msg2.msgtext), 0);
    }

    return 0;
}