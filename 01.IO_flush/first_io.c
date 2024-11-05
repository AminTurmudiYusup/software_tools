#include <stdio.h>

int main()
{
    puts("STDOUT");
    //fflush(stdout);
    fputs("STDER\n", stderr);
    //fflush(stderr);
    return 0;
}
