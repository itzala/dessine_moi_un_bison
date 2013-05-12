#ifndef LISTE_POINTS_H
#define LISTE_POINTS_H
#include "point.h"
#include "liste.h"
#include <stdbool.h>


typedef struct liste_points* ListePoints;

ListePoints creer_liste_points();
void detruire_liste_points(ListePoints l);
ListePoints clone_liste_points(ListePoints l);

Point get_point_tete(ListePoints l);
Point get_point_queue(ListePoints l);
Point get_point_indice(ListePoints l, int indice);
Point* get_points(ListePoints l);
int get_nb_points(ListePoints l);

ListePoints ajouter_point_liste(ListePoints l, Point p);

bool est_vide_liste_points(ListePoints l);

char* listePointsToString(ListePoints l);
#endif