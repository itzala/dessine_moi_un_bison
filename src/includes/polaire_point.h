#ifndef POLAIRE_POINT_H
#define POLAIRE_POINT_H

#include <stdlib.h>

typedef struct polaire * Polaire;


Polaire creer_polaire(double angle, double module);
void detruire_polaire(Polaire p);

Polaire set_angle_polaire(Polaire p, double angle);
Polaire set_module_polaire(Polaire p, double module);
double get_angle_polaire(Polaire p);
double get_module_polaire(Polaire p);

#endif
