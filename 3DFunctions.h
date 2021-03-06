#include <stdio.h>
#include <math.h>
extern int midx, midy;
int FLAG = 0;
double l = (midx / 2), m = (midy / 2);

void initR(double Resuslt[8][4])
{
	int i,j;
	for(i = 0 ; i < 8 ; i++)
	{
		for(j = 0 ; i < 4 ; i++)
		Resuslt[i][j] = 0; 
	}
}
void initR4(double Resuslt[4][4])
{
	int i,j;
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 0 ; i < 4 ; i++)
		Resuslt[i][j] = 0; 
	}
}
void afficher(double M[8][4])
{
	int i,j;
	printf("\n===========  matrice8 ========== \n");
	for(i = 0 ;i < 8 ; i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%lf ",M[i][j]);
		}
		printf("\n");
	}
	printf("\n======================================= \n");
}
void afficher4(double M[4][4])
{
	int i,j;
	printf("\n===========  matrice4 ========== \n");
	for(i = 0 ;i < 4 ; i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%lf ",M[i][j]);
		}
		printf("\n");
	}
	
	printf("\n========================================= \n");
}

double rotation[4][4];
// produit matrecial
void produitMatrecial(double M1[8][4],double M2[8][4],double Result[8][4],int L, int C)
{
	int i,j,k,sum=0;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			sum = 0;
			for (int k = 0; k < C; k++) {
				
				sum = sum + M1[i][k]*M2[k][j];
			}
			Result[i][j] = sum;
			
		}
		
	}

}
// perspective correction 
void perspectiveCorrection(double M[8][4])
{
	int i ,j;
	for( i = 0 ; i < 8 ; i++)
	{
    
		  for(j = 0 ; j < 4 ; j++)
		  {
		  	
			M[i][j] = (M[i][j]/M[i][3])*100;
			
		  }
	  
	}
}
void tracer3DRepere(int midx, int midy)
{
	line(midx,0,midx,midy);
	line(midx,midy,2*midx,midy);
	line(midx,midy,0+80,2*midy);
}
void calculateRotationM(double rotation[4][4],int type,int angle,int pas)
{
	initR(rotation);
	if(type == 0)
	{
		rotation[0][0] = 1;rotation[3][3] = 1;
		rotation[1][1] = cos(angle+pas);rotation[1][2] = sin(angle+pas);
		rotation[2][1] = -sin(angle+pas);rotation[2][2] = cos(angle+pas);
	}
	if(type == 1)
	{
		rotation[0][0] = cos(angle+pas);rotation[0][2] = -sin(angle+pas);
		rotation[2][0] = sin(angle+pas);rotation[2][2] = cos(angle+pas);
		rotation[3][3] = 1;
	}
	if(type == 2)
	{
		rotation[0][0] = cos(angle+pas);rotation[0][1] = sin(angle+pas);
		rotation[1][0] = -sin(angle+pas);rotation[1][1] = cos(angle+pas);
		rotation[2][2] = 1; rotation[3][3] = 1;
	}

}


