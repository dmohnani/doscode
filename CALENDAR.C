/* (c) Devesh Mohnani 1999

DOS / TURBO C Based Calendar Generation Program

*/

#include<stdio.h>
#include<dos.h>

int mcount,mmcount,indent=0,start=0,ly=0,dofjf=1,c,i,t,n;
int dom,y,y1,m,dim[12]={31,28,31,30,31,30,31,31,30,31,30,31};
void dear(int);
main()
{ textcolor(0);
  clrscr();clrscr();system("CLS");
	   for(i=23;i<58;i++)
	   {gotoxy(i,8);printf("%c",205);
	   gotoxy(i,16);putchar(205);}
	   for(i=9;i<16;i++)
	   {gotoxy(22,i);printf("%c",186);
	   gotoxy(58,i);putchar(186);}
	   gotoxy(22,8);putchar(201);
	   gotoxy(58,8);putchar(187);
	   gotoxy(22,16);putchar(200);
	   gotoxy(58,16);putchar(188);
	   gotoxy(25,10);
	   printf("Enter Year <YYYY>....  ");
	   scanf("%d",&y);gotoxy(25,13);printf("Enter Month <MM>.....  ");
	   scanf("%d",&m);if(y<1900 || m<1 || m>12) exit(1);

for(i=1900;i<y;i++)
  {    if(dofjf==6)
	   dofjf=0;
	    else
	    dofjf++;
	     if(i%4==0 && i%100!=0 || i%400==0 && i%100==0 )
             if(dofjf<6) dofjf++; else  dofjf=0;
  }
ly=(i%4==0 && i%100!=0 || i%400==0)?1:0;
dom=dofjf;
mcount=m-1;
if(ly==1) dim[1]=29;
for(i=0;i<mcount;i++)
{

 dom=(dom+dim[i]);
}
dom=(dom)%7;         /*if(dom==0) dom=7;*/
textcolor(5);
clrscr();
for(i=23;i<58;i++)
{
gotoxy(i,8);printf("%c",205);
gotoxy(i,16);putchar(205);
}
for(i=9;i<16;i++)
{
gotoxy(22,i);printf("%c",186);
gotoxy(58,i);putchar(186);
}
gotoxy(22,8);putchar(201);
gotoxy(58,8);putchar(187);
gotoxy(22,16);putchar(200);
gotoxy(58,16);putchar(188);
gotoxy(25,10);printf("DAY ON 1st OF  JAN  = ");dear(dofjf);
gotoxy(25,13);printf("DAY ON 1st OF MONTH = ");dear(dom);
gotoxy(3,23);textcolor(14+128);clreol();
printf("press any key.......");getch();
--m;
textbackground(3);
textcolor(0);
prinformat(m,y,dom);
do
{
switch(key())
 {
/*u*/case 72: { t=0; n=y+1;
		if((y%4==0 && y%100!=0 || y%400==0) && m<2)
		       {dom+=2;dim[1]=28;t=1;}
		if((y%4==0 && y%100!=0 || y%400==0) && m>=2)
		       {dom++;t=1;dim[1]=28;}
		if((n%4==0 && n%100!=0 || n%400==0) && m>=2)
		       {dom+=2;t=1;dim[1]=29;}
		if((n%4==0 && n%100!=0 || n%400==0) && m<2)
		       {dom++;dim[1]=29;t=1;}
		  if(t==0) {dom++;dim[1]=28;}
		  y++;
		  dom=dom%7;
		prinformat(m,y,dom);
		break;}
/*d*/case 80:{if(y==1900) break;
		t=0; n=y-1;
		if((y%4==0 && y%100!=0 || y%400==0) && m>=2)
		       {dom-=2;t=1;dim[1]=28;}
		if((y%4==0 && y%100!=0 || y%400==0) && m<2)
		       {dom--;t=1;dim[1]=28; }
		if((n%4==0 && n%100!=0 || n%400==0) && m<2)
		       {dom-=2;dim[1]=29;t=1;}
		if((n%4==0 && n%100!=0 || n%400==0) && m>=2)
		       {dom--;dim[1]=29;t=1;}
		if(t==0) {dom--;dim[1]=28;}
		y--;dom=dom+7;
		dom=dom%7;
                prinformat(m,y,dom);break;
		}

/*l*/case 75:{  t=0;
		n=(m>0)?m-1:11;
		dim[1]=28;
		if(m==2 && (y%4==0 && y%100!=0 || y%400==0))
		 {
		 dim[1]=29;
		 }
		 for(i=1;i<=dim[n];i++)
		 {
		 if(dom==0) {dom=6;goto pp;}
		 if(dom>0) dom--;pp:;
		 }
		 if(m<1)  { m=11; y--; goto pl;}
		 if(m>=1)  m--;
		 pl: prinformat(m,y,dom);break;
	     }
/*r*/case 77:{t=0;
		n=(m<11)?m+1:0;
		dim[1]=28;
		if(y%4==0 && (y%100!=0 || y%400==0))  dim[1]=29;
		if(m==0 && (y%4==0 && y%100!=0 || y%400==0))
		 {
		 dim[1]=29;
		 }
		 for(i=1;i<=dim[m];i++)
		 {
		 if(dom==6) {dom=0;goto pq;}
		 if(dom<6) dom++;pq:;
		 }
		 if(m>10)  { m=0; y++; goto pm;}
		 if(m<=11)  m++;
		 pm: prinformat(m,y,dom);break;
	      }
/*e*/case  1:{
	      gotoxy(2,25);
	      exit(1);
	      break;
	     }
/*d*/default:break;
  }
}while(1);
}





