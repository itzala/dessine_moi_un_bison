#include "variable.h"

struct variable
{
	char* type;
	char* nom;
	void* value;
};

void detruire_value(void* value, char* type);
bool est_reconnu_type(char* type);

Variable creer_variable(char* type, char* nom, void* value){
	if (est_reconnu_type(type))
	{
		Variable v = malloc(sizeof(struct variable));
		v->type = creer_char(type);
		v->nom = creer_char(nom);
		if (value != NULL)
		{
			v->value = creer_value(value, type);
		}
		else{
			v->value = NULL;
		}		
		return v;
	}
	else{
		printf("Type non reconnu : %s\n", type);
		return NULL;
	}
}

void detruire_variable(Variable v){
	detruire_value(v->value, v->type);
	free(v->nom);
	free(v->type);
	free(v);
}

Variable clone_variable(Variable v){
	return creer_variable(v->type, v->nom, v->value);
}

char* get_type_variable(Variable v){
	return v->type;
}

char* get_nom_variable(Variable v){
	return v->nom;
}

void* get_value_variable(Variable v){
	return v->value;
}


void set_type_variable(Variable v, char* value){
	if (est_reconnu_type(value))
	{
		free(v->type);
		v->type = creer_char(value);
	}
	else{
		printf("Le type %s n'est pas géré\n", value);
	}
}

void set_nom_variable(Variable v, char* value){
	free(v->nom);
	v->nom = creer_char(value);
}

void set_value_variable(Variable v, void* value){
	detruire_value(v->value, v->type);	
	void* tmp = creer_value(value, v->type);
	if (tmp == NULL)
	{
		v->value = NULL;
	}
	else{
		v->value = tmp;
	}
}


bool est_variable_type(Variable v, char* type){
	return est_reconnu_type(type) && !strcmp(v->type, type);
}


bool est_reconnu_type(char* type){
	return !strcmp(type, "point") || !strcmp(type, "chemin") || !strcmp(type, "image")||!strcmp(type, "reel");
}

char* toStringVariable(Variable v){
	if (v != NULL)
	{
		printf("Affichage variable %s (%s)\n", v->nom, v->type);
		if (v->value == NULL)
		{
			return "Variable vide\n";
		}
		if (!strcmp(v->type, "point"))
		{
			printf("point\n");
			return toStringPoint(v->value);
		}
		else if (!strcmp(v->type, "chemin"))
		{
			printf("chemin\n");
			return toStringChemin(v->value);
		}
		else if (!strcmp(v->type, "image"))
		{
			printf("image\n");
			imageToString(v->value);
		}
		else{
			char buffer[30];
			sprintf(buffer, "%f", *((double*)v->value));
			return buffer;
		}
	}
	return NULL;
}




char* creer_char(char* type){
	char* c = malloc(sizeof(type));
	strcpy(c, type);
	return c;
}

void* creer_value(void* value, char* type){
	if (!strcmp(type, "reel"))
	{
		void* v = malloc(sizeof(double));
		double tmp;
		if (value == NULL)
		{
			tmp = 0;
		}
		else{
			tmp = atof(value);
		}
		v = memcpy(v, &tmp, sizeof(double));
		return v;
	}
	else{
		return value;
	}
}



void detruire_value(void* value, char* type){
	if (value != NULL)
	{
		if (!strcmp(type, "point"))
		{
			detruire_point((Point) value);
		}
		else if (!strcmp(type, "chemin"))
		{
			detruire_chemin((Chemin) value);
		}
		else if (!strcmp(type, "image"))
		{
			detruire_image((Image) value);
		}
		else
		{
			free(value);
		}
	}
}