void tracerCube(double M[8][4],double projection[4][4] ,double ResultF[8][4], int L ,int C)
{
	initR(ResultF);
	produitMatrecial(M,projection,ResultF,8,4);

    if(FLAG == 1)
    {
    	perspectiveCorrection(ResultF);
	}

	setlinestyle(SOLID_LINE,12,3);
	setcolor(LIGHTBLUE);
	line(ResultF[0][0]+midx,midy-ResultF[0][1],ResultF[1][0]+midx,midy-ResultF[1][1]); 
	line(ResultF[0][0]+midx,midy-ResultF[0][1],ResultF[3][0]+midx,midy-ResultF[3][1]); 
	line(ResultF[2][0]+midx,midy-ResultF[2][1],ResultF[3][0]+midx,midy-ResultF[3][1]); 
	line(ResultF[1][0]+midx,midy-ResultF[1][1],ResultF[2][0]+midx,midy-ResultF[2][1]); 
	setcolor(GREEN);
	line(ResultF[1][0]+midx,midy-ResultF[1][1],ResultF[6][0]+midx,midy-ResultF[6][1]); 
	line(ResultF[0][0]+midx,midy-ResultF[0][1],ResultF[5][0]+midx,midy-ResultF[5][1]); 
	line(ResultF[2][0]+midx,midy-ResultF[2][1],ResultF[7][0]+midx,midy-ResultF[7][1]); 
	line(ResultF[3][0]+midx,midy-ResultF[3][1],ResultF[4][0]+midx,midy-ResultF[4][1]); 
	setcolor(LIGHTMAGENTA);
	line(ResultF[4][0]+midx,midy-ResultF[4][1],ResultF[5][0]+midx,midy-ResultF[5][1]); 
	line(ResultF[4][0]+midx,midy-ResultF[4][1],ResultF[7][0]+midx,midy-ResultF[7][1]); 
	line(ResultF[5][0]+midx,midy-ResultF[5][1],ResultF[6][0]+midx,midy-ResultF[6][1]); 
	line(ResultF[6][0]+midx,midy-ResultF[6][1],ResultF[7][0]+midx,midy-ResultF[7][1]); 
    setlinestyle(SOLID_LINE,1,1);
}
//Calcule la matrice de rotation
void RotationXYZ(double M[8][4],double projection[4][4] ,double Result[8][4],
int L, int C, int angle,int type)
{
	
	double TR1[8][4];
	int i,j;
	switch(type)
	{
		i = 0;
	case 0: // rotation suivi X
		for(i=0;i<angle;i=i+4)
		{
			
			cleardevice();
			setcolor(GREEN);
			tracer3DRepere(midx,midy);
			setcolor(BLUE);initR(TR1);initR4(rotation);
			calculateRotationM(rotation,0,i,j+i);
			produitMatrecial(M,rotation,TR1,8,4);
			tracerCube(TR1,projection,Result,8,4);
			delay(600);
			j=i;
		}
		break;  	
	case 1: // retation suivi Y
		for(i=0;i<angle;i=i+4)
		{
			cleardevice();
			setcolor(GREEN);
			tracer3DRepere(midx,midy);
			setcolor(BLUE);initR(TR1);
			calculateRotationM(rotation,1,i,j+i);
			produitMatrecial(M,rotation,TR1,8,4);
			tracerCube(TR1,projection,Result,8,4);
			delay(600);
			j=i;
		}
		break;
	case 2: // retotation suivi Z
		for(i = 0 ; i < angle ; i = i + 4)
		{
			cleardevice();
			setcolor(GREEN);
			tracer3DRepere(midx,midy);
			setcolor(BLUE);initR(TR1);
			calculateRotationM(rotation,2,i,i+j);
			produitMatrecial(M,rotation,TR1,8,4);
			tracerCube(TR1,projection,Result,8,4);
			delay(600);
			j = i;
		}
		
		break;
	default:
		break;	
	}
}

//TRANSLATION 
void translationLinearXYZ(double M[8][4],double cavalier[4][4],
double Result[8][4],int L , int C,int type,int amount)
{
	double TM0[4][4] = {
		{1 ,0 ,0 ,0        },
		{0 ,1 ,0 ,0        },
		{0 ,0 ,1 ,0        },
		{amount,0,0,0           }
	};
	double TM1[4][4] = {
		{1 ,0 ,0 ,0        },
		{0 ,1 ,0 ,0        },
		{0 ,0 ,1 ,0        },
		{0,amount,0,0      }
	};
	double TM2[4][4] = {
		{1 ,0 ,0 ,0      },
		{0 ,1 ,0 ,0      },
		{0 ,0 ,1 ,0      },
		{0,0,amount,0    }
	};
	double TM3[4][4] = {
		{1 ,0 ,0 ,0       },
		{0 ,1 ,0 ,0       },
		{0 ,0 ,1 ,0       },
		{1,2,2,   0       }
	};
	double TR[8][4];
	
	switch(type)
	{
		cleardevice();
		tracer3DRepere(midx,midy);
	case 0: //  suivi X
		
		initR(TR);
		setcolor(BLUE);	  
		produitMatrecial(M,TM0,TR,8,4);
		delay(1000);
		tracerCube(TR,cavalier,Result,8,4);
		break;
		
	case 1: //  suivi Y
		
		initR(TR);
		setcolor(RED);	  
		produitMatrecial(M,TM1,TR,8,4);
		delay(1000);
		tracerCube(TR,cavalier,Result,8,4);
		break;
	case 2: //  suivi Z
		
		initR(TR);
		setcolor(YELLOW);	  
		produitMatrecial(M,TM2,TR,8,4);
		delay(1000);
		tracerCube(TR,cavalier,Result,8,4);
		break;
	case 3: // suivi un Axe qlq
		
		initR(TR);
		setcolor(RED);	  
		produitMatrecial(M,TM3,TR,8,4);
		delay(1000);
		tracerCube(TR,cavalier,Result,8,4);
		break;
	default:
		break;	
	}
}

