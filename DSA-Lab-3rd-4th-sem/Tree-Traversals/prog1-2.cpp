#include <bits/stdc++.h>

using namespace std;

struct tree
{
    int data;
    tree *left = NULL;
    tree *right = NULL;
} *root = NULL, *root_ll = NULL;

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

void inOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void search(tree *root, int d)
{
    int height = 0, flag = 0;
    tree *temp = root;
    while (temp != NULL)
    {
        if (temp->data == d)
        {
            cout << "DATA FOUND AT HEIGHT: " << height << endl;
            flag = 1;
            break;
        }
        else if (temp->data > d)
        {
            temp = temp->left;
            height++;
        }
        else if (temp->data < d)
        {
            temp = temp->right;
            height++;
        }
    }
    if (flag == 0)
    {
        cout << "DATA NOT FOUND!!!" << endl;
    }
}

int main()
{
    int d, num;
    for (int i = 0; i < 1000; i++)
    {
        d = rand() % 1000;
        root = insert(root, d);
    }

    for (int i = 0; i < 1000; i++)
    {
        root_ll = insert(root_ll, i);
    }
    cout << "\n\nTREE:\n\nIN: ";
    inOrder(root);
    cout << "\n\nLL TREE:\n\nIN: ";
    inOrder(root_ll);
    // Uncomment below lines for required type of traversal
    // cout << endl
    //      << "PRE: ";
    // preOrder(root);
    // cout << endl
    //      << "POST: ";
    // postOrder(root);
    // cout << endl;
    cout << "\nEnter data to search for: ";
    cin >> num;
    search(root, num);
    search(root_ll, num);
    return 0;
}