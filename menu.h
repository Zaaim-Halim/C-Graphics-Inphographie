

int menu()
{
	int choix;
	printf("\n    MINI-PROJET D'INPHOGRAPHIE : ZAAIM HALIM");
	printf("\n====================================================");
	printf("\n1-> Line par la m�thode de BRESENHAM : y = ax + b ");
	printf("\n2-> Line par la m�thode de POLYNOMIALE : y = ax + b");
	printf("\n3-> Cercle par la m�thode de BRESENHAM : ");
	printf("\n4-> Cercle par la m�thode TRIGONOMETRIQUE : ");
	printf("\n5-> Cercle par la m�thode POLYNOMIALE : ");
	printf("\n6-> Ellipse par la m�thode POLINOMIALE : ");
	printf("\n7-> Ellipse par la m�thode TRIGONOMETRIQUE");
	printf("\n8-> Ellipse par la m�thode BRESENHAM : ");
	printf("\n9-> Horloge : ");
	printf("\n10-> Pondule : ");
	printf("\n11-> Quiter : ");
	printf("\n====================================================");
	printf("\n\tTapez votre choix : ");
	scanf("%d",&choix);
	return choix;
}
