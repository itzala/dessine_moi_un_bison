#ifndef UTIL_CAIRO_H
#define UTIL_CAIRO_H

#include <stdlib.h>
#include <gtk/gtk.h>
#include <cairo.h>
#include <string.h>

cairo_surface_t* creer_cairo_surface(char* type_surface, char* filename, int longueur, int largeur);
cairo_t* creer_cairo_contexte(cairo_surface_t* surface, GtkWidget* widget);

#endif