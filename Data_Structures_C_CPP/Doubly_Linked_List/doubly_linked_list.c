#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* create_node(int data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void insert_at_head(Node** head, int data)
{
    Node* new_node = create_node(data);

    if(*head == NULL){
        *head = new_node;
        return;
    }

    (*head)->prev = new_node;
    new_node->next = *head;
    *head = new_node;
}

void print(Node* current)
{
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void print_reversed(Node* current)
{
    if(current == NULL) return;

    while(current->next != NULL)
        current = current->next;
    
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->prev;
    }
    printf("\n");

}

int main()
{
    Node* head = NULL;

    for(int i=0; i<5; i++)
        insert_at_head(&head,i+1);

    print(head);
    print_reversed(head);
}
