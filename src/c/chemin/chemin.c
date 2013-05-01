#include "chemin.h"

struct chemin
{
	ListePoints tab;
	double epaisseur;
	int couleur;
};

Chemin creer_chemin(double epaisseur, int couleur){
	Chemin c = (Chemin) malloc(sizeof(struct chemin));
	c->tab = creer_liste_points();
	c->epaisseur = epaisseur;
	c->couleur = couleur;
	return c;
}

void detruire_chemin(Chemin c){
	detruire_liste_points(c->tab);
	free(c);
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




Chemin ajouter_point_chemin(Chemin c, Point p){
	ajouter_point_liste(c->tab, p);
	return c;
}


Chemin clone(Chemin c){
	Chemin copy = creer_chemin(get_epaisseur(c), get_couleur(c));
	// set_points(Chemin c, Point* l);
	return copy;
}

char* toStringChemin(Chemin c){
	char* buffer = malloc(sizeof(char)*50);
	sprintf(buffer, "Chemin : epaisseur=%d, couleur=%d", (int) get_epaisseur(c), get_couleur(c));
	return buffer;
}