#include "interface.h"



GtkWidget* creerBoiteScrollable(GtkWidget* widget){
	GtkWidget* box;
	box = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER(box), widget);
	gtk_scrolled_window_set_policy( GTK_SCROLLED_WINDOW( box ),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC );
	gtk_widget_show_all(box);
	return box;
}