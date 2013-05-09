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

"."			{return POINT;}
{reel}		{yylval.reel = atof(yytext);
			return DIGIT;}

"draw"		{return DRAW;}
"fill"		{return FILL;}
"image" 	{return IMG;}

":"	 		{return DOUBLE;}
","			{return COMMA;}

";"			{return TERM;}

"--"		{return SEP_P;}


%%