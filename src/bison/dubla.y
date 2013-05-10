%{
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
// #include "global.h"


#include "surface.h"

extern FILE *yyin;
extern int yylex();
void yyerror (char const *);
void error();
void creation_image();
void ajout_image_surface();

ListeImages li = NULL;
Image i = NULL;
Chemin c = NULL;
Point p = NULL;
Point premier_point_chemin = NULL;
Surface s = NULL;
int est_premier_point_chemin = 1;
double epaisseur = 1.0;
int couleur = 1;


%}

%union{
	void* ptr_p;
	double reel;
	int booleen;
}

%token IMG

%token DRAW FILL

%token POINT CYCLE
%token DOUBLE COMMA

%token DIGIT

%token PLUS DIV MINUS PROD
%token OPEN CLOSE TERM SEP_P END_FILE PAR_OP PAR_CLO

%left PLUS MINUS
%left PROD DIV

%type <ptr_p> point
%type <booleen> sep_expr
%type <reel> expression DIGIT

%start fichier
%%

fichier : 		instruction
				;

instruction :	DRAW {creation_image(); $<ptr_p>$ = creer_chemin_vide(epaisseur, couleur, false); c = $<ptr_p>$;} arguments {ajouter_chemin_image(get_image_queue(li), c); detruire_chemin(c); c=NULL; ajout_image_surface();} TERM instruction 
				| FILL {creation_image(); $<ptr_p>$ = creer_chemin_vide(epaisseur, couleur, true); c = $<ptr_p>$;} arguments {ajouter_chemin_image(get_image_queue(li), c); detruire_chemin(c); c=NULL; ajout_image_surface();} TERM instruction 
				| IMG image instruction
				| {}
				;

img-instr :		DRAW {$<ptr_p>$ = creer_chemin_vide(epaisseur, couleur, false); c = $<ptr_p>$;} arguments {ajouter_chemin_image(get_image_queue(li), c); detruire_chemin(c); c=NULL;} TERM img-instr 
				| FILL {$<ptr_p>$ = creer_chemin_vide(epaisseur, couleur, true); c = $<ptr_p>$;} arguments {ajouter_chemin_image(get_image_queue(li), c); detruire_chemin(c); c=NULL;} TERM img-instr 
				| IMG image img-instr
				| {}
				;

image :			{creation_image();} OPEN img-instr CLOSE {ajout_image_surface();} TERM
				;

arguments:		PAR_OP point PAR_CLO {ajouter_point_chemin(c, $2); detruire_point($2);} suivant
				;

suivant :		SEP_P boucle
				| {}
				;

boucle :		PLUS arguments
				| CYCLE suivant
				| arguments
				;

point :			expression sep_expr expression 	{if($1 < 0 || $3 < 0){
													error();
													$$ = NULL;
												}
												else{ 
													if ($2 == 1){
														$$ = creer_point_polaire($1, $3);
													}
													else {
														$$ = creer_point($1, $3);
													}
													if (est_premier_point_chemin){
														premier_point_chemin = clone_point($$);
														est_premier_point_chemin = 0;
													}
												}
												}
				;

sep_expr :		DOUBLE 							{$$ = 1;}
				| COMMA 						{$$ = 0;}
				;

expression :	DIGIT 							{$$ = $<reel>1;}
				| PAR_OP expression PAR_CLO			{$$ = $<reel>2;}
				| expression MINUS expression 	{$$ = $<reel>1 - $<reel>2;}
				| expression PLUS expression	{$$ = $<reel>1 + $<reel>2;}
				| expression DIV expression		{$$ = $<reel>1 / $<reel>2;}
				| expression PROD expression	{$$ = $<reel>1 * $<reel>2;}
				| 	 							{$$ = -1.0;}
				;


%%


/*
règles à rajouter

O --> + | - | * | /
E" --> 0 E | epsi

règles à modifier

E --> digit E" | "(" digit E" ")"

*/


int main(int argc, char** argv){
	
	if (argc != 6)
	{
		printf("Nombre d'arguments incorrect\n");
		return EXIT_FAILURE;
	}
	char* source = malloc(sizeof(char)*255);
	char* filename = malloc(sizeof(char)*255);
	char* extension = malloc(sizeof(char)*3);
	strcpy(source, argv[1]);
	strcpy(filename, argv[2]);
	strcpy(extension, argv[3]);

	int longueur = atoi(argv[4]);
	int largeur = atoi(argv[5]);

	cairo_surface_t *surface = creer_cairo_surface(extension, filename, longueur, largeur);
	cairo_t *cr = creer_cairo_contexte(surface, NULL);

	s = creer_surface(cr);
	li = creer_liste_images();

	FILE *fichier_source = fopen(source, "r");
	if (!fichier_source) {
		printf("Le fichier %s est innaccessible\n", source);
		return EXIT_FAILURE;
	}
	yyin = fichier_source;

	if(!yyparse())
		dessiner_surface(s);

	detruire_surface(s);
	cairo_destroy(cr);
	cairo_surface_destroy(surface);

	return EXIT_SUCCESS;
}

void error(){
	yyerror("Erreur Syntaxique");
}

void
yyerror (char const *s)
{
	fprintf (stderr, "%s\n", s);
	exit(1);
}


void creation_image(){
	i = creer_image();
	ajouter_image_liste(li, i);
	detruire_image(i);
}

void ajout_image_surface(){
	ajouter_image_surface(s, get_image_queue(li));
	supprimer_image_queue_liste(li);
}
