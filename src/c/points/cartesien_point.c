#include "cartesien_point.h"

struct cartesien {
	double x;
	double y;
};


Cartesien creer_cartesien(double abscisse, double ordonnee){
	Cartesien p = malloc(sizeof(struct cartesien));
	set_abscisse_cartesien(p, abscisse);
	set_ordonnee_cartesien(p, ordonnee);
	return p;
}
void detruire_cartesien(Cartesien p){
	free(p);
}

Cartesien set_abscisse_cartesien(Cartesien p, double abscisse){
	p->x = abscisse;
	return p;
}

Cartesien set_ordonnee_cartesien(Cartesien p, double ordonnee){
	p->y = ordonnee;
	return p;
}

double get_abscisse_cartesien(Cartesien p){
	return p->x;
}
double get_ordonnee_cartesien(Cartesien p){
	return p->y;
}
