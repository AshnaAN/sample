#include<stdio.h>
#include<graphics.h>
#include<math.h>

void linedda(int xa,int xb,int ya,int yb)
{
 int dx,dy,steps,k;
 float xi,yi,x,y;
 dx=xb-xa;
 dy=yb-ya;
 if(abs(dx)>abs(dy))
  steps=abs(dx);
 else
  steps=abs(dy);
 xi=(float)dx/steps;
 yi=(float)dy/steps;
 x=xa;
 y=ya;
 putpixel(round(x),round(y),2);
 for(k=1;k<=steps;k++)
 {
  x+=xi;
  y+=yi;
  putpixel(round(x),round(y),2);
 }
}
void shearxyr(float shx,int yr,int xa,int ya,int xb,int yb)
{
 int x1,y1,x2,y2;
 x1=xa+ya*shx-shx*yr;
 y1=ya;
 x2=xb+yb*shx-shx*yr;
 y2=yb;
 linedda(x1,x2,y1,y2);
}
void shearyxr(float shy,int xr,int xa,int ya,int xb,int yb)
{
 float x1,y1,x2,y2;
 y1=ya+xa*shy-shy*xr;
 x1=xa;
 y2=yb+xb*shy-shy*xr;
 x2=xb;
 linedda(round(x1),round(x2),round(y1),round(y2));
}
void shearx(float shx,int xa,int ya,int xb,int yb)
{
 float x1,y1,x2,y2;
 x1=xa+ya*shx;
 y1=ya;
 x2=xb+yb*shx;
 y2=yb;
 linedda(round(x1),round(x2),round(y1),round(y2));
}
void sheary(float shy,int xa,int ya,int xb,int yb)
{
 float x1,y1,x2,y2;
 y1=ya+xa*shy;
 x1=xa;
 y2=yb+xb*shy;
 x2=xb;
 linedda(round(x1),round(x2),round(y1),round(y2));
}

void main()
{
 printf("enter the four points");
 int xa,xb,ya,yb,xc,yc,xd,yd;
 scanf("%d%d%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
 printf("enter the shear and xref");
 float shx;
 int yr,ch;
 scanf("%f%d",&shx,&yr);
 printf("1. x direction \n 2.x direction shear relative to other reference \n3.y direction\n4.y direction relative to other reference\n");
 printf("enter your choice:");
 scanf("%d",&ch);
 int gd=DETECT,gm;
 initgraph(&gd,&gm," ");
 //moveto(0,0);
 setbkcolor(0);
 linedda(xa,xb,ya,yb);
 linedda(xb,xc,yb,yc);
 linedda(xc,xd,yc,yd);
 linedda(xd,xa,yd,ya);
 switch(ch)
 {
  case 1:
   shearx(shx,xa,ya,xb,yb);
   shearx(shx,xb,yb,xc,yc);
   shearx(shx,xc,yc,xd,yd);
   shearx(shx,xd,yd,xa,ya);
   break; 
   case 3:
    sheary(shx,xa,ya,xb,yb);
    sheary(shx,xb,yb,xc,yc);
    sheary(shx,xc,yc,xd,yd);
    sheary(shx,xd,yd,xa,ya);
    break;
    case 2:
     shearxyr(shx,yr,xa,ya,xb,yb);
     shearxyr(shx,yr,xb,yb,xc,yc);
     shearxyr(shx,yr,xc,yc,xd,yd);
     shearxyr(shx,yr,xd,yd,xa,ya);
     break;
    case 4:
     shearyxr(shx,yr,xa,ya,xb,yb); 
     shearyxr(shx,yr,xb,yb,xc,yc);
     shearyxr(shx,yr,xc,yc,xd,yd);
     shearyxr(shx,yr,xd,yd,xa,ya);
     break;
    case 5:
     break;
   } 
 getch();
 closegraph();
}
