#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
int cq[100],front=-1,rear=-1,max,data,i;
void main()
{
 	int cq[100],choice=0;
	printf("Enter the maximum size of queue:\n");
 	scanf("%d",&max);
	do
	{
	printf("enter a choice \n1:insertion in CQ  \n2:deletion in CQ  \n3:exit\t");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insert();
			display();
			break;
		case 2:
			delete();
			display();
			break;
		case 3:
			exit(0);
			break;
	
	}
	}
	while(choice!=3);
		
	
}
void insert()
{	
  			if(front==((rear+1)%max))
   				{
   					printf("queue overflow!!!!\n");
   				}
			else if(front==-1 && rear==-1)
				{
					front=0;
					rear=0;
					printf("enter the  element of CQ\t");
  					scanf("%d",&data);
  					cq[rear]=data;
				}
  			else
   				{
					rear=(rear+1)%max;
					printf("enter the  element of CQ\t");
  					scanf("%d",&data);
  					cq[rear]=data;
    				}
			
			
}

void delete()
{
	if(front==-1)
	{
		printf("cq is underflow!");
	}	
	else if(front==rear)
	{
		data=cq[front];
		front=-1;
		rear=-1;
		printf("the element deleted is %d\n",data);
	}
	else
	{
		data=cq[front];
		front=(front+1)%max;
                printf("the element deleted is %d\n",data);
 	}	

			
			
}

void display()
{
	if(front==-1 && rear==-1)
	{
		printf("\n there is no elemnt to display\n");
	}
	else
	{
		if(front==rear)
		{
			printf("%d\t",cq[rear]);
		}
	else if(front<rear)
		{		
			for(i=front;i<=rear;i++)
				{
					printf("%d\t",cq[i]);
				}
		}	
	else if(rear<front)
	{
		for(i=front;i<max;i++)
			printf("%d\t",cq[i]);
		for(i=0;i<=rear;i++)
			printf("%d\t",cq[i]);
	}
	}
}		

