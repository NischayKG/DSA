#include<stdio.h>
#include<string.h>
#define size 100
int is[size];
char cs[size];
int itop=-1,ctop=-1;
void ipush(int n)
{
	is[++itop]=n;
}
void cpush(char ch)
{
	cs[++ctop]=ch;
}
int ipop()
{
	return is[itop--];
}
char cpop()
{
	return cs[ctop--];
}
void decode(char str[])
{
	char temp[size],result[size],ch;
	int i,j,count;
	for (i=0;str[i]!='\0';i++)
	{
		count = 0;
		if (isdigit(str[i]))
		{
			count=str[i]-48;
			ipush(count);
		}
		else if (str[i] == ']')
		{
			count = ipop();
			strcpy(temp,"");
			j=0;
			while ((ch=cpop())!='[' )
			{
				temp[j++] = ch;
			}
			temp[j]='\0';
			strrev(temp);
			for (j = 0; j < count; j++)
				strcat(result,temp);
			for (j= 0; result[j]!='\0'; j++)
				cpush(result[j]);
			strcpy(result,"");
		}
		else if (str[i] == '[')
		{
			if (isdigit(str[i-1]))
				cpush(str[i]);
			else
			{
				cpush(str[i]);
				ipush(1);
			}
		}

		else
			cpush(str[i]);
	}
    j=0;
	while (ctop!=-1)
	{
		result[j++] =cpop();
	}
	result[j]='\0';
	printf("\n%s",strrev(result));
}

int main()
{
	char str[100];
	printf("Enter a String "); //"2[a2[b3[c]]]";
	gets(str);
	decode(str);
	return 0;
} 
