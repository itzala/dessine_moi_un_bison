#include "point.h"

struct point
{
	Cartesien p;
	bool polaire;
};

Point creer_point(double x, double y){
	Point p = (Point) malloc(sizeof(struct point));
	p->polaire = false;
	p->p = creer_cartesien(x,y);
	return p;
}

Point creer_point_polaire(double mod, double ang){
	Point p = (Point) malloc(sizeof(struct point));
	p->polaire = true;
	double x = mod * cos(ang);
	double y = mod * sin(ang);
	p->p = creer_cartesien(x, y);
	return p;
}

Point clone_point(Point p){
	return creer_point(get_abscisse(p), get_ordonnee(p));

}

void detruire_point(Point p){
	detruire_cartesien(p->p);
	free(p);
}

double get_abscisse(Point p){
	return get_abscisse_cartesien(p->p);
}

double get_ordonnee(Point p){
	return get_ordonnee_cartesien(p->p);
}

Point set_abscisse(Point p, double x){
	set_abscisse_cartesien(p->p, x);
	return p;
}

Point set_ordonnee(Point p, double y){
	set_ordonnee_cartesien(p->p, y);
	return p;
}


/* Attention : la fonction modifie la base (base += ajout) */
Point somme_point(Point base, Point ajout){
	set_abscisse(base, get_abscisse(base) + get_abscisse(ajout));
	set_ordonnee(base, get_ordonnee(base) + get_ordonnee(ajout));
	return base;
}



Cartesien polaire_vers_cartesien(Polaire p){
	double mod = get_module_polaire(p);
	double ang = get_angle_polaire(p);
	double x = mod * cos(ang);
	double y = mod * sin(ang);
	return creer_cartesien(x,y);
}


Polaire cartesien_vers_polaire(Cartesien p){
	double x = get_abscisse_cartesien(p);
	double y = get_ordonnee_cartesien(p);
	double sqrt_x2_y2 = sqrt((x*x)+(y*y));
	return creer_polaire(2 * atan(y / (x + sqrt_x2_y2)),
						sqrt_x2_y2);
}

Polaire point_vers_polaire(Point p){
	return cartesien_vers_polaire(p->p);
}

char* toStringPoint(Point p){
	return toStringCartesien(p->p);
}

char* toStringCartesien(Cartesien p){
	char* res = malloc(sizeof(char)*32);
	sprintf(res, 
		"(%f , %f)", 
		get_abscisse_cartesien(p), get_ordonnee_cartesien(p));
	return res;
}

char* toStringPolaire(Polaire p){
	char* res = malloc(sizeof(char)*32);
	sprintf(res, 
		"(%f : %f)", 
		get_module_polaire(p), get_angle_polaire(p));
	return res;
}