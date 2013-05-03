#include "liste_points.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, y, nb;
	if(argc < 2){
		x = 1;
		y = 1;
		nb = 12;
	}
	else if(argc == 4){
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		nb = atoi(argv[3]);
	}
	else{
		printf("Erreur : nombre de paramètres invalide\n");
		return EXIT_FAILURE;
	}

	ListePoints lp = creer_liste_points();
	Point p = NULL;
	for(int i=0 ; i<nb ; i++){
		p = creer_point(x, y);
		ajouter_point_liste(lp, p);
		x *= 2;
		y *= 2;
		detruire_point(p);
	}
	printf("%s\n", listePointsToString(lp));
	detruire_liste_points(lp);
	return EXIT_SUCCESS;
}