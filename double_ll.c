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
  NODE *new1=(NODE*)malloc(sizeof(NODE));
  if(new1==NULL)
  {
    printf("Error in creating new node");
    return;
  }
  printf("\nEnter the value of new 1st node -:");
  scanf("%d",&new1->info);
  new1->prev=NULL;
  new1->next=*ps;
  (*ps)->prev=new1;
  (*ps)=new1;
}
void insert_last(NODE **ps)
{
  NODE *new1=(NODE*)malloc(sizeof(NODE));
  if(new1==NULL)
  {
    printf("Error in creating new node");
    return;
  }
  NODE *node=*ps;
  while(node->next!=NULL)
    {node=node->next;}
  printf("\nEnter the value of new last node -:");
  scanf("%d",&new1->info);
  new1->next=NULL;
  new1->prev=node;
  node->next=new1;
}
void insert_after_value(NODE *s)
{
  NODE *node;
  int n;
  printf("\nEnter the value after which you want to insert");
  scanf("%d",&n);
  while(node->info!=n)
  {
    node=node->next;
    if(node==NULL)
    {
      printf("%d doesn't exist in list",n);
      return;
    }
  }
  NODE *new1=(NODE*)malloc(sizeof(NODE));
  printf("\nEnter the value of new  node -:");
  scanf("%d",&new1->info);
  if(node->next!=NULL)
  {
  scanf("%d",&new1->info);
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

void insert_after_node(NODE **ps)
{
  NODE *node=*ps;
  int n,i;
  printf("\nEnter the number at which you want to insert");
  scanf("%d",&n);
  for(i=1;i<n-1;i++)
  {
    node=node->next;
    if(node==NULL);
    {
      printf("wrong node number");
      return;
    }
  }
  NODE *new1=(NODE*)malloc(sizeof(NODE));
  printf("\nEnter the value of new  node -:");
  scanf("%d",&new1->info);
  if(n==1)
  {
    new1->prev=NULL;
    (*ps)->prev=new1;
    new1->next=(*ps);
    (*ps)=new1;
  }
  else if(node->next==NULL)
  {
    new1->next=NULL;
    new1->prev=node;
    node->next=new1;
  }
  else
  {
    new1->next=node->next;
    node->next->prev=new1;
    node->next=new1;
    new1->prev=node;
  }
}
void delete_first(NODE **ps)
{
	printf("\nAfter deleting the 1st node -:\n ");
	NODE *node=*ps;
	if(node==NULL)
	{
		printf("List is empty");
		return;
	}
	if(node->next=NULL)
	{
		*ps=NULL;
	}
	else{
	(*ps)=(*ps)->next;
	(*ps)->prev=NULL;
	free(node);}
}
void delete_end(NODE **ps)
{
 printf("\nAfter deleting the last node -:\n ");
	NODE *node=(*ps);
	if(node==NULL)
	{
		printf("List is empty");
		return;
	}
	while(node->next!=NULL)
		{node=node->next;}
	if(node==*ps)
	{
		*ps=NULL;
	}
	else
	{
		NODE *hold;
		hold=node;
		node=node->prev;
		hold->prev=NULL;
		node->next=NULL;
		free(hold);
	 }
}
void delete_value(NODE **ps)
{
	int n;
	NODE *node=*ps;
	if(node==NULL)
	{
		printf("List is empty");
		return;
	}
	printf("\n Enter the value to delete");
	scanf("%d",&n);
	while(node->info!=n)
	{
		node=node->next;
		if(node==NULL)
		{
			printf("%d is not in the list",n);
			return;
		}
	}
	if(node==*ps)
	{
		if(node->next!=NULL)
				node->next->prev=NULL;
		*ps=node->next;

	}
	else if(node->next==NULL)
		{
			node->prev->next=NULL;
		}
	else
		{
			node->prev->next=node->next;
			node->next->prev=node->prev;

		}
			free(node);
	}

void delete_nodeno(NODE **ps)
{
	int n,i;
	NODE *node=*ps;
	if(node==NULL)
	{
		printf("List is empty");
		return;
	}
	printf("\n Enter the no. of node you wan'a delete -:");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		node=node->next;
		if(node==NULL)
		{
			printf("node no. %d  doesn't exist\n",n);
			return;
		}
	}

	if(node==*ps)
	{
		if(node->next!=NULL)
				node->next->prev=NULL;
		*ps=node->next;
	}
	else if(node->next==NULL)
		{
			node->prev->next=NULL;
		}
	else
		{
			node->prev->next=node->next;
			node->next->prev=node->prev;

		}
			free(node);
}
int main()
{
	NODE *start=NULL;
	create_list(&start);
	traverse(start);
//  insert_first(&start);
//  traverse(start);
//  insert_last(&start);
//  traverse(start);
//  insert_after_value(start);
//  traverse(start);
//  insert_after_node(&start);
//  traverse(start);
//  delete_first(&start);
//	traverse(start);
//	delete_end(&start);
//	traverse(start);
//		delete_value(&start);
//		traverse(start);
			delete_nodeno(&start);
			traverse(start);
}
