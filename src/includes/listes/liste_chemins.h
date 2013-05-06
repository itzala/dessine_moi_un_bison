#ifndef LISTE_CHEMINS_H
#define LISTE_CHEMINS_H

#include "chemin.h"
#include "liste.h"

typedef struct liste_chemins* ListeChemins;

ListeChemins creer_liste_chemins();
void detruire_liste_chemins(ListeChemins l);
ListeChemins clone_liste_chemins(ListeChemins l);

Chemin get_chemin_tete(ListeChemins l);
Chemin get_chemin_indice(ListeChemins l, int indice);
Chemin* get_chemins(ListeChemins l);
int get_nb_chemins_liste(ListeChemins l);

ListeChemins ajouter_chemin_liste(ListeChemins l, Chemin p);

bool est_vide_liste_chemins(ListeChemins l);

void listeCheminsToString(ListeChemins l);
void dessiner_liste_chemins(ListeChemins l, cairo_t * contexte);

#endif