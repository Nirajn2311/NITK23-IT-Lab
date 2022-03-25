#include <bits/stdc++.h>

using namespace std;

struct tree
{
    int data;
    tree *left = NULL;
    tree *right = NULL;
};

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

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return 1 + max(height(node->right), height(node->left));
}

void is_node_avl_balanced(tree *node)
{
    int balance_factor = height(node->left) - height(node->right);
    cout << "BALANCE FACTOR OF NODE d = " << node->data << " is " << balance_factor << endl;
    if (abs(balance_factor) <= 1)
    {
        cout << "The node d = " << node->data << " is AVL balanced" << endl;
    }
    else
    {
        cout << "The node d = " << node->data << " is not AVL balanced" << endl;
    }
}

int is_tree_avl_balanced(tree *node)
{
    if (node == NULL)
    {
        return 1;
    }
    int balance_factor = height(node->left) - height(node->right);
    if (abs(balance_factor) <= 1 && is_tree_avl_balanced(node->left) && is_tree_avl_balanced(node->right))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void balance_factor(tree *temp)
{
    tree *node = temp;
    if (temp != NULL)
    {
        is_node_avl_balanced(node);
        balance_factor(node->left);
        balance_factor(node->right);
    }
}

int main()
{
    tree *node = new tree;
    node = NULL;
    int n, a;
    cout << "Enter number of nodes in tree" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int d = rand() % n;
        node = insert(node, d);
    }
    balance_factor(node);
    a = is_tree_avl_balanced(node);
    if (a == 1)
    {
        cout << "Tree is avl balanced " << endl;
    }
    else
    {
        cout << "Tree is not avl balanced" << endl;
    }
    return 0;
}