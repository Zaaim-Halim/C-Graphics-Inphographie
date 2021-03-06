//globale variables
int ccx=300,ccy=100,rr=200;
int X=0,Y,p;
void tracerPorteur()
{
	setcolor(GREEN);
	line(250,100,350,100);
	line(250,95,350,95);
	setcolor(RED);
}
int tracerPondule(int dtn,int width) {
	int x1,y1;
	setcolor(RED);
	line(200,100,400,100);
	if(X>=Y) {
		return 0;
	}
	cleardevice();
	tracerPorteur();
	if(dtn==1) {
		circle(ccx+X,ccy+Y,20);
		line(ccx,ccy,ccx+X,ccy+Y);
	} else {
		circle(ccx-X,ccy+Y,20);
		line(ccx,ccy,ccx-X,ccy+Y);
	}
	delay(10);
	if(kbhit()) 
    	exit(0);
	X++;
	if(p<0) 
    	p+=2*X+1;
	else {
		Y--;
		p+=2*(X-Y)+1;
	}
	x1=X;
    y1=Y;
	tracerPondule(dtn,width);
	cleardevice();
	tracerPorteur();
	if(dtn==1) {
		circle(ccx+x1,ccy+y1,20);
		line(ccx,ccy,ccx+x1,ccy+y1);
	} else {
		circle(ccx-x1,ccy+y1,20);
		line(ccx,ccy,ccx-x1,ccy+y1);
	}
	delay(10);
	if(kbhit()) 
	exit(0);
	return(0);
}

int pondule()
{
	int width = 50;
	cleardevice();
	setcolor(GREEN);
	line(250,100,350,100);
	while(1) {
		X=0;
		Y=rr;
		p=1-rr;
		tracerPondule(1,width);
		X=0;
		Y=rr;
		p=1-rr;
		tracerPondule(0,width);
	
	}
}
