/*
Date: 2020/0206
Author: Ian
Object: To implement queue with linked list.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

typedef struct queue{
    node *front;
    node *rear;
}queue;

void init_queue(queue *);
int isEmpty(queue *);
void enqueue(queue *, int);
int dequeue(queue *);

void init_queue(queue *q){
    q->front = NULL;
    q->rear = NULL;
    return;
}

int isEmpty(queue *q){
    return (q->front == NULL);
}

void enqueue(queue *q, int item){
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = item;
    tmp->link = NULL;
    if(isEmpty(q)) q->front = tmp; // In case queue is empty.
    else q->rear->link = tmp; // In case queue isn't empty.
    q->rear = tmp;
    printf("insert %d into queue.\n", item);
    return;
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("queue is empty!!\n");
        exit(1);
    }
    node *tmp = q->front;
    int item = q->front->data;
    q->front = q->front->link;
    if(q->front == NULL) q->rear = NULL; // In case there is only one node remained.
    free(tmp);
    printf("remove %d from queue.\n", item);
    return item;
}
int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    init_queue(q);

    int i;
    for(i=1; i<=100; i++){
        enqueue(q, i);
    }

    printf("-----------------------------\n");

    while(!isEmpty(q)){
        dequeue(q);
    }

    return 0;
}
