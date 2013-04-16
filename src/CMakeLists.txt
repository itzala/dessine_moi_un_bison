cmake_minimum_required(VERSION 2.8)



project(Dessine-moi_un_bison C)



# On détecte les packages avec PkgConfig
find_package(PkgConfig REQUIRED)
# On trouve les headers/bibliothèques de GTK+
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
# On ajoute les dossiers et définitions de GTK+
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})




# On créé l'exécutable
file(
	GLOB

	source_files

	c/*
)


add_executable(dessine_bison ${source_files})


# On lie les librairies
target_link_libraries(dessine_bison ${GTK3_LIBRARIES})