#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	if (argc < 2 || argc > 5)
	{
		usage();
	}
	else 
	{
		char racine[] = "./ressources/";
		char file_source[100], file_dest;
		int longueur, largeur;
		char* extension;
		strcpy(file_source, racine);
		if (!strcmp(argv[1], "all"))
		{
			strcat(file_source, "test_all.dubc");
		}
		if (argc == 2)
		{
		}
	}
	return 0;
}