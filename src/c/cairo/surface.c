#include <cairo-pdf.h>
#include "surface.h"

struct surface
{
	cairo_surface_t* espace;
	cairo_t* contexte;
	ListeImages tab;	
};

Surface creer_surface(char* filename, int largeur, int longueur, char* type_surface)
{
	printf("Fichier à générer : %s (Attention, dans build)\n", filename);

	Surface s = malloc(sizeof(struct surface));		
	if (!strcmp(type_surface, "pdf"))
		s->espace = cairo_pdf_surface_create(filename, largeur, longueur);
	else
	{
		printf("Type non géré pour l'instant... Seul le pdf est traité");
		exit(EXIT_FAILURE);			
	}

	s->contexte = cairo_create(s->espace);
	s->tab = creer_liste_images();
	
	return s;
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
	cairo_destroy(s->contexte);
	cairo_surface_destroy(s->espace);
	detruire_liste_images(s->tab);
	free(s);
}

void surfaceToString(Surface s)
{

}

Surface dessiner_surface(Surface s)
{
	//dessiner_liste_images(s->tab, s->contexte);
	cairo_move_to(s->contexte, 1, 1);
	cairo_line_to(s->contexte,2, 5);
	cairo_set_line_width(s->contexte, 0.5);	
	cairo_stroke(s->contexte);

	return s;
}