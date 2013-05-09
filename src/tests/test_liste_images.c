#include "liste_images.h"


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

Image creer_image_tests(int argc, const char** argv)
{
	int nb;
	if(argc < 2){
		nb = 2;
	}
	else if (argc==7)
	{
		nb = atoi(argv[6]);
	}
	Image img = creer_image(false);
	Chemin c = NULL;
	for(int i=0 ; i<nb ; i++){
		c = creer_chemin_test(argc-1, argv, i+1);
		ajouter_chemin_image(img, c);
		detruire_chemin(c);
	}

	return img;
}

int main(int argc, char const *argv[])
{
	int nb;
	if(argc < 2){
		nb = 12;
	}
	else if(argc == 8){
		nb = atoi(argv[7]);
	}
	else{
		printf("Erreur : nombre de paramètres invalide\n");
		return EXIT_FAILURE;
	}

	ListeImages li = creer_liste_images();
	Image img = NULL;
	for (int i = 0; i < nb; i++)
	{
		img = creer_image_tests(argc -1 , argv);
		ajouter_image_liste(li, img);
		detruire_image(img);
	}
	listeImagesToString(li);
	detruire_liste_images(li);
	return EXIT_SUCCESS;
}