#include <math.h>
#include<time.h>
#include<stdio.h>
#include <conio.h>
void horloge()
{
	char timebuf[9];
	char* marker;
	char c,stop;
	int x,y,s1,s2,s,ts,m1,m2,m,xm,ym,i,h1,h2,h,xh,yh,j;
	double x1,y1,xm1,ym1,xh1,yh1,rads,degs,tdegs,radm,degm,tdegm,radh,degh,tdegh;
	circle(320,240,100);
	for(i=1,degs=300.0;i<13;i++,degs=degs+30.0)
	{

		if(i==1)
		{  marker="1";  }
		else if(i==2)
		{  marker="2";  }
		else if(i==3)
		{  marker="3";  }
		else if(i==4)
		{  marker="4";  }
		else if(i==5)
		{  marker="5";  }
		else if(i==6)
		{  marker="6";  }
		else if(i==7)
		{  marker="7";  }
		else if(i==8)
		{  marker="8";  }
		else if(i==9)
		{  marker="9";  }
		else if(i==10)
		{  marker="10";  }
		else if(i==11)
		{  marker="11";  }
		else if(i==12)
		{  marker="12";  }

		rads=(degs*(3.14))/(180.0);
		x1=(95.0)*(cos(rads));
		y1=(95.0)*(sin(rads));
		x=(int)x1+320-3;
		y=(int)y1+240-5;
		outtextxy(x-2,y-1,marker);

	}
	while(1)
	{
		if(kbhit())break;
		_strtime(timebuf);
		s1=timebuf[6]-48;
		s2=timebuf[7]-48;
		s=s1*10+s2;
		degs=(s*360)/60-90;
		rads=(degs*(3.14))/(180.0);
		x1=(80.0)*(cos(rads));
		y1=(80.0)*(sin(rads));
		x=(int)x1+320;
		y=(int)y1+240;
		setcolor(2);
		line(320,240,x,y);
		outtextxy(10, 10, timebuf);
		
		tdegs=degs-6;
		rads=(tdegs*(3.14))/(180.0);
		
		x1=(80.0)*(cos(rads));
		y1=(80.0)*(sin(rads));
		x=(int)x1+320;
		y=(int)y1+240;
		setcolor(0);
		line(320,240,x,y);
		outtextxy(10, 10, timebuf);

		
		m1=timebuf[3]-48;
		m2=timebuf[4]-48;
		m=m1*10+m2;
		degm=(m*360)/60-90;
		radm=(degm*(3.14))/(180.0);
		xm1=(80.0)*(cos(radm));
		ym1=(80.0)*(sin(radm));
		xm=(int)xm1+320;
		ym=(int)ym1+240;
		setcolor(1);
		line(320,240,xm,ym);

		tdegm=degm-6;
		radm=(tdegm*(3.14))/(180.0);
		
		xm1=(80.0)*(cos(radm));
		ym1=(80.0)*(sin(radm));
		xm=(int)xm1+320;
		ym=(int)ym1+240;
		setcolor(0);
		line(320,240,xm,ym);

		h1=timebuf[0]-48;
		h2=timebuf[1]-48;
		h=h1*10+h2;
		j=m/12;
		degh=(h*30)+(j*6)-90;
		radh=(degh*(3.14))/(180.0);
		xh1=(60.0)*(cos(radh));
		yh1=(60.0)*(sin(radh));
		xh=(int)xh1+320;
		yh=(int)yh1+240;
		setcolor(getmaxcolor());
		line(320,240,xh,yh);

		tdegh=degh-6;
		radh=(tdegh*(3.14))/(180.0);
		xh1=(60.0)*(cos(radh));
		yh1=(60.0)*(sin(radh));
		xh=(int)xh1+320;
		yh=(int)yh1+240;
		setcolor(0);
		line(320,240,xh,yh);

		ts=s;

         
	}


}

