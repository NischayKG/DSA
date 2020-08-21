#include<stdio.h>
#define size 10
void insert(int queue[],int *f,int *r,int n)
{
  if(*r==size-1)
  {
    printf("queue overflow");
    return;
  }
  (*r)++;
  queue[*r]=n;
  if(*f==-1)
  {
    *f=0;

  }

}
int delete(int queue[],int *f,int *r)
{
  int n=0;
  if(*f==-1)
  {
    printf("queue underflow");
    return -1;
  }
  n=queue[*f];
  if(*f==*r)
  {
    *f=*r=-1;
  }
  else
  {
    (*f)=(*f)+1;
  }
  return n;
}

int main()
{
  int queue[size];
  int f=-1;
  int r=-1;
  int n=0,choice=0;
  do{
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.exit");
    printf("Enter choice");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Enter value");
      scanf("%d",&n);
      insert(queue,&f,&r,n);
      break;
      case 2:
      n=delete(queue,&f,&r);
      printf("\n%d is deleted",n);
      break;
      case 3:
      printf("Exiting program...");
      break;
      default :
      printf("Enter right choice and try again");
    }
  }
  while(choice!=3);
}
