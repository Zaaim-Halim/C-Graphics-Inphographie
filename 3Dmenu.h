

int _3Dmenu()
{
	int choix;
	printf("\n  MINI-PROJET D'INPHOGRAPHIE : ZAAIM HALIM");
	printf("\n===============================================");
	printf("\n1-> Translation :");
	printf("\n2-> Rotation :");
	printf("\n3-> Projection en Perspective :");
	printf("\n4-> Perspective plus Translation :");
	printf("\n5-> projection Cabinet :");
	printf("\n6-> Translation plus Rotation :");
	printf("\n7-> Perspective, Translation et Rotation :");
    printf("\n8-> symetrie parapport XY, YZ... :");
    printf("\n9-> cylindre:");
	printf("\n10-> Quitter :");
	printf("\n===============================================");
	printf("\n\tTappez votre choix : ");
	scanf("%d",&choix);
	return choix;
}
