#include<iostream>
using namespace std;

class Node 
{
	//type
	public:

	//pointer to the next node
	Node *next;

	//data
	int data;

	//construct
	Node()
	{
		next=NULL;
	}
};

class clinklist
{
	//head->node type pointer
	Node *head;

	//tail->node type pointer
	Node *tail;

	//type
	public:

	//constructor
	clinklist()
	{
		head=NULL;
		tail=NULL;
	}

//insert
void insert(int value)
{
	//addition of the 1st node
	Node *p=new Node;
	p->data=value;

	//for the 1st node
	if (head==NULL)
	{head=p;}

	//for other node
	else
	{
	 tail->next=p;
	 p->next=head;
	}
	tail=p; 	
}

//insertat
void insertat(int pos,int value)
{
	//applyning conditions
	if( pos>(this->count()+1) )
	cout<<"such a position doesn't exist in the linklist. "<<endl;
	else
	{
		Node *p=new Node;
		p->data=value;
		int i=1;Node *temp=head;
		while(i<pos-1)
		{temp=temp->next;i++;}
		if(pos!=1)
		{
			p->next=temp->next;
			temp->next=p;
		}
		else if(pos==1)
		{
			p->next=temp;
			head=p;
		}
	}
}

//delete
void del()
{
	//before tail has to point to the head
	Node *p=head;
	while(p->next!=tail)
	{p=p->next;}

	//updating the tail
	tail=p;
	p=p->next;
	p->next=NULL;

	//delete p
	delete p;
	tail->next=head;
}

//delat
void delat(int pos)
{
	if ( pos>this->count() )
	cout<<"The linklist does not contain that many elements";
	else 
	{
		//reach the point before the pos
		Node *p=head;
		int i=1;
		while(i<pos-1)
		{p=p->next;i++;}
	
		Node *d=p->next;
		p->next=d->next;
		d->next=NULL;
		delete d;
	}
}

//count
int count()
{
	Node *p=head;int i=1;
	while (p!=tail)
	{p=p->next;i++;}
	return i;
}

//display
void display()
{
	Node *p=head;
	while(p!=tail)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
	cout<<p->data<<endl;
	
}
};

int main()
{
	clinklist cl;
	cl.insert(1);cl.insert(2);cl.insert(3);cl.insert(4);cl.insert(5);cl.insert(6);cl.insert(7);cl.insert(8);
	cl.display();
	cl.insertat(2,7);
	cl.display();
	cl.insertat(10,3);
	cl.del();
	cl.display();
	cl.delat(2);cl.display();
	return 0;
}