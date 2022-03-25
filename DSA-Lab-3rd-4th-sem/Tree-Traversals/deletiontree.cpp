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
struct node *Insert(node *root, int a)
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

void DelTree(node *root)
{
    if (root == NULL)
        return;

    DelTree(root->left);
    DelTree(root->right);

    cout << "\nDeleting node " << root->data;
    delete root;
}

int main()
{
    struct node *root = NULL;
    root = Insert(root, 35);
    root = Insert(root, 23);
    root = Insert(root, 15);
    root = Insert(root, 58);
    root = Insert(root, 78);
    root = Insert(root, 67);

    cout << "Post-Order\n";
    Postorder(root);
    cout << "\n";
    DelTree(root);

    root = NULL;

    cout << "\n\nTree Deleted\n";
}
