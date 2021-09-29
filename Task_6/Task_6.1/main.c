#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#define MAX_LINE 80
#define MAX_OPTS 20


/*
    In Task_6.1, I changed the program in a way such that it takes two commands at a time and executes them serially as background jobs.
    The modified code is as can be seen below and I made sure to add a line comment next to each modification I added indicating that it is a modification.
*/
int main()
{
  char *myopts1[MAX_OPTS];
  char *myopts2[MAX_OPTS]; //modification
  char tempstring1[MAX_LINE];
  char tempstring2[MAX_LINE]; //modification
  char *wordstring;
  char newlinestring[MAX_LINE];
  int should_run = 1;
  int ac;

  while (should_run) {
    printf("osh1> ");
    scanf("%[^\n]",tempstring1);
    fgets(newlinestring,MAX_LINE,stdin);
    printf("\treceived (%s)\n", tempstring1);

    printf("osh2> "); //modification
    scanf("%[^\n]",tempstring2); //modification
    fgets(newlinestring,MAX_LINE,stdin); //modification
    printf("\treceived (%s)\n", tempstring2); //modification

    printf("\tnow scanning tokens\n");

    ac = 0;
    wordstring = strtok(tempstring1," ");
    while (wordstring != NULL) {
      printf("\tstoring token (%s)",wordstring);
      myopts1[ac] = malloc(MAX_LINE*sizeof(char));
      strcpy(myopts1[ac],wordstring);
      printf(" = (%s)\n", myopts1[ac]);
      ac++;
      wordstring = strtok(NULL," ");
    }
    myopts1[ac] = NULL;
    fflush(stdout);

    //Lines 53 through 65 are all modifications to the existing code
    ac = 0;
    wordstring = strtok(tempstring2," ");
    while (wordstring != NULL) {
      printf("\tstoring token (%s)",wordstring);
      myopts2[ac] = malloc(MAX_LINE*sizeof(char));
      strcpy(myopts2[ac],wordstring);
      printf(" = (%s)\n", myopts2[ac]);
      ac++;
      wordstring = strtok(NULL," ");
    }
    myopts2[ac] = NULL;
    printf(" --> done \n");
    fflush(stdout);

    pid_t child1_pid;
    pid_t child2_pid; //modification
    child1_pid = fork();

    if (child1_pid == 0) {
      printf("\nCHILD 1 working on %s\n", myopts1[0]);
      printf("CHILD 1 finishing...\n\nResult:\n"); //modification
      fflush(stdout);
      execvp(myopts1[0], myopts1);
    } else {
      wait(NULL); //modification
      child2_pid = fork(); //modification
      if (child2_pid == 0) {
        printf("\nCHILD 2 working on %s\n", myopts2[0]); //modification
        printf("CHILD 2 finishing...\n\nResult:\n"); //modification
        fflush(stdout); //modification
        execvp(myopts2[0], myopts2); //modification
      }
      else{
        should_run = 1;
        wait(NULL);
      }
    }
  }
}
