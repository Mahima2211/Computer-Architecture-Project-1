#include<stdio.h>
#include<stdlib.h>



struct Node
{


 	int num, h;
 	struct Node* l;
 	struct Node* r;
  
};


int ins (struct Node *root, int n)
 {


    if(root == NULL)
    {
    root = malloc(sizeof(struct Node));

    	root->num = n;
    	root->h = 1;
    	printf("inserted 1\n");

     return 0;
    }


    if (root->num == n)
    {
    printf("duplicate\n");
    return 0;
    }

  
    struct Node *t = root;
    struct Node *t1 = root;
    int htemp = 1;

  
    while (t != NULL)
    {


      if (t->num == n)
      {
      printf("duplicate");
      return 0;
      }
    
      else if (t->num > n)
      {
      t1 = t;
      t = t->l;
      htemp++;
      }
    
      else 
      {
      t1 = t;
      t = t->r;
      htemp++;
      }
    }
  
  struct Node *toinsert;

  toinsert = malloc(sizeof(struct Node));
  toinsert->num = n;
  toinsert->h = htemp;

  if (t1->num > n)
   {
    t1->l = toinsert;
   } 
  else 
   {
    t1->r = toinsert;
   }
  printf("inserted %d\n", htemp);
  return 0;
}



//to see if the node exists in the tree
 int search(struct Node *root, int n)
 {
  

  if(root == NULL)
  {
    printf("absent\n");
    return 0;
  }

  if (root->num == n)
  {
    printf("present 1\n");
    return 0;
  }
    
  struct Node *t = root;

  while (t != NULL)
  {
    if (t->num == n)
    {
      printf("present %d\n", t->h);
      return 0;
    }

    else if (t->num > n)
    {
      t = t->l;
    }
    else
    {
      t = t->r;
    }
  }
  
  printf("absent\n");
  return 0;
  
 } 




//recursive function to implement reheighting

int reh(struct Node *head, int h)
 {
 
   if(head == NULL)
   {
    return 0;
   }  

   if (head->r != NULL)
   {
    reh(head->r, h+1);
   }
 
   if (head->l != NULL)
   {
    reh(head->l, h+1);
   }


   head->h = h;
   return 0;

}




struct Node *delete(struct Node *root, int n, int h)
{
  struct Node *l;
  struct Node *r = root->r;
  struct Node *t1 = root;
  
    
  //IF R IS A LEAF

  if (root->r == NULL)
  {
    
    if(root->l == NULL)
    {
      root = NULL;
      printf("success\n");
      return root;
    }
   

    root = root->l;
    reh(root, h);
    printf("success\n");

    return root;

  }
    
  
  else 
  {
    
    if(r-> l != NULL)
     {
      
      while(r->l != NULL)
      {
	t1 = r;
	r = r->l; 
      }
 
      t1->l = NULL;
    }
   

    if(t1 != root)
    {
      if(r->r != NULL)
      {
	l = r->r;
	t1->l = l;
	
      }
      r->r = root->r;
    }


    if(root->l != NULL)
    {
      r->l = root->l;
    } 
    else
    {
      r->l = NULL;
    }


    root = r;
    reh(root, h);
    printf("success\n");

    return root;
  }
}

struct Node* delhelp (struct Node *root, int n)
{

     struct Node *t = root;
     struct Node *t1 = NULL;
  
     while(t != NULL)
     {

      if(t->num == n)
      {
      t = delete(t, n, t->h);

      if(t1 != NULL)
       {
	if(t->num < t1->num)
        {
	  t1->l = t;
	} 
        else
        {
	  t1->r = t;
	}
      } 
       else
      {
	return t;
      }
      break; 
                
    } 
     else if(t->num > n)
     {
      t1 = t;
      t = t->l;
      
    } 
     else
     {
      t1 = t;
      t = t->r;
    }
  }
  
  if(t == NULL)
  {
    printf("fail\n");
  }
   return root;
  
}

  


  
int main(int argc, char** argv)
{

  FILE *f;
  char ch;
  int n;

  
  if (argc != 2)
  {
    printf("error\n");
    return 0;
  }
  

  f = fopen(argv[1], "r");
  fscanf(f, "%c %d\n", &ch, &n);
  
  //if the actio is i it is supposed to be inserted 

  while (ch != 'i')
  {
    printf("absent\n");
    fscanf(f, "%c %d\n", &ch, &n);
  }
  
  
  struct Node *root = malloc(sizeof(struct Node));
  root->num = n;
  root->h = 1;

  printf("inserted 1\n");
  
  while (fscanf(f, "%c %d\n", &ch, &n) == 2) 
  {

    if (ch == 'i')
    {
      ins(root, n);
    }
    
    else if (ch == 's')
    {
      search(root, n);
    }
        
    else if (ch == 'd')
    {
     root = delhelp(root, n);
    }
     
    
    else 
    {
      printf("error\n");
    }
  }

  return 0;
}



