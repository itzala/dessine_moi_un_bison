#include "liste_images.h"

ListeChemins creer_liste_chemins_tests(int argc, char** argv)
{
	ListeChemins lc = creer_liste_chemins();

	return lc;
}

Image creer_image_tests(int argc, char** argv)
{
	Image img = creer_image();
	ListeChemins lc = creer_liste_chemins_tests(argc, argv);
	ajouter_chemin(img, lc);
	detruire_liste_chemins(lc);

	return img;
}

int main(int argc, char const *argv[])
{
	int nb;
	if(argc < 2){
		nb = 12;
	}
	else if(argc == 4){
		nb = atoi(argv[3]);
	}
	else{
		printf("Erreur : nombre de paramètres invalide\n");
		return EXIT_FAILURE;
	}

	ListeImages li = creer_liste_images();
	Image img = NULL;

	for (int i = 0; i < nb; i++)
	{
		img = creer_image_tests(argc, argv);
		ajouter_image(li, img);
		detruire_image(img);
	}

	detruire_liste_images(li);
	return EXIT_SUCCESS;
}