#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
  FILE *f;
  int r1, r2, c1,c2;
  

  //checking if the command line argument is enteres & valid
  
  if(argc<2)
  {
   printf("error/n");
   exit(0);
  }

  f = fopen(argv[1], "r");



  if(f==NULL)
  {
   printf("error\n");
   exit(0);
  }

//USING THE FIRST METHOD OF ALLOCATING SPACE FOR MATRICES!!!!
  
  fscanf(f,"%d %d",&r1, &c1);

  int res1[100][100];
  int res2[100][100];
  int prod[100][100];
   
  int i,j;

  for(i=0;i<r1;i++)
  {
   for(j=0;j<c1;j++)
   {
    fscanf(f,"%d", &res1[i][j]);
   }
   fscanf(f,"\n");
  }

//copying out the second matrix in the next res
  fscanf(f, "%d %d", &r2,&c2);

  for(i=0;i<r2;i++)
  {
   for(j=0;j<c2;j++)
   {   
    fscanf(f, "%d", &res2[i][j]);
   }
    fscanf(f, "\n");
  }

 int k,x;
//resulting product matrix 

  for(i=0;i<r1;i++)
  {
   for(j=0;j<c2;j++)
   {  
    for(k=0;k<r2;k++)
    {
     x = x + res1[i][k]*res2[k][j];
    } 
    prod[i][j] = x;
    x=0;
   }
  }

 
 for(i=0;i<r1;i++)
 {
  for(j=0;j<c2;j++)
  {
   printf("%d\t", prod[i][j]);
   }
   printf("\n");
} 

return 0;
}







