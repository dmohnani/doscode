/* (c) Devesh Mohnani 1999
Stack implementation using Array */
#include<stdio.h>
#define max 20
#define null 0
struct stack
	   {  int top;
	    int elements[max];
	    };
void push(struct stack *ps,int element)
		   {
		    if(ps->top==max-1)
		    {printf("\n STACK OVERFLOW");
		     return;
		     }
		      else
		      {
		      ps->elements[++ps->top]=element;
		      return;
		      }
		  }

int pop(struct stack *ps)
	     {
	       if(ps->top==-1)
	      {printf("\n\n\t\tSTACK IS EMPTY::");
	       return(null);
	       }
	       else
	       {
		return(ps->elements[ps->top--]);
		}
		}


main()
{
int ch,i,j,k,temp;
struct stack stack1,*ptr;
ptr=&stack1;
stack1.top=-1;
clrscr();
lab:
printf("\n\nTHIS ROUTINE PERFORMS STACK OPERATIONS");
printf("\n\n\tWANT TO \n\t1:PUSH INTO STACK\n\t2:POP FROM STACK\n\t3:VIEW DATA\n\t4:QUIT");
printf("\n\n\tENTER A CHOICE--->");scanf("%d",&ch);
switch((int)ch)
{
case 1: printf("\nenter ELEMENT-->");scanf("%d",&i);push(ptr,i);break;
case 2: j=pop(ptr);printf("popped element is-->%d",j);break;
case 3: if(stack1.top!=-1)
for(k=0;k<=ptr->top;k++)
printf("\nElement no.%d is = %d",k,stack1.elements[k]);break;
case 4: exit(0);
default:goto lab;
}
goto lab;
}
