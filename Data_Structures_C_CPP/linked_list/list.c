#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* head;

void insert(int num,int n)
{
    // insere node no começo / coloca ela como primeiro, e "arrasta" o resto pra frente
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = num;
    temp1->next = NULL;
/*
    if(*headPointer != NULL) temp->next = *headPointer;
    *headPointer = temp;
*/
    if(n==0)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;

    for(int i=0; i<n-2; i++)
    {
        temp2 = temp2->next;
    }

    // temp2 = anterior do node a ser adicionado
    // temp1 = node a ser adicionado

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    /*
    printf("Quantidade de numeros a serem adicionados: ");
    int n; scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        printf("Numero: ");
        int x; scanf("%d",&x);
        insert(x, &head);
    }
    */

   insert(2,1);
   insert(3,2);
   insert(4,1);
   insert(5,2);

    // printf("Antes: %d\n",head->data);
    print();
    // printf("\nDepois: %d\n",head->data);
}
