#include<stdio.h>
typedef struct list
{
	int info;
	struct list *next;
}NODE;
void insert(NODE **pfront,NODE **prear,int n)
{
	NODE *node;
	node=(NODE *)malloc(sizeof(NODE));
	if(node==NULL)
	  {
	  	printf("Queue Overflow");
	  	return;
	  }
	node->info=n;
	node->next=NULL;
	if(*pfront==NULL)
	    {
	    	*pfront=*prear=node;
	    }
	else
	   {
	   	  (*prear)->next=node;
	   	  (*prear)=(*prear)->next;
	   }
}
int delete(NODE **pfront,NODE **prear)
{
	int n=0;
	NODE *temp;
	if(*pfront==NULL)
	{
		printf("\nQueue Underflow");
	}
	else
	{
		n=(*pfront)->info;
		if(*pfront==*prear)
		{
			free(*pfront);
			*pfront=*prear=NULL;
		}
		else
		{
			temp=*pfront;
			(*pfront)=(*pfront)->next;
			free(temp);
		}

	}
	return n;
}
void traverse(NODE *front)
{
	NODE *p=front;
	if(p==NULL)
	{
		printf("\nQueue Underflow");
		return;
	}
	while(p!=NULL)
	{
		printf("%5d",p->info);
		p=p->next;
	}
}
int main()
{
	NODE *front=NULL,*rear=NULL;
	int n,ch;
	do{
		printf("\n*****MENU*****");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. traverse");
		printf("\n4. Exit");
		printf("\n***************");
		printf("\nEnter Your Choice 1/2/3/4 : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter value to insert : ");
					scanf("%d",&n);
					insert(&front,&rear,n);
					break;
			case 2: n=delete(&front,&rear);
					printf("\n%d deleted",n);
					break;
			case 3: traverse(front);
					break;
			case 4: printf("\n\n Thank you");
					break;
			default:printf("\nWrong Choice....");
		}

	}while(ch!=4);
}
