// The time complexity for both types of list is same ie. O(n) .
// Deletion of a node is easier in doubly linked list.

#include <bits/stdc++.h>

using namespace std;

struct SingleNode
{
    int id;
    string name;
    SingleNode *next = NULL;
} *shead = NULL;

struct DoubleNode
{
    int id;
    string name;
    DoubleNode *next = NULL;
    DoubleNode *prev = NULL;
} *dhead = NULL;

void sing_insert()
{
    SingleNode *node = new SingleNode;
    cout << "\nEnter ID: ";
    cin >> node->id;
    cout << "Enter Name: ";
    cin >> node->name;
    node->next = shead;
    shead = node;
}

void sing_delete()
{
    int key, flag = 0;
    SingleNode *node = shead, *prev = NULL;
    if (node == NULL)
    {
        cout << "\nLIST EMPTY!!!" << endl;
        return;
    }
    cout << "\nEnter Student ID for deletion: ";
    cin >> key;
    if (node->id == key)
    {
        cout << "\nCANNOT DELETE AS THERE IS NO NODE BEHIND HEAD!!!" << endl;
        return;
    }
    else
    {
        while (node->next != NULL)
        {
            if (node->next->id == key)
            {
                flag = 1;
                break;
            }
            prev = node;
            node = node->next;
        }
    }
    if (flag)
    {
        if (prev != NULL)
        {
            prev->next = node->next;
            delete node;
        }
        else
        {
            shead = node->next;
            delete node;
        }
        cout << "\nRECORD DELETED" << endl;
    }
    else
    {
        cout << "\nRECORD NOT FOUND!!!" << endl;
    }
}

void sing_display()
{
    SingleNode *node = shead;
    if (node == NULL)
    {
        cout << "\nLIST EMPTY!!!" << endl;
        return;
    }
    cout << "\n\nLIST OF STUDENTS\n----------------" << endl;
    while (node != NULL)
    {
        cout << "ID: " << node->id << "\tNAME: " << node->name << endl;
        node = node->next;
    }
}

void doub_insert()
{
    DoubleNode *node = new DoubleNode;
    cout << "\nEnter ID: ";
    cin >> node->id;
    cout << "Enter Name: ";
    cin >> node->name;
    node->next = dhead;
    if (dhead != NULL)
    {
        dhead->prev = node;
    }
    dhead = node;
}

void doub_delete()
{
    int key, flag = 0;
    DoubleNode *node = dhead, *pnode;
    if (node == NULL)
    {
        cout << "\nLIST EMPTY!!!" << endl;
        return;
    }
    cout << "\nEnter Student ID for deletion: ";
    cin >> key;
    if (node->id == key)
    {
        cout << "\nCANNOT DELETE AS THERE IS NO NODE BEHIND HEAD!!!" << endl;
        return;
    }
    else
    {
        while (node->next != NULL)
        {
            if (node->next->id == key)
            {
                flag = 1;
                break;
            }
            node = node->next;
        }
    }
    if (flag)
    {
        if (node->prev != NULL)
        {
            pnode = node->prev;
            pnode->next = node->next;
            node->next->prev = pnode;
            delete node;
        }
        else
        {
            dhead = node->next;
            dhead->prev = NULL;
            delete node;
        }
        cout << "\nRECORD DELETED" << endl;
    }
    else
    {
        cout << "\nRECORD NOT FOUND!!!" << endl;
    }
}

void doub_display()
{
    DoubleNode *node = dhead;
    if (node == NULL)
    {
        cout << "\nLIST EMPTY!!!" << endl;
        return;
    }
    cout << "\n\nLIST OF STUDENTS\n----------------" << endl;
    while (node != NULL)
    {
        cout << "ID: " << node->id << "\tNAME: " << node->name << endl;
        node = node->next;
    }
}

int main()
{
    int opt, t;
    char ans;
    cout << "\nWhich type of list do you want to use?";
    cout << "\n1. Singly Linked List";
    cout << "\n2. Doubly Linked List";
    cout << "\nEnter your option: ";
    cin >> t;
    if (t != 1 && t != 2)
    {
        cout << "\nINVALID OPTION ENTERED!!!" << endl;
        exit(0);
    }
    do
    {
        if (t == 1)
        {
            cout << "\nSINGLY LINKED LIST\n------------------";
        }
        else
        {
            cout << "\nDOUBLY LINKED LIST\n------------------";
        }
        cout << "\nWhat do you want to do?";
        cout << "\n1. Insert element (Gets inserted into the beginning)";
        cout << "\n2. Delete a node (Node behind the node of given key gets deleted)";
        cout << "\n3. Display list of students";
        cout << "\nEnter your option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            if (t == 1)
            {
                sing_insert();
            }
            else
            {
                doub_insert();
            }
            break;

        case 2:
            if (t == 1)
            {
                sing_delete();
            }
            else
            {
                doub_delete();
            }
            break;

        case 3:
            if (t == 1)
            {
                sing_display();
            }
            else
            {
                doub_display();
            }
            break;

        default:
            cout << "\nINVALID OPTION ENTERED!!!" << endl;
            break;
        }

        cout << "\nDo you want to continue(Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}