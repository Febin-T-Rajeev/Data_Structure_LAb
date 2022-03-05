#include<stdio.h>
void main()
{
	int arr[100],i,pos,ele,n,del,j,s,choice;
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the numbers in the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
printf("ENTER YOUR CHOICE:\n1.INSERT\t2.DELETE\t3.SEARCH");
scanf("%d",&choice);
switch(choice)
{
	case 1:
	{	
	printf("enter the position and elemnt to be inserted:");
 	scanf("%d %d",&pos,&ele);
	for(i=n-1;i>=pos;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[pos]=ele;
	n=n+1;
	for(i=0;i<n;i++)
	{	
		printf("%d\t",*(arr+i));
	}	
	}
	break;
	case 2:
	{
	printf("enter the positio at which element to delete");
	scanf("%d",&del);
	for(i=del;i<n;i++)
	{
				arr[i]=arr[i+1];
	}
	n=n-1;
	for(i=0;i<n;i++)
	{	
		printf("%d\t",*(arr+i));
	}	
	}
	break;
	case 3:
	{
	printf("enter the element to search:");
	scanf("%d",&s);	
	for(i=0;i<n;i++)
	{
		if(arr[i]==s)
		{		
			printf("the element found at position %d",i);
		} 
				
	}
	}
	break;
	default:
	printf("INVALID CHOICE");
}

	
	
}

