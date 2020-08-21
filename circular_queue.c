#include<stdio.h>
#define SIZE 10

void insert(int cq[],int *f,int *r,int n)
{
  if((*f)==(*r+1)%SIZE)
  {
    printf("\n Circular queue overflow");
    return;
  }
  if((*r)==-1)
  {
    (*f)=(*r)=0;
  }
  else if((*f)!=0&&(*r)==SIZE-1)
  {
    (*r)=0;
  }
  else
  {
    (*r)++;
  }

  cq[*r]=n;
}

int delete(int cq[],int *f,int *r)
{
  int n;
  if((*f)==-1)
  {
    printf("Circular queue underflow");
    return;
  }
  n=cq[*f];
  if(*f==*r)
  {
    *f=*r=-1;
  }
  else if(*f==SIZE-1)
  {
    *f=0;
  }
  else
  {
    (*f)++;
  }
  return n;
}

void traverse(int cq[],int f,int r)
{
  if(f==-1)
  {
    printf("Circular Queue underflow");
    return;
  }
  if(f<=r)
  {
    for(int i=f;i<=r;i++)
    {
      printf("%d",cq[i]);
    }
  }
  else
  {
    for(int i=f;i<=SIZE-1;i++)
    {
      printf("%d",cq[i]);
    }
    for(int i=0;i<=r;i++)
    {
      printf("%d",cq[i]);
    }
  }
}


int main()
{
  int cq[SIZE];
  int f=-1,r=-1;
  int n,ch;
	do{
		printf("\n*****MENU*****");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. traverse");
		printf("\n4. Exit");
		printf("\n***************");
		printf("\nEnter Your Choice 1/2/3/4 : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter value to insert : ");
					scanf("%d",&n);
					insert(cq,&f,&r,n);
					break;
			case 2: n=delete(cq,&f,&r);
					printf("\n%d deleted",n);
					break;
			case 3: traverse(cq,f,r);
					break;
			case 4: printf("\n\n Thank you");
					break;
			default:printf("\nWrong Choice....");
		}

	}while(ch!=4);
}
