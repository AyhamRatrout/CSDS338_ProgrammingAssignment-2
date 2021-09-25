#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void displayStrings(char *input1, char *input2)
{
    printf("The first string is: %s\n", input1);
    printf("The second string is: %s\n", input2);
    printf("\n");
}

void swap(char *input1, char *input2)
{
    int currentPosition = 0;
    char temporary;

    while(input1[currentPosition] != '\0' || input2[currentPosition] != '\0')
    {
        temporary = input1[currentPosition];
        input1[currentPosition] = input2[currentPosition];
        input2[currentPosition] = temporary;
        currentPosition++;
    }
}

void main()
{
    char *input1 = malloc(1000 * sizeof(char));
    char *input2 = malloc(1000 * sizeof(char));

    printf("Greetings fellow user. Please type two words/sentences below, one per line, so that I can swap them for you...\n");

    fgets(input1, INT_MAX / 2, stdin);
    fgets(input2, INT_MAX / 2, stdin);
    printf("\n");

    displayStrings(input1, input2);
    swap(input1, input2);
    printf("After the swap...\n\n");
    displayStrings(input1, input2);
}
