#include<stdio.h>
#include<stdlib.h>
void insbeg();
void insmid();
void insend();
void delbeg();
void delmid();
void delend();
void display();
void creation();
struct node
{
	int data;
	struct node *next,*prev;
};
struct node *head,*newnode,*temp,*temp1;
void main()
{
	int choice=0;
	clrscr();
	do
	{
		printf("enter the choice\n1.creation\n2.insbeg\n3.insmid\n4.insend\n5.delbeg\n6.delmid\n7.delend\n8.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:creation();display();break;
			case 2:insbeg();display();break;
			case 3:insmid();display();break;
			case 4:insend();display();break;
			case 5:delbeg();display();break;
			case 6:delmid();display();break;
			case 7:delend();display();break;
			case 8:exit(0);break;
		}

	}while(choice!=8);
getch();
}
void creation()
{
	int ch=1;
	head=0;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the element to be inserted\t:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==0)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		printf("do you want to continue(1/0)y/n!");
		scanf("%d",&ch);
	}
}
void display()
{
	int count=0;
	temp=head;
	while(temp!=NULL)
	{
		count=count+1;
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("the number of nodes is:\t %d\n",count);
}
void insbeg()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the element to be inserted\t:");
	scanf("%d",&newnode->data);
	newnode->next=head;
	newnode->prev=NULL;
	head=newnode;
}
void insmid()
{
	int pos,count=0,i=1;
	temp=head;
	while(temp!=NULL)
	{
		count=count+1;
		temp=temp->next;
	}
	printf("enter the position after which the element to be inserted\t:");
	scanf("%d",&pos);
	if(pos>count)
	{
		printf("invalid position");
	}
	else
	{
		temp=temp1=head;
		while(i<pos)
		{

			temp1=temp;
			temp=temp->next;
			i++;
		}

		printf("enter the element to be inserted\t:");
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->next=temp,
		temp->prev=newnode;
		newnode->prev=temp1;
		temp1->next=newnode;
       }
}
void insend()
{
	newnode=(struct node*)malloc(sizeof(struct  node));
	printf("enter the element to be inserted\t:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}
void delbeg()
{
	if(head==NULL)
	printf("node absent\n");
	temp=head;
	head=temp->next;
	head->prev=NULL;
	free(temp);
}
void delmid()
{
	int del;
	if(head==NULL)
	printf("node absent\n");
	printf("enter the data to delete\t:");
	scanf("%d",&del);
	temp=head;
	while(temp->data!=del)
	{
		if(temp->next==NULL)
		{
			printf("given node is not found \n");
		}
		else
		{
			temp=temp->next;
		}
	}
	if(temp==head)
	{
		head=NULL;
		free(temp);
	}
	else
	{
		temp->prev->next=temp->next;
		free(temp);
	}

       /*	{
		temp1=temp;
		temp=temp->next;
		i++;
	}
	else
	{
		//temp1->next=temp->next;
		//temp->next->prev=temp1;
		temp->prev->next=temp->next;
		free(temp);
	}*/
}
void delend()
{
	if(head==NULL)
	printf("node absent\n");
	temp=head;
	while(temp->next!=NULL)
	{
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	free(temp);
}