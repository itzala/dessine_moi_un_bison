#include "liste_points.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, y, nb;
	if(argc < 2){
		x = 1;
		y = 1;
		nb = 10;
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
	Point p1 = creer_point(x, y);

	ListePoints lp = creer_liste_points();
	for(int i=0 ; i<nb ; i++){
		liste_points_ajouterPoint(lp, p1);
		detruire_point(p1);
		x *= 2;
		y *= 2;
		p1 = creer_point(x,y);
	}
	printf("%s\n", listePointsToString(lp));
	liste_points_supprimer_tete(lp);
	printf("%s\n", listePointsToString(lp));
	liste_points_supprimer_point(lp, p1);
	printf("%s\n", listePointsToString(lp));
	detruire_liste_points(lp);
	return EXIT_SUCCESS;
}