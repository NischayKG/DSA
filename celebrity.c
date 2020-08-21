#include<stdio.h>
int stack[100];
int top=-1;
void Push(int n)
{
	stack[++top]=n;
}
int Pop()
{
	return stack[top--];
}
 
int main() 
{ 
	int i,j,n,A,B,C;
	printf("Enter no of Person: ");
	scanf("%d",&n);
	int M[n][n];
	for(i = 0;i < n;i++)
        for(j = 0;j < n;j++)
            scanf("%d",&M[i][j]);
/*	M[4][4] = { {0, 0, 1, 0}, 
				{0, 0, 1, 0}, 
				{0, 0, 0, 0}, 
				{0, 0, 1, 0}};*/
	for(i = 0; i < n; i++) 
		Push(i); 
	A=Pop(); 
	B=Pop(); 
	while (top > 1) 
	{ 
		if (M[A][B]==1) 
		{ 
			A = Pop(); 
		} 
		else
		{ 
			B = Pop(); 
		} 
	} 
	// Potential candidate? 
	C = Pop(); 
	
	if (M[C][B]==1) 
		C = B; 

	if (M[C][A]==1) 
		C = A; 
	for (i = 0; i < n; i++) 
	{ 
		if ( (i != C) && (M[C][i]==1 || M[i][C]==0))  
			C=-1; 
	} 
	if(C==-1)
		printf("\nNo Celebrity");
	else
		printf("\nCelebrity Id : %d",C);
	return 0; 
} 

