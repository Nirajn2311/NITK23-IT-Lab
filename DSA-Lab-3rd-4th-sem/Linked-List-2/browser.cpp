#include <bits/stdc++.h>

using namespace std;

struct History
{
    int id;
    string webpage;
    History *next = NULL;
    History *prev = NULL;
} *head = NULL, *current = NULL;

int i = 1;

void page_insert()
{
    History *node = new History;
    cout << "\nEnter webpage name: ";
    cin >> node->webpage;
    node->prev = head;
    node->id = i;
    i++;
    if (head != NULL)
    {
        head->next = node;
    }
    current = head = node;
}

void delete_pages()
{
    History *node = current->next, *temp;
    head = current;
    while (node != NULL)
    {
        temp = node;
        node = node->next;
        delete temp;
    }
}

void next_page()
{
    if (current->next == NULL)
    {
        cout << "\nNO NEXT PAGE, CREATING NEW PAGE!!" << endl;
        page_insert();
        return;
    }
    int op;
    cout << "\nNEXT PAGE MENU\n--------------";
    cout << "\nWhat do you want to do?";
    cout << "\n1. Go to a new webpage";
    cout << "\n2. Go to next page in history which is - " << current->next->webpage;
    cout << "\nEnter your option: ";
    cin >> op;
    switch (op)
    {
    case 1:
        delete_pages();
        page_insert();
        break;

    case 2:
        current = current->next;
        break;

    default:
        cout << "\nINVALID OPTION ENTERED!!!" << endl;
        break;
    }
}

void prev_page()
{
    if (current->prev == NULL)
    {
        cout << "\nYOU ARE AT TOP PAGE!!" << endl;
        return;
    }
    current = current->prev;
}

void display()
{
    History *node = head;
    cout << "\n\nHISTORY\n-------" << endl;
    while (node != NULL)
    {
        if (current->id == node->id)
        {
            cout << "ID: " << node->id << "\tPAGE: " << node->webpage << "\t<-- YOU ARE HERE" << endl;
        }
        else
        {
            cout << "ID: " << node->id << "\tPAGE: " << node->webpage << endl;
        }
        node = node->prev;
    }
}

int main()
{
    char ans;
    int opt;
    current = head;
    page_insert(); // Required for startup
    do
    {
        cout << "\nMENU\n----";
        cout << "\nWhat do you want to do?";
        cout << "\n1. Go to next page";
        cout << "\n2. Go to previous page";
        cout << "\nEnter your option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            next_page();
            break;

        case 2:
            prev_page();
            break;

        default:
            cout << "\nINVALID OPTION ENTERED!!!" << endl;
            break;
        }
        display();
        cout << "\nDo you want to continue(Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}