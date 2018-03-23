#include<stdio.h>
#include<stdlib.h>


//globalizing the nodes and binary tree components

struct Node
{
    int num, h;
    struct Node* l;
    struct Node* r;
    
};
  
  int i(struct Node* root, int x);
  int s(struct Node* root, int x);

//the main method which operates on acepting finals

int main(int argc, char** argv)
  {
    FILE *f;
    char ch;
    int x;
    
    if (argc != 2)
   {
        printf("error\n");
        return 0;
    }
    
    f = fopen(argv[1], "r");

    if(f==NULL)
    {
      printf("error\n");
      return 0;
    }


    fscanf(f, "%c %d\n", &ch, &x);
    
   //no s till there is a i : LOGIC!


    while (ch != 'i')
   {
        printf("absent\n");
        fscanf(f, "%c %d\n", &ch, &x);
    }
    
    //root

    struct Node *root = malloc(sizeof(struct Node));

    root->num = x;
    root->h = 1;
    printf("inserted 1\n");
    
    while (fscanf(f, "%c %d\n", &ch, &x) == 2)
    {
        if (ch == 'i')
        {
            i(root, x);
        }
        
        else if (ch == 's')
        {
            s(root, x);
        }
        
        else 
        {
            printf("error\n");
        }
     }

    fclose(f);
    return 0;
}


//function to insert node
int i(struct Node *root, int x)
  {
    if (root->num == x)
    {
        printf("duplicate\n");
        return 0;
    }
    
    struct Node *t1 = root;
    struct Node *t2 = root;
    int htemp = 1;
    
    while (t1 != NULL)
     {
        if (t1->num == x)
        {
            printf("duplicate\n");
            return 0;
        }
        
        //left subtree
        else if (t1->num > x)
        {
            t2 = t1;
            t1 = t1->l;

            htemp++;
        }
         
        //right subtree
        else 
        {
            t2 = t1;
            t1 = t1->r;
            htemp++;
        }
    }
    

    struct Node *toInsert;

    toInsert = malloc(sizeof(struct Node));
    toInsert->num = x;
    toInsert->h = htemp;

    if (t2->num > x)
     {
        t2->l = toInsert;
     }
    else 
     {
        t2->r = toInsert;
     }

    printf("inserted %d\n", htemp);
    return 0;
    
 }


//function to search a number in the tree
int s(struct Node *root, int x)
 {
    
    //the root is the search number
    if (root->num == x)
    {
        printf("present 1\n");
        return 0;
    }

    
    struct Node *t1 = root;

    while (t1 != NULL)
    {
        if (t1->num == x)
        {
            printf("present %d\n", t1->h);
            return 0;
        }

        else if (t1->num > x)
        {
            t1 = t1->l;
        }

        else
        {
            t1 = t1->r;
        }
    }
    
    printf("absent\n");
    return 0;
    
}



