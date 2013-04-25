#include <stdlib.h>
#include <stdio.h>
#include <cairo.h>
#include <cairo-pdf.h>

#include "draw.h"
#include "point_cartesien.h"

#define MAX_POINTS 50

struct surface
{
	cairo_surface_t* space;
	cairo_t contexte;
	Cartesien* liste_points;
	int nb_points;
};


Surface creer_surface(char* filename, int largeur, int longueur)
{
	s = malloc(sizeof(struct surface));

	s->space = cairo_pdf_surface_create(filename, largeur, longueur);
	s->contexte = cairo_create(s->space);
	s->liste_points = malloc(sizeof(Cartesien*))
	s->nb_points = 0;
	return s;
}

Surface detruire_surface(Surface s)
{
	cairo_destroy(s->contexte);
	cairo_surface_destroy(s->space);
	free(s->liste_points);
	free(s);
}

Surface add_point(Surface s, Cartesien p)
{
	if (s->nb_points < MAX_POINTS)
	{
		s->liste_points[s->nb_points] = p;
		s->nb_points++;
	}

	return s;
}

Surface dessiner(Surface s)
{
	if (s->nb_points > 0)
	{
		Cartesien point = s->liste_points[0];
		cairo_move_to(s->contexte, point->get_abscisse_cartesien(), point->get_ordonnee_cartesien())

		for (int i = 1; i s->nb_points; i++)
		{
			point = s->liste_points[i];
			cairo_line_to(s->contexte, point->get_abscisse_cartesien(), point->get_ordonnee_cartesien())
			cairo_stroke(s->contexte);
		}		
	}

	return s;
}