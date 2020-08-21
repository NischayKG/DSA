#include<stdio.h>
#include<malloc.h>
typedef struct list
{
	int info;
	struct list *next;
}NODE;

void createlist(NODE **start)
{
	NODE *node;
	char ch;
	do{
	if((*start)==NULL)
	{
		(*start)=(NODE *)malloc(sizeof(NODE));
		printf("\nEnter value for new Node ");
		scanf("%d",&(*start)->info);
		(*start)->next=NULL;
		node=*start;
	}
	else
	{
		node->next=(NODE *)malloc(sizeof(NODE));
		node=node->next;
		printf("\nEnter value for new Node ");
		scanf("%d",&node->info);
		node->next=NULL;
	}
	printf("\nDo you to create more node :");
	fflush(stdin);
	ch=getchar();
	}while(ch=='y' || ch=='Y');
}

void traverse(NODE *node)
{
	if(node==NULL)
	{
		printf("List is empty");
		return;
	}
	printf("\n");
	while(node!=NULL)
	{
		printf("%d->",node->info);
		node=node->next;
	}
}

void rotate(NODE **pstart,int k)
{
	if(k==0)
	{
		return;
	}
	NODE *current=*pstart;
	int count=1;
	while(current!=NULL&&count<k)
	{
		current=current->next;
		count++;
	}
	if(current==NULL)
	{
		return;
	}
	NODE *kthNode=current;
	while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=*pstart;
		*pstart=kthNode->next;
		kthNode->next=NULL;
}



int main()
{
	NODE *start=NULL;
	createlist(&start);
	traverse(start);
		rotate(&start,3);//i.e    Rotating from 3rd position
			traverse(start);
}
