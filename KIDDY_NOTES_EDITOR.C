/* (c) Devesh Mohnani 1999 
Dos & TURBO-C based KIDDY Editor
*/

#include<stdio.h>
#include<dos.h>
FILE *fp;int cc;char far *ptr=0xB8000000,fn[12];int ctr;char c;
int scan,ascii;
main()
{
int i,x=3,y=4;
clrscr();
textbackground(1);
clrscr();
gotoxy(4,2);printf("[F1:OPEN] * [F2:SAVE] * [F3:NEW] * [F4:HELP] * [F5:EXIT] * KIDDY EDIT v1.0");
gotoxy(2,1);putchar(201);
for(i=3;i<=78;i++) {gotoxy(i,3);putchar(205);
gotoxy(i,1);putchar(205);gotoxy(i,24);putchar(196);}
for(i=2;i<=23;i++)
{if(i>=3 && i<79) continue;
gotoxy(2,i);putchar(186);
gotoxy(79,i);putchar(186);}
gotoxy(2,3);putchar(200);gotoxy(79,3);putchar(188);
gotoxy(79,1);putchar(187);gotoxy(x,y);
while(1)
{
  getkey();
  if(ascii==0 || ascii==9 || ascii==27  ||ascii==224)
      switch(scan)
	 {
	 case 72:{if(y>4)  y--;gotoxy(x,y);break;}
	 case 80:{if(y<23) y++;gotoxy(x,y);break;}
	 case 75:{if(x>3)  x--;gotoxy(x,y);break;}
	 case 77:{if(x<77) x++;gotoxy(x,y);break;}
	 case 15:{if(x<74) x=x+4;gotoxy(x,y);break;}
	 case 63:{law:gotoxy(3,25);printf("Exit (Y/N):->Y");gotoxy(16,25);
	     c=getch();switch(c){
			     case 'y':case 'Y':
			     { clrscr();textbackground(0);
			     system("cls");fflush(stdin);exit(0);break;}
			     case 'n':case 'N':
	  {gotoxy(16,25);putchar(c);delay(3000);
	  gotoxy(3,25);printf("                          ");gotoxy(x,y);
	    break;}          default:goto law; }}
	 case 71:{x=3;     gotoxy(x,y);break;}
	 case 79:{x=77;    gotoxy(x,y);break;}
	 case 83:{printf(" ");gotoxy(x,y);break;}

	 case 62:
	 {gotoxy(3,25);printf("About:KIDDY EDITOR v1.0 (c) DEVESH mohnani VIth sem [ok]");
	 getch();
	 gotoxy(3,25); printf("                                                        ");
	 gotoxy(x,y);
	 break;
	 }
	 case 59: {
		   gotoxy(3,25);printf("OPEN FILE--->\"TEMP.TXT\"  [ok] ");
		   getch();
		   gotoxy(3,25);printf("                                ");
	 gotoxy(x,y);
	 fp=fopen("TEMP.TXT","r+");
	 ctr=482;
	 while(fp!=EOF)
	 {
	 *(ctr+ptr)=fgetc(fp);
	  ctr=ctr+2;
	  if(ctr%160==0&&ctr<=3678) ctr=ctr+2;
	  else
	  if(ctr>=3678) break;
	 }
	 break;
	 }
	 case 61:     {
		       gotoxy(3,25);printf("NEW FILE--->\"TEMP.TXT\"  [ok] ");
		       getch();
		       gotoxy(3,25);printf("                             ");
	 for(ctr=480;ctr<=3679;ctr=ctr+2)
	 *(ctr+ptr)='\0';
	 gotoxy(3,4);
	 break;
	 }
	 case 60:
	 {
	 gotoxy(3,25);printf("File Saved As:-->TEMP.TXT      [ok]");
	 getch();
	 gotoxy(3,25);printf("                                    ");
	 gotoxy(x,y);fp=fopen( "TEMP.TXT","w+");
	 if(fp==NULL)
	 {
	 gotoxy(3,25);
	 printf("DISK IS FULL OR WRITE PROTECTED      ");
	 getch();
         gotoxy(3,25);
	 printf("                                     ");
	 gotoxy(x,y);
	 break;
	 }
	 else
	 {         gotoxy(77,23);putchar(26);
		   for(ctr=480;ctr<=3679;ctr=ctr+2)
		     {
		     cc=*(ptr+ctr);
		     if(ctr%160==0) cc=13;
		     fputc(cc,fp);
		     }
		     fclose(fp);

	  }

	  gotoxy(x,y);
	  }

	  }


else

   switch(ascii)
	 {
	    case 33:case 34:case 35:case 36:case 37:case 38:case 39:case 40:
	    case 41:case 42:case 43:case 44:case 45:case 46:case 47:case 48:
	    case 49:case 50:case 51:case 52:case 53:case 54:case 55:
	    case 56:case 57:case 58:case 59:case 60:case 61:case 62:case 63:
	    case 64:case 65:case 66:case 67:case 68:case 69:case 70:case 71:
	    case 72:case 73:case 74:case 75:case 76:case 77:case 78:case 79:
	    case 80:case 81:case 82:case 83:case 84:case 85:case 86:case 87:
	    case 88:case 89:case 90:case 91:case 92:case 93:case 94:case 95:
	    case 96:case 97:case 98:case 99:case 100:case 101:
	    case 102:case 103:case 104:case 105:case 106:case 107:case 108:
	    case 109:case 110:case 111:case 112:case 113:case 114:case 115:
	    case 116:case 117:case 118:case 119:case 120:case 121:case 122:
	    case 123:case 124:case 125:case 126:
	      {
	       if(x<77) {fflush(stdin);putchar(ascii); x++;gotoxy(x,y);}
	       if(x==78){fflush(stdin);putchar(ascii); x=3;y++;gotoxy(x,y);}
	       break;
	      }
	   case 13:{if(y<23) {x=3;y++;gotoxy(x,y);}break;}
	   case 32:{if(x<78) {fflush(stdin);putchar(32);x++; gotoxy(x,y);}
		    if(x==78 && y<23) { putchar(32);x=3;y++;gotoxy(x,y);}
		    break;}
	   case 8:{if(x>3){fflush(stdin);putchar(32);--x;gotoxy(x,y);}
	    else
	      if(x==3 && y>4){putchar(32);y--;x=77;gotoxy(x,y);fflush(stdin);putchar(32);}
	   break; }
	 }
}




}


getkey()
{
union REGS i,o;
while(!kbhit())
     ;
 i.h.ah=0;  /*function or service no. */
 int86(22,&i,&o);
 ascii=o.h.al;
 scan=o.h.ah;

}
