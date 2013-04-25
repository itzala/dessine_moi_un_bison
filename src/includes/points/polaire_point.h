#ifndef POLAIRE_POIN_H
#define POLAIRE_POIN_H

#include "cartesien_point.h"
#include <math.h>


typedef struct polaire * Polaire;


Polaire creer_polaire(double angle, double module);
void detruire_polaire(Polaire p);

Polaire set_angle_polaire(Polaire p, double angle);
Polaire set_module_polaire(Polaire p, double module);
double get_angle_polaire(Polaire p);
double get_module_polaire(Polaire p);

Polaire cartesien_vers_polaire(Cartesien p);
#endif
