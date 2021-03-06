#include<stdio.h>
#include "line.h"
#include "menu.h"
#include "cercle.h"
#include "ellipse.h"
#include "Horloge.h"
#include "pondule.h"
typedef struct Point{
	int x;
	int y;
};
//golobal variables
Point point1,point2,point3,point4;
int r,r1;
int _2D() {
	int choix;
	do{
		choix = menu();
		switch(choix)
		{
		case 1:
			printf("\ndonner les coordonnés du point intial : ");
			printf("\nXi = ");
			scanf("%d",&point1.x);
			printf("\nYi = ");
			scanf("%d",&point1.y);
			printf("\ndonner les coordonnés du point final : ");
			printf("\nXf = ");
			scanf("%d",&point2.x);
			printf("\nYf = ");
			scanf("%d",&point2.y);
			cleardevice();
			BresenhamLine(point1.x,point1.y, point2.x,point2.y,RED);
			break;
		
		case 2:
			printf("\ndonner les coordonnés du point intial : ");
			printf("\nXi = ");
			scanf("%d",&point1.x);
			printf("\nYi = ");
			scanf("%d",&point1.y);
			printf("\ndonner les coordonnés du point final : ");
			printf("\nXf = ");
			scanf("%d",&point2.x);
			printf("\nYf = ");
			scanf("%d",&point2.y);
			cleardevice();
			linePolynomial(point1.x,point1.y,point2.x,point2.y,GREEN);
			break;
		case 3:
			printf("\ndonner les coordonnés x et y de centre : ");
			printf("\nX = ");
			scanf("%d",&point1.x);
			printf("\nY = ");
			scanf("%d",&point1.y);
			printf("\ndonner le Rayon r : ");
			printf("\nR = ");
			scanf("%d",&r);
			cleardevice();
			BresenhamCircle(point1.x,point1.y,r);
			break;
		case 4:
			printf("\ndonner les coordonnés x et y de centre : ");
			printf("\nX = ");
			scanf("%d",&point1.x);
			printf("\nY = ");
			scanf("%d",&point1.y);
			printf("\ndonner le Rayon r : ");
			printf("\nR = ");
			scanf("%d",&r);
			cleardevice();
			cicleTrigonomitrque(point1.x,point1.y,r,GREEN);
			break;
		case 5:
			printf("\ndonner les coordonnés x et y de centre : ");
			printf("\nX = ");
			scanf("%d",&point1.x);
			printf("\nY = ");
			scanf("%d",&point1.y);
			printf("\ndonner le Rayon r : ");
			printf("\nR = ");
			scanf("%d",&r);
			cleardevice();
			circlePolynomial(point1.x,point1.y,r,GREEN);
			break;
		case 6:
			printf("\ndonner les coordonnés x et y de centre : ");
			printf("\nX = ");
			scanf("%d",&point1.x);
			printf("\nY = ");
			scanf("%d",&point1.y);
			printf("\ndonner le Rayon r1 : ");
			printf("\nR1 = ");
			scanf("%d",&r);
			printf("\ndonner le Rayon r2 : ");
			printf("\nR2 = ");
			scanf("%d",&r1);
			cleardevice();
			ellipsePolynomial(point1.x,point1.y,r,r1,GREEN);
			break;
		case 7:
			printf("\ndonner les coordonnés x et y de centre : ");
			printf("\nX = ");
			scanf("%d",&point1.x);
			printf("\nY = ");
			scanf("%d",&point1.y);
			printf("\ndonner le Rayon r1 : ");
			printf("\nR1 = ");
			scanf("%d",&r);
			printf("\ndonner le Rayon r2 : ");
			printf("\nR2 = ");
			scanf("%d",&r1);
			cleardevice();
			ellipsTrigonomitrique(point1.x,point1.y,r,r1,GREEN);
			break;
		case 8:
			printf("\ndonner les coordonnés x et y de centre : ");
			printf("\nX = ");
			scanf("%d",&point1.x);
			printf("\nY = ");
			scanf("%d",&point1.y);
			printf("\ndonner le Rayon r1 : ");
			printf("\nR1 = ");
			scanf("%d",&r);
			printf("\ndonner le Rayon r2 : ");
			printf("\nR2 = ");
			scanf("%d",&r1);
			cleardevice();
			ellipsBresenham(point1.x,point1.y,r,r1,GREEN);
			break;
		case 9:
			cleardevice();
			setcolor(RED);
			printf("\n\ttappez un charactère pour sortie !! ");
			horloge();
			break;
		case 10:
			pondule();
			break; // to just get out !!
		case 11:
			
			break; // to just get out !!
		default:
			printf("\n\t choix non reconu !!");
			delay(1000);
			break;
		}

	system("cls");
	}while(choix != 11);

}
