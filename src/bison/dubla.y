%{
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>


#include "surface.h"
#include "dessine_moi_un_bison.h"

extern FILE *yyin;
extern int yylex();


%}

%union{
	void* ptr_p;
	double reel;
	int booleen;
}

%token IMG
%token VAR
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

instruction :	DRAW 						{dub_creation_image(); 
												$<ptr_p>$ = dub_creation_chemin(false);
										 	} 
					arguments 				{dub_ajout_chemin_image();
												dub_ajout_image_surface();
											} 
							TERM instruction 
				| FILL 						{dub_creation_image(); 
												$<ptr_p>$ = dub_creation_chemin(true);
											}
					arguments 				{dub_ajout_chemin_image();
												dub_ajout_image_surface();
											}
							TERM instruction 
				| IMG image instruction
				| {}
				;

img-instr :		DRAW 						{$<ptr_p>$ = dub_creation_chemin(false);}
					arguments 				{dub_ajout_image_surface();}
							TERM img-instr 
				| FILL 						{$<ptr_p>$ = dub_creation_chemin(true);}
					arguments				{dub_ajout_image_surface();}
							TERM img-instr 
				| IMG image img-instr
				| {}
				;

image :			{dub_creation_image();} OPEN img-instr CLOSE {dub_ajout_image_surface();} TERM
				;

arguments:		PAR_OP point PAR_CLO 				{dub_ajout_point_chemin();}
									suivant
				;

suivant :		SEP_P boucle
				| {}
				;

boucle :		PLUS arguments
				| CYCLE {ajouter_point_chemin(c, premier_point_chemin);} suivant
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
