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
void insert_first(NODE **start)
{
	NODE *new1=(NODE *)malloc(sizeof(NODE));
	if(new1==NULL)
	{
		printf("Error in creating");
//	return 0;
	}
	printf("\nEnter the data in new node ");
	scanf("%d",&new1->info);
	new1->next=*start;
	*start=new1;
}
void insert_end(NODE **start)
{
	NODE *ptr=*start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	NODE *new1=(NODE*)malloc(sizeof(NODE));
	printf("\nEnter the data in new node ");
	scanf("%d",&new1->info);
	ptr->next=new1;
	new1->next=NULL;
}
insert_position(NODE **start)
{
	int n;
	printf("Enter the position in which you want to enter the node");
	scanf("%d",&n);
	NODE *new1=(NODE*)malloc(sizeof(NODE));
	printf("\nEnter the data in new node");
	scanf("%d",&new1->info);
	NODE *ptr=*start,*gtr=*start;
	int count=1;
	for(;count<n-1&&ptr->next!=NULL;count++)
	{
		ptr=ptr->next;
		gtr=gtr->next;
	}
	gtr=gtr->next;
	new1->next=gtr;
	ptr->next=new1;
}
delete_first(NODE **start)
{
	NODE *temp=*start;
	printf("\nThe deleting node is %d ",temp->info);
	(*start)=(*start)->next;
	free(temp);
}

delete_end(NODE **start)
{
	NODE *ptr=*start;
	NODE *ptr2;
	while(ptr->next!=NULL)
	{
		ptr2=ptr;
		ptr=ptr->next;
	}
	printf("\nThe deleting node is %d ",ptr->info);
	ptr2->next=NULL;
	free(ptr);
}

delete_position(NODE **start)
{
	printf("\nEnter the position which you want to delete ");
	int n;
	scanf("%d",&n);
	int i=1;
	NODE *hold=*start,*forw=*start;
	while(i<n&&hold->next!=NULL)
	{
		hold=hold->next;
		i++;
		forw=hold;
	}
	forw=forw->next;
	NODE *prev=*start;
	while(prev->next!=hold)
	{
		prev=prev->next;
	}
	prev->next=forw;
	free(hold);
}
reverse_list(NODE **start)
{
	NODE *cur=*start;
	NODE *bur=(*start)->next;
	NODE *mur=(*start)->next->next;
//	printf("\n%d ",cur->info);
	//printf("%d ",bur->info);
	//printf("%d \n",mur->info);
	int count=1;
	while(mur->next!=NULL)
	{
		bur->next=cur;
		if(count)
		{cur->next=NULL;
			count--;}
		cur=bur;
		bur=mur;
		mur=mur->next;
	}
	mur->next=bur;
	(*start)=mur;
}

void reverse(NODE **start)
{
    NODE* prev = NULL;
   NODE* current = *start;
  NODE* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *start = prev;
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

int main()
{
	NODE *start=NULL;
	createlist(&start);
	traverse(start);
/*	insert_first(&start);
	printf("\n");
	traverse(start);
	insert_end(&start);
	traverse(start);
	insert_position(&start);
	traverse(start);

	delete_first(&start);
	traverse(start);
	delete_end(&start);
	traverse(start);
	delete_position(&start);
	traverse(start);*/
//	reverse_list(&start); //need to improve this function
//	traverse(start);
  printf("\n");
	reverse(&start);
	traverse(start);
	delete_all(&start);
	traverse(start);


}
