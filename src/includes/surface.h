#ifndef _SURFACE_H_
#define _SURFACE_H_


typedef surface* Surface;

Surface creer_surface(char* filename, int largeur, int longueur);
Surface detruire_surface(Surface s);
Surface dessiner_surface(Surface s);

#endif