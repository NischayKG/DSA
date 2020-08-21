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

remove_dublicate(NODE **start)
{
  int n=1;
  NODE *temp=*start;
  while(temp->next!=NULL)
  {
    n++;
    temp=temp->next;
  }
  int arr[n];
  NODE *ptr=*start;
  int i=0;
  arr[i]=ptr->info;
  while(ptr->next!=NULL)
  {
    i++;
    ptr=ptr->next;
    arr[i]=ptr->info;
  }
  int j;
int l,m,store;
for(l=0;l<n;l++)
{
  store=arr[l];
  for(m=0;m<n;m++)
  {
    if(l==m)
      m++;
    if(arr[m]==arr[l])
      arr[m]++;
  }
}
ptr=*start;
i=0;
ptr->info=arr[i];
while(ptr->next!=NULL)
{
  ptr=ptr->next;
  i++;
  ptr->info=arr[i];
}

}



int main()
{
	NODE *start=NULL;
	createlist(&start);
	traverse(start);
  //remove_dublicate(&start);
  //traverse(start);
	rotate(&start,3);//i.e    Rotating from 3rd position


}
