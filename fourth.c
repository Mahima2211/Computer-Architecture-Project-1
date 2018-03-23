#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv)

{

  FILE *f;
  int rows, cols;
  
  

if(argc<2)
{
printf("error\n");
exit(0);
}

f = fopen(argv[1],"r");

//checking if the file entered is valid and exists
if(f==NULL)
{
 printf("error\n");
 exit(0);
}

fscanf(f,"%d %d",&rows, &cols);


if(rows==0 || cols==0)
{
 printf("Error\n");
 exit(0);
}

int res[100][100];

int c,i,j;


for(i=0;i<rows;i++)
 {
  for(j=0;j<cols;j++)
   {  
    fscanf(f,"%d", &res[i][j]);
   }
  fscanf(f, "\n");
}

for(i=0;i<rows;i++)
{  
 for(j=0;j<cols;j++)
  {
   
      fscanf(f, "%d", &c);
      c= (int) c + res[i][j];
      res[i][j] = c;
    }
    fscanf(f, "\n");
  }

//to print out the final matrix which is seperated by a tab

 for(i=0;i<rows;i++)
 {  
  for(j=0;j<cols;j++)
  {
   printf("%d\t", res[i][j]);
  }
  printf("\n");
}
 
  
  return 0;
}

