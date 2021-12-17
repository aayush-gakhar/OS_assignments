#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    FILE *source, *dest;

    // Open the source file
    source = fopen(argv[1], "r");

    // Open the destination file
    dest = fopen(argv[2], "w");

    // create a buffer
    char buffer[10];

    // read and write
    while (fread(buffer,sizeof(buffer),1,source))
    {
        fwrite(buffer,sizeof(buffer),1,dest);
    }
    fwrite(buffer,sizeof(buffer),1,dest);
    fclose(source);
    fclose(dest);
    return 0;
}
