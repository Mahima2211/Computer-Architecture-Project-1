#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  if(argc<2)
    {
      printf("error\n");
      exit(0);
    }
  int num = atoi(argv[1]);
  int flag = 0;
int i;


  for( i=2;i<=num/2;++i)
    {
      if(num%i==0)
	{
	  flag =1;
	  break;
	}

    }
  if(flag==0)
    {
      printf("yes\n");
    }
  else
    {
      printf("no\n");
    }


  

  return 0;
}
