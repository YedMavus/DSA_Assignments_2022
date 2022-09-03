#include<iostream>
using namespace std;

/*
Write a Program in C/C++ to sort n integers using insertion sort and linked list.

Do not use an array.
*/

typedef struct Node{
	int data;
	struct Node *next;
} node;

node *head, *p,*q;
void print(Node * head)
{
	Node * pr;
	pr=head;
	while(pr!=NULL)
	{
		cout<<pr->data<<"->";
		pr=pr->next;
		
	}
	
	cout<<"NULL";
}
/*
Considers first entered element as head of the list.
for each next element insertion, it is compared with current element,
 if greater, next element is comapred, if less, is inserted
*/

int main()
{
	int n;
	cin>>n;
	head = new Node;
	cin>>head->data;
	head->next=NULL;
	for(int i = 1; i<n; i++)
	{
		p=head;
		// cout<<i<<endl;
		// print(head);
		// cout<<endl;
		Node * temp = new Node;
		temp->next=NULL;
		cin>>temp->data;

		//IF VAL LESS THAN HEAD VAL, HEAD HAS TO CHANGE
		if(temp->data<head->data)
		{
			temp->next=head;
			head=temp;
			p=temp;
			continue;
		}
		else if(p->next==NULL)
				{p->next=temp;continue;}
		while(p!=NULL)
		{
			q=p;
			p=p->next;
			if(q->data < temp->data && p->data > temp->data)
			{
				temp->next=p;
				q->next=temp;
				break;//insertion complete
			}
			if(p->next==NULL)
			{
				p->next=temp;break;
			}
			
		}
	}

	cout<<endl;
	print(head);
}