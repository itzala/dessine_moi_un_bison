// #include "liste_images.h"

// struct liste_images
// {
// 	Image* tab;
// 	int nb;
// 	int max;
// };

// void rallonger(ListeImages li)
// {
// 	li->max *= 2;
// 	li->tab = (Image*)realloc(l->tab, sizeof(Image)*l->max);
// }

// bool est_pleine(ListeImages li)
// {
// 	return li->nb >= li->max;
// }

// bool est_vide_liste_images(ListeImages li)
// {
// 	return li->nb < 1;
// }

// ListeImages creer_liste_images()
// {
// 	ListeImages li = (ListeImages) malloc(sizeof(struct liste_images));
// 	li->tab = (Image*) malloc(sizeof(Image)*li->max);
// 	li->nb = 0;
// 	li->max = MAX_TAILLE;
// 	return li;
// }

// void detuire_liste_images(ListeImages li)
// {
// 	for (int i = 0; i < li->nb; i++)
// 	{
// 		detruire_image(li->tab[i]);
// 	}

// 	free(li);
// }

// ListeImages ajouter_image(ListeImages li, Image img)
// {
// 	if (est_pleine(li))
// 	{
// 		rallonger(li);
// 	}

// 	l->tab[l->nb] = clone_image(img);
// 	l->nb++;
// }

// void listeImagesToString(ListeImages li)
// {
// 	for (int i = 0; i < li->nb; i++)
// 	{
// 		imageToString(li->tab[i]);
// 	}
// }