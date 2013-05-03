#include "liste_images.h"


Image creer_image_tests(int argc, const char** argv)
{
	Image img = NULL;

	
	
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
		ajouter_image(li, img);
		detruire_image(img);
	}

	detruire_liste_images(li);
	return EXIT_SUCCESS;
}