prinformat(int mq,int yyr,int doms)
{
textcolor(0);clrscr();
indent=0;
start=0;
switch(mq)
 {
case 0:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tJanuary    %d",yyr);goto lab;}
case 1:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tFebruary   %d",yyr);goto lab;;}
case 2:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tMarch      %d",yyr);goto lab;}
case 3:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tApril      %d",yyr);goto lab;}
case 4:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tMay        %d",yyr);goto lab;;}
case 5:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tJune       %d",yyr);goto lab;}
case 6:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tJuly       %d",yyr);goto lab;}
case 7:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tAugust     %d",yyr);goto lab;}
case 8:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tSeptember  %d",yyr);goto lab;}
case 9:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tOctober    %d",yyr);goto lab;}
case 10:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tNovember   %d",yyr);goto lab;}
case 11:{clrscr();
		 gotoxy(1,4);printf("\t\t\t\t\tDecember   %d",yyr);}
lab:printf("\n\n\n\n\t\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT");

gotoxy(4,10);
printf("\t\t");

       for(i=1;i<=dim[mq];i++)
	{ if (start==0)
	  {indent=doms+indent;
	   for(c=1;c<=doms;c++)
	   printf("\t");
	   start=1;
	  }
	  printf("%d\t",i);
	  indent++;
	  if(indent==7)  { printf("\n\n\t\t");indent=0;}
	}
 }
	   for(i=13;i<72;i++)
	   {gotoxy(i,6);printf("%c",205);
	    gotoxy(i,21);putchar(205);}
	   for(i=7;i<21;i++)
	   {gotoxy(12,i);printf("%c",186);
	   gotoxy(72,i);putchar(186);}
	   gotoxy(12,6);putchar(201);
	   gotoxy(72,6);putchar(187);
	   gotoxy(12,21);putchar(200);
	   gotoxy(72,21);putchar(188);
gotoxy(5,24);textcolor(6);clreol();
printf("up/dn=next/prev year(same month)\t right/left=next/prev month(same year)");
gotoxy(35,22);textcolor(7);clreol();
printf("Esc=Exit");
gotoxy(80,25);
return;
}

key()
{
union REGS i,o;
while(!kbhit());
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}


void dear(int pot)
{
switch(pot)
{
case 0:printf("Sunday");break;
case 1:printf("Monday");break;
case 2:printf("Tuesday");break;
case 3:printf("Wednesday");break;
case 4:printf("Thursday");break;
case 5:printf("Friday");break;
case 6:printf("Saturday");break;
}

}