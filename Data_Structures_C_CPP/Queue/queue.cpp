#include <stdlib.h>
 
typedef struct Node

{
    int value;
    struct Node* next;
}Node;

typedef struct queue
{
    Node* front;
    Node* rear;
}queue;

Node* create_node(int value)
{
    Node* retorno = (Node*)malloc(sizeof(Node));
    retorno->value = value;
    retorno->next = NULL;
    return retorno;
}

void push(queue* q, int value)
{
    Node* new_rear = create_node(value);

    if(q->front == NULL && q->rear == NULL)
    {
        q->front = q->rear = new_rear;
        return;
    }

    q->rear->next = new_rear;
    q->rear = new_rear;
}

void pop(queue* q)
{
    Node* temp = q->front;

    if(q->front == NULL) return;

    if(q->front == q->rear) q->front = q->rear = NULL;

    else q->front = q->front->next;
    
    free(temp);
}
