#include<stdio.h>
int main()
{
  int line,row,column;
  scanf("%d",&line);
  for(row=0;row<line;row++)
  {
    for(column=0;column<line;cloumn++)
    {
      if(row==0||row==line-1||column==0||column==line-1)
      {
        printf("1");
      }
    }
    printf("\n");
  }
}
