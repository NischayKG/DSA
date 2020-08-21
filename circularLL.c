#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct List{
  int info;
  struct list *next;

}NODE;

void create_list(NODE **ps)
{
  NODE *new1;
  NODE *node;
  char ch;
  do{
    new1=(NODE*)malloc(sizeof(NODE));
    printf("Enter the for new node-:");
    scanf("%d",&new1->info);
    if((*ps)==NULL)
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
    printf("Do you want to create more node? ");
    fflush(stdin);
    ch=getchar();
  }while(ch=='y'||ch=='Y');
}

void traverse(NODE *start)
{
  printf("\n");
  NODE *node=start;
  if(node==NULL)
  {
    printf("\nList is Empty");
    return;
  }
  do {
    printf("%d->",node->info);
    node=node->next;
  } while(node!=start);
}
 void insert_first(NODE **ps)
 {
   NODE *new1,*node;
   node=*ps;
   new1=(NODE*)malloc(sizeof(NODE));
   printf("Enter the for new node-:");
   scanf("%d",&new1->info);
   if(node==NULL)
   {
     new1->next=new1;
     *ps=new1;
   }
   else if(node->next==*ps)
   {
     new1->next=node;
     node->next=new1;
    *ps=new1;
   }
   else{
   do
   {
     node=node->next;
   }while(node->next!=*ps);
     new1->next=*ps;
     node->next=new1;
     *ps=new1;
  }
 }

 void insert_last(NODE **ps)
 {
   NODE *new1,*node;
   node=*ps;
   new1=(NODE*)malloc(sizeof(NODE));
   printf("\nEnter the for new node-:");
   scanf("%d",&new1->info);
   if(node==NULL)
   {
     new1->next=new1;
     *ps=new1;
   }
   else if(node->next==*ps)
   {
     node->next=new1;
     new1->next=*ps;
   }
   else{
   do
   {
    node=node->next;
   }while(node->next!=*ps);
   node->next=new1;
   new1->next=*ps;
    }
  }

  void insert_value(NODE *s)
  {
    NODE *node=s;
    int n;
    printf("\nEnter the value after which you want to insert");
    scanf("%d",&n);
    while(node->info!=n)
      {
        node=node->next;
        if(node==s)
        {
          printf("%d doesnt exist",n);
          return;
        }
      }
      NODE *new1=(NODE*)malloc(sizeof(NODE));
      printf("\nEnter the value of new node");
      scanf("%d",&new1->info);
      new1->next=node->next;
      node->next=new1;

  }
  void delete_value(NODE **ps)
  {
    NODE *p,*node=*ps;
    if(node==NULL)
    {
      printf("\nList is empty");
      return;
    }
    int n;
    printf("\nEnter the value you want to delete :");
    scanf("%d",&n);
    while(node->info!=n)
    {
      p=node;
      node=node->next;
      if(node->next==*ps)
      {
        printf("\n%d Value does not exist",n);
        return;
      }
    }
    if(node==*ps)
    {
      NODE *q=*ps;
      do{
        q=q->next;
      }
      while(q->next!=*ps);
      q->next=node->next;
      *ps=node->next;
      free(node);
      return;
    }
    p->next=node->next;
    free(node);

  }
/*  void insert_aftervalue(NODE *ps)
  { int n;
    NODE *new1,*node;
    node=*ps;
    new1=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter the for new node-:");
    scanf("%d",&new1->info);
    printf("\nEnter the value after which you want to insert :");
    scanf("%d",&n);
    if(node==NULL)
    {
      printf("List is empty");
      new1->next=new1;
      *ps=new1;
    }
    else{
     do{
      node=node->next;}
      while(node->next!=n&&node!=*ps);
      node->next=new1;
    new1->next=*ps;
  }

}*/
int main()
{
  NODE *start=NULL;
  create_list(&start);
  traverse(start);
  //insert_first(&start);
  //traverse(start);
  //insert_last(&start);
  //traverse(start);
  //insert_aftervalue(&start);// by me...
  //traverse(start);          //by me...have some error
  //  insert_value(start);
  //  traverse(start);
    delete_value(&start);
    traverse(start);

}
