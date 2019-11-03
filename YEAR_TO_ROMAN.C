/* (c) Devesh Mohnani 1999
Convert Year to Roman Number format
*/
#include<stdio.h>
main()
{
char  *u[]={"I","II","III","IV","V","VI","VII","VIII","IX","X"};
char  *t[]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C"};
char  *h[]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"};
int year,i,j,k,l,temp;clrscr();
printf("\n\n\n\t\tENTER A YEAR LESS THAN 9999--->  ");
scanf("%d",&year);if(year>=9999 || year<1) exit();
i=year%10;temp=year-i;j=temp%100;temp=temp-j;k=temp%1000;temp=temp-k;
printf("\n\n\t\tROMAN YEAR--->  ");for(l=1000;l<=temp;l=l+1000) putchar('M');
k=k/100;j=j/10;
if(k!=0) printf("%s",h[k-1]);
if(j!=0) printf("%s",t[j-1]);
if(i!=0) printf("%s",u[i-1]);
getch();
}
