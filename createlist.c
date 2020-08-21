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
	while(node!=NULL)
	{
		printf("%d->",node->info);
		node=node->next;
	}
}
void insert_first(NODE **pstart)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	if(new1==NULL)
	{
		printf("Error in creating new node");
		return;
	}
	printf("Enter value for new node : ");
	scanf("%d",&new1->info);
	new1->next=*pstart;
	*pstart=new1;
}
void insert_last(NODE *start)
{
	NODE *node=start;
	while(node->next!=NULL)
		node=node->next;
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	if(new1==NULL)
	{
		printf("Error in creating new node");
		return;
	}
	printf("\nEnter value for New Node : ");
	scanf("%d",&new1->info);
	new1->next=NULL;
	node->next=new1;
}
void insert_any(NODE **start)
{
	int n,i;
	printf("Enter node no to insert :");
	scanf("%d",&n);
	NODE *node=*start;
	for(i=1;i<=n-2;i++)
		node=node->next;
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for new Node : ");
	scanf("%d",&new1->info);
	new1->next=node->next;
	node->next=new1;
	
}
void insert_aftervalue(NODE *start)
{
	int n;
	printf("\nEnter value after which to insert :");
	scanf("%d",&n);
	NODE *node=start;
	while(node->info!=n)
	{
		node=node->next;
		if(node==NULL)
		{
			printf("\n%d does not",n);
			return;
		}
	}
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for new Node : ");
	scanf("%d",&new1->info);
	new1->next=node->next;
	node->next=new1;

}
int main()
{
	NODE *start=NULL;
	createlist(&start);
	traverse(start);
	//insert_first(&start);
	//insert_last(start);
	//insert_any(&start);
	insert_aftervalue(start);
	printf("\n");
	traverse(start);
}
