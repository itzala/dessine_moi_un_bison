#include "image.h"

struct image
{
	ListeChemins tab;
};

Image creer_image()
{
	Image img = (Image) malloc(sizeof(struct image));
	img->tab = creer_liste_chemins();
	
	return img;
}

Image clone_image(Image img_src)
{
	Image clone = creer_image();
	clone->tab = clone_liste_chemins(img_src->tab);
	return clone;
}

void detruire_image(Image img)
{
	detruire_liste_chemins(img->tab);
	free(img);
}

ListeChemins get_chemins_image(Image img)
{
	return img->tab;
}

Chemin get_chemin_tete_image(Image img)
{	
	return get_chemin_tete(img->tab);
}

Chemin get_chemin_indice_to_image(Image img, int indice)
{	
	return get_chemin_indice(img->tab, indice);
}

int get_nb_chemins_image(Image img){
	return get_nb_chemins_liste(img->tab);
}

Image ajouter_chemin_image(Image img, Chemin c)
{
	ajouter_chemin_liste(img->tab, c);	
	return img;
}

void imageToString(Image img)
{
	listeCheminsToString(img->tab);
}