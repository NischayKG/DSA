//A logical concept in Data Structure...

#include<stdio.h>

void push(int stack[],int *top,int size,int value)
{
  if(*top==size-1)
  {
    printf("Stack overflow");
    return;
  }
  (*top)++;
  stack[*top]=value;
}

int pop(int stack[],int *top,int size)
{
  if(*top==-1)
  {
    printf("Stack underflow");
    return 0;
  }
  int n=stack[*top];
  (*top)--;
  return n;
}

int main()
{
  int top=-1;
  int size;
  printf("Entder stack size");
  scanf("%d",&size);
  int stack[size];
  push(stack,&top,size,5);
  push(stack,&top,size,7);
  push(stack,&top,size,9);
  printf("%d ",pop(stack,&top,size));
  printf("%d ",pop(stack,&top,size));
  printf("%d ",pop(stack,&top,size));
  printf("%d ",pop(stack,&top,size));

}
