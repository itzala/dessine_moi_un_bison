%{
#include <stdlib.h>
#include <stdio.h>

void error(){
	yyerror();
}
%}
%TOKEN IMG DRAW FILL DOUBLE COMMA POINT SEP_C PLUS DIV MINUS PROD CYCLE DIGIT OPEN CLOSE TERM

%%

start : mot
		;
mot : 	instruction
		| IMG OPEN instruction CLOSE TERM
		;
instruction:	DRAW arguments TERM
				| FILL arguments TERM
				| {}
				;
arguments:	(point)suivant
			;
point :	expression sep_expr expression
			;
sep_expr :	:
			| ,
			;
expression :	DIGIT
				|( DIGIT )
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

E --> digit E" | ( digit E" )

*/


int main(int argc, char** argv){
	yyparse();

	/* quelle commande a été trouvée ?*/

	return EXIT_SUCCES;
}