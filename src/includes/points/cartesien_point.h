#ifndef CARTESIEN_POINT_H
#define CARTESIEN_POINT_H

#include <stdlib.h>

typedef struct cartesien * Cartesien;


Cartesien creer_cartesien(double abscisse, double ordonnee);
void detruire_cartesien(Cartesien p);

Cartesien set_abscisse_cartesien(Cartesien p, double abscisse);
Cartesien set_ordonnee_cartesien(Cartesien p, double ordonnee);
double get_abscisse_cartesien(Cartesien p);
double get_ordonnee_cartesien(Cartesien p);

#endif
