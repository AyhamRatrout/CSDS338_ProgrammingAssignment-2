#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>

int CAPACITY = 100000;
int StartingPID = 0;

typedef struct Task
{
    int priority;
    int burst;
    int PID;
}Task;

typedef struct Queue
{
    int capacity;
    int size;
    int front;
    int rear;
    Task *tasks[];
}Queue;

Task *createTask()
{
    Task *T;
    T = (Task *) malloc(sizeof(Task));
    T->priority = rand() % 256;
    T->burst = 1 + rand() % 100;
    T->PID = StartingPID++;
    return T;
}

Queue *createQueue()
{
    Queue *Q;
    Q = (Queue *) malloc(sizeof(Queue));
    //Q->tasks[CAPACITY] = (Task *) malloc(CAPACITY * sizeof(Task));
    Q->size = 0;
    Q->capacity = CAPACITY;
    Q->front = 0;
    Q->rear = -1;
    return Q;
}

int isEmpty(Queue *Q)
{
    if(Q->size==0)
    {
        return 1;
    }
    return 0;
}

int isFull(Queue *Q){
    if(Q->size == Q->capacity)
    {
        return 1;
    }
    return 0;
}

void dequeue(Queue *Q)
{
    if(isEmpty(Q) == 1)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        Q->size--;
        Q->front++;
        if(Q->front==Q->capacity)
        {
            Q->front=NULL;
        }
    }
    return;
}

Task *front(Queue *Q)
{
    if(Q->size==0)
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    return Q->tasks[Q->front];
}

void enqueue(Queue *Q, Task *T)
{
    if(isFull(Q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        Q->size++;
        Q->rear = Q->rear + 1;
        if(Q->rear == Q->capacity)
        {
            Q->rear = 0;
        }
        Q->tasks[Q->rear] = T;
    }
    return;
}


void main()
{
    Task *CPU[1];
    CPU[0] = NULL;
    struct Queue *runQueue[256];
    for(int i = 0; i < 256; i++){
        runQueue[i] = createQueue();
    }

    int cycleTimePassed = 0;
    int CPUCycleDone = 0;

    //simulator starts here
    for(int i = 0; i < 70; i++){

        if(cycleTimePassed != 0 && (cycleTimePassed % 10) == 0){
            CPUCycleDone = 1;
        }
        else{
            CPUCycleDone = 0;
        }
        //creates 10 different tasks
        for(int j = 0; j < 2; j++){
            Task *T = createTask();
            printf("New task created! Priority = %d \t Burst Time = %d \t PID = %d\n", T->priority, T->burst, T->PID);
            enqueue(runQueue[T->priority], T);
        }
        cycleTimePassed++;
        if(CPU[0] == NULL){
            for(int j = 0; j < 256; j++){
                if(isEmpty(runQueue[j]) != 1){
                    CPU[0] = runQueue[j]->tasks[0];
                    dequeue(runQueue[j]);
                    break;
                }
            }
            printf("\nProcess with PID %d and priority %d was just moved to the CPU. Remaining time to complete this process is: %d\n\n", CPU[0]->PID, CPU[0]->priority, CPU[0]->burst);
        }
        else{
            CPU[0]->burst--;
            printf("\nProcess with PID %d and priority %d is currently running on the CPU. Remaining time to complete this process is: %d\n\n", CPU[0]->PID, CPU[0]->priority, CPU[0]->burst);
            if(CPU[0]->burst == 0){
                printf("\nProcess with PID %d and priority %d is done executing! A new process will be added to the CPU in the next cycle.\n\n", CPU[0]->PID, CPU[0]->priority);
                cycleTimePassed = 0;
                CPU[0] = NULL;
            }
            else if(CPUCycleDone == 1){
                enqueue(runQueue[CPU[0]->priority], CPU[0]);
                printf("\nProcess with PID %d and priority %d has used up a full CPU cycle and is yet to be completed! This process will be kicked off the CPU and a new process will take its place in the next cycle.\n\n", CPU[0]->PID, CPU[0]->priority, CPU[0]->burst);
                cycleTimePassed = 0;
                CPU[0] = NULL;
            }
        }
        //Sleep(250);
    }
}
