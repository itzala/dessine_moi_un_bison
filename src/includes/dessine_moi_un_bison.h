#ifndef DESSINE_MOI_UN_BISON_H
#define DESSINE_MOI_UN_BISON_H

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

#include "y.tab.h"
#include "surface.h"

extern FILE *yyin;
extern int yyparse();

double epaisseur;
int couleur;
int est_premier_point_chemin;
Point p;
Point premier_point_chemin;
Chemin c;
ListeImages li;
Surface s;


Point dub_creation_point(double x, double y, int sep);
Chemin dub_creation_chemin(bool fill);
void dub_creation_image();
void dub_ajout_point_chemin();
void dub_ajout_chemin_image();
void dub_ajout_image_surface();
void error();
void yyerror (char const *s);

#endif