%{
#include <dubla.tab.h>
%}

%%

[[:digit:]] {/*Transformer le string en int*/ return DIGIT;}
"."		{return POINT;}

"{"		{return OPEN;}
"}"		{return CLOSE;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return PROD;}
"/"		{return DIV;}

draw	{return DRAW;}
fill	{return FILL;}
image 	{return IMG;}


":"	 	{return DOUBLE;}
","		{return COMMA;}



%%