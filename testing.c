#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char minimum_occurance(char str[])
{
  int alp[256];
  char res;
  for(int i=0;i<256;i++)
  {
    alp[i]=0;
  }
  int indx;
  for(int i=0;str[i]!='\0';i++)
  {
    indx=(int)str[i];
    alp[indx]++;
  }
  for(int i=0;i<256;i++)
  {
    if(alp[i]==1)
    {

      res=(char)i;

      break;
    }
  }
  return res;
}

int main( )
{
    char str[1000];
    scanf("%[^\n]s",str);
    char res=minimum_occurance(str);
    printf("%c",res);
    return 0;
}
