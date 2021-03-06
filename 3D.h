#include "3DMenu.h"
#include "3DFunctions.h"
// Globale variables
extern int midx, midy;
//matrice Result
double Result[8][4];
//Cube
double M[8][4] ={
                 {0,0,0,50}, //A
                 {50,0,0,50}, //B
				 {50,50,0,50}, //C
				 {0,50,0,50}, //D
                 {0,50,-50,50}, //E
				 {0,0,-50,50}, //F
				 {50,0,-50,50}, //G
				 {50,50,-50,50}  //H
				 };
//Matric te retation ;
double R[4][4];
//cavalier Matric
double cavalier[4][4] = {{1,0,0,0},{0,1,0,0},{(double)sqrt(2)/2,(double)sqrt(2)/2,0,0},{0,0,0,1}};
//cabinet Matric
double canbinet[4][4] = {{1,0,0,0},{0,1,0,0},{sqrt(3)/4,1/4,0,0},{0,0,0,1}};

int AXE()
{
	int choix;
	printf("\n    TRANSLATION TYPE");
	printf("\n====================================================");
	printf("\n0-> suivi axe X :");
	printf("\n1-> suivi axe Y :");
	printf("\n2-> suivi axe Z :");
	printf("\n3-> suivi axe QLQ : ");
	printf("\n====================================================");
	printf("\n\tTapez votre choix : ");
	do{
		scanf("%d",&choix);
	}while(0>choix>3);
	
	return choix;
}
int rotationAXE()
{
	int choix;
	do{
	printf("\n    ROTATION TYPE");
	printf("\n====================================================");
	printf("\n0-> suivi axe X :");
	printf("\n1-> suivi axe Y :");
	printf("\n2-> suivi axe Z :");
	printf("\n====================================================");
	printf("\n\tTapez votre choix : ");
	
	scanf("%d",&choix);
	}while(0>choix>3);
	
	return choix;
}
int symetrie()
{
	int choix;
	do{
	printf("\n    Symetrie TYPE");
	printf("\n====================================================");
	printf("\n0-> suivi XY :");
	printf("\n1-> suivi YZ :");
	printf("\n2-> suivi XZ :");
	printf("\n====================================================");
	printf("\n\tTapez votre choix : ");
	
	scanf("%d",&choix);
	}while(0>choix>3);
	
	return choix;
}
int projectionPerspect()
{
	int choix;
	do{
	printf("\n    Projection TYPE");
	printf("\n====================================================");
	printf("\n0-> suivi plan X = 0 :");
	printf("\n1-> suivi plan Y = 0 :");
	printf("\n2-> suivi plan Z = 0 :");
	printf("\n====================================================");
	printf("\n\tTapez votre choix : ");
	
	scanf("%d",&choix);
	}while(0>choix>3);
	
	return choix;
}
int translationRotationAXE()
{
	int choix;
   do{
   
    printf("\n    ROTATION & TRANSLATION AXE");
	printf("\n====================================================");
	printf("\n0-> suivi axe X :");
	printf("\n1-> suivi axe Y :");
	printf("\n2-> suivi axe Z :");
	printf("\n====================================================");
	printf("\n\tTapez votre choix : ");
	
	scanf("%d",&choix);
	}while(0>choix>3);
	
	return choix;  	
}
int translationPerspect()
{
	int choix;
   do{
   
    printf("\n    ROTATION & TRANSLATION AXE");
	printf("\n====================================================");
	printf("\n0-> suivi l'axe X et perspective x = 0 :");
	printf("\n1-> suivi l'axe Y et perspective y = 0 :");
	printf("\n2-> suivi l'axe Z et perspective z = 0 :");
	printf("\n====================================================");
	printf("\n\tTapez votre choix : ");
	
	scanf("%d",&choix);
	}while(0>choix>3);
	
	return choix;  	
}

int _3D()
{
	int choix; int translationAxe,amount; 
	int rotationType, angle,symetrieType,projectionP,tr,tp;
	do{
		choix = _3Dmenu();
		setcolor(GREEN);
		tracerCube(M,cavalier,Result,8,4);
		switch(choix)
		{
			case 1:
				translationAxe = AXE();
			    printf("donnez la valeur de translastion suivant ce Axe entre 1 et 4: ");
			    scanf("%d",&amount);
				translationLinearXYZ(M,cavalier,Result,8,4,translationAxe,amount);
				
			   break;
			case 2:
				rotationType = rotationAXE();
				printf("donnez la valeur d'angle de Rotation svuivant ce Axe : ");
			    scanf("%d",&angle);
				RotationXYZ(M,cavalier,Result,8,4,angle,rotationType);
				
				break;
			case 3:
				 printf("choisir le plan de projection : ");
				 projectionP = projectionPerspect();
				 projectionEnperspective(M,cavalier,Result,8 ,4,projectionP);
				
				break;
			case 4:
				  printf("choisir l'axe de translation et plan de perspective  : ");
				  tp = translationPerspect();
			      PerspectiveETranslation(M,cavalier,Result,8 ,4,tp);
				break;
			case 5:
				 cleardevice();
				 projectionCabinet(M,canbinet,Result,8 ,4);
				break;
			case 6:
			       printf("choisir l'axe  : ");
				   tr = translationRotationAXE();
	               translationEtRotation(M,cavalier,Result,8 ,4,tr);		 
				break;
			case 7:
				 
				break;
			case 8:
				 printf("choisir l'axe de symerie : ");
				 symetrieType = symetrie();
				 symetrieXYZ(M,cavalier,Result,8 ,4,symetrieType);
				 
				break;
			case 9:
				cleardevice();
				cylindre();
					
				break; // cylindre
			case 10:
				break; // to just get out !!
			default:
				printf("\n\t choix non reconu !!");
		    	delay(1000);
		    	break;
		}
	 system("cls");
	}while(choix != 10);
	 system("cls");	
	 
	return 0;
}
