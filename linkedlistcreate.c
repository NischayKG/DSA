#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int info;
	struct Node *next;
}NODE;
NODE * create(NODE *start)
{
	NODE *node=start;
	char ch;
	do{
		if(start==NULL)
		{
			start=(NODE *)malloc(sizeof(NODE));
			node=start;
			printf("\nEnter value for new node : ");
			scanf("%d",&node->info);
			node->next=NULL;
		}
		else
		{
			node->next=(NODE *)malloc(sizeof(NODE));
			node=node->next;
			printf("\nEnter value for new node : ");
			scanf("%d",&node->info);
			node->next=NULL;
		}
		printf("\nDo you want to create more node ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch!='n');
	return start;
}
void traverse(NODE *start)
{
	NODE *node=start;
	if(node==NULL)
	{
		printf("\nList is empty");
		return;
	}
	while(node!=NULL)
	{
		printf("%d ",node->info);
		node=node->next;
	}
}
void insert_first(NODE **pstart)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for new node : ");
	scanf("%d",&new1->info);
	new1->next=*pstart;
	*pstart=new1;
}
void insert_last(NODE *start)
{
	NODE *node,*new1;
	node=start;
	while(node->next!=NULL)
	{
		node=node->next;
	}
	new1=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter value for new Node: ");
	scanf("%d",&new1->info);
	new1->next=NULL;
	node->next=new1;
}
void insert_after_value(NODE *node,int n)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	while(node!=NULL && node->info!=n )
	{
		node=node->next;
	}
	if(node==NULL)
	  printf("\n%d does not exist",n);
	else
	{
		printf("\nEnter value for new node : ");
		scanf("%d",&new1->info);
		new1->next=node->next;
		node->next=new1;
	}
}
void insert_node(NODE *node,int n)
{
	NODE *new1;
	int i;
	if(n==1)
	    {
		printf("Please insert as first node ");
		return;
	}
	new1=(NODE *)malloc(sizeof(NODE));
	
	for(i=1;node!=NULL && i<=n-2;i++)
	    node=node->next;
	if(node==NULL)
	   printf("Wrong Input");
	else
	{
	printf("\Enter value for new node : ");
	scanf("%d",&new1->info);	
	new1->next=node->next;
	node->next=new1;  
	}
}
NODE * delete_first(NODE *node)
{
	NODE *p;
	if(node==NULL)
	{
		printf("\nList is empty");
		return;
	}
	p=node;
	node=p->next;
	free(p);
	return node;
}
void delete_last(NODE *node)
{
	NODE *p;
	if(node==NULL)
	{
		printf("List is empty");
		return;
	}
	while(node->next->next!=NULL)
	{
	    node=node->next;	
	}
	p=node->next;
	node->next=NULL;
	free(p);	
}
NODE * delete_value(NODE *start,int n)
{
	NODE *p,*q;
	if(start==NULL)
	{
		printf("List is empty");
		return start;
	}
	p=start;
	if(p->info==n)
	{
		start=p->next;
		free(p);
	}
	else
	{
		q=p->next;
		while(q!=NULL && q->info!=n)
		{
			p=q;
			q=q->next;
		}
		if(q==NULL)
		{
			printf("%d does nor exist :",n);
			return start;
		}
		else
		{
			p->next=q->next;
			free(q);
		}
	}
	return start;
}
NODE * delete_node(NODE *start,int n)
{
	NODE *p,*q;
	int i;
	p=start;
	if(p==NULL)
	{
		printf("\nList is empty");
		return;
	}
	if(n==1)
	{
		start=p->next;
		free(p);
		return start;
	}
	q=p->next;
	for(i=1;q!=NULL && i<=n-2;i++)
	{
		p=q;
		q=q->next;
	}
	if(q==NULL)
	{
		printf("\nWrong node number");
		return start;
	}
	p->next=q->next;
	free(q);
	return start;
}
NODE * delete_list(NODE *start)
{
    NODE *temp;
    if(start==NULL)
    {
    	printf("List is empty");
    	return start;
	}
    while(start != NULL)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
    printf("\nLinked List Deleted successfully ");
    return start;
}
int main()
{
    NODE *start=NULL;
    int n;
	start=create(start);
	printf("\nList after creation : ");
	traverse(start);
	//insert_first(&start);
	//insert_last(start);
	//printf("\nEnter node number : ");
	//scanf("%d",&n);
	//insert_node(start,n);
	//insert_after_value(start,n);
	//start=delete_first(start);
	//delete_last(start);
	//printf("\nEnter node number to delete : ");
	//scanf("%d",&n);
	//start=delete_node(start,n);
	start=delete_list(start);
	printf("\nList after Deletion : ");
	traverse(start);
}








