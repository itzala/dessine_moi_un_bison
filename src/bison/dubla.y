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

%token ID
%token DIGIT 

%token PLUS DIV MINUS PROD NEG
%token EGAL EQUAL
%token OPEN CLOSE TERM SEP_P END_FILE PAR_OP PAR_CLO

%left PLUS MINUS
%left PROD DIV

%left EQUAL EGAL

%type <reel> expression DIGIT
%type <string> ID
%type <ptr> point instruction affect value img-instr
%type <booleen> sep_expr

%start fichier
%%

fichier : 		instructions
				;

instructions :	VAR variable TERM instructions	
				| instruction {dub_ajout_image_surface();} TERM instructions
				| {}
				;

variable :		type ID {
							$<ptr>$ = creer_variable($<string>1, $<string>2, NULL);
							ajouter_variable_liste(lv, $<ptr>$);
							detruire_variable($<ptr>$);
						}
						affect {									
									set_value_variable(get_variable_queue(lv), $<ptr>4);									
									// printf("%s\n", toStringVariable($<ptr>$));
								}
				;

affect :		EGAL value				{$<ptr>$ = $<ptr>2; 
											imageToString($<ptr>2);
										}
				| 						{$$ = NULL;}
				;

value :			expression				{$$ = malloc(sizeof(char)*30); sprintf($$, "%f", $1);};
				| instruction 			{$$ = NULL;}
				;

type :			IMG 		{$<string>$ = "image";}
				| CHEMIN 	{$<string>$ = "chemin";}
				| POINT 	{$<string>$ = "point";}
				| REEL 		{$<string>$ = "reel";}
				;

instruction :	DRAW 						{
												dub_creation_image(); 
												dub_creation_chemin(false);
										 	} 
					arguments 				{
												$<ptr>$ = dub_ajout_chemin_image();
											} 
							
				| FILL 						{
												dub_creation_image(); 
												dub_creation_chemin(true);
											}
					arguments 				{
												$<ptr>$ = dub_ajout_chemin_image();
											}
							
				| image 					{$<ptr>$ = $<ptr>1;}
				| ID affect					{$<ptr>$ = $<ptr>1;}
				;

img-instrs :	img-instr TERM {dub_ajout_image_surface();} img-instrs
				| VAR variable img-instrs
				| {}

img-instr :		DRAW 						{dub_creation_chemin(false);}
					arguments				{$<ptr>$ = NULL;}
							
				| FILL 						{$<ptr>$ = dub_creation_chemin(true);}
					arguments				{$<ptr>$ = NULL;}
							
				| image 					{$<ptr>$ = $<ptr>1;}
				| ID affect					{
												// if (est_dans_liste(lv, $<string>1))
												// {
												// 	if ($<ptr1>2 != NULL)
												// 	{
												// 		set_value_variable(get_variable_par_nom(lv, $<string>1), $<ptr>1);
												// 		if (est_variable_type(get_variable_par_nom(lv, $<string>1), "reel"))
												// 		{
												// 			$<ptr>$ = NULL;
												// 		}
												// 		else{
												// 			$<ptr>$ = get_value_variable(get_variable_par_nom(lv, $<string>1));
												// 		}
												// 	}
												// 	else{
												// 			printf("Erreur : La variable %s n'existe pas\n", $<string>1);
												// 			error();
												// 		}

												// }
											}
				;

image :			IMG {$<ptr>$ = dub_creation_image();} OPEN img-instrs CLOSE
				;

arguments:		PAR_OP point PAR_CLO 				{$<ptr>$ = 	dub_ajout_point_chemin($2);}
									suivant
				| ID suivant
				;

suivant :		SEP_P boucle
				| {}
				;

boucle :		PLUS PAR_OP point PAR_CLO {dub_ajout_point_chemin(somme_point($3, get_point_queue(get_liste_points_chemin(c))));}
										suivant
				| CYCLE 							{ajouter_point_chemin(c, get_point_indice_chemin(c, 0));}
						suivant
				| arguments
				;

point :			expression sep_expr expression 	{$$ = dub_creation_point($1, $3, $2);
												}
				;

sep_expr :		DOUBLE 							{$$ = 1;}
				| COMMA 						{$$ = 0;}
				;

expression :	PAR_OP expression PAR_CLO		{$$ = $<reel>2;}
				| MINUS expression %prec NEG	{$$ = -$<reel>2;}
				| expression MINUS expression 	{$$ = $<reel>1 - $<reel>3;}
				| expression PLUS expression	{$$ = $<reel>1 + $<reel>3;}
				| expression DIV expression		{$$ = $<reel>1 / $<reel>3;}
				| expression PROD expression	{$$ = $<reel>1 * $<reel>3;}
				| DIGIT 						{$$ = $<reel>1;}
				| ID 							{
													if (est_dans_liste(lv, $<string>1))
													{
														if (est_variable_type(get_variable_par_nom(lv, $<string>1), "reel"))
														{
															$$ = *((double*)get_value_variable(get_variable_par_nom(lv, $<string>1)));
														}
														else{
															printf("Erreur : La variable %s n'est pas un réél\n", $<string>1);
															error();
														}
													}
													else{
															printf("Erreur : La variable %s n'existe pas\n", $<string>1);
															error();
														}

												}
				;


%%
