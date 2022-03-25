#include <bits/stdc++.h>

using namespace std;

struct tree
{
    int data;
    tree *left = NULL;
    tree *right = NULL;
} *node1 = NULL, *node2 = NULL;

tree *newNode(int d)
{
    tree *temp = new tree();
    temp->data = d;
    return temp;
}

tree *insert(tree *root, int d)
{
    if (root == NULL)
    {
        root = newNode(d);
    }
    else if (root->data >= d)
    {
        root->left = insert(root->left, d);
    }
    else
    {
        root->right = insert(root->right, d);
    }
    return root;
}

tree *copy_tree(tree *source, tree *destination)
{
    tree *temp = source;

    if (temp != NULL)
    {
        destination = insert(destination, temp->data);
        copy_tree(temp->left, destination);
        copy_tree(temp->right, destination);
    }
    return destination;
}

void deletion(tree *source)
{
    tree *temp = source;
    if (temp != NULL)

    {
        deletion(temp->left);
        deletion(temp->right);
        cout << "Deleting " << temp->data << endl;
        delete temp;
    }
}

int main()
{
    int data;
    for (int i = 1; i <= 10; i++)
    {
        data = rand() % 10;
        node1 = insert(node1, data);
    }

    node2 = copy_tree(node1, node2);
    cout << "Deleting the original tree" << endl;
    deletion(node1);
    cout << "\nDeleting the copied tree" << endl;
    deletion(node2);

    // We prefer postorder for deletion as it is much easier delete elements from leaf to root and with lesser time also.
}
