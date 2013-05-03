#ifndef _CHEMIN_H_
#define _CHEMIN_H_

#include <cairo.h>

#include "liste_points.h"

typedef struct chemin* Chemin;

Chemin creer_chemin(double epaisseur, int couleur, ListePoints l);
Chemin creer_chemin_vide(double epaisseur, int couleur);
void detruire_chemin(Chemin c);

Point* get_points_chemin(Chemin c);
Point get_point_indice_chemin(Chemin c, int indice);
double get_epaisseur(Chemin c);
int get_couleur(Chemin c);
int get_nb_points_chemin(Chemin c);

// Chemin set_points(Chemin c, Point* l);
Chemin set_epaisseur(Chemin c, double epaisseur);
Chemin set_couleur(Chemin c, int couleur);

Chemin ajouter_point_chemin(Chemin c, Point p);

Chemin clone(Chemin c);
char* toStringChemin(Chemin c);
#endif