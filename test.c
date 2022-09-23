#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        printf("%d = %s\n", i, argv[i]);
        i++;
    }
    return 0;
}
