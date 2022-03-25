#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *right = NULL;
    node *left = NULL;
};

class BinarySearchTree
{
    node *root;

public:
    BinarySearchTree()
    {
        root = NULL;
    }

    void insert(int d)
    {
        node *p = new node;
        p->data = d;
        if (root == NULL)
        {
            root = p;
        }
        else
        {
            node *x = root;
            node *y = root;
            while (x != NULL)
            {
                y = x;
                if (d < x->data)
                {
                    x = x->left;
                }
                else if (d > x->data)
                {
                    x = x->right;
                }
            }
            if (d > y->data)
            {
                y->right = p;
            }
            else if (d < y->data)
            {
                y->left = p;
            }
        }
    }

    int search(int d)
    {
        if (root == NULL)
        {
            cout << "THE BINARY SEARCH TREE IS EMPTY!!!" << endl;
            return 0;
        }
        else
        {
            int count = 0;
            int found = 0;
            node *x = root;
            while (x != NULL && found == 0)
            {
                if (d < x->data)
                {
                    x = x->left;
                    count++;
                }
                else if (d > x->data)
                {
                    x = x->right;
                    count++;
                }
                else if (d == x->data)
                {
                    found = 1;
                    count++;
                }
            }
            return count;
        }
    }
};

int main()
{
    BinarySearchTree obj;
    int insert[10000];
    int random;
    int sum = 0;
    for (int i = 0; i < 10000; i++)
    {
        random = rand();
        insert[i] = random;
        obj.insert(insert[i]);
    }
    for (int i = 0; i < 1000; i++)
    {
        int y = obj.search(insert[i]);
        sum += y;
    }
    float result = float(sum) / 1000;
    cout << result << endl;
    return 0;
}