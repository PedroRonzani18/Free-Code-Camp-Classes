#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* under;
}Node;

typedef struct stack
{
    Node* top;
}stack;

Node* create_node(int data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data = data;
    new_node->under = NULL;

    return new_node;
}

void push(stack* st, int data)
{
    Node* new_node = create_node(data);

    new_node->under = st->top;
    st->top = new_node;
}

void pop(stack* st)
{
    if(st->top == NULL) return;

    Node* prev_top = st->top;

    st->top = st->top->under;

    free(prev_top);
}

void print(stack st)
{
    Node* current = st.top;

    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->under;
    }
    printf("\n");
    
}

int is_empty(stack st)
{
    return st.top == NULL;
}

Node* top(stack st)
{
    return st.top;
}

int main()
{
    stack st;

    for(int i=0; i<5; i++)
    {
        push(&st, i+1);
    }
    print(st);
    pop(&st);
    print(st);
    pop(&st);
    print(st);
}
