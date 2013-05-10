#include <cairo-pdf.h>
#include "surface.h"

struct surface
{
	cairo_t* contexte;
	ListeImages tab;	
};

Surface creer_surface(cairo_t* contexte)
{
	if (contexte != NULL)
	{
		Surface s = malloc(sizeof(struct surface));		
		s->contexte = contexte;
		s->tab = creer_liste_images();
		return s;
	}
	else
	{
		printf("Erreur ! Vous n'avez pas renseigné le contexte sur lequel dessiner\n");
		exit(1);
		return NULL;
	}
}

Surface ajouter_image_surface(Surface s, Image img)
{
	ajouter_image_liste(s->tab, img);
	return s;
}

Image get_image_en_tete_surface(Surface s)
{
	return get_image_tete(s->tab);
}

Image get_image_indice_surface(Surface s, int indice)
{
	return get_image_indice(s->tab, indice);
}

void detruire_surface(Surface s)
{
	detruire_liste_images(s->tab);
	free(s);
}

void surfaceToString(Surface s)
{
	listeImagesToString(s->tab);
}

Surface dessiner_surface(Surface s)
{
	dessiner_liste_images(s->tab, s->contexte);
	return s;
}