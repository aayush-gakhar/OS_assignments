#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void readcsv(char section){
    int fd = open("student_record.csv", O_RDONLY);
     
    if (fd < 0){
        perror("File open");
        return;
    }
    float avg[6]={0,0,0,0,0,0};
    int n=0;
    char c='0';
    int v,comma;
    
    while (1) // first row skip
    {
        read(fd,&c,1);
        if(c=='\n'){
            break;
        }
    }
    int flag=1;
    while(read(fd,&c,1)>0)
    {
        comma=0;
        while (1)
        {
            read(fd,&c,1);
            if(c=='\n'){
                flag=0;
                break;
            }
            if(c==','){
                read(fd,&c,1);
                v=section==c;
                if(v)n++;
                read(fd,&c,1);
                break;
            }
        }
        if(!flag)break;
        for (int i = 0; i < 6; i++)
        {
            int num=0;
            while (1)
            {
                if(read(fd,&c,1)<=0)break;
                if(c==',' || c=='\n'){
                    break;
                }else if (c=='\r'){
                    read(fd,&c,1);
                    break;
                }
                
                else{
                    num*=10;
                    num+=c-'0';
                }
            }if(v){
                avg[i]+=num;
            }
        }
    }
    printf("Section: %c\n",section);
    printf("Assignment 1 | Assignment 2 | Assignment 3 | Assignment 4 | Assignment 5 | Assignment 6\n");
    for (int i = 0; i < 6; i++){
        printf("%f      ",avg[i]/n);
    }
    printf("\n");
    

}


int main(int argc, char const *argv[]){
    pid_t pid=fork();
    if(pid<0){
        perror("pid");
		return EXIT_FAILURE;
    }
    if(pid==0){
        readcsv('A');
        exit(0);
    }else{
        int status;
        waitpid(pid,&status,0);
        readcsv('B');
    }
    return 0;
}