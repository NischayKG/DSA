#include<stdio.h>
int stack[10]={0};
int top=-1;
void push(int n)
{
	if(top==9)
	{
		printf("Stack Overflow");
		return;
	}
	stack[++top]=n;
}
int pop()
{
	return stack[top--];
}
int main()
{
	int adj[4][4]={{0,1,0,1},{0,0,1,0},{0,1,0,1},{1,1,1,0}};
    int i,j,s;
    int flag[4]={0};
	s=0;
	for(i=0;i<4;i++)
	{
		flag[s]=1;
		for(j=0;j<4;j++)
		{
			if(adj[s][j]==1)
			{
				if(flag[j]==0)
				{
					flag[j]=1;
					push(j);
				}
			}
		}
		flag[s]=2;
		printf("V%d ",s);
		s=pop();
	}
    
}
