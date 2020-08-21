#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct poly
{
  int coef;
  int exp;
  struct poly *next;
}NODE;

void createpoly(NODE **ps)
{
  NODE *node,*new1;
  char ch;
  do
  {
    new1=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter coefficient :");
    scanf("%d",&new1->coef);
    printf("\nEnter exponent :");
    scanf("%d",&new1->exp);
    new1->next=NULL;
    if(*ps==NULL)
    {
      *ps=new1;
      node=*ps;
    }
    else
    {
      node->next=new1;
      node=node->next;
    }
    printf("\nDo you want to create more node :");
    fflush(stdin);
    ch=getchar();
  }while(ch=='y'||ch=='Y');
}
void addpoly(NODE *s1,NODE *s2,NODE **ps3)
{
  NODE *new1,*node;
  while(s1!=NULL&&s2!=NULL)
  {
    new1=(NODE*)malloc(sizeof(NODE));
    new1->next=NULL;
    if(s1->exp==s2->exp)
    {
      new1->coef=s1->coef+s2->coef;
      new1->exp=s1->exp;
      s1=s1->next;
      s2=s2->next;
    }
    else{
       if(s1->exp>s2->exp)
       {
      new1->coef=s1->coef;
      new1->exp=s1->exp;
      s1=s1->next;
      }
      else
      {
      new1->coef=s2->coef;
      new1->exp=s2->exp;
      s2=s2->next;
      }
    }

    if(*ps3==NULL)
    {
      *ps3=new1;
      node=*ps3;
    }
    else
    {
      node->next=new1;
      node=node->next;
    }
  }
  while(s1!=NULL)
  {
    new1=(NODE*)malloc(sizeof(NODE));
    new1->next=NULL;
    new1->coef=s1->coef;
    new1->exp=s1->exp;
    if(*ps3==NULL)
    {
      *ps3==new1;
      node=*ps3;
    }
    else
    {
      node->next=new1;
      node=node->next;
    }

  }
  while(s2!=NULL)
  {
    new1=(NODE*)malloc(sizeof(NODE));
    new1->next=NULL;
    new1->coef=s2->coef;
    new1->exp=s2->exp;
    if(*ps3==NULL)
    {
      *ps3==new1;
      node=*ps3;
    }
    else
    {
      node->next=new1;
      node=node->next;
    }
  }
}

void display(NODE *s)
{
  if(s==NULL)
  {
    printf("\nList is Empty");
    return;
  }
  else
  {
    while(s!=NULL)
    {
      if(s->next==NULL)
        printf("%dx^%d",s->coef,s->exp);
      else
        printf("%dx^%d+",s->coef,s->exp);
      s=s->next;
    }
  }
}
int main()
{
  NODE *s1=NULL;
  NODE *s2=NULL;
  NODE *s3=NULL;
  printf("\nCreating first polynomial :");
  createpoly(&s1);
  printf("\nCreating second polynomial :");
  createpoly(&s2);
//  addpoly(s1,s2,&s3);

  printf("\n");
  display(s1);
  printf("\n");
  display(s2);
  printf("\n");
  display(s3);
}
