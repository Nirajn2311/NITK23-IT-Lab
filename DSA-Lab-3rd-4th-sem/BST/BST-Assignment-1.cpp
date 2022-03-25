#include <bits/stdc++.h>

using namespace std;

struct tree
{
    char data;
    tree *left = NULL;
    tree *right = NULL;
};

tree *newNode(char data)
{
    tree *Node = new tree();
    Node->data = data;
    return Node;
}

int search(char arr[], int start, int end, char value)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
}

tree *buildTree(char in[], char pre[], int inStart, int inEnd)
{
    static int preIndex = 0;
    if (inStart > inEnd)
    {
        return NULL;
    }
    tree *tNode = newNode(pre[preIndex++]);
    if (inStart == inEnd)
    {
        return tNode;
    }
    int inIndex = search(in, inStart, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, inStart, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}

void dispInorder(tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    dispInorder(tree->left);
    cout << tree->data << " ";
    dispInorder(tree->right);
}

int main()
{
    char in[] = {'D', 'B', 'A', 'G', 'E', 'H', 'C', 'F'};
    char pre[] = {'A', 'B', 'D', 'C', 'E', 'G', 'H', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    tree *root = buildTree(in, pre, 0, len - 1);
    cout << "Inorder traversal of the constructed tree is: ";
    dispInorder(root);
    cout << endl;
    return 0;
}