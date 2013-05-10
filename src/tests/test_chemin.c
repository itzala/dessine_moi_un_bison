#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "chemin.h"

int main(int argc, char const *argv[])
{
	int x, y, nb, largeur, couleur;
	if(argc < 2){
		x = 1;
		y = 1;
		nb = 10;
		largeur = 1;
		couleur = 0;
	}
	else if(argc == 6){
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		nb = atoi(argv[3]);
		largeur = atoi(argv[4]);
		couleur = atoi(argv[5]);
	}
	else{
		printf("Erreur : nombre de paramètres invalide\n");
		return EXIT_FAILURE;
	}

	Chemin c1 = creer_chemin(largeur, couleur, NULL, false);
	Point p1 = creer_point(x, y);

	for(int i=0 ; i<nb ; i++){
		ajouter_point_chemin(c1, p1);
		detruire_point(p1);
		x *= 2;
		y *= 2;
		p1 = creer_point(x,y);
	}
	printf("%s\n", toStringChemin(c1));
	printf("%s\n", toStringChemin(clone(c1)));



	
	detruire_chemin(c1);
	return 0;
}
