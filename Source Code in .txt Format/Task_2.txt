#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fptr;
    char str[10000];
    int n = 0;

    system("ps | tail -n +2 > /tmp/proclist");
    system("sleep .1");
    fptr = fopen("/tmp/proclist","r");

    fscanf(fptr, "%s", str);
    while (fscanf(fptr,"%s",str)!= EOF)
    {
       if(strstr(str, "bash") == NULL && atoi(str) > 0)
       {
           char killCommand[1000] = "kill -9 ";
           strcat(killCommand, str);
           system(killCommand);
       }
    }
}
