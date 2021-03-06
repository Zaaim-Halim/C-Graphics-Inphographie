#include "courbMenu.h"
#include <math.h>
// fact
extern int midx, midy;
int fact(int n)
{
    if(n>1)
        return n*fact(n-1);
    else if(n>=0)
        return 1;
}
void linges(int px[], int py[], int n)
{
	int i , j = 1;
	i = 0;
	while(i< n && j < n)
	{
	    line(midx+px[i],midy-py[i],midx+px[j],midy-py[j]);
		i++;
		j++;
	}
}

void bezier(int px[], int py[], int n)
{
    float u,x,y,b;

    // tracer la premiere point
    putpixel(px[0]+midx,midy-py[0],BLUE);

    // calcule de factoriel de n-1
    int nfact=fact(n-1);

    // 0.0001 est le pas!
    for(u=0.0001;u<1;u+=0.0001)
    {
        // initial x =0 et y = 0
        x=0;
        y=0;

        for(int i=0;i<n;i++)
        {
            /*
                formul:

                b(u) =     n! * (1-u)^(n-i) * u^i
                        -------
                        i!(n-i)!
            */
            b=(nfact*pow(1-u,n-1-i)*pow(u,i))/(fact(n-1-i)*fact(i));

            // changer x et y
            x+=b*px[i];
            y+=b*py[i];
        }
        // tracer x et y 
        putpixel(midx+x,midy-y,BLUE);
    }

    // tracer la deriniere point
    putpixel(midx+px[n-1],midy-py[n-1],BLUE);
}

int courbes()
{
	int choix,i,n;
	int px[100],py[100];
	int kx[4]={0,150,230,300},ky[4] = {0,200,200,100};
	do{
		choix = courbMenu();
		switch(choix)
		{
		  case 1:cleardevice();
		        tracer3DRepere(midx,midy);
		  	    printf("tapez le nombre des points: ");
                scanf("%d",&n);
                printf("Enter %d Points: ",n);

                for(i=0;i<n;i++)
                {
                	printf("\nPoint : %d\n" , i+1);
                	printf("Proint %d X = ",i+1);
                	scanf("%d",&px[i]);
                	printf("\nProint %d Y = ",i+1);
					scanf("%d",&py[i]);
				}
                
                setbkcolor(WHITE);
                setcolor(RED);
                linges(px,py,n);
                setcolor(GREEN);
                setlinestyle(SOLID_LINE,12,3);
                bezier(px,py,n);
                setlinestyle(SOLID_LINE,1,1);
		      break;
		  case 2:
		  	    
		      break;
		  default:
		    printf("\n\t choix non reconu !!");
		    delay(1000);
		    break;	
		}
	system("cls");
	}while(choix != 2);
	return 0;
}
