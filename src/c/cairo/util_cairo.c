#include "util_cairo.h"

extern cairo_surface_t* cairo_pdf_surface_create(const char *filename, double width_in_points, double height_in_points);
extern cairo_surface_t* cairo_svg_surface_create(const char *filename, double width_in_points, double height_in_points);
extern cairo_surface_t* cairo_image_surface_create(cairo_format_t format, int longueur, int largeur);

cairo_surface_t* creer_cairo_surface(char* type_surface, char* filename, int longueur, int largeur){
	if (!strcmp(type_surface, "pdf"))
	{
		return cairo_pdf_surface_create(filename, longueur, largeur);
	}
	else if (!strcmp(type_surface, "svg"))
	{
		return cairo_svg_surface_create(filename, longueur, largeur);
	}
	else if (!strcmp(type_surface, "png"))
	{
		return cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 390, 60);
	}
	else
	{
		printf("Erreur : le type %s n'est pas géré par cette fonction\n", type_surface);
		exit(1);
		return NULL;
	}
}
cairo_t* creer_cairo_contexte(cairo_surface_t* surface, GtkWidget* widget){
	if (surface != NULL)
	{
		return cairo_create(surface);
	}
	else if (widget !=NULL)
	{
		return gdk_cairo_create(gtk_widget_get_window(widget));
	}
	else
	{
		printf("Erreur : l'un des deux paramètre ne doit pas être NULL\n");
		exit(1);
		return NULL;
	}
}