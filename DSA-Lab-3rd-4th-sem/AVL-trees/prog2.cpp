#include <bits/stdc++.h>

using namespace std;

// bool flag;
// string unbalance;
// int subTree;

class node
{
public:
    int data;
    int balance;
    node *left, *right;
    int height;
    node(int val)
    {
        data = val;
        left = right = NULL;
        balance = 0;
        height = -1;
    }
};

int maximum(int a, int b)
{
    return (a >= b) ? a : b;
}

int nodeHeight(node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    node->height = 1 + maximum(nodeHeight(node->left), nodeHeight(node->right));
    return node->height;
}

void setBalance(node *root)
{
    int lh, rh;
    if (root == NULL)
    {
        return;
    }
    lh = nodeHeight(root->left);
    rh = nodeHeight(root->right);
    root->balance = lh - rh;
    setBalance(root->left);
    setBalance(root->right);
}

node *rightRotate(node *b)
{
    node *x = b->left;
    node *T2 = x->right;
    x->right = b;
    b->left = T2;
    b->height = nodeHeight(b);
    x->height = nodeHeight(x);
    return x;
}

node *leftRotate(node *a)
{
    node *y = a->right;
    node *T2 = y->left;
    y->left = a;
    a->right = T2;
    a->height = nodeHeight(a);
    y->height = nodeHeight(y);
    return y;
}

int getBalance(node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return nodeHeight(N->left) - nodeHeight(N->right);
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        node *temp = new node(data);
        return temp;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }
    root->height = nodeHeight(root);
    int balance = getBalance(root);
    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void reportAVL(node *root)
{
    if (root != NULL)
    {
        reportAVL(root->left);
        reportAVL(root->right);
        cout << "Balance factor = " << root->balance << ", height = " << nodeHeight(root) << " at node - " << root->data << endl;
    }
}

node *insert1(node *root, int data)
{
    if (root == NULL)
    {
        node *x = new node(data);
        return x;
    }
    if (data < root->data)
    {
        root->left = insert1(root->left, data);
    }
    else
    {
        root->right = insert1(root->right, data);
    }
    return root;
}

node *createTree(int MAX_SIZE)
{
    int n;
    node *root = NULL;
    while (MAX_SIZE > 0)
    {
        cout<<"Enter node data: ";
        cin >> n;
        root = insert(root, n);
        MAX_SIZE--;
    }
    return root;
}

bool del(node *root, int data)
{
    if (root != NULL)
    {
        if (root->data == data)
        {
            delete root;
            return true;
        }
        if (del(root->left, data))
            root->left = NULL;
        if (del(root->right, data))
            root->right = NULL;
    }
    return false;
}

int main()
{
    int max, num, n;
    bool flag = true;
    string unbalance = "";
    int subTree = 0;
    cout << "Enter number of nodes: ";
    cin >> max;
    node *root = createTree(max);
    setBalance(root);
    reportAVL(root);
    cout << "\nAVL tree constructed" << endl;
    cout << "\n\nEnter a node: ";
    cin >> n;
    insert1(root, n);
    setBalance(root);
    reportAVL(root);
    cout << "\nAfter rotation: " << endl;
    del(root, n);
    root = insert(root, n);
    cout << endl;
    setBalance(root);
    reportAVL(root);
    return 0;
}