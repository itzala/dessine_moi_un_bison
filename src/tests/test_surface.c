#include "surface.h"

Chemin creer_chemin_test(int argc, char** argv){	
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
	return c1;
}

Image creer_image_test(int argc, char** argv){
	int nb_chemins;
	if(argc < 2){
		nb_chemins = 1;
	}
	else{
		nb_chemins = argv[6];
	}
	Image img = creer_image();
	argc -= 1;
	for(int i=0 ; i<nb_chemins ; i++){
		ajouter_chemin(img, creer_chemin_test(argc, argv));
	}
	return img;
}


int main(int argc, char const *argv[])
{
	int nb_images;
	char* contexte;
	if (argc < 2)
	{
		nb_images = 1;
		contexte = "PDF";
	}
	else if (argc == 9)
	{
		nb_images = atoi(argv[7]);
		contexte = "PDF";
		argc -= 2;
	}
	else{
		printf("Erreur : nombre de paramètres invalide\n");
		return EXIT_FAILURE;
	}
	Surface surf = creer_surface(contexte);
	for(int i=0 ; i< nb_images ; i++){
		ajouter_image(surf, creer_image_test(argc, argv));
	}
	surfaceToString(surf);
	dessiner_surface(surf);

	detruire_surface(surf);
	return 0;
}