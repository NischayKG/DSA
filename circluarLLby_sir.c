#include<stdio.h>
#include<malloc.h>
typedef struct list
{
	int info;
	struct list *next;
}NODE;
void create_list(NODE **ps)
{
	NODE *new1,*node;
	char ch;
	do{
	new1=(NODE *)malloc(sizeof(NODE));
	printf("Enter value for new node: ");
	scanf("%d",&new1->info);
	if(*ps==NULL)
	{
		*ps=new1;//address of new node will be in start
		new1->next=*ps;
		node=new1;
	}
	else
	{
		node->next=new1;
		node=node->next;
		node->next=*ps;
	}
	printf("\nDo you want to create more node: ");
	fflush(stdin);
	ch=getchar();
	}while(ch=='Y' || ch=='y');
}
void traverse(NODE *start)
{
	NODE *node=start;
	if(node==NULL)
	{
		printf("List is Empty : ");
		return;
	}
	do{
		if(node->next==start)
			printf("%d",node->info);
		else
			printf("%d->",node->info);
		node=node->next;
	}while(node!=start);
}
void insert_first(NODE **ps)
{
	NODE *new1,*node;
	node=*ps;
	new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for new node: ");
	scanf("%d",&new1->info);
	if(node==NULL)
	{
		new1->next=new1;
	}
	else
		if(node->next==*ps)
		{
			new1->next=node;
			node->next=new1;
		}
		else
		{
		do{
		node=node->next;
		}while(node->next!=*ps);
		new1->next=*ps;
		node->next=new1;
	}
	*ps=new1;
}
void insert_last(NODE **ps)
{
	NODE *node=*ps;
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for new Node: ");
	scanf("%d",&new1->info);
	if(node==NULL)
	{
		new1->next=new1;
		*ps=new1;
	}
	else
	{
	do{
		node=node->next;
	}while(node->next!=*ps);
	new1->next=*ps;
	node->next=new1;
	}
}
void insert_value(NODE *s)
{
	NODE *node=s;
	int n;
	printf("\nEnter value after which to insert:");
	scanf("%d",&n);
	while(node->info!=n)
	{
		node=node->next;
		if(node==s)
		{
			printf("%d does not exist",n);
			return;
		}
	}
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for New Node:");
	scanf("%d",&new1->info);
	new1->next=node->next;
	node->next=new1;
}
void delete_value(NODE **ps)
{
	NODE *node=*ps;
	NODE *p;
	int n;
	if(node==NULL)
	{
		printf("\nList is empty");
		return;
	}
	printf("\nEnter value to delete");
	scanf("%d",&n);
	while(node->info!=n)
	{
		p=node;
		node=node->next;
		if(node==*ps)
		{
			printf("%d does not exist",n);
			return;
		}
	}
	if(node==*ps)
	{
		NODE *q=*ps;
		do{
			q=q->next;
		}while(q->next!=*ps);
		q->next=node->next;
		*ps=node->next;
		free(node);
	}
	else
	{
	p->next=node->next;
	free(node);
	}
}
int main()
{
	NODE *start=NULL;
	create_list(&start);
	traverse(start);
	//insert_first(&start);
	//insert_last(&start);
	//insert_value(start);
	delete_value(&start);
	printf("\n");
	traverse(start);
}
