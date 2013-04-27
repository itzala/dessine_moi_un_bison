#ifndef _CHEMIN_H_
#define _CHEMIN_H_

#include "cartesien_point.h"

typedef chemin* Chemin;

Chemin creer_chemin();
Chemin detruire_chemin(Chemin c);
Chemin ajouter_trait(Chemin c, Trait t);
Chemin dessiner_chemin(Chemin c, cairo_t contexte);

#endif