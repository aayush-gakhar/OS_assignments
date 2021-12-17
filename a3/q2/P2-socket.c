#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PORT 8080



int main(){
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address\n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed\n");
        return -1;
    }

    char *ID, *str, *lID;
    int maxID = 0;
    for (int i = 0; i < 10; i++){
        valread = read(sock,buffer,100);
        printf("\n--------------------\n");
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
        buffer[0] = '\0';
        sprintf(buffer,"%d",maxID);
        printf("Sending ID: %s\n", buffer);
        send(sock , buffer , strlen(buffer) , 0 );
    }

    return 0;
}