// Projection en Perspective sur z = 0 , y = 0, x = 0
void projectionEnperspective(double M[8][4],double cavalier[4][4],
double Result[8][4],int L , int C,int type)
{
	double TR1[8][4];
	
	double SM0[4][4] = { //x = 0
		{0 ,0 ,0 ,-0.1 },
		{0 ,1 ,0 ,0  },
		{0 ,0 ,1 ,0  },
		{0 ,0, 0, 1}
	};
	double SM1[4][4] = { // y = 0
		{1 ,0 ,0 ,0   },
		{0 ,0 ,0 ,-0.1},
		{0 ,0 ,1 ,0   },
		{0 ,0, 0, 1   }
	};
	double SM2[4][4] = { // z = 0
		{1 ,0 ,0 ,0   },
		{0 ,1 ,0 ,0   },
		{0 ,0 ,0 ,-0.1},
		{0 ,0 ,0,1}
	};
	switch(type)
	{
		
	case 0: // x = 0
	
		cleardevice();
		setcolor(GREEN);
		tracer3DRepere(midx,midy);
		setcolor(RED);initR(TR1);
		FLAG = 1;
		tracerCube(M,SM0,Result,8,4);
		FLAG = 0;
		break;
		  	
	case 1: // y = 0
	
		cleardevice();
		setcolor(GREEN);
		tracer3DRepere(midx,midy);
		setcolor(RED);initR(TR1);
	    FLAG = 1;
		tracerCube(M,SM1,Result,8,4);
		FLAG = 0;
		break;
		
	case 2: // z = 0
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);
		setcolor(BLUE);initR(TR1);
		FLAG = 1;
		tracerCube(M,SM2,Result,8,4);
	    FLAG = 0;
		break;
	default:
		break;	
	}
}
//Projection cabinet 
void projectionCabinet(double M[8][4],double cabinet[4][4],
       double Result[8][4],int L , int C)
{
	setcolor(RED);
	tracer3DRepere(midx,midy);
	tracerCube(M,cabinet,Result,8,4);
}

