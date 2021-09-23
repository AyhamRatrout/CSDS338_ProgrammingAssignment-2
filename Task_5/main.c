#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<limits.h>

/*
*/
char *trim(char toTrim[])
{
    char *end;

    while(isspace((unsigned char)*toTrim))
    {
        toTrim++;
    }

    if(*toTrim == 0)
    {
        return toTrim;
    }

    end = toTrim + strlen(toTrim) - 1;

    while(end > toTrim && isspace((unsigned char)*end))
    {
        end--;
    }

    end[1] = '\0';

    return toTrim;
}

/*
*/
char *removeFirstTwoWords(char *userInput)
{
    int wordCounter = 0;
    userInput = trim(userInput);

    while(*userInput != '\0' && wordCounter != 2)
    {
        if(*userInput != ' ')
        {
            userInput++;
        }
        else
        {
            userInput = trim(userInput);
            wordCounter++;
        }
    }

    if(wordCounter < 2)
    {
        printf("Hey, don't try to trick me like that! Your input had less than three words and therefore there is no third word to be printed :(");
    }
    return userInput;
}

/*
*/
void thirdWord(char *userInput)
{
    userInput = removeFirstTwoWords(userInput);
    char result[strlen(userInput)];
    int i = 0;

    while(*userInput != ' ')
    {
        result[i] = *userInput;
        i++;
        userInput++;
    }
    result[i] = '\0';
    printf("%s\n", result);
}

void main()
{
    char userInput[sizeof(INT_MAX) / 2];

    printf("Hello there fellow user. Please type something below so that I can return to you the third word...\n");

    fgets(userInput, (INT_MAX / 2), stdin);

    thirdWord(userInput);
}


