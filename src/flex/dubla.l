%{
#include "y.tab.h"
#define YY_NO_INPUT

int fileno();
%}
%option nounput

blanks			[ \t\n]+

entier			[[:digit:]]+

reel			{entier}("."{entier})?

identifiant 	[[:alpha:]_][[:alnum:]_]*

%%
{blanks}		{}

{reel}			{yylval.reel = atof(yytext);
				return DIGIT;}

"var"			{return VAR;}
"chemin"		{return CHEMIN;}
"point"			{return POINT_C;}
"reel"			{return REEL;}
"cycle"			{return CYCLE;}
"draw"			{return DRAW;}
"fill"			{return FILL;}
"image" 		{return IMG;}

{identifiant}	{yylval.string = yytext;
				return ID;}

"{"				{return OPEN;}
"}"				{return CLOSE;}
"("				{return PAR_OP;}
")"				{return PAR_CLO;}
"+"				{return PLUS;}
"-"				{return MINUS;}
"*"				{return PROD;}
"/"				{return DIV;}
"="				{return EGAL;}

"=="			{return EQUAL;}

":"	 			{return DOUBLE;}
","				{return COMMA;}

";"				{return TERM;}

"--"			{return SEP_P;}

"."				{return POINT;}

\"				{}
\'				{}

%%

