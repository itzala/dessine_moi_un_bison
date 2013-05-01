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

void rallonger_liste_chemins(ListePoints l){
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

Point get_point_tete(ListePoints l){
	if(! est_vide_liste_points(l)){
		return l->tab[0];
	}
	return NULL;
}

Point get_point_indice(ListePoints l, int indice){
	if(!est_vide_liste_points(l)){
		int nb_neg = l->nb * (-1);
		if (abs(indice) < l->nb || indice == nb_neg){
			return l->tab[(l->nb + indice)%l->nb];
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

ListePoints ajouter_point_liste(ListePoints l, Point p){
	if(est_pleine(l)){
		rallonger_liste_chemins(l);
	}
	l->tab[l->nb] = p;
	l->nb++;
	return l;
}

bool est_vide_liste_points(ListePoints l){
	return l->nb < 1;
}

void listePointsToString(ListePoints l){
	printf("%s", toStringPoint((Point) l->tab[0]));
	for(int i=1 ; i< l->nb ; i++){
		printf(" , %s", toStringPoint(l->tab[i]));
	}
	printf("\n");
}