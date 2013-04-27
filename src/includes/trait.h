#ifndef _TRAIT_H_
#define _TRAIT_H_

#include "cartesien_point.h"

typedef trait* Trait;

Trait creer_segment(Cartesien origine, Cartesien fin, int epaisseur);
Trait detruire_segment(Trait t);

Cartesien get_origine(Trait t);
Cartesien get_fin(Trait t);
float get_epaisseur(Trait t);

Trait dessiner_trait(Trait t, cairo_t contexte);

#endif