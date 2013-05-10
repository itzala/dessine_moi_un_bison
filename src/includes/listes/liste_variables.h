#ifndef _LISTE_VARIABLES_H_
#define _LISTE_VARIABLES_H_

#include "variable.h"

typedef struct liste_variables* ListeVariables;

ListeVariables creer_liste_variables();
void detruire_liste_variables(ListeVariables l);
ListeVariables clone_liste_variables(ListeVariables l);

Variable get_variable_tete(ListeVariables l);
Variable get_variable_indice(ListeVariables l, int indice);
Variable get_variable_par_nom(ListeVariables l, char* nom);
int get_nb_variables(ListeVariables l);

ListeVariables ajouter_variable_liste(ListeVariables l, Variable p);

bool est_vide_liste_variables(ListeVariables l);
bool est_dans_liste(ListeVariables l, char* nom);

char* listeVariablesToString(ListeVariables l);

#endif