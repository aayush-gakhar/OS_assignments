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
    int y=101;
    while(y--){
        long num;
        int res= syscall(reader, &num);
        if(res<0){
            printf("queue cleared %d\n",res);
            return -1;
        }
    }
    return 0;
}
