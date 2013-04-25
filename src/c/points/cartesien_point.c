#include "cartesien_point.h"

struct cartesien
{
	double x;
	double y;
};


Cartesien creer_cartesien(double abscisse, double ordonnee){
	Cartesien p = malloc(sizeof(struct cartesien));
	set_abscisse_cartesien(p, abscisse);
	set_ordonnee_cartesien(p,abscisse);
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

Cartesien polaire_vers_cartesien(Polaire p){
	double mod = get_module_polaire(p);
	double ang = get_angle_polaire(p);
	double x = mod * cos(ang);
	double y = mod * sin(ang);
	return creer_cartesien(x,y);
}
