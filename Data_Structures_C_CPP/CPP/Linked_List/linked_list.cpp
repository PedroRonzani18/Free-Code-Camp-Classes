/*
#include <stdio.h>

#include "LinkedList.h"

template <typename T>
void LinkedList<T>::print()
{
    Node<T>* current = head;
    while(current != nullptr)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

template <typename T>
void LinkedList<T>::print(Node<T>* head)
{
    Node<T>* current = head;
    while(current != nullptr)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

template <typename T>
void LinkedList<T>::reverse_print_iterate()
{
    Node<T>* reversed_head = reverse_iterate();
    print(reversed_head);
}

template <typename T>
Node<T>* LinkedList<T>::find_Node_by_value(T value)
{
    Node<T>* aux = head;
    while(aux != nullptr)
    {
        if(aux->data == value) return aux;
        aux = aux->next;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::insert_before_head(T value)
{
    Node<T>* temp = new Node<T>(value);
    temp->next = head;
    head = temp;
}

template <typename T>
void LinkedList<T>::insert_after_Node(Node<T>* Node_to_insert_after, Node<T>* new_Node)
{
    new_Node->next = Node_to_insert_after->next;
    Node_to_insert_after->next = new_Node;
}

template <typename T>
void LinkedList<T>::insert_value_in_index(T data, int pos)
{
    Node<T>* temp1 = new Node<T>(data);

    if(pos == 0){
        temp1->next = head; // necessario para adicionar no começo se a lista nao está vazia
                            // temp1 (novo Node<T> a ser dicionado no começo) aponta para primeira posicao
                            // proximo Node<T> é o anterior head: antes tinha um head, agora esse temp1 será o head, por isso next tem que ser o anterior


        head = temp1; // head aponta para posição na memoria onde se encontra o primeiro termo
                      // agora head aponta para o primeiro Node<T>, nao nullptr
        return;
    }

    Node<T>* temp2 = head;

    for(int i=0; i<pos-1; i++) 
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

template <typename T>
void LinkedList<T>::push_back(T value)
{
    Node<T>* new_Node = new Node<T>(value);

    if(head == nullptr)
    {
        head = new_Node;
        return;
    }

    Node<T>* aux = head;

    while(aux->next != nullptr)
        aux = aux->next;

    aux->next = new_Node;
}


template <typename T>
void LinkedList<T>::delete_Node_at_index(int pos)
{
    Node<T>* temp1 = head;
    if(pos == 0)
    {
        head = temp1->next;
        delete temp1;
        return;
    }

    for(int i=0; i<pos-1; i++) 
        temp1 = temp1->next;

    Node<T>* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

template <typename T>
Node<T>* LinkedList<T>::reverse_iterate()
{
    Node<T> *prev, *current, *next;
    current = head;
    prev = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    return head;
}


*/
