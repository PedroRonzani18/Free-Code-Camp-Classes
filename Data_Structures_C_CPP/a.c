#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valor;
}Node;

void tes(Node* node)
{
    node->valor = 20;
}

int main()
{
    Node* aux = NULL;
    aux->valor = 10;

    printf("%d\n",aux->valor);
    tes(aux);
    printf("%d\n",aux->valor);
}