#include "liste_chemins.h"


struct liste_chemins
{
	Chemin* tab;
	int nb;
	int max;
};

bool est_pleine_liste_chemins(ListeChemins l){
	return l->nb >= l->max;
}

void rallonger(ListeChemins l){
	l->max *= 2;
	l->tab = (Chemin*) realloc(l->tab, sizeof(Chemin)*l->max);
}


ListeChemins creer_liste_chemins(){
	ListeChemins l = (ListeChemins) malloc(sizeof(struct liste_chemins));
	l->nb = 0;
	l->max = MAX_TAILLE;
	l->tab = (Chemin*) malloc(sizeof(Chemin)*l->max);
	return l;
}

ListeChemins clone_liste_chemins(ListeChemins l){
	ListeChemins cp = creer_liste_chemins();
	for(int i = 0 ; i<get_nb_chemins_liste(l) ; i++){
		ajouter_chemin_liste(cp, get_chemin_indice(l, i));
	}
	return cp;
}


void detruire_liste_chemins(ListeChemins l){
	for(int i=0 ; i<l->nb ; i++){
		detruire_chemin(l->tab[i]);
	}
	free(l->tab);
	free(l);
}

Chemin get_chemin_tete(ListeChemins l){
	if(! est_vide_liste_chemins(l)){
		return l->tab[0];
	}
	return NULL;
}

Chemin get_chemin_indice(ListeChemins l, int indice){
	if(!est_vide_liste_chemins(l)){
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

Chemin* get_chemins(ListeChemins l){
	return l->tab;
}

int get_nb_chemins_liste(ListeChemins l){
	return l->nb;
}

ListeChemins ajouter_chemin_liste(ListeChemins l, Chemin c){
	if(est_pleine_liste_chemins(l)){
		rallonger(l);
	}
	l->tab[l->nb] = clone(c);
	l->nb++;
	return l;
}

bool est_vide_liste_chemins(ListeChemins l){
	return l->nb < 1;
}

int get_nb_chemins(ListeChemins l)
{
	return l->nb;
}

void listeCheminsToString(ListeChemins l){
	if (est_vide_liste_chemins(l))
	{
		printf("Aucun chemin\n");
	}
	else{
		printf("%s", toStringChemin(l->tab[0]));
		for(int i=1 ; i< l->nb ; i++){
			printf(" ,\n\n %s", toStringChemin(l->tab[i]));
		}
		printf("\n");
	}
}

void dessiner_liste_chemins(ListeChemins l, cairo_t * contexte)
{
	for(int i = 0; i < l->nb; i++)
		dessiner_chemin(l->tab[i], contexte, i);	
}