#include <math.h>
void plot4pixels(int x,int y,int h,int k,int crColor)
{
	putpixel(x+h,y+k,crColor);
	putpixel(x+h,-y+k,crColor);
	putpixel(-x+h,y+k,crColor);
	putpixel(-x+h,-y+k,crColor);
}
//ELLIPSE BRESENHAM
void ellipsBresenham(int x0 , int y0 , int rx , int ry , int crColor)
{
	long d1,d2;
	int i,gd,gm,x,y;
	long rxsq,rysq,tworxsq,tworysq,dx,dy;
	rxsq=rx*rx;
	rysq=ry*ry;
	tworxsq=2*rxsq;
	tworysq=2*rysq;
	x=0;
	y=ry;
	d1=rysq-rxsq*ry+(0.25*rxsq);
	dx=tworysq*x;
	dy=tworxsq*y;
	do
	{
		putpixel(x0+x,y0+y,15);
		putpixel(x0-x,y0-y,15);
		putpixel(x0+x,y0-y,15);
		putpixel(x0-x,y0+y,15);
		if(d1<0)
		{
			x=x+1;
			y=y;
			dx=dx+tworysq;
			d1=d1+dx+rysq;
		}
		else
		{
			x=x+1;
			y=y-1;
			dx=dx+tworysq;
			dy=dy-tworxsq;
			d1=d1+dx-dy+rysq;
		}
		delay(10);
	}
	while(dx<dy);
	d2=rysq*(x+0.5)*(x+0.5)+rxsq*(y-1)*(y-1)-(rxsq*rysq);
	do
	{
		putpixel(x0+x,y0+y,15);
		putpixel(x0-x,y0-y,15);
		putpixel(x0+x,y0-y,15);
		putpixel(x0-x,y0+y,15);
		if(d2>0)
		{
			x=x;
			y=y-1;
			dy=dy-tworxsq;
			d2=d2-dy+rxsq;
		}
		else
		{
			x=x+1;
			y=y-1;
			dx=dx+tworysq;
			dy=dy-tworxsq;
			d2=d2+dx-dy+rxsq;
		}
	}
	while(y>0);
}

//ELLIPSE TRIGONOMITRIQUE
void ellipsTrigonomitrique(int h , int k , int r1 , int r2 , int crColor)
{
	float x=0;
	float y=r2;
	float angle=0;
	float range=r1;

	do
	{
		putpixel((int)(h+x+0.5),(int)(k+y+0.5),crColor);
		putpixel((int)(h+x+0.5),(int)(k-y+0.5),crColor);
		putpixel((int)(h-x+0.5),(int)(k-y+0.5),crColor);
		putpixel((int)(h-x+0.5),(int)(k+y+0.5),crColor);

		angle+=0.05;

		x=(r1*cos(angle));
		y=(r2*sin(angle));
	}
	while(angle<=range);
}

//ELLIPSE POLYNOMIAL
void ellipsePolynomial(int h , int k , int r1 , int r2 , int crColor)
{
	int x,y;
	x = 0 , y = r2;
	while(x <= r1)
	{
		plot4pixels(x,y,h,k,crColor);
		x++;
		y = r2*sqrt(((r1*r1)-(x*x*1.0))/(r1*r1));
		plot4pixels(x,y,h,k,crColor);
	}
}
