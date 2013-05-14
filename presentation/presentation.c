#include <sys/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(){
	printf("Usage: ./presentation [fonctionnalité à tester] (paramètre suivants optionnels) [longueur] [largeur] [extension]\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[])
{
	if (argc < 2 || argc > 5)
	{
		usage();
	}
	else 
	{
		char* file_source;
		char* file_dest;
		char* longueur = malloc(sizeof(char)*10);
		char* largeur = malloc(sizeof(char)*10);
		char* extension = malloc(sizeof(char)*10);
		file_source = (char*) malloc(sizeof(char)*100);
		file_dest = (char*) malloc(sizeof(char)*100);
		char racine[] = "./ressources/presentation_";
		char* commande = malloc(sizeof(char)*200);

		strcpy(file_source, racine);	
		strcpy(file_dest, "./ressources/sortie_");
		strcat(file_source, argv[1]);
		strcat(file_dest, argv[1]);
		strcat(file_source, ".dubc");		
		strcpy(commande, "../bin/dessine_moi_un_bison ");
		if (access(file_source, 0) == 0)
		{
			if (argc == 5)
			{
				strcpy(longueur,argv[2]);
				strcpy(largeur,argv[3]);

				if (strcmp(argv[4], "pdf"))
					printf("Seuls les pdf sont gérés\n");
				extension = "pdf";
				
			}
			else if (argc == 2)
			{
				longueur = "100";
				largeur = longueur;
				extension = "pdf";
				printf("%s %s %s\n", commande, file_source, file_dest);
			}
			else{
				usage();
			}


			strcat(file_dest, ".");
			strcat(file_dest, extension);
			
			// Commande à lancer : ../bin/dessine_moi_un_bison [source] [dest] [extension] [longueur] [largeur]
			strcat(commande, file_source);
			strcat(commande, " ");
			strcat(commande, file_dest);
			strcat(commande, " ");
			strcat(commande, extension);
			strcat(commande, " ");
			strcat(commande, longueur);
			strcat(commande, " ");
			strcat(commande, largeur);
			printf("On exécute la commande :\t%s\n", commande);
			system(commande);
			free(commande);
			commande = malloc(sizeof(char)*200);
			strcpy(commande, "evince ");
			strcat(commande, file_dest);
			system(commande);
		}
		else
		{
			printf("Erreur le fichier %s n'est pas accessible en lecture\n", file_source);
			
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}