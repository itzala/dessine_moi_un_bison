%{
#include <stdlib.h>
#include <stdio.h>

#include "../includes/cairo/surface.h"

void error(){
	yyerror();
}
%}
%token IMG DRAW FILL DOUBLE COMMA POINT SEP_P CYCLE DIGIT OPEN CLOSE TERM PLUS DIV MINUS PROD

%%

start : mot
		;
mot : 	instruction
		| IMG OPEN instruction CLOSE TERM
		;
instruction:	DRAW {printf("Commande draw bizutée !");} arguments TERM
				| FILL arguments TERM
				| {}
				;
arguments:	 "("point")"suivant
			;
point :	expression sep_expr expression
			;
sep_expr :	DOUBLE
			| COMMA
			;
expression :	DIGIT
				| "(" DIGIT ")"
				| MINUS DIGIT
				| "(" MINUS DIGIT ")"
				;
suivant :	DOUBLE boucle
			| COMMA boucle
			| {}
			;
boucle :	PLUS arguments
			| CYCLE suivant
			| arguments

%%


/*
règles à rajouter

O --> + | - | * | /
E" --> 0 E | epsi

règles à modifier

E --> digit E" | "(" digit E" ")"

*/


int main(int argc, char** argv){
	yyparse();


	Surface s = creer_surface("../ressources/essai.pdf", 50, 50, "pdf");

	detruire_surface(s);

	/* quelle commande a été trouvée ?*/

	return EXIT_SUCCES;
}