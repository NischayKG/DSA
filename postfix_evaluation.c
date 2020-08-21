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
        char exp[size];
        int i;
        int A,B,C,num;
        printf("Enter the expression : ");
        scanf("%s",exp);
        for(i=0;exp[i]!='\0';i++)
        {
                if(isdigit(exp[i]))
                {
                        num = exp[i] - 48;
                        push(num);
                }
                else
                {
                        A = pop();
                        B = pop();
                        switch(exp[i])
                        {
                                case '+':

                                        C = B + A;
                   						 break;

                                case '-':

                                        C = B - A;
                                        break;

                                case '*':

                                        C = B * A;
                                        break;

                                case '/':

                                        C = B / A;
                                        break;

                                case '^':
                                	   C=pow(B,A);
                                	   break;
                        }
                        push(C);
                }

        }
        printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
        return 0;

}
