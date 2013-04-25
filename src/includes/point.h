#ifndef POINT_H
#define POINT_H

#include "polaire_point.h"
#include "cartesien_point.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Cartesien polaire_vers_cartesien(Polaire p);
Polaire cartesien_vers_polaire(Cartesien p);

char* toString(Cartesien p);
char* toStringPolaire(Polaire p);

#endif
