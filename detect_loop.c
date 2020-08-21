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
 int detect_loop(NODE *list)
 {
	 NODE *p,*q;
	 p=list;
	 q=list;
	 while(p!=NULL&&q!=NULL&&q->next!=NULL)
	 {
		 p=p->next;
		 q=q->next->next;
		 if(p==q)
		 {
			 return;
		 }
	 }
	 return 0;
 }


int main()
{
	NODE *start=NULL;
	createlist(&start);
	traverse(start);
		int flag=detect_loop(start);
		if(flag==1)
		{
			printf("\nLoop exist ");
		}
		else
		{
			printf("\nLoop doesn't exist");
		}
			traverse(start);
}
