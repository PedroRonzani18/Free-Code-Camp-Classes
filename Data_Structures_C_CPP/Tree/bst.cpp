#include <cstddef>
#include <iostream>

struct Node
{
    int data;
    Node* right;
    Node* left;
};

struct Bst
{
    Node* root = NULL;
};


Node* constructor_node(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data)
{
    if(*root == NULL)   
        *root = constructor_node(data);

    else if(data <= (*root)->data) 
        insert(&(*root)->left, data);
    else 
        insert(&(*root)->right, data);
}

bool search(Node** root, int data)
{
    if(*root == NULL) return false;
    
    std::cout << (*root)->data << std::endl;

    if((*root)->data == data) return true;

    else if(data <= (*root)->data) 
        return search(&(*root)->left, data);
    else 
        return search(&(*root)->right, data);
}

int find_min(Node* root)
{
    if(root == NULL) 
    {
        std::cout << "Arvore vazia\n";
        return -1;
    }

    while(root->left != NULL) 
        root = root->left;
    return root->data;
}

int find_max(Node* root)
{
    if(root == NULL) 
    {
        std::cout << "Arvore vazia\n";
        return -1;
    }

    while(root->right != NULL) 
        root = root->right;
    return root->data;
}

int height(Node* root)
{
    if(root == NULL) return -1;

    return std::max(height(root->left), height(root->right)) + 1;
}


void tree_traversal_preorder(Node* current)
{
    if(current == NULL) return;
    std::cout << current->data << std::endl;
    tree_traversal_preorder(current->left);
    tree_traversal_preorder(current->right);
}

void level_order_traversal()
{
    
}


int main()
{
    Bst bs;

    insert(&bs.root, 15);
    insert(&bs.root, 10);
    insert(&bs.root, 20);
    insert(&bs.root, 25);
    insert(&bs.root,  8);
    insert(&bs.root, 12);

    tree_traversal_preorder(bs.root);

/*
    int num; std::cout << "Numero: "; std::cin >> num;

    std::cout << "Min: " << find_min(bs.root) << std::endl;
    std::cout << "Min: " << find_min(bs.root) << std::endl;
    std::cout << "Hei: " << height(bs.root) << std::endl;

    if(search(&bs.root, num) == true) std::cout << "SIM\n";
    else std::cout << "NAO\n";
*/
}
