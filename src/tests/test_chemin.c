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
	ListePoints lp = creer_liste_points();

	Point p1 = creer_point(x, y);

	ListePoints lp = creer_liste_points();
	for(int i=0 ; i<nb ; i++){
		liste_points_ajouterPoint(lp, p1);
		detruire_point(p1);
		x *= 2;
		y *= 2;
		p1 = creer_point(x,y);
	}
	Chemin c1 = creer_chemin(lp, largeur, couleur);
	cheminToString(c1);
	detruire_chemin(c1);
	detruire_liste_points(lp);
	return 0;
}