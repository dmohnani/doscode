/*(C) Devesh Mohnani 1999
 Simple Linked List */
 
/*--------------------------------------------------------------------------
  malloc -Allocates requested size of bytes and retuns pointer to the first
  ------  byte of allocated space.
			      ptr=(cast type*)malloc(no. of bytes)
 ---------------------------------------------------------------------------
  calloc -Allocates space for an array of elements, initializes them to zero
  ------  and returns a pointer to memory.
			      ptr=(cast type*)calloc(n,size of one element)
  -------------------------------------------------------------------------
  free   -Frees Previously allocated space.
  ------                      free(ptr)
  -------------------------------------------------------------------------
  realloc-Modifies the size of previously allocated space.
  -------                     ptr = realloc(ptr,newsize)
  -------------------------------------------------------------------------
      ****  THESE FUNCTIONS USE HEAP AREA (FREE MEMORY) PRESENT BETWEEN
	PERMANENT STORAGE AREA AND STACK.****
  -------------------------------------------------------------------------*/

/*program*/


#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct linklist
{
int item;
struct linklist *next;       /*self referential structurers*/
};

typedef struct linklist node;

void main()
{
node *delete(node *p),*insert(node *p),*find(node *p,int key),*head,*i;
void create(node *p);
int count(node *p),ch,k;
void print(node *p);
lab:
clrscr(); printf("\n");
printf("THIS ROUTINE CREATES A SINGLY LINKED LIST & PERFORMS ALL the OPERATIONS ON IT\n");
printf("-----------------------------------------------------------------------------\n");
printf("\n\nWANT TO\n");
printf("1:Create a Linked List\n");
printf("2:Print list\n");
printf("3:Find a node\n");
printf("4:Insert a node\n");
printf("5:Delete a node\n");
printf("6:Quit Program\n");
printf("\n\nEnter Your Choice->");
scanf("%d",&ch);
switch (ch)
	{
case 1: create(head);
	break;
case 2: print(head);
	printf("\nNO.OF ITEMS--->%d",count(head));
	getch();
	break;
case 3: printf("\nEnter Key to be Searched->");
	scanf("%d",&k);
	i=find(head,k);
	if(i==NULL) printf("\nKEY NOT FOUND");
	if(i!=NULL) printf("\nKey is There");
	getch();
	break;
case 4: head=insert(head);
	break;
case 5: head=delete(head);
	getch();
	break;
case 6: free(head);
	exit(0);
	return;
	}
goto lab;
}


void create(node *list)
{
printf("\nInput an item(Type -999 at end):->");
scanf("%d",&list->item);

if(list->item==-999)  list->next=NULL;
else
{
list->next=(node*)malloc(sizeof(node));
create(list->next);
}
return;
}


void print(node *list)
{
if(list->next!=NULL)
{
printf("%d->",list->item);
if(list->next->next==NULL)
 printf("%d",list->next->item);

print(list->next);
}
return;
}

int count(node *list)
{
if(list->next==NULL)
     return(0);
  else
     return(1+count(list->next));
}


node *insert(node *head)  /*returns a new node in the linkedlist*/
{
 node *find(node *p,int a);
 node *new;/*pointer to new node*/
 node *n1; /*pointer to node preceding key node*/
 int key;
 int x; /*new item <number> to be inserted*/

 printf("\n\nEnter Value of new Item->");
 scanf("%d",&x);
 printf("\nEnter Value of key Item  (TYPE -999 *IF* LAST)->");
 scanf("%d",&key);

 if(head->item==key)  /*new node is first*/
 {
 new=(node*)malloc(sizeof(node));
 new->item=x;
 new->next=head;
 head=new;
 }

 else    /*find key node & insert new node before the key node*/
 {
 n1=find(head,key); /*find key node*/

 if(n1==NULL)
    printf("\nKey node is not found\n");

  else
   {
   new=(node*)malloc(sizeof(node));
   new->item=x;
   new->next=n1->next;
   n1->next=new;
   }
 }
return(head);
}



node *find(node *list,int key)
{
  if(list->item==key || list->next->item==key)   /*key found*/
       return(list);
  else
    if(list->next->item==NULL)    /*end*/
       return(NULL);
    else
      find(list->next,key);
}


node *delete(node *list)
{
  node *find(node *p,int a);
  int key;                /*item to be deleted*/
  node *n1;                /* pointer to node preceding key node*/
  node *p;                  /*temporary  pointer*/

  printf("\n What Item (NUMBER) is to be deleted->");
  scanf("%d",&key);

  if(list->item==key)   /*first node is to be deleted*/
  {
    p=list->next;
    free(list);
    list=p;
  }
  else
  {
    n1=find(list,key);

    if(n1==NULL)
       printf("\nKEY NOT FOUND");
    else
    {                         /*delete key node*/
     p=n1->next->next;       /*pointer to the node following the key node*/
     free(n1->next);         /*free key node*/
     n1->next=p;
    }
  }
return(list);
}
