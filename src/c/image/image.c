// #include "image.h"

// struct image
// {
// 	ListeChemins tab;	
// };

// Image creer_image()
// {
// 	Image img = (Image) malloc(sizeof(struct image));
// 	img->tab = creer_liste_chemins();
	
// 	return img;
// }

// Image clone_image(Image img_src)
// {
// 	Image clone = (Image) malloc(sizeof(struct image));
// 	clone->tab = clone_liste_chemins(img->tab);

// 	return clone;
// }

// void detruire_image(Image img)
// {
// 	detruire_liste_chemins(img->tab);
// 	free(img);
// }

// ListeChemins get_chemins(Image img)
// {
// 	return img->tab;
// }

// Chemin get_chemin_tete(Image img)
// {	
// 	return est_vide_liste_chemins(img->tab) ? NULL : img->tab[0];
// }

// Chemin get_chemin_indice_to_image(Image img, int indice)
// {	
// 	return get_chemin_indice(img->tab, indice);
// }

// Image ajouter_chemin(Image img, Chemin c)
// {
// 	ajouter_chemin_liste(img->tab, c);	
// 	return img;
// }

// void imageToString(Image img)
// {
// 	listeCheminsToString(img->tab);
// }