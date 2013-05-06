#ifndef IMAGE_H
#define IMAGE_H

#include "liste_chemins.h"

typedef struct image* Image;

Image creer_image();
Image clone_image(Image img_src);
void detruire_image(Image img);

ListeChemins get_chemins_image(Image img);
Chemin get_chemin_indice_to_image(Image img, int indice);
Chemin get_chemin_tete_image(Image img);
int get_nb_chemins_image(Image img);


Image ajouter_chemin_image(Image img, Chemin c);

void imageToString(Image img);
void dessiner_image(Image img, cairo_t * contexte);

#endif