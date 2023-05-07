#include <iostream>
#include <string>

using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}
void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}
bool search(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else
    {
        if (root->data == data)
        {
            
            return true;
        }
        else
        {
            if (root->data > data)
            {
                return search(root->left, data);
            }
            else
            {
                return search(root->right, data);
            }
        }
    }
    return false;
}
int findmin(Node *root)
{
    if (root->left == NULL)
    {
        return root->data;
    }
    return findmin(root->left);
}
int findMax(Node *root)
{
    if (root->right == NULL)
    {
        return root->data;
    }
    return findmin(root->right);
}
Node* Delete(Node* root, int deleteValue)
{
    if (root == NULL) {
        return root;
    }

    if (deleteValue < root->data) {
        root->left = Delete(root->left, deleteValue);
    } else if (deleteValue > root->data) {
        root->right = Delete(root->right, deleteValue);
    } else {
        //  no tiene hijos o solo tiene un hijo
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //  tiene dos hijos
        root->data = findmin(root->right);
        root->right = Delete(root->right, findmin(root->right));
    }

    return root;
}
int main()
{
    int busqueda = 0;
    Node *root = NULL;
    //ejercicio 1 y 2
    root = insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);
    insertNode(root, 9);
    insertNode(root, 13);
    //ejercicio 3
    printTree(root);
    cout << endl;
    //ejercicio 4
    cout << "ponga numero a buscar" << endl;
    cin >> busqueda;
     if (search(root, busqueda))
    {
        cout << "ha sido encontrado el " << busqueda << endl;
    }else{
        cout << "No ha sido encontrado el " << busqueda << endl;
    }
    //ejercicio 5
    cout << "valor minimo: "<< findmin(root) << " encontrado" << endl;
    //ejercicio 6
    cout << "valor Maximo: "<< findMax(root) << " encontrado" << endl;
    //ejercicio 7, se elimina el nodo 7
    Delete(root, 7);
    printTree(root);

    return 0;
}