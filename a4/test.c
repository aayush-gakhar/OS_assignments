#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

#define writer 448
#define reader 449

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    int x=100 , y=100;
    if(pid!=0){
        int rand = open("/dev/urandom", O_RDONLY);
        if(rand<0){
            perror("open");
            return -1;
        }
        unsigned long long num;
        while(x--){
            int res=read(rand, &num, sizeof num);
            if(res<0){
                perror("read");
            }else{
                printf("writing number = %llu\n",num);
                res = syscall(writer, &num);
                if(res<0){
                    printf("writer syscall returned %d\n", res);
                    if(res==-1){
                        printf("queue full\n");
                    }
                    return -1;
                }
                sleep(1);
            }
        }
        
    }else{
        usleep(500000);
        while(y--){
            unsigned long long num;
            int res= syscall(reader, &num);
            if(res<0){
                printf("reader syscall returned %d\n",res);
                if(res==-1){
                    printf("queue empty\n");
                }
                sleep(1);
                continue;
            }
            printf("reading number = %llu\n",num);
            sleep(1);
        }
    }
    return 0;
}
