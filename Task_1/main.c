#include<stdio.h>
#include<stdlib.h>

int CAPACITY = 100000;

typedef struct Queue
{
    int capacity;
    int size;
    int front;
    int rear;
    int *elements;
}Queue;

Queue * createQueue()
{
    Queue *Q;
    Q = (Queue *) malloc(sizeof(Queue));
    Q->elements = (int *) malloc(sizeof(int)*CAPACITY);
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
            Q->front=0;
        }
    }
    return;
}

int front(Queue *Q)
{
    if(Q->size==0)
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    return Q->elements[Q->front];
}

void enqueue(Queue *Q,int element)
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
        Q->elements[Q->rear] = element;
    }
    return;
}


void main()
{
    Queue *arrayOfQueues[256];
    for (int i = 0; i < 256; i++)
    {
        arrayOfQueues[i] = createQueue();
    }
}
