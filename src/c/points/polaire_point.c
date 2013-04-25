#include "polaire_point.h"

struct polaire {
	double angle;
	double module;
};


Polaire creer_polaire(double angle, double module){
	Polaire p = malloc(sizeof(struct polaire));
	set_angle_polaire(p, angle);
	set_module_polaire(p, module);
	return p;
}

void detruire_polaire(Polaire p){
	free(p);
}


Polaire set_angle_polaire(Polaire p, double angle){
	p->angle = angle;
	return p;
}

Polaire set_module_polaire(Polaire p, double module){
	p->module = module;
	return p;
}

double get_angle_polaire(Polaire p){
	return p->angle;
}

double get_module_polaire(Polaire p){
	return p->module;
}
