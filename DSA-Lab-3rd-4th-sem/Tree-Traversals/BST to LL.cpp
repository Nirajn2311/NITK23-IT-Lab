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

//Main Function
int main()
{
    struct node *root = NULL;

    //Insertion of 1000  elements
    for (int i = 0; i < 1000; i++)
    {
        root = Insert(root, i);
    }

    //In-Order
    cout << "In-Order:\n ";
    Inorder(root);

    cout << "\n\n\n\nIn this all the elements are arranged in increasing order from 0-1000.";
    cout << "\nDue to this order of insertion the following element would always be greater than the previous element.";
    cout << "\nHence, the element will always be inserted into the right subtree and will never be inserted into left.";
    cout << "\nTherefore the structure which was devised to be a Binary Search Tree will be degenerated to a Linked List." << endl;
    return 0;
}