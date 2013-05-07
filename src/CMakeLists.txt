cmake_minimum_required(VERSION 2.8)

project(DESSINE_BISON C)

find_program(FLEX flex DOC "Path to the flex lexical analyser generator.")
if(NOT ${FLEX})
message(SEND_ERROR "Flex not found.")
endif
find_program(BISON bison DOC "Path to the bison parser generator.")
if(NOT ${BISON})
message(SEND_ERROR "Bison not found.")
endif

# On détecte les packages avec PkgConfig
find_package(PkgConfig REQUIRED)
# On trouve les headers/bibliothèques de GTK+
pkg_check_modules(
	GTK3 
	REQUIRED 
	gtk+-3.0)


# On ajoute les dossiers et définitions de GTK+
include_directories(
	${GTK3_INCLUDE_DIRS}
	${DESSINE_BISON_SOURCE_DIR}/includes
	${DESSINE_BISON_SOURCE_DIR}/includes/points
	${DESSINE_BISON_SOURCE_DIR}/includes/chemin
	${DESSINE_BISON_SOURCE_DIR}/includes/image
	${DESSINE_BISON_SOURCE_DIR}/includes/listes
	${DESSINE_BISON_SOURCE_DIR}/includes/cairo
)


link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})




# On créé l'exécutable
file(
	GLOB_RECURSE
	source_files_exec
	${DESSINE_BISON_SOURCE_DIR}/c/*
)

ADD_DEFINITIONS(-std=c99 -g -Wall)


add_executable(
	dessineBison 
	${source_files_exec}
)


# On lie les librairies
target_link_libraries(dessineBison
${GTK3_LIBRARIES}
cairo)

add_subdirectory(tests)
add_subdirectory(includes)