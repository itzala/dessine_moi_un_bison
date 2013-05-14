#include "liste_variables.h"


struct liste_variables
{
	Variable* tab;
	int nb;
	int max;
};

bool est_pleine_liste_variables(ListeVariables l){
	return l->nb >= l->max;
}

void rallonger_liste_variables(ListeVariables l){
	l->max *= 2;
	l->tab = (Variable*) realloc(l->tab, sizeof(Variable)*l->max);
}

ListeVariables creer_liste_variables(){
	ListeVariables l = (ListeVariables) malloc(sizeof(struct liste_variables));
	l->max = MAX_TAILLE;
	l->tab = (Variable*) malloc(sizeof(Variable)*l->max);
	l->nb = 0;
	return l;
}

void detruire_liste_variables(ListeVariables l){
	free(l->tab);
	free(l);
}

ListeVariables clone_liste_variables(ListeVariables l){
	ListeVariables cp = creer_liste_variables();
	for (int i = 0 ; i<l->nb ; i++){
		ajouter_variable_liste(cp, get_variable_indice(l, i));
	}
	return cp;
}

Variable get_variable_tete(ListeVariables l){
	if(! est_vide_liste_variables(l)){
		return l->tab[0];
	}
	return NULL;
}

Variable get_variable_queue(ListeVariables l){
	if(! est_vide_liste_variables(l)){
		return l->tab[l->nb-1];
	}
	return NULL;
}

Variable get_variable_indice(ListeVariables l, int indice){
	if(!est_vide_liste_variables(l)){
		if (!(indice < 0 || indice >= l->nb)){
			return l->tab[indice];
		}
		printf("L'indice %d est hors limites\n", indice);
	}
	else {
		printf("La liste est vide\n");
	}
	return NULL;
}

Variable* get_variables(ListeVariables l){
	return l->tab;
}

int get_nb_variables(ListeVariables l){
	return l->nb;
}

Variable get_variable_par_nom(ListeVariables l, char* nom){
	for (int i = 0; i < l->nb; ++i)
	{
		char* nom_var = (char*) get_nom_variable(l->tab[i]);
		if (!strcmp(nom_var , nom))
		{
			return get_variable_indice(l, i);
		}
	}
	return NULL;
}


ListeVariables ajouter_variable_liste(ListeVariables l, Variable p){
	if(est_pleine_liste_variables(l)){
		rallonger_liste_variables(l);
	}
	l->tab[l->nb] = clone_variable(p);
	l->nb++;
	return l;
}

bool est_dans_liste(ListeVariables l, char* nom){
	return get_variable_par_nom(l, nom) != NULL;
}

bool est_vide_liste_variables(ListeVariables l){
	return l->nb < 1;
}

char* listeVariablesToString(ListeVariables l){
	return "ListeVariables";
}