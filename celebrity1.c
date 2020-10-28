#include<stdio.h>
 int main(){
	 printf("Hello");
    int n,i,j,count,pos;
    printf("\nEnter number of person: ");
    scanf("%d",&n);
    int a[n][n];
    for(i = 0;i < n;i++){
        for(j = 0;j < n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    count = 0;
    for(i = 0;i < n;i++)
	{
        pos = 0;
        for(j = 0;j < n;j++)
		{
            if(a[i][j] == 0)
                count++;
            else
			{
                count = 0;
                break;
            }
        }
        if(count == n)
		{
            pos = i;
            printf("Celebrity Id: %d",pos);
            break;
        }
    }
    return 0;
}
