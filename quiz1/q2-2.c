#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x=-2;
    unsigned int y = -33;
    int z;
    z = x + y;
    printf("%u %u %u", x,y,z);
    printf("%d %d %d", x,y,z);
    // 4294967296
    return 0;
}
