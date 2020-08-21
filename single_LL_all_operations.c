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
void delete_first(NODE **pstart)
{
	NODE *node=*pstart;
	if(node==NULL)
	{
		printf("List is Empty");
		return;
	}
	*pstart=node->next;
	free(node);
}
void delete_last(NODE **pstart)
{
	NODE *node=*pstart;
	NODE *p=*pstart;
	if(node==NULL)
	{
		printf("List is empty");
		return;
	}
	while(node->next!=NULL)
	{
		p=node;
		node=node->next;
	}
	p->next=NULL;
	free(node);
}
void delete_nodeno(NODE **pstart)
{
	NODE *node=*pstart;
	NODE *p=*pstart;
	if(node==NULL)
	{
		printf("List is Empty");
		return;
	}
	int i,n;
	printf("Enter node no to delete ");
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
		{
			p=node;
			node=node->next;
			if(node==NULL)
			{
				printf("Enter a valid node number");
				return;
			}
		}
		if(p==*pstart)
			*pstart=node->next;
		else
			p->next=node->next;
		free(node);
}
void delete_value(NODE **pstart)
{
	NODE *node=*pstart;
	NODE *p=*pstart;
	if(node==NULL)
	{
		printf("List is Empty");
		return;
	}
	int n;
	printf("\nEnter value to delete : ");
	scanf("%d",&n);
	while(node->info!=n)
	{
		p=node;
		node=node->next;
		if(node==NULL)
		{
			printf("%d does not exist",n);
			return;
		}
	}
	if(p==*pstart)
		*pstart=node->next;
	else
		 p->next=node->next;
	free(node);
}
void print_reverse(NODE *list)
{
	if(list==NULL)
		return;
	print_reverse(list->next);
	printf("%d ",list->info);
}
void ReplaceDuplicates(NODE *node)
{
    int A[100]={0};
    NODE *temp =node;
    int max = 0;
    while (temp!=NULL)
	{
        A[temp->info]++;
        if (max < temp->info)
            max = temp->info;
        temp = temp->next;
    }

    while (node!=NULL)
	{
        if (A[node->info] > 1)
           	A[node->info] = -1;
        else
			if (A[node->info] == -1)
            		node->info = ++max;
        node = node->next;
    }
}
void delete_list(NODE **pstart)
{
    NODE *temp;
    if(*pstart==NULL)
    {
    	printf("List is empty");
    	return;
	}
    while(*pstart != NULL)
    {
        temp = *pstart;
        *pstart = (*pstart)->next;
        free(temp);
    }
    printf("\nLinked List Deleted successfully ");
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
void pairwiseswap(NODE *list)
{
	int n;
	NODE *temp=list;
	while(temp!=NULL && temp->next!=NULL)
	{
	    n=temp->info;
		temp->info=temp->next->info;
		temp->next->info=n;
		temp=temp->next->next;
	}
}
void rotate(NODE **pstart, int k)
{
    if (k == 0)
       return;
    NODE *current = *pstart;
    int count = 1;
    while (current != NULL && count < k)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;
    NODE *kthNode = current;
    while (current->next != NULL)
        current = current->next;
  	current->next = *pstart;
    *pstart= kthNode->next;
    kthNode->next = NULL;
}
int detect_loop(NODE *list)
{
	NODE *p,*q;
	p=list;
	q=list;
	while(p!=NULL && q!=NULL && q->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
		if(p==q)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	NODE *start=NULL;
	createlist(&start);
	traverse(start);
	//insert_first(&start);
	//insert_last(start);
	//insert_any(&start);
	//insert_aftervalue(start);
	//delete_first(&start);
	//delete_last(&start);
	//delete_nodeno(&start);
	//delete_value(&start);
	//ReplaceDuplicates(start);
	//delete_list(&start);
	//reverse_list(&start);
	//rotate(&start,3);
	printf("\n");
	int flag=detect_loop(start);
	if(flag==1)
		printf("Loop Exist");
	else
		printf("Loop not Exist");
	//traverse(start);
	//print_reverse(start);
}
