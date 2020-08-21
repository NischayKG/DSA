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

void delete_all(NODE **pstart)
{
	NODE *temp;
	if(*pstart==NULL)
	{
		printf("\nThe list is empty ");
		return;
	}
	while(*pstart!=NULL)
	{
		temp=*pstart;
		*pstart=(*pstart)->next;
		free(temp);
	}
	printf("\nThe list is empty now\n");

}

void reverse_list(NODE **ps)
{
	NODE *p,*q,*r;
	p=*ps;
	q=r=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=r;
		r=p;
		p=q;
	}
	*ps=r;
}
int main()
{
	NODE *start=NULL;
	createlist(&start);
	traverse(start);
//	delete_all(&start);
//	traverse(start);
printf("\n");
	reverse_list(&start);
	traverse(start);

}
