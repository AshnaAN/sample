//Rahul V Reji
//45
#include<graphics.h>

#include<stdio.h>

#include<math.h>

void main()

{

 int gd=DETECT,gm=0,radx,rady,xc,yc,theta=0,theta_end=90;

 printf("Enter the ellipse  centre and radius");

 scanf("%d%d%d%d",&xc,&yc,&radx,&rady);

 float rad=(3.1417/180),angle,x,y;

 initgraph(&gd,&gm,"");

 while(theta<=theta_end)

 {

  angle=rad*theta;

  x=radx*cos(angle);

  y=rady*sin(angle);

  putpixel(xc+x,yc+y,2);

  putpixel(xc-x,yc+y,2);

  putpixel(xc+x,yc-y,2);

  putpixel(xc-x,yc-y,2);

  theta++;

 }

 getch();

 closegraph();

} 





OUTPUT:

Enter the ellipse  centre and radius100

100

50

20







