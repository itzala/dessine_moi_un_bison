#include "chemin.h"

struct chemin
{
	ListePoints tab;
	double epaisseur;
	int couleur;
	bool fill;
};

Chemin creer_chemin_vide(double epaisseur, int couleur, bool fill){
	return creer_chemin(epaisseur, couleur, NULL, fill);
}

Chemin creer_chemin(double epaisseur, int couleur, ListePoints l, bool fill){
	Chemin c = (Chemin) malloc(sizeof(struct chemin));
	c->tab = (l == NULL ? creer_liste_points() : clone_liste_points(l));
	c->epaisseur = epaisseur;
	c->couleur = couleur;
	c->fill = fill;
	return c;
}

Chemin vider_chemin(Chemin c){
	detruire_liste_points(c->tab);
	c->tab = creer_liste_points();
	return c;
}


void detruire_chemin(Chemin c){
	detruire_liste_points(c->tab);
	free(c);
}

bool est_rempli(Chemin c){
	return c->fill;
}

ListePoints get_liste_points_chemin(Chemin c){
	return c->tab;
}

Point* get_points_chemin(Chemin c){
	return get_points(c->tab);
}

Point get_point_indice_chemin(Chemin c, int indice){
	return get_point_indice(c->tab, indice);
}

double get_epaisseur(Chemin c){
	return c->epaisseur;
}

int get_couleur(Chemin c){
	return c->couleur;
}

int get_nb_points_chemin(Chemin c){
	return get_nb_points(c->tab);
}


// Chemin set_points(Chemin c, Point* l){

// }

Chemin set_epaisseur(Chemin c, double epaisseur){
	c->epaisseur = epaisseur;
	return c;
}

Chemin set_couleur(Chemin c, int couleur){
	c->couleur = couleur;
	return c;
}

Chemin set_fill(Chemin c, bool fill){
	c->fill = fill;
	return c;
}


Chemin ajouter_point_chemin(Chemin c, Point p){
	ajouter_point_liste(c->tab, p);
	return c;
}


Chemin clone(Chemin c){
	Chemin copy = creer_chemin(get_epaisseur(c), get_couleur(c), get_liste_points_chemin(c), est_rempli(c));
	// set_points(Chemin c, Point* l);
	return copy;
}

char* toStringChemin(Chemin c){
	if (est_vide_liste_points(c->tab))
	{
		return "Chemin vide";
	}
	char* buffer_liste = listePointsToString(c->tab);
	char* buffer = malloc(sizeof(char)*50+strlen(buffer_liste));
	sprintf(buffer, "Chemin : epaisseur=%d, couleur=%d, liste :\n%s", (int) get_epaisseur(c), get_couleur(c), buffer_liste);
	free(buffer_liste);
	buffer = realloc(buffer, sizeof(char)*strlen(buffer));
	return buffer;
}

void dessiner_chemin(Chemin c, cairo_t * contexte)
{
	int x, y;
	Point p = get_point_tete(c->tab); 
	x = get_abscisse(p);
	y = get_ordonnee(p);
	printf("\tDessin du chemin\n");
	printf("\t\tTracé du point %d, %d\n", x, y);
	
	cairo_move_to(contexte, x, y);

	int nb_points = get_nb_points(c->tab);
	for (int i = 1; i < nb_points; i++)
	{
		p = get_point_indice(c->tab, i); 
		x = get_abscisse(p);
		y = get_ordonnee(p);
		printf("\t\tTracé du point %d, %d\n", x, y);
		cairo_line_to(contexte, x, y);
	}
	printf("\t\tActivation de l'épaisseur : %lf\n\n", c->epaisseur);
	cairo_set_line_width(contexte, c->epaisseur);
}