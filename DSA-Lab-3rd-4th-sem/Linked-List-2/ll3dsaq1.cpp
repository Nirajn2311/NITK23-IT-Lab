#include <iostream>

using namespace std;

struct webp
{
	int pageno;
	webp *next;
	webp *prev;
};

void insertwebp(webp **head, int page)
{
	webp *newnode = new webp;
	webp *ref = *head;
	newnode->pageno = page;
	newnode->prev = NULL;
	if (*head != NULL)
	{
		ref->prev = newnode;
	}
	newnode->next = *head;
	*head = newnode;
}
int main()
{
	int x;
	char y;
	webp *head = new webp;
	head = NULL;
	for (int i = 10; i >= 1; i--)
	{
		insertwebp(&head, i);
	}
	webp *pointer = head;
	do
	{
		cout << "YOU ARE IN THE PAGE NUMBER " << pointer->pageno << endl;
		cout << "ENTER '1' TO GO TO THE NEXT PAGE" << endl;
		cout << "ENTER '2' TO GO TO THE PREVIOUS PAGE" << endl;

		cin >> x;
		if (x != 1 && x != 2)
			cout << "YOU HAVE ENTERED AN INVALID OPTION" << endl;

		switch (x)
		{
		case 1:

			if (pointer->next != NULL)
			{
				pointer = pointer->next;
				cout << "YOU ARE IN PAGE NUMBER : " << pointer->pageno << endl;
			}
			else
			{
				cout << "YOU ARE AT THE LAST PAGE , YOU CANNOT GO NEXT" << endl;
			}
			break;
		case 2:

			if (pointer->prev != NULL)
			{
				pointer = pointer->prev;
				cout << "YOU ARE IN PAGE NUMBER : " << pointer->pageno << endl;
			}
			else
			{
				cout << "YOUR ARE AT THE FIRST PAGE YOU CANNOT GO TO THE PREVIOUS PAGE" << endl;
			}
			break;
		}
		cout << "Do you want to continue? (Y/N) : ";
		cin >> y;

	} while (y == 'y' || y == 'Y');

	return 0;
}