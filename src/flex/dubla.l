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
"("			{return PAR_OP;}
")"			{return PAR_CLO;}
"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return PROD;}
"/"			{return DIV;}

"."			{printf("point\n"); return POINT;}
{reel}		{yylval.reel = atof(yytext);
			printf("%f\n", yylval.reel);
			return DIGIT;}

"draw"		{printf("draw\n"); return DRAW;}
"fill"		{printf("fill\n"); return FILL;}
"image" 	{printf("image\n"); return IMG;}

":"	 		{printf("double\n"); return DOUBLE;}
","			{printf("comma\n"); return COMMA;}

";"			{printf("term\n"); return TERM;}

"--"		{printf("sep_p\n"); return SEP_P;}

<<EOF>>		{printf("END_FILE\n"); return END_FILE;}

%%