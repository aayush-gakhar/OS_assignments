#include <math.h>
#include <stdio.h>

char add(float a,float b)
{
return (int)(round (a)+round (b)) ;
}

int main(int argc, char const *argv[])
{
    printf("%d\n",add(1.5,4.5));
    return 0;
}