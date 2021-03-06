
void BresenhamLine(int x1, int y1, int x2, int y2, int crColor)
{
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1; dy = y2 - y1;
	dx1 = abs(dx); dy1 = abs(dy);
	px = 2 * dy1 - dx1;	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1; y = y1; xe = x2;
		}
		else
		{
			x = x2; y = y2; xe = x1;
		}

		putpixel(x, y, crColor);

		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			if (px < 0)
			px = px + 2 * dy1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) y = y + 1; else y = y - 1;
				px = px + 2 * (dy1 - dx1);
			}
			putpixel(x, y, crColor);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1; y = y1; ye = y2;
		}
		else
		{
			x = x2; y = y2; ye = y1;
		}

		putpixel(x, y, crColor);

		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			if (py <= 0)
			py = py + 2 * dx1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) x = x + 1; else x = x - 1;
				py = py + 2 * (dx1 - dy1);
			}
			putpixel(x, y, crColor);
		}
	}
}
void linePolynomial(int x0, int y0, int x1, int y1,int crColor)  
{  
	int dx, dy, p, x, y;  
	dx=x1-x0;  
	dy=y1-y0;  
	x=x0;  
	y=y0;  
	p=2*dy-dx;  
	while(x<x1)  
	{  
		if(p>=0)  
		{  
			putpixel(x,y,crColor);  
			y=y+1;  
			p=p+2*dy-2*dx;  
		}  
		else  
		{  
			putpixel(x,y,crColor);  
			p=p+2*dy;}  
		x=x+1;  
	}  
}  
