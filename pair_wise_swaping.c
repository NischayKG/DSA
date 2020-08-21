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
void pairwiseswaping(NODE *list)
{
	int n;
	NODE *temp=list;
	while(temp!=NULL&&temp->next!=NULL)
	{
		n=temp->info;
		temp->info=temp->next->info;
		temp->next->info=n;
		temp=temp->next->next;
	}
}

int main()
{
	NODE *start=NULL;
	createlist(&start);
	traverse(start);
		pairwiseswaping(&start);

			traverse(start);
}
