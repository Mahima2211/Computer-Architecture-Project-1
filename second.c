#include<stdio.h>
#include<stdlib.h>



struct Node
{  
   int num;
   struct Node *next;

};
struct Node* insertNode(struct Node* first, int x);
 
struct Node* deleteNode(struct Node* first, int x);

int main(int argc, char** argv)
{
  FILE* f;
  char ch;
  int x;
  struct Node *first=NULL;
  
  if(argc!=2)
  {
    
    return 0;
  }

  f = fopen(argv[1], "r");
  
  if(f==NULL)
  {
   printf("error\n");
   return 0;
  }


  while(fscanf(f, "%c%d\n", &ch, &x)==2)
  {
    if(ch == 'i')
    {
      first = insertNode(first, x);
    }

    else if(ch=='d')
    {
      
      first = deleteNode(first, x);
    }

    else
    {
      printf("error\n");
      return 0;
    }
  }

  
  if(!feof(f))
  {
    printf("error\n");
    return 0;
  }


  while(first!=NULL)
  {
    printf("%d\t", first->num);
    first = first->next;
  }
  printf("\n");

  fclose(f);
  free(first);
  return 0;

}


  struct Node* insertNode(struct Node* first, int x)
  {
    
    struct Node* temp;
   if(first==NULL)
   {
     first = malloc(sizeof(struct Node));
     
     first->num =x;
     first->next = NULL;
     return first;

   }

   else if(first->num > x)
   {
     struct Node *toInsert = malloc(sizeof(struct Node));
   
     toInsert->num = x;
     toInsert->next = first;
     return toInsert;
   }
    
   else
   {
      struct Node *ptr = first;
    
      while(ptr!=NULL)
      {
        if(ptr->num == x)
        {
          return first;
        }
      

      else if(ptr->num > x)
      {
        struct Node *toInsert;
        toInsert = malloc(sizeof(struct Node));


        toInsert->num = x;
        toInsert->next = temp->next;
        temp->next = toInsert;
        return first;
      }

      temp = ptr;
      ptr = ptr->next;
    
    }

    struct Node *toInsert;
    toInsert = malloc(sizeof(struct Node));

    toInsert->num = x;
    temp->next = toInsert;

      

     return first;
   }
   return first;
  }



  struct Node *deleteNode (struct Node* first, int x)
  {
    
  struct Node *ptr1 = first;
     
    struct Node *ptr2 = first;
   
    if(first==NULL)
    {
      return first;
    }

    else if(first->num == x)
    {
      if(first->next == NULL)
      {
       return NULL;
      }
      else
      {
       return first->next;
      }
    }
    
    while(ptr1!=NULL)
    {
      if(ptr1->num==x)
      {
       ptr2->next = ptr1->next;
       return first;
      }

     ptr2 = ptr1;
     ptr1 = ptr1->next;
   }



    return first;
 }


 







 
