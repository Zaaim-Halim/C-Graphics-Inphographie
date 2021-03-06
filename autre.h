
#include "autreMenu.h"
// Globale variables
extern int midx, midy;
#define PI 3.14

void systemSolair()
{
	 int m=0,v=260,eh=300,mr=100,j=10,s=230,u=190,n=20;
	 float pi=3.1424,a,b,c,d,e,f,g,h,z;
	   while(1)
    {
        // Changer le diplacement dans l'orbit 
        a=(pi/180)*m++;
        b=(pi/180)*v++;
        c=(pi/180)*eh++;
        d=(pi/180)*mr++;
        e=(pi/180)*j++;
        f=(pi/180)*s++;
        g=(pi/180)*u++;
        h=(pi/180)*n++;
        n++;

        cleardevice();

        // Soleil
        setcolor(YELLOW);
        circle(midx,midy,20);

        setcolor(RED);
        //Mercure
        circle(midx+60*sin(a),midy-35*cos(a),8); // planète
        ellipse(midx,midy,0,360,60,35);  // orbit

        //Venus
        circle(midx+100*sin(b),midy-60*cos(b),12);
        ellipse(midx,midy,0,360,100,60);

        //Terre
        circle(midx+130*sin(c),midy-80*cos(c),10);
        ellipse(midx,midy,0,360,130,80);

        //Mars
        circle(midx+170*sin(d),midy-100*cos(d),11);
        ellipse(midx,midy,0,360,170,100);

        //Jupiter
        circle(midx+200*sin(e),midy-130*cos(e),14);
        ellipse(midx,midy,0,360,200,130);

        //Saturne
        circle(midx+230*sin(f),midy-155*cos(f),12);
        ellipse(midx,midy,0,360,230,155);

        //Uranus
        circle(midx+260*sin(g),midy-180*cos(g),9);
        ellipse(midx,midy,0,360,260,180);

        //Neptune
        circle(midx+280*sin(h),midy-200*cos(h),9);
        ellipse(midx,midy,0,360,280,200);

        delay(50);
    }
}
// https://fr.wikipedia.org/wiki/Flocon_de_Koch 
void koch(int x1, int y1, int x2, int y2, int it)
{
	
    //find angle
    float angle = 60*PI/180;

    //find p3 near p1
    int x3 = (2*x1+x2)/3;
    int y3 = (2*y1+y2)/3;

    //find p4 near p2
    int x4 = (x1+2*x2)/3;
    int y4 = (y1+2*y2)/3;

    //find joining pt
    int dx=x4-x3;
    int dy=y4-y3;

    int x = x3 + dx*cos(angle)+dy*sin(angle);
    int y = y3 - dx*sin(angle)+dy*cos(angle);

    if(it > 0)
    {
        //recursion with it-1
        koch(x1, y1, x3, y3, it-1); //13
        koch(x3, y3, x, y, it-1);   //30
        koch(x, y, x4, y4, it-1);   //04
        koch(x4, y4, x2, y2, it-1); //42
    }
    else
    {
        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}
void tracerFloconKoch()
{
	 int x1 = 100, y1 = 200, x2 = 400, y2 = 200, x3 = 250, y3 = 450, it;

  cleardevice();
    setcolor(RED);

    it = 5;

    koch(x1, y1, x2, y2, it);   //12
    koch(x2, y2, x3, y3, it);   //23
    koch(x3, y3, x1, y1, it);   //31

    return ;
}

int autre()
{
	int choix;
	do{
		choix = autreMenu();
		switch(choix)
		{
			case 1:
		        systemSolair();
				break;
			case 2 :
				 tracerFloconKoch();
				
				break;
		
			default : 
			    printf("\n\t choix non reconu !!");
		    	delay(1000);
		    	break;
					
		}
		
	}while(choix != 3);
}
