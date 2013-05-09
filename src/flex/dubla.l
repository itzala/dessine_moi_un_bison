%{
// #include "global.h"
#include "y.tab.h"
#define YY_NO_INPUT

int fileno();
%}
%option nounput

blanks	[ \t\n]

entier	[[:digit:]]+

reel	{entier}("."{entier})?

%%
{blanks}	{}

"{"			{return OPEN;}
"}"			{return CLOSE;}
"("			{printf("("); return PAR_OP;}
")"			{printf(")"); return PAR_CLO;}
"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return PROD;}
"/"			{return DIV;}

"."			{printf(" point \n"); return POINT;}
{reel}		{yylval.reel = atof(yytext);
			printf("%f", yylval.reel);
			return DIGIT;}

"draw"		{printf(" draw "); return DRAW;}
"fill"		{printf(" fill "); return FILL;}
"image" 	{printf(" image "); return IMG;}

":"	 		{printf(" : "); return DOUBLE;}
","			{printf(" , "); return COMMA;}

";"			{printf(" term\n"); return TERM;}

"--"		{printf("--"); return SEP_P;}


%%