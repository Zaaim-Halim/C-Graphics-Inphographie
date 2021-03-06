#include<stdio.h>
#include <graphics.h>
#include "2D.h"
#include "3D.h"
#include "autre.h"
#include "courbes.h"
#include "GlobalMenu.h"

int midx, midy;
void tracer2DRepere(int midx, int midy)
{
	line(midx,0,midx,2*midy);
	line(0,midy,midx*2,midy);
}

int main(int argc, char** argv)
{

    int gdriver = DETECT, gmode, errorcode;
	
	int choix;
	char* path = "C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\x86_64-w64-mingw32\\include\\winbgim";
	initgraph(&gdriver, &gmode, path);
	errorcode = graphresult();
	if (errorcode != grOk) 
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		_getch();
		exit(1); /* terminer avec code d'erreur */
	}

	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	setbkcolor(15);
	setcolor(RED);
	outtextxy(midx-110,midy-14,"MINI PROJET D'INFORGAPHIE");
	outtextxy(midx-70,midy+14,"Tapez  Votre choix");
	
	//code here
	do {
		system("cls");
		choix = GlobalMenu();
		switch(choix)
		{
		case 1:
			cleardevice();
			system("cls");
			tracer2DRepere(midx,midy);
			_2D();
			break;
		case 2:
			cleardevice();
			system("cls");
			tracer3DRepere(midx,midy);
			_3D();
			break;
		case 3:
			cleardevice();
			system("cls");
			tracer3DRepere(midx,midy);
			courbes();
			break;
		case 4 :
			cleardevice();
			autre();
			break;
		case 5 :
			break;
		
		default:
			printf("\n\t choix non reconu !!");
			delay(1000);
			
			break;
	   }
	}while(choix != 5);
		closegraph();
	return 0;
}
