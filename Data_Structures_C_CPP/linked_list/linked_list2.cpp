#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* global_head;

void print(Node* current)
{
    while(current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void print_recursive(Node* current) // Menos eficiente que iterativo
{
    if(current != NULL)
    {
        printf("%d ",current->data);
        print_recursive(current->next);
    }
    else printf("\n");
}

void reverse_print_recursive(Node* current)
{
    if(current == NULL) return
    reverse_print_recursive(current->next);
    printf("%d",current->data);
}



Node* create_node(int value)
{
    Node* retorno = (Node*)malloc(sizeof(Node));
    retorno->data = value;
    retorno->next = NULL;
    return retorno;
}

void insert_before_head(int value, Node** head)
{
    Node* temp = create_node(value);
    temp->next = *head;
    *head = temp;
}

void insert_after_node(Node* node_to_insert_after, Node* new_node)
{
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}

Node* find_node_by_value(Node* head, int value)
{
    Node* aux = head;
    while(aux != NULL)
    {
        if(aux->data == value) return aux;
        aux = aux->next;
    }
    return NULL;
}

void insert_value_in_index(int data, int pos, Node** head)
{
    Node* temp1 = (Node*)malloc(sizeof(Node));

    temp1->data = data;
    temp1->next = NULL;

    if(pos == 0){
        temp1->next = *head; // necessario para adicionar no começo se a lista nao está vazia
                            // temp1 (novo node a ser dicionado no começo) aponta para primeira posicao
                            // proximo node é o anterior head: antes tinha um head, agora esse temp1 será o head, por isso next tem que ser o anterior


        *head = temp1; // head aponta para posição na memoria onde se encontra o primeiro termo
                      // agora head aponta para o primeiro node, nao NULL
        return;
    }

    Node* temp2 = *head;

    for(int i=0; i<pos-1; i++) 
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void delete_node_at_index(int pos, Node** head)
{
    Node* temp1 = *head;
    if(pos == 0)
    {
        *head = temp1->next;
        free(temp1);
        return;
    }

    for(int i=0; i<pos-1; i++) 
        temp1 = temp1->next;

    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void reverse_iterate(Node** head)
{
    Node *prev, *current, *next;
    current = *head;
    prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void reverse_recursive(Node** head, Node** current)
{
    if((*current)->next == NULL)
    {
        head = current;
        return;
    }
    reverse_recursive(head,&(*current)->next);

    Node* new_previous = (*current)->next;
    new_previous->next = *current;
    (*current)->next = NULL;
}


void reverse_new(Node** head_ref) {
    Node* first, *rest;

    if (*head_ref == NULL) return; // confere se está vazia

    first = *head_ref; //sets the first node to be the head node
    rest = first->next; //rest of the list to be the next node

    if (rest == NULL) return; // checks if the rest of the list is NULL
                              // means there is only one node in the list
                              // chegou no ultimo node

    reverse_new(&rest); // If there are more than one node in the list, the function calls itself recursively with the rest of the list as the input
                        // This recursive call will reverse the rest of the list, making the last node the new head.

    first->next->next = first; // adjusts the pointers between the first and the rest of the list
                               // The next pointer of the first node is set to point to itself,
                               // o proximo do antigo anterior é esse em questão, basicamente mudandoa  orientação do ponteiro
                               /*
                                    A -> B => A <- B
                                    first->next->next = first
                                    o proximo do atual é o atual
                               */
                              
    first->next = NULL; // the next pointer of the rest of the list is set to NULL
                        // o node mais a esquerda fica NULL pra que ele sirva como o fim da list

    *head_ref = rest; // the head_ref is updated to point to the rest of the list, which is now the new head

    // the original head node becomes the last node in the list, and the rest of the list becomes the reversed list.
}



int main()
{
    Node* head = NULL;
    global_head = NULL;
    Node* temp;

    for(int i=0; i<5; i++)
    {
        insert_value_in_index(i+1, i, &head);
    }

    print(head);
    reverse_new(&head);
    print(head);

}
