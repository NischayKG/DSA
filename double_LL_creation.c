#include<stdio.h>
typedef struct listnode
{
	struct listnode *prev;
	int info;
	struct listnode *next;
}NODE;
void create_list(NODE **start)
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
		(*start)->prev=NULL;
		node=*start;
	}
	else
	{
		node->next=(NODE *)malloc(sizeof(NODE));
		node->next->prev=node;
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
	NODE *p;
	if(node==NULL)
	{
		printf("List is Empty");
		return;
	}
	while(node!=NULL)
	{
		p=node;
		printf("%d->",node->info);
		node=node->next;
	}
	node=p;
	while(node!=NULL)
	{
		printf("%d->",node->info);
		node=node->prev;
	}
}
int main()
{
	NODE *start=NULL;
	create_list(&start);
	traverse(start);
}
