#ifndef LISTE_IMAGES_H
#define LISTE_IMAGES_H

#include "image.h"
#include "liste.h"

typedef struct liste_images* ListeImages;

ListeImages creer_liste_images();
void detruire_liste_images(ListeImages li);

bool est_vide_liste_images(ListeImages li);

ListeImages ajouter_image_liste(ListeImages li, Image img);
Image get_image_indice(ListeImages li, int indice);
Image get_image_tete(ListeImages li);
int get_nb_images(ListeImages li);
void dessiner_liste_images(ListeImages li, cairo_t * contexte);
void listeImagesToString(ListeImages li);

#endif