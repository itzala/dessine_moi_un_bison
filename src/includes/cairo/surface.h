#ifndef _SURFACE_H_
#define _SURFACE_H_

#include "liste_images.h"
#include "util_cairo.h"

typedef struct surface* Surface;

Surface creer_surface(cairo_t* contexte);
void detruire_surface(Surface s);

Surface ajouter_image_surface(Surface s, Image img);

Image get_image_en_tete_surface(Surface s);
Image get_image_indice_surface(Surface s, int indice);

Surface dessiner_surface(Surface s);
void surfaceToString(Surface s);

#endif