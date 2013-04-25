#ifndef _DRAW_H_
#define _DRAW_H_

typedef surface* Surface;

Surface creer_surface(char* filename, int largeur, int longueur);
Surface detruire_surface(Surface s);
Surface add_point(Surface s, Cartesien p);
Surface dessiner(Surface s);

#endif