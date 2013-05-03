#include "liste_images.h"

struct liste_images
{
	Image* tab;
	int nb;
	int max;
};

void rallonger_liste_images(ListeImages li)
{
	li->max *= 2;
	li->tab = (Image*)realloc(li->tab, sizeof(Image)*li->max);
}

bool est_pleine_liste_images(ListeImages li)
{
	return li->nb >= li->max;
}

bool est_vide_liste_images(ListeImages li)
{
	return li->nb < 1;
}

ListeImages creer_liste_images()
{
	ListeImages li = (ListeImages) malloc(sizeof(struct liste_images));
	li->tab = (Image*) malloc(sizeof(Image)*li->max);
	li->nb = 0;
	li->max = MAX_TAILLE;
	return li;
}

void detruire_liste_images(ListeImages li)
{

	free(li->tab);
	free(li);
}

int get_nb_images(ListeImages li)
{
	return li->nb;
}

ListeImages ajouter_image(ListeImages li, Image img)
{
	if (est_pleine_liste_images(li))
	{
		rallonger_liste_images(li);
	}

	li->tab[li->nb] = clone_image(img);
	li->nb++;
	return li;
}

void listeImagesToString(ListeImages li)
{
	for (int i = 0; i < li->nb; i++)
	{
		imageToString(li->tab[i]);
	}
}