#include <bits/stdc++.h>

using namespace std;

struct CircularList
{
    int id;
    string data;
    CircularList *next = NULL;
} *last = NULL;

void insert()
{
    CircularList *node = new CircularList;
    cout << "\nEnter ID: ";
    cin >> node->id;
    cout << "Enter Data: ";
    cin >> node->data;
    if (last == NULL)
    {
        last = node;
        last->next = last;
    }
    else
    {
        node->next = last->next;
        last->next = node;
        last = node;
    }
}

void delete_even()
{
    int i = 1;
    if (last == NULL)
    {
        cout << "\nCIRCULAR LIST EMPTY!!!" << endl;
        return;
    }
    CircularList *node = last->next, *temp = last;
    do
    {
        if (i % 2 == 0)
        {
            if (node == last)
            {
                last = temp;
            }
            temp->next = node->next;
            temp = node;
            delete temp;
        }
        temp = node;
        node = node->next;
        i++;
    } while (node != last->next);
}

void display()
{
    if (last == NULL)
    {
        cout << "\nEMPTY CIRCULAR LIST!!!" << endl;
        return;
    }
    CircularList *node = last->next;
    cout << "\nLIST OF NODES\n-------------" << endl;
    do
    {
        cout << "ID: " << node->id << "\tDATA: " << node->data << endl;
        node = node->next;
    } while (node != last->next);
}

int main()
{
    char ans;
    int opt;
    do
    {
        cout << "\nMENU\n----";
        cout << "\nWhat do you want to do?";
        cout << "\n1. Insert node";
        cout << "\n2. Delete all even nodes";
        cout << "\n3. Display nodes";
        cout << "\nEnter your option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insert();
            break;

        case 2:
            delete_even();
            break;

        case 3:
            display();
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