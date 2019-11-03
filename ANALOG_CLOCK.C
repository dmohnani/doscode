/* (c) Devesh Mohnani 1999-2000
Analog Clock using Borland Turbo Graphics Library on Dos */

#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<graphics.h>
#include<math.h>
int gd=DETECT,gm,g[60],h[60],stangle=90,endangle,i,k,xf,yf,c,l;char *str="AM";
float hour,min,sec;struct arccoordstype arcinfo;struct time ti;
float hangle,mangle,sangle,xh,xm,xs,yh,ym,ys,xhh,xmm,xss,yhh,ymm,yss;
float  rads,mx,my;
main()
{
rads=3.14159/180;
gettime(&ti);
hour=ti.ti_hour;min=ti.ti_min;sec=ti.ti_sec;
if(hour>12) hour-=12;
sangle=(sec*(-6))*rads;
mangle=(min*(-6))*rads+sangle/60;
hangle=(hour*(-30)+min*(-0.5))*rads+sangle/3600;
initgraph(&gd,&gm,"E:\\turb\\bgi");
mx=getmaxx()/2;my=getmaxy()/2;

plot();xh=mx;xm=mx;xs=mx;
ys=my-150;ym=my-130;yh=my-95;

xss=mx+(xs-mx)*cos(sangle)-(ys-my)*sin(-sangle);
yss=my+(xs-mx)*sin(-sangle)+(ys-my)*cos(sangle);

xmm=mx+(xm-mx)*cos(mangle)-(ym-my)*sin(-mangle);
ymm=my+(xm-mx)*sin(-mangle)+(ym-my)*cos(mangle);

xhh=mx+(xh-mx)*cos(hangle)-(yh-my)*sin(-hangle);
yhh=my+(xh-mx)*sin(-hangle)+(yh-my)*cos(hangle);

xs=xss;ys=yss;xm=xmm;ym=ymm;xh=xhh;yh=yhh;

setcolor(CYAN);
line(mx,my,xs,ys);
line(mx,my,xm,ym);
line(mx,my,xh,yh);
while(!kbhit())
{
sleep(1);
gettime(&ti);
setcolor(BLACK);
line(mx,my,xs,ys);
line(mx,my,xmm,ym);
line(mx,my,xh,yh);


sangle=(-6)*rads;
mangle=(sangle/60);
hangle=(mangle/60);
xss=mx+(xs-mx)*cos((sangle))-(ys-my)*sin(-(sangle));
yss=my+(xs-mx)*sin(-(sangle))+(ys-my)*cos((sangle));

xmm=mx+(xm-mx)*cos((mangle))-(ym-my)*sin(-(mangle));
ymm=my+(xm-mx)*sin(-(mangle))+(ym-my)*cos((mangle));

xhh=mx+(xh-mx)*cos((hangle))-(yh-my)*sin(-(hangle));
yhh=my+(xh-mx)*sin(-(hangle))+(yh-my)*cos((hangle));

xs=xss;ys=yss;xm=xmm;ym=ymm;xh=xhh;yh=yhh;


setcolor(CYAN);
line(mx,my,xs,ys);
line(mx,my,xmm,ym);
line(mx,my,xh,yh);
/*for(l=0;l<=10;l++)
circle(mx,my,l);*/
gotoxy(35,2);
c=ti.ti_hour;
if(c>=12) { c-=12; str="PM";} else str="AM";
printf("%02d:%02d:%02d %s",c,ti.ti_min,ti.ti_sec,str);
}
closegraph();
exit(0);
}

plot()
{
gotoxy(63,2);printf("%c Omega",234);
setcolor(LIGHTBLUE);
rectangle(70,15,570,460);
line(70,32,570,32);
ellipse(319,239,0,360,190,190);
setfillstyle(4,RED);
floodfill(565,455,LIGHTBLUE);
g[0]=319;   h[0]=99;
for(i=1;i<60;i++)
{
endangle = stangle + (i * 6);
 setcolor(BLACK);
 arc(mx,my,stangle,endangle,170);
 setcolor(WHITE);
 getarccoords(&arcinfo);
 g[i] = arcinfo.xend;
 h[i] = arcinfo.yend;
}

for(i=0;i<60;i++)
{
if(i==0) {setcolor(CYAN);outtextxy(312,68,"12");setcolor(15);}
else
{
if(i%5!=0) circle(g[i], h[i], 1);
else
{
k=i/5;
setcolor(CYAN);
switch(k)
{
case 1: {outtextxy(g[60-i], h[60-i],"1");break;}
case 2: {outtextxy(g[60-i], h[60-i], "2"); break;}
case 3: {outtextxy(g[60-i], h[60-i], "3"); break; }
case 4: {outtextxy(g[60-i], h[60-i], "4"); break;}
case 5: {outtextxy(g[60-i], h[60-i], "5"); break; }
case 6: {outtextxy(g[60-i], h[60-i], "6");break; }
case 7: {outtextxy(g[60-i], h[60-i], "7"); break; }
case 8: {outtextxy(g[60-i], h[60-i]-2, "8"); break; }
case 9: {outtextxy(g[60-i]-2, h[60-i]-3, "9");  break;}
case 10:{outtextxy(g[60-i], h[60-i], "10"); break;}
case 11:{outtextxy(g[60-i], h[60-i], "11"); break;}
}
setcolor(15);
}
}
}

}