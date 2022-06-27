#include<stdio.h>
#include<stdlib.h>
int day,diff,cur_y,J1SD,NDPM,D,LY;long days;
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JLY,AUG, SEP,
			 OCT, NOV, DEC,M_MIN =  1,M_MAX = 12 } M;
main(){clrscr();printf("ENTER YEAR----->>>>>>");scanf("%d",&cur_y);
diff=cur_y-1900; days=((diff-1)*365.25)+1;day=days%7;J1SD=day+1;
LY=cur_y; LY=LY%4;printf("\n\n\n\t\t Calendar Year %d", cur_y);
for ( M = M_MIN; M <= M_MAX; M++ ) {
switch(M){
case JAN: printf("\n\n\n January    %d\n",cur_y); NDPM = 31;          break;
case FEB: printf("\n\n\n February   %d\n",cur_y); NDPM = LY ? 28 : 29;break;
case MAR: printf("\n\n\n  March     %d\n",cur_y); NDPM = 31;          break;
case APR: printf("\n\n\n  April     %d\n",cur_y); NDPM = 30;          break;
case MAY: printf("\n\n\n   May      %d\n",cur_y); NDPM = 31;          break;
case JUN: printf("\n\n\n  June      %d\n",cur_y); NDPM = 30;          break;
case JLY: printf("\n\n\n  July      %d\n",cur_y); NDPM = 31;          break;
case AUG: printf("\n\n\n August     %d\n",cur_y); NDPM = 31;          break;
case SEP: printf("\n\n\nSeptember   %d\n",cur_y); NDPM = 30;          break;
case OCT: printf("\n\n\n October    %d\n",cur_y); NDPM = 31;          break;
case NOV: printf("\n\n\nNovember    %d\n",cur_y); NDPM = 30;          break;
case DEC: printf("\n\n\nDecember    %d\n",cur_y); NDPM = 31;          break;}
printf("\nSUN  MON  TUE  WED  THU  FRI  SAT\n");
printf("---  ---  ---  ---  ---  ---  ---\n");
for(D=1;D<=1+J1SD*5;D++) printf( " ");
for(D=1;D<=NDPM;D++)
{printf("%2d",D);printf("%s",(D + J1SD) % 7 > 0 ? "   " : "\n ");}getch();
J1SD=(J1SD + NDPM) % 7;}
getch();               }
