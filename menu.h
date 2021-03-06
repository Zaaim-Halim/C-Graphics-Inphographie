

int menu()
{
	int choix;
	printf("\n    MINI-PROJET D'INPHOGRAPHIE : ZAAIM HALIM");
	printf("\n====================================================");
	printf("\n1-> Line par la méthode de BRESENHAM : y = ax + b ");
	printf("\n2-> Line par la méthode de POLYNOMIALE : y = ax + b");
	printf("\n3-> Cercle par la méthode de BRESENHAM : ");
	printf("\n4-> Cercle par la méthode TRIGONOMETRIQUE : ");
	printf("\n5-> Cercle par la méthode POLYNOMIALE : ");
	printf("\n6-> Ellipse par la méthode POLINOMIALE : ");
	printf("\n7-> Ellipse par la méthode TRIGONOMETRIQUE");
	printf("\n8-> Ellipse par la méthode BRESENHAM : ");
	printf("\n9-> Horloge : ");
	printf("\n10-> Pondule : ");
	printf("\n11-> Quiter : ");
	printf("\n====================================================");
	printf("\n\tTapez votre choix : ");
	scanf("%d",&choix);
	return choix;
}
