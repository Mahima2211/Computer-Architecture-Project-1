#include<stdio.h>
#include<stdlib.h>

struct Node
 {   
  int num;
  struct Node* next;
 }


int main(int argc, char** argv)
 {

  FILE* f;
  struct Node *htfirst = NULL;
  struct Node **ht[10000];
  char ch;
  int n;
  
  f=fopen(argv[1],"r");

  //to check for correct input
  if(f==NULL)
  {  
   printf("error\n");
   exit(0);
  }

  //filling in the hasntable by running a pointer through it
  
  int i;
  for(i=0;i<10000;i++)
  {
   ht[i] = NULL;
  }
  
  //filling in the hashtable
  while(fscanf(f, "%c %d\n", &ch, &n)==2)
  {
   int hashk;
   if(n>=0)
   {
    hashk = n%10000;
   }
   else
   {
    hashk = -(n%10000);
   }
  

   if(ch=='i')
   {

    if(ht[hashk]==NULL)
    {
     ht[hashk] = insertf(first,n);
    }


    else 
    {
    struct Node *t = ht[hashk];
    ht[hashk] = insert(t,n);
    }
   }
 

  elseif(ch=='s')
  {

   if(ht[hashk]==NULL)
   {
    printf("absent\n");
   }
  
   else
   {
    struct Node *t = ht[hashk];
    int i=0;
    
    
    present(t,n)==0
















return 0;
}


struct Node* insertf(struct Node *first, int n1)
{ 
  if(first==NULL)
  {  
   first =malloc(sizeof(struct Node));
   first->num = n1;
   first->next = NULL;
   printf("inserted\n");
   return first;
  }


  else
  {
   int i=0;
   struct Node *temp = first;

   while(temp!=NULL)
   {
    if(temp->num == n1)
    {
     i=1;
    }
    temp = temp->next;
   }


   if(i==1)
   {  
    printf("duplicate\n");
    return first;
   } 
   
   //node is not a duplicate and has to be inserted
   struct Node *toinsert;
   struct Node *ptr = front; 
   while(temp->next!=NULL)
   {
    temp = temp->next;
   }
   
   toinsert = malloc(sizeof(struct Node));

   toinsert->num = n1;
   temp->next = toinsert;
   toinsert->next = NULL;
   printf("inserted\n");
   return first;
  }
}









 










  

  
