#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
// #include "interface.h"


GtkWidget* creerBoiteScrollable(GtkWidget* widget){
	GtkWidget* box;
	box = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER(box), widget);
	gtk_scrolled_window_set_policy( GTK_SCROLLED_WINDOW( box ),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC );
	gtk_widget_show_all(box);
	return box;
}


int
main(int argc, char** argv){

	// On utilise la bibliothèque GTK
	gtk_init(&argc, &argv);
	GtkWidget* FenetrePrincipale;
	GtkWidget* EditeurCode;
	GtkWidget* BoutonExecCode;
	GtkWidget* Apercu;
	GtkWidget* DerouleEditeurCode;
	GtkWidget* BoiteEditeur;



	// On créé la fenêtre principale
	FenetrePrincipale = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(FenetrePrincipale), "Dessine-moi un Bison !");
	gtk_window_set_default_size(GTK_WINDOW(FenetrePrincipale), 800, 600);
	gtk_window_set_position(GTK_WINDOW(FenetrePrincipale), GTK_WIN_POS_CENTER);

	g_signal_connect(G_OBJECT(FenetrePrincipale), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

	EditeurCode = gtk_text_view_new();
	// On créé l'éditeur
	BoiteEditeur = creerBoiteScrollable(EditeurCode);
	printf("toto\n");
	gtk_container_add(GTK_CONTAINER(FenetrePrincipale), BoiteEditeur);
	printf("tata\n");

    /* Affichage et boucle évènementielle */
    gtk_widget_show_all(FenetrePrincipale);
    printf("tutu\n");
    gtk_main();
 
    /* On quitte.. */
	return EXIT_SUCCESS;
}