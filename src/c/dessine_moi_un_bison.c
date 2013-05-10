#include "dessine_moi_un_bison.h"

Point dub_creation_point(double x, double y, int sep){
	Point p;
	if(x < 0 || y < 0){
		error();
		p = NULL;
	}
	else{ 
		if (sep){
			p = creer_point_polaire(x, y);
		}
		else {
			p = creer_point(x, y);
		}
		if (est_premier_point_chemin){
			premier_point_chemin = clone_point(p);
			est_premier_point_chemin = 0;
		}
	}
	return p;
}

Chemin dub_creation_chemin(bool fill){
	Chemin tmp = creer_chemin_vide(epaisseur, couleur, fill); 
	c = tmp; 
	est_premier_point_chemin=1;
	return c;
}

void dub_creation_image(){
	Image i = creer_image();
	ajouter_image_liste(li, i);
	detruire_image(i);
}

void dub_ajout_point_chemin(Point p){
	ajouter_point_chemin(c, p);
	detruire_point(p);
}

void dub_ajout_chemin_image(){
	ajouter_chemin_image(get_image_queue(li), c);
	detruire_chemin(c);
	if(! est_premier_point_chemin)
		detruire_point(premier_point_chemin);
	c=NULL;
}

void dub_ajout_image_surface(){
	ajouter_image_surface(s, get_image_queue(li));
	supprimer_image_queue_liste(li);
}



void error(){
	yyerror("Erreur Syntaxique");
}

void
yyerror (char const *s)
{
	fprintf (stderr, "%s\n", s);
	exit(1);
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
	est_premier_point_chemin = 1;
	p = NULL;
	premier_point_chemin = NULL;
	c = NULL;
	li = creer_liste_images();
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
	cairo_destroy(cr);
	cairo_surface_destroy(surface);

	return EXIT_SUCCESS;
}