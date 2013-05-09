#include "liste_chemins.h"

#include <stdlib.h>
#include <stdio.h>

ListePoints creer_liste_points_test(int x, int y, int nb)
{
	Point p1 = creer_point(x, y);
	ListePoints lp = creer_liste_points();
	for(int i=0 ; i<nb ; i++){
		ajouter_point_liste(lp, p1);
		detruire_point(p1);
		x *= 2;
		y *= 2;
		p1 = creer_point(x,y);
	}
	return lp;
}

Chemin creer_chemin_test(int argc, const char** argv, int multi)
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
		x = atoi(argv[1]) * multi;
		y = atoi(argv[2]) * multi;
		nb = atoi(argv[3]);
		largeur = atoi(argv[4]);
		couleur = atoi(argv[5]);
	}

	Chemin c = creer_chemin_vide(largeur, couleur, false);
	Point p1 = creer_point(x, y);

	for(int i=0 ; i<nb ; i++){
		ajouter_point_chemin(c, p1);
		detruire_point(p1);
		x *= multi;
		y *= multi;
		p1 = creer_point(x,y);
	}

	return c;
}

int main(int argc, char const *argv[])
{
	int nb;
	if(argc < 2){
		nb = 12;
	}
	else if(argc == 7){
		nb = atoi(argv[6]);
	}
	else{
		printf("Erreur : nombre de paramètres invalide\n");
		return EXIT_FAILURE;
	}

	ListeChemins lc = creer_liste_chemins();
	Chemin c = NULL;
	for(int i=0 ; i<nb ; i++)
	{
		c = creer_chemin_test(argc, argv, (i + 1));
		ajouter_chemin_liste(lc, c);
		detruire_chemin(c);
	}
	listeCheminsToString(lc);
	ListeChemins cp = clone_liste_chemins(lc);
	listeCheminsToString(cp);
	detruire_liste_chemins(lc);
	return EXIT_SUCCESS;
}