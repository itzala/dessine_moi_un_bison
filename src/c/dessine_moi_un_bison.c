#include "dessine_moi_un_bison.h"

Point dub_creation_point(double x, double y, int sep){
	Point p;
	if (sep){
		p = creer_point_polaire(x, y);
	}
	else {
		p = creer_point(x, y);
	}
	return p;
}

Chemin dub_creation_chemin(bool fill){
	c = creer_chemin_vide(epaisseur, couleur, fill); 
	return c;
}

Image dub_creation_image(){
	Image i = creer_image();
	ajouter_image_liste(li, i);
	detruire_image(i);
	return get_image_queue(li);
}

Chemin dub_ajout_point_chemin(Point p){
	ajouter_point_chemin(c, p);
	// detruire_point(p);
	return c;
}

Image dub_ajout_chemin_image(){
	ajouter_chemin_image(get_image_queue(li), c);
	detruire_chemin(c);
	c=NULL;
	return get_image_queue(li);
}

void dub_ajout_image_surface(){
	ajouter_image_surface(s, get_image_queue(li));
	supprimer_image_queue_liste(li);
}

void* dub_ajouter_element_variable(char* nom){
	Variable v = get_variable_par_nom(lv, nom);
	if (v != NULL)
	{
		if (!strcmp(get_type_variable(v), "image"))
		{
			dub_ajout_image_surface();
		}
		else if (!strcmp(get_type_variable(v), "chemin"))
		{
			dub_ajout_chemin_image();
		}
		else if (!strcmp(get_type_variable(v), "point"))
		{
			dub_ajout_point_chemin(get_value_variable(v));
		}
		return get_value_variable(v);

	}
	return NULL;
}



void error(){
	yyerror("Erreur Syntaxique");
}

void
yyerror (char const *s)
{
	fprintf (stderr, "%s\n", s);
	exit(EXIT_FAILURE);
}


int main(int argc, char const *argv[])
{
	if (argc != 6)
	{
		printf("Nombre d'arguments incorrect\n");
		return EXIT_FAILURE;
	}
	char* source = malloc(sizeof(char)*255);
	char* filename = malloc(sizeof(char)*255);
	char* extension = malloc(sizeof(char)*3);
	strcpy(source, argv[1]);
	strcpy(filename, argv[2]);
	strcpy(extension, argv[3]);

	int longueur = atoi(argv[4]);
	int largeur = atoi(argv[5]);

	cairo_surface_t *surface = creer_cairo_surface(extension, filename, longueur, largeur);
	cairo_t *cr = creer_cairo_contexte(surface, NULL);

	epaisseur = 1.0;
	couleur = 1;	
	c = NULL;
	li = creer_liste_images();
	lv = creer_liste_variables();
	s = creer_surface(cr);
	FILE *fichier_source = fopen(source, "r");
	if (!fichier_source) {
		printf("Le fichier %s est innaccessible\n", source);
		return EXIT_FAILURE;
	}
	yyin = fichier_source;

	if(!yyparse())
		dessiner_surface(s);

	detruire_surface(s);
	detruire_liste_variables(lv);
	detruire_liste_images(li);
	cairo_destroy(cr);
	cairo_surface_destroy(surface);

	return EXIT_SUCCESS;
}