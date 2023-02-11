#include <cstddef>
#include <iostream>
#include <queue>
#include <climits>

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

Node* find_min(Node* root)
{
    if(root == NULL) 
    {
        std::cout << "Arvore vazia\n";
        return NULL;
    }

    while(root->left != NULL) 
        root = root->left;
    return root;
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


void preoder_traversal(Node* current)
{
    if(current == NULL) return;
    std::cout << current->data << std::endl;
    preoder_traversal(current->left);
    preoder_traversal(current->right);
}

void inorder_traversal(Node* current)
{
    if(current == NULL) return;
    inorder_traversal(current->left);
    std::cout << current->data << std::endl;
    inorder_traversal(current->right);
}

void postorder_traversal(Node* current)
{
    if(current == NULL) return;
    inorder_traversal(current->left);
    inorder_traversal(current->right);
    std::cout << current->data << std::endl;
}

bool is_subtree_lesser(Node* root, int value)
{
    if(root == NULL) return true;

    if(root->data <= value
    && is_subtree_lesser(root->left, value)
    && is_subtree_lesser(root->right, value))
        return true;
    return true;
}

bool is_subtree_greater(Node* root, int value)
{
    if(root == NULL) return true;

    if(root->data > value
    && is_subtree_greater(root->left, value)
    && is_subtree_greater(root->right, value))
        return true;
    return true;
}

bool check_if_binary_tree_is_bst(Node* current)
{
    if(current == NULL) return true;

    if(is_subtree_lesser(current->left, current->data)
    && is_subtree_greater(current->right, current->data)
    && check_if_binary_tree_is_bst(current->left)
    && check_if_binary_tree_is_bst(current->right))
        return true;
    return false;
}

bool is_bts_util(Node* current, int min_value, int max_value)
{
    if(current == NULL) return true;

    if(current->data > min_value
    && current->data < max_value
    && is_bts_util(current->left, min_value, current->data)
    && is_bts_util(current->right, current->data, max_value))
        return true;
    return false;
}

bool is_bst(Node* root)
{
    return is_bts_util(root, INT_MIN, INT_MAX);
}

void level_order_traversal(Node* root)
{
    if(root == NULL) return;

    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* current = q.front();
        std::cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
}

void delete_node_from_bst(Node** root, int data)
{
    if(root == NULL) return;
    else if(data < (*root)->data)
        delete_node_from_bst(&(*root)->left, data);
    else if(data > (*root)->data)
        delete_node_from_bst(&(*root)->right, data);
    else
    {
        // caso 1: sem filhos
        if((*root)->right == NULL && (*root)->left == NULL)
        {
            delete *root;
            *root = NULL;
        }
        
        // Caso 2: 1 filho
        else if((*root)->left == NULL)
        {
            Node* temp = *root;
            *root = (*root)->right;
            delete temp;
        }

        else if((*root)->right == NULL)
        {
            Node* temp = *root;
            *root = (*root)->left;
            delete temp;
        }

        // Caso 3: 2 filhos
        else
        {
            int temp = find_min((*root)->right)->data;
            (*root)->data = temp;
            delete_node_from_bst(&(*root)->right, temp);
        }
    }
    return;
}


Node* find(Node* current, int data)
{
    if(current == NULL) return NULL;
    if(current->data == data) return current;

    Node* t1 = find(current->left, data);
    Node* t2 = find(current->right, data);

    if(t1 != NULL) return t1;
    if(t2 != NULL) return t2;
    return NULL;
}


Node* inorder_successor(Node* root, int data)
{
    Node* current = find(root, data);
    if(current == NULL) return NULL;

    // Caso 1: node tem subtree pela direita
    if(current->right != NULL)
        return find_min(current->right);
    
    else { // Caso 2: não há subtree pela direita
        Node* sucessor = NULL;
        Node* ancestor = root;

        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                sucessor = ancestor;
                ancestor = ancestor->left;

            }
            else
                ancestor = ancestor->right;
        }
        return sucessor;
    }
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

    std::cout << inorder_successor(bs.root, 12)->data << std::endl;

    /*
    inorder_traversal(bs.root);
    delete_node_from_bst(&bs.root, 8);
    std::cout << "antes\n";

    inorder_traversal(bs.root);
    */


/*
    int num; std::cout << "Numero: "; std::cin >> num;

    std::cout << "Min: " << find_min(bs.root) << std::endl;
    std::cout << "Min: " << find_min(bs.root) << std::endl;
    std::cout << "Hei: " << height(bs.root) << std::endl;

    if(search(&bs.root, num) == true) std::cout << "SIM\n";
    else std::cout << "NAO\n";
*/

    //std::cout << check_if_binary_tree_is_bst(bs.root) << std::endl;
}
