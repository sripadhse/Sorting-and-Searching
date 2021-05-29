#include<bits/stdc++.h>
using namespace std;
struct node
{
node *link;
int data;
}*head;
void display();
//This will create the doubly linked list of n length 1..n
void create(int n)
{ node *p;
	if(head==NULL)
		{p=new node;
		p->data=1;
		p->link=NULL;
		head=p;
		}
	for(int i=2;i<=n;i++)
	{
		node *q=new node;
		q->data=i;
		q->link=NULL;
		p->link=q;p=q;
 
	}
	p->link=head;
	display();
}
 
//this will print the values
void display()
{  
	//q for free the node, p will follow the head
	node *H=head,*followH,*forDel;  
	
	if(H->link==H) //in case only one node
		{cout<<H->data<<endl;free(H);H=NULL;}
	else
	{
	followH=H;
	H=head->link;
	cout<<H->data<<" ";  //will print 2
 
	while(H!=NULL) //run from 2...n
	{
 	 forDel=H;
 	 if(H->link->link!=H) //if there more then two node
 	 {
 
 	 H=H->link->link;
 	 followH->link=forDel->link;followH=followH->link;//h5tfree(q);
 	 cout<<H->data<<" ";
 	 }
 	 else //in case only onde node left just print one by one and free it
 	 {  
 	 	forDel=H; H=H->link;
 	 	cout<<H->data<<" ";
 	 	
 	 	free(forDel);
 	 	forDel=H;
 	 	free(forDel);
 	 	H=NULL;
 	 }
	}
}
}
int main()
{
	int n;
	cin>>n;
	create(n);
 
}