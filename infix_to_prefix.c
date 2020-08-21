#include<stdio.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1;
void push(char x)
{
	if(top==size-1)
	{
		printf("\nStack overflow");
		return;
	}
	stack[++top]=x;
}
char pop()
{
	if(top==-1)
	   return -1;
	else
	   return stack[top--];
}
int priority(char x)
{
	int p=-1;
	switch(x)
	{
		case '+':
		case '-': p=1;
				break;
		case '*':
		case '/':
		case '%':p=2;
		         break;
		case '^':p=3;
	}
	return p;
}
int main()
{
	char infix[size],x,prefix[size];
	char *exp;
	int i=-1;
	printf("Enter an infix expression : ");
	gets(infix);
	exp=strrev(infix);
	while(*exp!='\0')
	{
		if(isalnum(*exp))
		    prefix[++i]=*exp; //printf("%c",*exp);
		else
			if(*exp==')')
			    push(*exp);
			else
			  if(*exp=='(')
			  {
				while((x=pop())!=')')
			  	  prefix[++i]=x; //printf("%c",x);
			  }
			  else
			  {
			  	while(priority(stack[top])>priority(*exp))
			  	     prefix[++i]=pop();//printf("%c",pop());
			  	push(*exp);
			  }
			  exp++;
	}
	while(top!=-1)
	  {
	  	prefix[++i]=pop();//printf("%c",pop());
	  }
	prefix[++i]='\0';
	//printf("\n%s",str1) ;
	printf("\n%s",strrev(prefix));

}