//Translation plus Rotation
void PerspectiveETranslation(double M[8][4],double cavalier[4][4],
       double Result[8][4],int L , int C,int type)
{
	//======== Perspective matrices ==============
	double PM0[4][4] = { //x = 0
		{0 ,0 ,0 ,-0.1 },
		{0 ,1 ,0 ,0  },
		{0 ,0 ,1 ,0  },
		{2 ,0, 0, 1}
	};
	double PM1[4][4] = { // y = 0
		{1 ,0 ,0 ,0   },
		{0 ,0 ,0 ,-0.1},
		{0 ,0 ,1 ,0   },
		{0 ,2, 0, 1   }
	};
	double PM2[4][4] = { // z = 0
		{1 ,0 ,0 ,0   },
		{0 ,1 ,0 ,0   },
		{0 ,0 ,0 ,-0.1},
		{0 ,0 ,4,1}
	};
	//==============================
	double P0[4][4] = { //x = 0
		{0 ,0 ,0 ,-0.1 },
		{0 ,1 ,0 ,0  },
		{0 ,0 ,1 ,0  },
		{0   ,0, 0, 1}
	};
	double P1[4][4] = { // y = 0
		{1 ,0 ,0 ,0   },
		{0 ,0 ,0 ,-0.1},
		{0 ,0 ,1 ,0   },
		{0 ,0, 0, 1   }
	};
	double P2[4][4] = { // z = 0
		{1 ,0 ,0 ,0   },
		{0 ,1 ,0 ,0   },
		{0 ,0 ,0 ,-0.1},
		{0 ,0 ,0,1    }
	};
	//==============================

	switch(type)
	{
	case 0: 
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);	
		FLAG = 1;
		tracerCube(M,P0,Result,8,4);
		delay(1000);
		tracerCube(M,PM0,Result,8,4);
		FLAG = 0;
    	
		break;  	
	case 1: 
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);	
		FLAG = 1;
		tracerCube(M,P1,Result,8,4);
		delay(1000);
		tracerCube(M,PM1,Result,8,4);
		FLAG = 0;
		break;
	case 2: 
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);
		FLAG = 1;
		tracerCube(M,P2,Result,8,4);
		delay(1000);
		tracerCube(M,PM2,Result,8,4);
		FLAG = 0;
		break;
	default:
		break;	
	}
}
//Perspective, Translation et Rotation
void translationEtRotation(double M[8][4],double cavalier[4][4],
       double Result[8][4],int L , int C,int type)
{
	double TR1[8][4],TR2[8][4];
	//rotation matrices ==============
	double R00[4][4] ={ 
	    {1 ,0 ,0 ,0        },
		{0 ,cos(45) ,sin(45) ,0 },
		{0 ,-sin(45),cos(45) ,0 },
		{0,0,0,1           }
		};
	double R11[4][4] = {
	    {cos(-12) ,0 ,-sin(-12) ,0},
		{0 ,0 ,0 ,0        },
		{sin(-12) ,0 ,cos(-12) ,0},
		{0,0,0,1          }
	};
	double R22[4][4] ={ 
	    {cos(45) ,sin(45) ,0 ,0},
		{-sin(45) ,cos(45) ,0 ,0},
		{0 ,0 ,1 ,0        },
		{0,0,0,1           }
	  };
	// Matrices de translation s =======
	double TM0[4][4] = {
		{1 ,0 ,0 ,0        },
		{0 ,1 ,0 ,0        },
		{0 ,0 ,1 ,0        },
		{2,0,0,0           }
	};
	double TM1[4][4] = {
		{1 ,0 ,0 ,0        },
		{0 ,1 ,0 ,0        },
		{0 ,0 ,1 ,0        },
		{0, 2.5 ,0 ,0        }
	};
	double TM2[4][4] = {
		{1 ,0 ,0 ,0      },
		{0 ,1 ,0 ,0      },
		{0 ,0 ,1 ,0      },
		{0,0,3,0         }
	};
	//==============================

	switch(type)
	{
	case 0: // rotation 45^ et translation suinvat X
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);
		tracerCube(M,cavalier,Result,8,4);
		initR(TR1);initR(TR2);
		produitMatrecial(M,TM0,TR1,8,4);
		produitMatrecial(TR1,R00,TR2,8,4);
		delay(1000);
		tracerCube(TR2,cavalier,Result,8,4);
    	
		break;  	
	case 1: // rotation 45^ et translation suinvat Y
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);
		tracerCube(M,cavalier,Result,8,4);
		initR(TR1);	initR(TR2);
		produitMatrecial(M,R11,TR1,8,4);
		produitMatrecial(TR1,TM1,TR2,8,4);
		delay(1000);
		tracerCube(TR2,cavalier,Result,8,4);
		break;
	case 2: // rotation 45^ et translation suinvat Z
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);
		tracerCube(M,cavalier,Result,8,4);
		initR(TR1);initR(TR2);
		produitMatrecial(M,TM2,TR1,8,4);
		produitMatrecial(TR1,R22,TR2,8,4);
		delay(1000);
		tracerCube(TR2,cavalier,Result,8,4);
		
		break;
	default:
		break;	
	}
}

