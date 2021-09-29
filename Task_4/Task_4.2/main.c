#include <stdio.h>
#include <stdlib.h>

/*
    In order to demonstrate whether malloc performs lazy or immediate allocation of memory, I needed to split this task into two parts: 4.1 and 4.2.

    In Task 4.2, I basically create a variable (a pointer), malloc space for that variable, initialize the variable (pointer) with values at each index of the malloced space,
    and finally sleep the system. Now, when I run top, if malloc has lazy allocation then RES = USED <<< VIRT and if not, then RES = USED is approximately equal to VIRT.

    The obtained results, in addition to explanations and screenshots, can be found in the document titled: "Accompanying Notes, Screenshots, and Answers (A supplement to my code)."
*/
void main()
{
    char *c;
    int n = 100 * 1000 * 1000;
    c = malloc(n * sizeof(char));
    for(int i = 0; i < n; i++)
    {
        c[i] = 'a';
    }
    system("sleep 10000");
}
