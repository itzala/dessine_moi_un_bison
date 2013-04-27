#ifndef LISTE_IMAGES_H
#define LISTE_IMAGES_H

#include "image.h"

typedef struct liste_images* ListeImages;

ListeImages creer_liste_images();
void detuire_liste_images(ListeImages li);

bool est_vide_liste_images(ListeImages li);

ListeImages ajouter_image(ListeImages li, Image img);
Image get_image_indice(ListeImages li, int indice);
Image get_image_tete(ListeImages li);

void listeImagesToString(ListeImages li);

#endif