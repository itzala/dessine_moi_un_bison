// #include <stdlib.h>
// #include <stdio.h>
// #include <cairo.h>
// #include <cairo-pdf.h>

// #include "surface.h"

// #define MAX_CHEMINS 50

// struct surface
// {
// 	cairo_surface_t* espace;
// 	cairo_t contexte;
// 	Chemin* liste_chemins;
// 	int nb_chemins;
// 	int nb_chemins_max;
// };

// Surface creer_surface(char* filename, int largeur, int longueur)
// {
// 	s = malloc(sizeof(struct surface));

// 	s->espace = cairo_pdf_surface_create(filename, largeur, longueur);
// 	s->contexte = cairo_create(s->espace);
// 	s->nb_chemins = 0;
// 	s->nb_chemins_max = MAX_CHEMINS;
	
// 	return s;
// }

// Surface ajouter_chemin(Surface s, Chemin c)
// {
// 	if (s->nb_chemins >= s->nb_chemins_max)
// 	{
// 		s->nb_chemins_max *= 2;
// 		s->liste_chemins = realloc(s->liste_chemins, sizeof(Chemin) * s->nb_chemins_max);
// 	}

// 	s->liste_chemins[s->nb_chemins] = c;
// 	s->nb_chemins++;
	
// 	return s;
// }

// Surface detruire_surface(Surface s)
// {
// 	cairo_destroy(s->contexte);
// 	cairo_surface_destroy(s->espace);
// 	free(s);
// }

// Surface dessiner_surface(Surface s)
// {
// 	for (int i = 0; i < s->nb_chemins; i++)
// 	{
// 		dessiner_chemin(s->liste_chemins[i] , s->contexte);
// 	}

// 	return s;
// }