// symetrie parapport XY, YZ... 
void symetrieXYZ(double M[8][4],double cavalier[4][4],
double Result[8][4],int L , int C,int type)
{

	double TR1[8][4];
	double SM1[4][4] = {
		{-1 ,0 ,0 ,0},
		{0 ,1 ,0 ,0 },
		{0 ,0 ,1 ,0 },
		{0 ,0, 0, 1 }
	};
	double SM0[4][4] = {
		{1 ,0 ,0 ,0 },
		{0 ,1 ,0 ,0 },
		{0 ,0 ,-1 ,0},
		{0 ,0, 0, 1 }
	};
	double SM2[4][4] = {
		{1 ,0 ,0 ,0 },
		{0 ,-1 ,0 ,0},
		{0 ,0 ,1 ,0 },
		{0 ,0, 0, 1 }
	};			             
	switch(type)
	{
		
	case 0: // Symetrie XY
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);
		tracerCube(M,cavalier,Result,8,4);
		setcolor(YELLOW);initR(TR1);
		produitMatrecial(M,SM0,TR1,8,4);
		tracerCube(TR1,cavalier,Result,8,4);
		break;  	
	case 1: // Symetrie YZ
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);
		tracerCube(M,cavalier,Result,8,4);
		setcolor(GREEN);initR(TR1);
		produitMatrecial(M,SM1,TR1,8,4);
		tracerCube(TR1,cavalier,Result,8,4);
		
		break;
	case 2: // Symetrie XZ
		
		cleardevice();
		setcolor(RED);
		tracer3DRepere(midx,midy);
		tracerCube(M,cavalier,Result,8,4);
		setcolor(BLUE);initR(TR1);
		produitMatrecial(M,SM2,TR1,8,4);
		tracerCube(TR1,cavalier,Result,8,4);
		
		break;
	default:
		break;	
	}
}
void produitMatriciel480_4(float cyl[480][4],float mry[4][4],float cyl1[480][4], int L,int C)
{
	int i,j,k,sum=0;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			sum = 0;
			for (int k = 0; k < C; k++) {
				
				sum = sum + cyl[i][k]*mry[k][j];
			}
			cyl1[i][j] = sum;
			
		}
		
	}	
}
void cylindre(){
	float w;
	float z;
	float T1[4][4] = {
	{1.0 ,0.0 ,0.0 ,0.0 },
	{0.0 ,1.0 ,0.0 ,0.0 },
	{0.0 ,0.0 ,1.0 ,0.0 },
	{305.0,274.0,1.0,0.0}
};
	float cyl[480][4],cyl1[480][4],cyl2[480][4],cyl3[480][4];
	float cabinet[4][4]={
	    {1.0,0.0,0.0,0.0          },
		{0.0,1.0,0.0,0.0          },
		{0.433012,0.250001,0.0,0.0},
		{0.0,0.0,0.0,100.0        }
		};
	int k=0;
	for(z=-240;z<240;z+=20){
		for(w=0;w<=2*M_PI;w+=M_PI/10){
			cyl[k][0]=100*cos(w);
			cyl[k][1]=100*sin(w);
			cyl[k][2]=z;
			cyl[k][3]=1;
			k++;
		}	
	}

	float g;
	setcolor(RED);
	tracer3DRepere(midx,midy);
	setcolor(GREEN);
	for(g=0.0;g<=M_PI;g+=M_PI/100){
		float mry[4][4]={
		    {cos(g),0.0,sin(g),0.0},
			{0.0,1.0,0.0,0.0      },
			{sin(g),0.0,cos(g),0.0},
			{0.0,0.0,0.0,1.0      }
		};
			
		produitMatriciel480_4(cyl,mry,cyl1,480,4);
		produitMatriciel480_4(cyl1,T1,cyl3,480,4);
		produitMatriciel480_4(cyl3,cabinet,cyl2,480,4);
		
	}
	int t;
	for(k=0;k<479;k++){ 
		line(cyl2[k][0],cyl2[k][1],cyl2[k+1][0],cyl2[k+1][1]);
		
		for(t=0;t<460;t++){ 

			line(cyl2[t][0],cyl2[t][1],cyl2[t+2][0],cyl2[t+2][1]);
		}
	} 


}

