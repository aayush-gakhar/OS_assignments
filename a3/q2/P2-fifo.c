#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
    int fd1;
    char *fifo1 = "/tmp/myfifo";

    char buffer[100];
    char *ID, *str, *lID;
    int maxID = 0;
    for (int i = 0; i < 10; i++){
        printf("\n--------------------\n");
        fd1=open(fifo1,O_RDONLY);
        read(fd1,buffer,100);
        printf("Message number %d recieved\n", i+1);
        ID = strtok(buffer, " ");
        str = strtok(NULL, " ");
        while (ID != NULL){
            lID=ID;
            maxID = atoi(ID)>maxID?atoi(ID):maxID;
            printf("ID: %s, String: %s\n", ID, str);
            ID = strtok(NULL, " ");
            str = strtok(NULL, " ");
        }
        close(fd1);

        fd1=open(fifo1,O_WRONLY);
        sprintf(buffer,"%d",maxID);
        write(fd1,buffer,strlen(buffer)+1);
        close(fd1);
    }

    return 0;
}