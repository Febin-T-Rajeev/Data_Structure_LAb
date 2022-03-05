#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head,*newnode,*temp;
void creation();
void display();
void ins_beg();
void ins_mid();
void ins_end();
void del_beg();
void del_mid();
void del_end();
void main()
{
	int choice=0;
	do
	{
		printf("enter the choice\n1:creation\n2:insert beg\n3:insert mid\n4:insert end\n5:delete beg\n6:delete mid\n7:delete end\n8:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				creation();
				display();
				break;
			case 2:
				ins_beg();
				display();
				break;
			case 3:
				ins_mid();
				display();
				break;
			case 4:
				ins_end();
				display();
				break;
			case 5:
				del_beg();
				display();
				break;
			case 6:
				del_mid();
				display();
				break;
			case 7:
				del_end();
				display();
				break;
			case 8:
				exit(0);
				break;

		}
	}while(choice!=8);
}
void creation()
{
	int a=1;
	head=0;
	while(a)
	{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==0)
	{
		head=temp=newnode;
	}
	else
	{
		temp->next=newnode;
		temp=newnode;
	}
	printf("do yo want to continue(1/0):\n");
	scanf("%d",&a);
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
	printf("the number of nodes is:\t%d\n",count);
}
void ins_beg()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the data to be inserted:\n");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
}
void ins_end()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the data to be insered:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}
void ins_mid()
{
	int count=0,pos,i=1;
	temp=head;
	while(temp!=NULL)
	{
	count=count+1;
	temp=temp->next;
	}
	printf("enter the position after which the elemnt should inserted:\t");
	scanf("%d",&pos);
	if(pos>count)
	{
	printf("invalid position!");
	}
	else
	{
		temp=head;
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter the data:");
		scanf("%d",&newnode->data);
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void del_beg()
{
	if(head==NULL)
	{
		printf("no nodes!");
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
	}
}
void del_end()
{
	struct node *prevnode;
	temp=head;
	while(temp->next!=NULL)
	{
		prevnode=temp;
		temp=temp->next;
	}
	if(temp==head)
	{
		head=0;
	}
	else
	{
		prevnode->next=NULL;
	}
	free(temp);
}
void del_mid()
{
	struct node *nextnode;
	int pos,i=1;
	temp=head;
	printf("enter the position to delete:\t");
	scanf("%d",&pos);
	while(i<pos-1)
	{
		temp=temp->next;
		i++;
	}
	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
}




