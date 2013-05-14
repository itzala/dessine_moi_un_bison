#ifndef DESSINE_MOI_UN_BISON_H
#define DESSINE_MOI_UN_BISON_H

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

#include "y.tab.h"
#include "surface.h"
#include "variable.h"
#include "liste_variables.h"

extern FILE *yyin;
extern int yyparse();

double epaisseur;
int couleur;
int est_premier_point_chemin;
bool est_dans_image;
Chemin c;
ListeImages li;
ListeVariables lv;
Surface s;
void* value;
char* valeur;

Point dub_creation_point(double x, double y, int sep);
Chemin dub_creation_chemin(bool fill);
Image dub_creation_image();
Chemin dub_ajout_point_chemin(Point p);
Image dub_ajout_chemin_image();
void dub_ajout_image_surface();
void* dub_ajouter_element_variable(char* nom);
void error();
void yyerror (char const *s);

#endif