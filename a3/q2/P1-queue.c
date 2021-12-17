#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuffer {
    long msgtype;
    char msgtext[100];
} msg,msg2;

void generate_random_string(char* str,int len){
    int i;
    for(i=0;i<len;i++){
        str[i] = 'a' + rand()%26;
    }
    str[i] = '\0';
}


int main(int argc, char const *argv[])
{
    key_t key;
    int msgid;
    key = ftok("share", 'a');
    printf("key: %d\n", key);
    msgid=msgget(key, 0666 | IPC_CREAT);
    msgctl(msgid, IPC_RMID, NULL);
    msgid=msgget(key, 0666 | IPC_CREAT);
    printf("msgid: %d\n", msgid);
    char* arr[50];
    char str[100];
    for(int i=0;i<50;i++){
        arr[i] = (char*)malloc(sizeof(char)*10);
        generate_random_string(arr[i],9);
    }
    int i=0;
    while(1){
        msg.msgtype = 1;
        msg.msgtext[0] = '\0';
        for(int j=0;j<5;j++){
            if(i+j>=50)
                break;
            sprintf(str, "%d %s ",i+j,arr[i+j]);
            strcat(msg.msgtext,str);
        }
        printf("\nmessage sent: %s\n",msg.msgtext);
        msgsnd(msgid, &msg, sizeof(msg.msgtext), 0);
        usleep(100000);
        msg2.msgtype = 4;
        msgrcv(msgid, &msg2, sizeof(msg.msgtext), 4, 0);
        printf("ID recieved: %s\n",msg2.msgtext);
        i=atoi(msg2.msgtext)+1;
        if(i>=50)
            break;
    }
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
