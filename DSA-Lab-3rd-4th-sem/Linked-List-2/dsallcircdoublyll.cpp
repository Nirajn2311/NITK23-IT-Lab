#include <iostream>
using namespace std;
struct node
{
	int songno;
	node *next;
	node *prev;
};
void push(node **head, int song)
{
	node *newnode = new node;
	node *temp = *head;
	newnode->songno = song;
	if (*head == NULL)
	{
		newnode->next = newnode;
		newnode->prev = newnode;
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		temp = temp->prev;
		temp->next = newnode;
		newnode->prev = temp;
		*head = newnode;
	}
}

void del(node **head, int song)
{
	node *temp = *head;
	node *ref = new node;
	if (*head != NULL)
	{
		if (temp->songno == song)
		{
			delete temp;
			*head = NULL;
		}
		else
		{
			while (temp->next->songno != song)
			{
				temp = temp->next;
			}
			ref = temp->next;
			temp->next = temp->next->next;
			temp->next->prev = temp;
			delete ref;
		}
	}
	else
		cout << "Playlist is empty , no song to delete!" << endl;
}

void display(node *head)
{
	node *temp = head;
	if (head != NULL)
	{

		do
		{
			cout << "Playing song number " << temp->songno << endl;
			temp = temp->next;
		} while (temp != head);
	}
	else
		cout << "Playlist is empty, no songs to display" << endl;
}
int main()
{
	node *head = new node;
	head = NULL;
	int n, i, x, d;
	char cont;
	cout << "Enter number of songs in your playlist : ";
	cin >> n;
	for (i = n; i >= 1; i--)
	{
		push(&head, i);
	}
	node *temp = head;
	do
	{
		cout << "OPERATIONS PERFORMED BY MUSIC PLAYER" << endl;
		cout << "1. PLAY CURRENT SONG " << endl;
		cout << "2. PLAY NEXT SONG " << endl;
		cout << "3. PLAY PREVIOUS SONG " << endl;
		cout << "4. PLAY ENTIRE PLAYLIST " << endl;
		cout << "5. DELETE A SONG " << endl;
		cout << "Enter the operation you want to perform : ";
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Playing song number " << temp->songno << endl;
			break;
		case 2:
			if (temp->next == head)
			{
				temp = temp->next;
				cout << "You are at the end of the playlist , playing song number " << temp->songno << endl;
			}
			else
			{
				temp = temp->next;
				cout << "Playing song number " << temp->songno << endl;
			}
			break;
		case 3:
			if (temp == head)
			{
				temp = temp->prev;
				cout << "You are at the beginning of the playlist, playing song number " << temp->songno << endl;
			}
			else
			{
				temp = temp->prev;
				cout << "Playing song number " << temp->songno << endl;
			}
			break;
		case 4:
			cout << "Playlist starts " << endl;
			display(head);
			break;
		case 5:
			cout << "Enter the number of the song you want to delete : ";
			cin >> d;
			del(&head, d);

			break;
		default:
			cout << "You have entered an invalid option !" << endl;
		}
		cout << "Do you want to continue? (Y/N) : ";
		cin >> cont;

	} while (cont == 'y' || cont == 'Y');
	return 0;
}
