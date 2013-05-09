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
	li->tab = (Image*) realloc(li->tab, sizeof(Image) * li->max);	
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
	li->nb = 0;
	li->max = MAX_TAILLE;
	li->tab = (Image*) malloc(sizeof(Image)*li->max);
	return li;
}

void detruire_liste_images(ListeImages li)
{
	for (int i = 0; i < get_nb_images(li); ++i)
	{
		detruire_image(li->tab[i]);
	}
	free(li->tab);
	free(li);
}

int get_nb_images(ListeImages li)
{
	return li->nb;
}

ListeImages ajouter_image_liste(ListeImages li, Image img)
{
	if (est_pleine_liste_images(li))
	{
		rallonger_liste_images(li);
	}
	li->tab[li->nb] = clone_image(img);
	li->nb++;
	return li;
}

Image get_image_indice(ListeImages li, int indice)
{
	if(!est_vide_liste_images(li)){
		int nb_neg = li->nb * (-1);
		if (abs(indice) < li->nb || indice == nb_neg){
			return li->tab[(li->nb + indice)%li->nb];
		}
		printf("L'indice %d est hors limites\n", indice);
	}
	else {
		printf("La liste est vide\n");
	}
	return NULL;
}

Image get_image_tete(ListeImages li)
{
	if(!est_vide_liste_images(li))
		return li->tab[0];

	printf("La liste est vide\n");	
	return NULL;
}

Image get_image_queue(ListeImages li)
{
	if(!est_vide_liste_images(li))
		return li->tab[li->nb-1];

	printf("La liste est vide\n");	
	return NULL;

}


ListeImages supprimer_image_queue_liste(ListeImages li)
{
	if (!est_vide_liste_images(li))
	{
		detruire_image(li->tab[li->nb-1]);
		li->nb--;
	}
	return li;
}

void listeImagesToString(ListeImages li)
{
	for (int i = 0; i < li->nb; i++)
	{
		imageToString(li->tab[i]);
	}
}

void dessiner_liste_images(ListeImages li, cairo_t * contexte)
{
	for(int i = 0; i < li->nb; i++)
		dessiner_image(li->tab[i], contexte);	
}