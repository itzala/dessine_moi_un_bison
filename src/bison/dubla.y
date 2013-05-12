%{
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>


#include "surface.h"
#include "variable.h"
#include "liste_variables.h"
#include "dessine_moi_un_bison.h"

extern FILE *yyin;
extern int yylex();


%}

%union{
	void* ptr;
	double reel;
	int booleen;
	char* string;
}

%token VAR CHEMIN POINT_C REEL
%token IMG
%token DRAW FILL

%token POINT CYCLE
%token DOUBLE COMMA

%token DIGIT ID

%token PLUS DIV MINUS PROD
%token EGAL EQUAL
%token OPEN CLOSE TERM SEP_P END_FILE PAR_OP PAR_CLO

%left PLUS MINUS
%left PROD DIV

%left EQUAL EGAL

%type <ptr> point
%type <booleen> sep_expr
%type <reel> expression DIGIT

%start fichier
%%

fichier : 		instructions
				;

instructions :	VAR variable TERM instructions
				| instruction TERM instructions
				| {}
				;

variable :		type ID affect
				;

affect :		EGAL value		
				| 				
				;

value :			expression		
				| instruction
				;

type :			IMG 		{$<ptr>$ = "image";}
				| CHEMIN 	{$<ptr>$ = "chemin";}
				| POINT 	{$<ptr>$ = "point";}
				| REEL 		{$<ptr>$ = "reel";}
				;

instruction :	DRAW 						{dub_creation_image(); 
												$<ptr>$ = dub_creation_chemin(false);
										 	} 
					arguments 				{dub_ajout_chemin_image();
												dub_ajout_image_surface();
											} 
							
				| FILL 						{dub_creation_image(); 
												$<ptr>$ = dub_creation_chemin(true);
											}
					arguments 				{dub_ajout_chemin_image();
												dub_ajout_image_surface();
											}
							
				| image 					{$<ptr>$ = $<ptr>1; dub_ajout_image_surface();}
				| ID 				
				;

img-instrs :	img-instr img-instrs
				| VAR variable img-instrs
				| {}

img-instr :		DRAW 						{$<ptr>$ = dub_creation_chemin(false);}
					arguments 				{dub_ajout_image_surface();}
							
				| FILL 						{$<ptr>$ = dub_creation_chemin(true);}
					arguments				{dub_ajout_image_surface();}
							
				| image 					{$<ptr>$ = $<ptr>1; dub_ajout_image_surface();}
				| ID 				
				;

image :			IMG {$<ptr>$ = dub_creation_image();} OPEN img-instrs CLOSE
				;

arguments:		PAR_OP point PAR_CLO 				{dub_ajout_point_chemin($2);}
									suivant
				;

suivant :		SEP_P boucle
				| {}
				;

boucle :		PLUS PAR_OP point PAR_CLO {dub_ajout_point_chemin(somme_point($3, get_point_queue(get_liste_points_chemin(c))));} suivant
				| CYCLE 							{ajouter_point_chemin(c, get_point_indice_chemin(c, 0));} suivant
				| arguments
				;

point :			expression sep_expr expression 	{$$ = dub_creation_point($1, $3, $2);
												}
				;

sep_expr :		DOUBLE 							{$$ = 1;}
				| COMMA 						{$$ = 0;}
				;

expression :	PAR_OP expression PAR_CLO		{$$ = $<reel>2;}
				| MINUS expression				{$$ = -$<reel>2;}
				| expression MINUS expression 	{$$ = $<reel>1 - $<reel>2;}
				| expression PLUS expression	{$$ = $<reel>1 + $<reel>2;}
				| expression DIV expression		{$$ = $<reel>1 / $<reel>2;}
				| expression PROD expression	{$$ = $<reel>1 * $<reel>2;}
				| DIGIT 						{$$ = $<reel>1;}
				;


%%
