#include <stdlib.h>
#include <stdio.h>
#include <cairo.h>
#include <cairo-pdf.h>

#include "trait.h"

struct trait
{
	Cartesien origine;
	Cartesien fin;
	float epaisseur;
};

Trait creer_trait(Cartesien origine, Cartesien fin, float epaisseur)
{
	Trait t = malloc(sizeof(struct trait));
	t->origine = origine;
	t->fin = fin;
	t->epaisseur = epaisseur;
	return t;
}

Cartesien get_origine(Trait t)
{
	return t->origine;
}

Cartesien get_fin(Trait t)
{
	return t->fin;
}

float get_epaisseur(Trait t)
{
	return t->epaisseur;
}

Trait detruire_trait(Trait t)
{	
	free(t);
}

Trait dessiner_trait(Trait t, cairo_t contexte, int first_trait)
{
	Cartesien point = t->get_origine();

	if (first_trait < 1)	
		cairo_move_to(contexte, point->get_abscisse(), point->get_ordonnee());	
	else
		cairo_line_to(contexte, point->get_abscisse(), point->get_ordonnee());	

	point = t->get_fin();
	cairo_line_to(contexte, point->get_abscisse(), point->get_ordonnee());	
	cairo_set_line_width(contexte, t->get_epaisseur());
	cairo_stroke(contexte);

	return t;
}