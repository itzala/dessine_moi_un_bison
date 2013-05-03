#include "image.h"

Chemin creer_chemin_test(int argc, const char** argv){	
	int x, y, nb, largeur, couleur;
	if(argc < 2){
		x = 1;
		y = 1;
		nb = 10;
		largeur = 1;
		couleur = 0;
	}
	else{
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		nb = atoi(argv[3]);
		largeur = atoi(argv[4]);
		couleur = atoi(argv[5]);
	}
	
	Point p1 = NULL;
	ListePoints lp = creer_liste_points();
	
	for(int i=0 ; i<nb ; i++){
		p1 = creer_point(x,y);
		ajouter_point_liste(lp, p1);
		detruire_point(p1);
		x *= 2;
		y *= 2;
	}
	Chemin c1 = creer_chemin(largeur, couleur, lp);
	return c1;
}

int main(int argc, char const *argv[])
{
	int nb_chemins;
	if(argc < 2){
		nb_chemins = 1;
	}
	else if(argc == 7){
		nb_chemins = atoi(argv[6]);
		argc -= 1;
	}
	else{
		printf("Erreur : nombre de paramètres invalide\n");
		return EXIT_FAILURE;
	}
	Image img = creer_image();
	imageToString(img);
	Chemin c1 = NULL;
	for(int i=0 ; i<nb_chemins ; i++){
		printf("creation chemin n°%d\n", i);
		c1 = creer_chemin_test(argc, argv);
		ajouter_chemin_image(img, c1);
		detruire_chemin(c1);
	}
	imageToString(img);
	Image clone = clone_image(img);
	printf("\n\nAffichage du clone\n");
	imageToString(clone);

	detruire_image(img);
	detruire_image(clone);
	
	return EXIT_SUCCESS;
}