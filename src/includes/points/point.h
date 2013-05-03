#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cartesien_point.h"
#include "polaire_point.h"

typedef struct point* Point;

Point creer_point(double x, double y);
Point creer_point_polaire(double mod, double ang);
Point clone_point(Point p);
void detruire_point(Point p);

double get_abscisse(Point p);
double get_ordonnee(Point p);


Cartesien polaire_vers_cartesien(Polaire p);
Polaire cartesien_vers_polaire(Cartesien p);


char* toStringPoint(Point p);
char* toStringCartesien(Cartesien p);
char* toStringPolaire(Polaire p);

#endif
