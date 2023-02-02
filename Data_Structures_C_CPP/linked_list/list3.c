#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;


void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insert(int data, int n, Node* head)
{
    Node* temp1 = (Node*)malloc(sizeof(Node));

    temp1->data = data;
    temp1->next = NULL;

    if(n == 0){
        temp1->next = head; // necessario para adicionar no começo se a lista nao está vazia
                            // temp1 (novo node a ser dicionado no começo) aponta para primeira posicao
                            // proximo node é o anterior head: antes tinha um head, agora esse temp1 será o head, por isso next tem que ser o anterior


        head = temp1; // head aponta para posição na memoria onde se encontra o primeiro termo
                      // agora head aponta para o primeiro node, nao NULL
        return;
    }

    Node* temp2 = head;

    for(int i=0; i<n-1; i++) 
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}


int main()
{
    Node* head = NULL;
    insert(2,0, head);
    insert(3,1, head);
    insert(4,0, head);
    insert(5,1, head);
    print(head);
}
