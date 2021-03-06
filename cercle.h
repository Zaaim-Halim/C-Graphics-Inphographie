#include <math.h>

//BRESNHAM
void symetry_8(int xc,int yc,int x,int y)  
{  
	putpixel(x+xc,y+yc,RED);  
	putpixel(x+xc,-y+yc,YELLOW);  
	putpixel(-x+xc,-y+yc,GREEN);  
	putpixel(-x+xc,y+yc,YELLOW);  
	putpixel(y+xc,x+yc,12);  
	putpixel(y+xc,-x+yc,14);  
	putpixel(-y+xc,-x+yc,15);  
	putpixel(-y+xc,x+yc,6);  
}  

void BresenhamCircle(int xc,int yc,int r)  
{  
	int x=0,y=r,d=3-(2*r);  
	symetry_8(xc,yc,x,y);  

	while(x<=y)  
	{  
		if(d<=0)  
		{  
			d=d+(4*x)+6;  
		}  
		else  
		{  
			d=d+(4*x)-(4*y)+10;  
			y=y-1;  
		}  
		x=x+1;  
		symetry_8(xc,yc,x,y);  
	}  
}  
//TRIGONOMETRIQUE 
void tracer(int x,int y,int h,int k,int crColor)
{
	putpixel(x+h,y+k,crColor);
	putpixel(x+h,-y+k,crColor);
	putpixel(-x+h,y+k,crColor);
	putpixel(-x+h,-y+k,crColor);
	putpixel(y+h,x+k,crColor);
	putpixel(y+h,-x+k,crColor);
	putpixel(-y+h,x+k,crColor);
	putpixel(-y+h,-x+k,crColor);
}
void cicleTrigonomitrque(int xc, int yc ,int r, int crColor)
{
	double a = 0.0 ;
	int y1,x1;
	while(a <= M_PI/4)
	{
		x1 =(int)r*cos(a);
		y1 =(int)r*sin(a);
		
		tracer(x1,y1,xc,yc,crColor);	
		a = a+M_PI/50;
	}
}
//POLYNOMIALE
void circlePolynomial(int xc, int yc ,int r, int crColor)
{
	int x = 0 , y = r ;
	while(x <= r/sqrt(2))
	{
		y = sqrt(r*r-x*x);  
		putpixel(x+xc,y+yc, crColor);
		putpixel(x+xc,-y+yc,crColor);
		putpixel(y+xc,-x+yc, crColor);
		putpixel(-y+xc,-x+yc, crColor);
		putpixel(-x+xc,-y+yc, crColor);
		putpixel(-x+xc,y+yc, crColor);
		putpixel(-y+xc,x+yc, crColor);
		putpixel(y+yc,x+yc, crColor);
		x++;	
	}
}
