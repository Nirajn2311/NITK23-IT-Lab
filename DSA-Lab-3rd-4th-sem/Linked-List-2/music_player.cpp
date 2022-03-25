#include <bits/stdc++.h>

using namespace std;

struct Playlist
{
    string song;
    Playlist *next = NULL;
    Playlist *prev = NULL;
} *head = NULL, *current = NULL;

void insert()
{
    Playlist *node = new Playlist;
    cout << "\nEnter Song name: ";
    cin >> node->song;
    if (head == NULL)
    {
        node->next = node;
        node->prev = node;
        current = head = node;
    }
    else
    {
        head->prev->next = node;
        node->prev = head->prev;
        head->prev = node;
        node->next = head;
        current = node;
    }
}

void play_current()
{
    if (head == NULL)
    {
        cout << "\nPLAYLIST EMPTY!!!" << endl;
        return;
    }
    cout << "\nPlaying Song: " << current->song << endl;
}

void play_next()
{
    if (head == NULL)
    {
        cout << "\nPLAYLIST EMPTY!!!" << endl;
        return;
    }
    if (current->next == head)
    {
        current = current->next;
        cout << "\nEND OF PLAYLIST, GOING TO BEGINNING!!";
        cout << "\nPLAYING SONG: " << current->song << endl;
    }
    else
    {
        current = current->next;
        cout << "\nPLAYING SONG: " << current->song << endl;
    }
}

void play_prev()
{
    if (head == NULL)
    {
        cout << "\nPLAYLIST EMPTY!!!" << endl;
        return;
    }
    if (current == head)
    {
        current = current->prev;
        cout << "\nSTART OF PLAYLIST, GOING TO END!!";
        cout << "\nPLAYING SONG: " << current->song << endl;
    }
    else
    {
        current = current->prev;
        cout << "\nPLAYING SONG: " << current->song << endl;
    }
}

void play_all()
{
    if (head == NULL)
    {
        cout << "\nPLAYLIST EMPTY!!!" << endl;
        return;
    }
    current = head;
    do
    {
        cout << "\nPlaying Song: " << current->song;
        current = current->next;
    } while (current != head);
    cout << endl;
}

void delete_song()
{
    if (head == NULL)
    {
        cout << "\nPLAYLIST EMPTY!!!" << endl;
        return;
    }
    Playlist *node = current, *p = current->prev;
    cout << "\nDELETING SONG: " << current->song << endl;
    if (node == p)
    {
        current = head = NULL;
    }
    else if (node == head)
    {
        head = head->next;
        p->next = head;
        head->prev = p;
        delete node;
        current = head;
    }
    else if (node->next == head)
    {
        head->prev = p;
        p->next = head;
        delete node;
        current = head;
    }
    else
    {
        current = current->next;
        p->next = node->next;
        node->next->prev = p;
        delete node;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "\nPLAYLIST EMPTY!!!" << endl;
        return;
    }
    Playlist *node = head;
    cout << "\n\nPLAYLIST\n--------" << endl;
    do
    {
        if (current->song == node->song)
        {
            cout << "SONG: " << node->song << "\t\t<--CURRENT SONG" << endl;
        }
        else
        {
            cout << "SONG: " << node->song << endl;
        }
        node = node->next;
    } while (node != head);
}

int main()
{
    char ans;
    int opt;
    do
    {
        cout << "\nPLAYLIST MENU\n-------------";
        cout << "\nWhat do you want to do?";
        cout << "\n1. Add song";
        cout << "\n2. Play current song";
        cout << "\n3. Play next song";
        cout << "\n4. Play previous song";
        cout << "\n5. Play entire playlist";
        cout << "\n6. Delete current song";
        cout << "\n7. Display playlist";
        cout << "\nEnter your option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insert();
            break;

        case 2:
            play_current();
            break;

        case 3:
            play_next();
            break;

        case 4:
            play_prev();
            break;

        case 5:
            play_all();
            break;

        case 6:
            delete_song();
            break;

        case 7:
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