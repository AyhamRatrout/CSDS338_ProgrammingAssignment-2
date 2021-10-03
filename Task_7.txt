#include <stdio.h>
#include <stdlib.h>

void main()
{
    int **i;
    i = malloc(sizeof(int*));
    *i = malloc(sizeof(int));
    **i = 40;

    printf("%d\n", **i);
}
