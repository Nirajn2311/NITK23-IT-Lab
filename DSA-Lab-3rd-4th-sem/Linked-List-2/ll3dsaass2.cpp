# include<iostream>
using namespace std;
struct cnode
{
	int number;
	cnode *next;
};
void push(cnode **head, int no)
{
	cnode *newnode=new cnode;
	cnode *temp=*head;
	newnode->number=no;
	newnode->next=*head;
	if(*head==NULL)
		{newnode->next=newnode;
			*head=newnode;
		}
		else
		{
		   
			while(temp->next!=*head)
				temp=temp->next;
			temp->next=newnode;
			*head=newnode;
		}
}

void del(cnode *head, int no)
{
	cnode *temp=head;
	cnode *ref;
 if(head!=NULL)
 {
 	while(temp->next->number!=no)
 	{
 		temp=temp->next;
 	}
 		ref=temp->next;
 	if(temp->next->next==head)
 	{
 	    temp->next=head;
 	    
 	}
 	else
 
 	temp->next=temp->next->next;
 	delete ref;
 }
 else
 	cout<<"No element to delete"<<endl;
}
void display(cnode *head)
{
	cnode *temp=head;
	if(temp!=NULL)
	{
		do
		{
			cout<<"You are in node number "<<temp->number<<endl;
		    temp=temp->next;
		}while(temp!=head);
		

	}
	else
		cout<<"Circular linked list is empty";

}


int main()
{
	cnode *head=new cnode;
	head=NULL;
	int n,i;
	cout<<"Enter number of elements in circular linked list : ";
	cin>>n;
	for(i=n;i>=1;i--)
		push(&head,i);
	display(head);
  for(i=1;i<=n;i++)
  if(i%2==0)
  del(head,i);
	display(head);

}
