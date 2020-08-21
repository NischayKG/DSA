#include<stdio.h>
#include<malloc.h>
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
void insert_first(NODE **ps)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	if(new1==NULL)
	{
		printf("Error in createing new node");
		return;
	}
	printf("\nEnter value for new node:");
	scanf("%d",&new1->info);
	new1->prev=NULL;
	new1->next=*ps;
	(*ps)->prev=new1;
	(*ps)=new1;
}
void insert_last(NODE **ps)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	if(new1==NULL)
	{
		printf("Error in createing new node");
		return;
	}
	NODE *node=*ps;
	while(node->next!=NULL)
		node=node->next;
	printf("\nEnter value for new Node:");
	scanf("%d",&new1->info);
	new1->next=NULL;
	new1->prev=node;
	node->next=new1;	
}
void insert_after_value(NODE *s)
{
	NODE *node=s;
	int n;
	printf("\nEnter value after which to insert:");
	scanf("%d",&n);
	while(node->info!=n)
	{
		node=node->next;
		if(node==NULL)
		{
			printf("%d does not exist in the list",n);
			return;
		}
	}
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for new node : ");
	scanf("%d",&new1->info);
	if(node->next!=NULL)
	{
		new1->next=node->next;
		node->next->prev=new1;
		new1->prev=node;
		node->next=new1;
	}
	else
	{
		new1->next=NULL;
		new1->prev=node;
		node->next=new1;
	}	
}
void insert_nodeno(NODE **ps)
{
	NODE *node=*ps;
	int n,i;
	printf("\nEnter node no to insert :");
	scanf("%d",&n);
	for(i=1;i<=n-2;i++)
	{
		node=node->next;
		if(node==NULL)
		{
			printf("Wrong node no");
			return;
		}
	}
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for new Node: ");
	scanf("%d",&new1->info);
	if(n==1)
	{
		new1->prev=NULL;
		(*ps)->prev=new1;
		new1->next=*ps;
		*ps=new1;
	}
	else
	if(node->next==NULL)
	{
		new1->next=NULL;
		new1->prev=node;
		node->next=new1;
	}
	else
	{
		new1->next=node->next;
		node->next->prev=new1;
		new1->prev=node;
		node->next=new1;	
	}
	
}
int main()
{
	NODE *start=NULL;
	create_list(&start);
	traverse(start);
	//insert_first(&start);
	//insert_last(&start);
	//insert_after_value(start);
	insert_nodeno(&start);
	printf("\n");
	traverse(start);
}
