#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
  int info;
  struct node *next;
}NODE;

void push(NODE **ptop,int n)
{
  NODE *new1;
  new1=(NODE*)malloc(sizeof(NODE));
  if(new1==NULL)
  {
    printf("Stack overflow");
    return;
  }
  new1->info=n;
  new1->next=*ptop;
  *ptop=new1;

}

int pop(NODE **ptop)
{
  NODE *node=*ptop;
  if(*ptop==NULL)
  {
    printf("Stack Underflow");
    return;
  }
  int n=node->info;
  (*ptop)=node->next;
  free(node);
  return n;
}

int main()
{

  NODE *top=NULL;
  int choice,n;
  do{
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.EXIT");
    printf("\nEnter your choice 1/2/3... -:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("\nEnter the value you want to push :");
      scanf("%d",&n);
      push(&top,n);
      break;
      case 2:
      n=pop(&top);
      if(n!=-1)
        printf("\n%d",n);
      break;
      case 3:
      printf("Exiting the program");
      break;
      default: printf("\nWrong choice ");
    }
  }while(choice!=3);

}
