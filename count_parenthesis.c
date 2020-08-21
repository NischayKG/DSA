#include<stdio.h>
#include<string.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void Push(int n)
{
	stack[++top]=n;
}
int Pop()
{
	return stack[top--];
}
int FindMax(char str[])
{
	int n = strlen(str);
	int x,i,result=0;
	Push(-1);
	for (i=0; i<n; i++)
	{
		if (str[i]=='(')
			Push(i);
		else
		{
			Pop();
			if (top!=-1)
			{
				 x=i-stack[top];
				 if(x>result)
					result = x;
			}
			else
				Push(i);
		}
	}
	return result;
}
int main()
{
	char str[100];
	printf("Input String with parenthesis ");
	gets(str); //((()() Ans: 4
	printf("Max Length = %d",FindMax(str));
	return 0;
} 
