// #include <stdlib.h>
// #include <stdio.h>

// #include <cairo.h>
// #include <cairo-pdf.h>

// #include "segment.h"
// #include "chemin.h"

// #define MAX_TRAITS 50

// struct chemin
// {
// 	Segment* liste_traits;
// 	int nb_trait;
// };

// Chemin creer_chemin()
// {
// 	Chemin c = malloc(sizeof(struc chemin));
// 	c->nb_trait = 0;
// 	c->liste_traits = malloc(sizeof(Segment*));

// 	return c;
// }

// Chemin detruire_chemin(Chemin c)
// {
// 	free(c);
// }

// Chemin ajouter_trait(Chemin c, Trait t)
// {


// 	return c;
// }

// Chemin dessiner_chemin(Chemin c, cairo_t contexte)
// {
// 	for (int i = 0; i < c->nb_trait; i++)
// 	{
// 		dessiner_trait(c->liste_traits[i], contexte, i);
// 	}

// 	return c;
// }