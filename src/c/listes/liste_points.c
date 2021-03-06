#include "liste_points.h"
#include "point.h"

struct liste_points
{
	Point* tab;
	int nb;
	int max;
};

bool est_pleine(ListePoints l){
	return l->nb >= l->max;
}

void rallonger_liste_points(ListePoints l){
	l->max *= 2;
	l->tab = (Point*) realloc(l->tab, sizeof(Point)*l->max);
}

ListePoints creer_liste_points(){
	ListePoints l = (ListePoints) malloc(sizeof(struct liste_points));
	l->max = MAX_TAILLE;
	l->tab = (Point*) malloc(sizeof(Point)*l->max);
	l->nb = 0;
	return l;
}

void detruire_liste_points(ListePoints l){
	free(l->tab);
	free(l);
}

ListePoints clone_liste_points(ListePoints l){
	ListePoints cp = creer_liste_points();
	for (int i = 0 ; i<l->nb ; i++){
		ajouter_point_liste(cp, get_point_indice(l, i));
	}
	return cp;
}

Point get_point_tete(ListePoints l){
	if(! est_vide_liste_points(l)){
		return l->tab[0];
	}
	return NULL;
}

Point get_point_queue(ListePoints l){
	if(! est_vide_liste_points(l)){
		return l->tab[l->nb-1];
	}
	return NULL;
}

Point get_point_indice(ListePoints l, int indice){
	if(!est_vide_liste_points(l)){
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

Point* get_points(ListePoints l){
	return l->tab;
}

int get_nb_points(ListePoints l){
	return l->nb;
}

ListePoints ajouter_point_liste(ListePoints l, Point p){
	if(est_pleine(l)){
		rallonger_liste_points(l);
	}
	l->tab[l->nb] = clone_point(p);
	l->nb++;
	return l;
}

bool est_vide_liste_points(ListePoints l){
	return l->nb < 1;
}

char* listePointsToString(ListePoints l){
	if (est_vide_liste_points(l))
	{
		return "Pas de points";
	}
	int taille = 50;
	int taille_ini = 50;
	char* res = malloc(sizeof(char)*taille);
	char* buffer = malloc(sizeof(char)*taille);
	int new_taille = sprintf(buffer, "%s", toStringPoint(l->tab[0]));
	for(int i=0 ; i< l->nb ; i++){
		new_taille = sprintf(buffer, "%s", toStringPoint(l->tab[i]));
		while(new_taille > taille){			// Tant il y a plus de caractères à rajouter que de place disponible
			taille *= 2;					// On double la place disponible
			if(new_taille < taille){
				taille_ini += taille;							// On ajoute la nouvelle place disponible à la taille initiale
				res = realloc(res, taille_ini*sizeof(char));	// On réalloue le tableau
			}
		}

		strncat(res, buffer, new_taille);								// 
		taille -= new_taille;
	}
	free(buffer);
	return res;
}