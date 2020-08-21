#include<stdio.h>
#include<math.h>
#define size 100
int stack[size];
int top = -1;
void push(int x)
{
        if(top==size-1)
         {
			printf("\nStack Overflow");
			return;
		 }
		stack[++top] = x;
}

int pop()
{
       if(top==-1)
         {
         	printf("\nStack Underflow");
         	return 0;
		 }
	    return stack[top--];
}
int main()
{
	char exp[100];
	int A,B,C,n;
	int i;
	printf("Enter prefix expression: ");
	gets(exp);
	strrev(exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(isdigit(exp[i]))
		{
			n=exp[i]-48;
			push(n);
		}
		else
		{
			A=pop();
			B=pop();
			switch(exp[i])
			{
				case '+':C=A+B;
					    break;
				case '-':C=A-B;
						break;
				case '*':C=A*B;
						break;
				case '/':C=A/B;
						break;
				case '^':C=pow(A,B);
						break;
			}
			push(C);
		}
	}
	printf("\nResult=%d",pop());
}
