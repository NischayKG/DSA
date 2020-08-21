#include<stdio.h>
#include<string.h>
void printpattern(char str[],int index)
{
  if(index==strlen(str))
  {
    printf("\n%s",str);
    return; //if end the return after printing...
  }

  else if(str[index]=='?')
  {
    str[index]='0';
    printpattern(str,index+1);
    str[index]='1';
    printpattern(str,index+1);
    str[index]='?';  //to get all posible solution, that's why it is placed ? again

  }
  else
  printpattern(str,index+1);

}


int main()
{
  char str[100];
  printf("Enter the Binary string with ? = ");
  gets(str);
  printpattern(str,0); // 0 to check 1st character...
}
