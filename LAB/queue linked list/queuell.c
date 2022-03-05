#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node* next;
};
struct node *front=NULL,*newnode,*rear=NULL,*temp;
void enqueue();
void dequeue();
void display();
void peek();
void main()
{
	int choice=0;
	do
	{
		printf("enter the choice\n1:enqueue\n2:dequeue\n3:peek\n4:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				display();
				break;
			case 2:
				dequeue();
				display();
				break;
			case 3:
				peek();
				break;
			case 4:
				exit(0);
				break;
		}
	}while(choice!=4);
}
void enqueue()
{
	int a,n=1;
	while(n)
	{
		printf("enter the data:\t");
		scanf("%d",&a);
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=a;
		newnode->next=NULL;
		if(front==NULL && rear==NULL)
		{
			front=rear=newnode;
		}
		else
		{
			rear->next=newnode;
			rear=newnode;
		}
		printf("do you want to continue:(1/0)\t");
		scanf("%d",&n);
	}
}
void dequeue()
{
	temp=front;
	if(front==NULL && rear==NULL)
	{
		printf("the queue is empty!!");
	}
	else
	{
		printf("the element deleted is %d\n",front->data);
		front=front->next;
		free(temp);
	}
}
void display()
{
	if(front==NULL && rear==NULL)
	{
		printf("the queue is empty!!");
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void peek()
{
	if(front==NULL && rear==NULL)
	{
		printf("the queue is empty!!");
	}
	else
	{
		printf("the front element is: %d\n",front->data);
		printf("the rear element is: %d\n",rear->data);
	}
}

