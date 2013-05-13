#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include "surface.h"

typedef struct variable* Variable;

Variable creer_variable(char* type, char* nom, void* value);
void detruire_variable(Variable v);

Variable clone_variable(Variable v);

char* get_type_variable(Variable v);
char* get_nom_variable(Variable v);
void* get_value_variable(Variable v);

void set_type_variable(Variable v, char* value);
void set_nom_variable(Variable v, char* value);
void set_value_variable(Variable v, void* value);

bool est_variable_type(Variable v, char* type);

char* creer_char(char* type);
void* creer_value(void* value, char* type);
char* toStringVariable(Variable v);

#endif