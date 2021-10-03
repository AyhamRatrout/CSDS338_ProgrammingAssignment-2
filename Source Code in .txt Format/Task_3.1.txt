#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *pointer1 = (int *) malloc(10 * sizeof(int));
    int *pointer2 = (int *) calloc(10, sizeof(int));

    if(pointer1 == NULL){
        printf("Malloc failed to allocate memory...");
    }
    else{
        printf("The values below show that malloc returns a pointer to an uninitialized block of memory (an array of int in this case). This is apparent as the values being printed below are random values (probably memory locations) which indicate that this memory block is yet to be initialized\n\n");
        for(int i = 0; i < 10; i++){
            printf("%d, ", pointer1[i]);
        }
    }

    printf("\n\n\n");

    if(pointer2 == NULL){
        printf("Calloc failed to allocate memory...");
    }
    else{
        printf("The values below show that calloc returns a pointer to a zero-initialized block of memory (or buffer). This is apparent as the values being printed below all have zero-values.\n\n");
        for(int i = 0; i < 10; i++){
            printf("%d, ", pointer2[i]);
        }
        printf("\n");
    }
}
