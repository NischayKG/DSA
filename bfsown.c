#include<stdio.h>
int queue[10]={0};
int front=-1,rear=-1;
void insert(int n)
{
	if(rear==9)
	{
		printf("Queue Overflow");
		return;
	}
	if(front==-1)
	    front=0;
	queue[++rear]=n;
}
int delete()
{
	int n=queue[front];
	if(front==rear)
	     front=rear=-1;
	else
	    front=front+1;
	return n;
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
					insert(j);
				}
			}
		}
		flag[s]=2;
		printf("V%d ",s);
		s=delete();
		
	}
    
}
