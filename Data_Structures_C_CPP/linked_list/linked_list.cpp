#include <iostream>

struct Node
{
    int data;
    Node* link;
};

int main()
{
    Node* temp = new Node();

    temp->data = 2;
    temp->link = NULL;

    Node* a = temp;

    temp = new Node();
    temp->data = 4;
    temp->link = NULL;

    Node* temp1 = a;

    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }
    
}