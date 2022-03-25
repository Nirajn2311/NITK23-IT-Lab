#include <iostream>

using namespace std;

//Structure of Node
struct node
{
    //Data Element
    int data;
    //Pointer to Left and Right Nodes
    node *left, *right;
};

//Creation of New Node
node *NewNode(int a)
{
    node *temp = new node();
    temp->data = a;
    temp->left = NULL;
    temp->right = NULL;
    //Returns newly created node
    return temp;
}

//Insertion
node *Insert(node *root, int a)
{
    if (root == NULL)
    {
        root = NewNode(a);
    }
    //Lower value to Left Node
    else if (root->data >= a)
    {
        root->left = Insert(root->left, a);
    }
    //Greater Value to Right Node
    else
    {
        root->right = Insert(root->right, a);
    }
    return root;
}

//INORDER
void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

//PREORDER
void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

//POSTORDER
void Postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

//Main Function
int main()
{
    struct node *root = NULL;

    //Insertion of 1000 random elements
    for (int i = 0; i < 1000; i++)
    {
        root = Insert(root, rand() % 1000);
    }

    //In-Order
    cout << "In-Order:\n ";
    Inorder(root);

    //Pre-Order
    cout << "\n\n\nPre-Order:\n ";
    Preorder(root);

    //Post-Order
    cout << "\n\n\nPost-Order:\n ";
    Postorder(root);

    return 0;
}