#include<stdio.h>
#include<stdlib.h>


int main( int argc, char** argv)
{

int ptr;

if(argc<2)
{
printf("error\n");
exit(0);
}

for(ptr= 1; ptr<argc; ptr++)
{

char *ch = argv[ptr]; 

  //so basically extracting words and then finding the last letter by incrementing the pointer

int temp =0;

while(*(ch+temp)!='\0')
{
temp = temp+1;
}

printf("%c",ch[temp-1]);
}


printf("\n");




return 0;
}
