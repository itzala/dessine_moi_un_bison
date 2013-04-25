#include "point.h"

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

char* toString(Cartesien p){
	char* res = malloc(sizeof(char)*32);
	sprintf(res, 
		"Cartesien(%f , %f)", 
		get_abscisse_cartesien(p), get_ordonnee_cartesien(p));
	return res;
}

char* toStringPolaire(Polaire p){
	char* res = malloc(sizeof(char)*32);
	sprintf(res, 
		"Polaire(%f : %f)", 
		get_module_polaire(p), get_angle_polaire(p));
	return res;
}