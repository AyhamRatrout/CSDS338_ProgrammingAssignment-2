#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n = 1000 * 1000;
    float *c = (float *) calloc(n, sizeof(float));
    system("sleep 10000");
}
