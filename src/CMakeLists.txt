cmake_minimum_required(VERSION 2.8)
project(DESSINE_BISON C)

find_package(BISON)
find_package(FLEX)

# On détecte les packages avec PkgConfig
find_package(PkgConfig REQUIRED)
# On trouve les headers/bibliothèques de GTK+
pkg_check_modules(
	GTK3 
	REQUIRED 
	gtk+-3.0)

set(DESSINE_BISON_BINARY_DIR "${DESSINE_BISON_SOURCE_DIR}/../bin/")

# On ajoute les dossiers et définitions de GTK+
include_directories(
	${GTK3_INCLUDE_DIRS}
	${CAIRO}
	${DESSINE_BISON_SOURCE_DIR}/includes
	${DESSINE_BISON_SOURCE_DIR}/includes/points
	${DESSINE_BISON_SOURCE_DIR}/includes/chemin
	${DESSINE_BISON_SOURCE_DIR}/includes/image
	${DESSINE_BISON_SOURCE_DIR}/includes/listes
	${DESSINE_BISON_SOURCE_DIR}/includes/cairo
)


link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})



ADD_DEFINITIONS(-std=c99 -g -Wall)



add_subdirectory(tests)




find_package(BISON)
find_package(FLEX)

BISON_TARGET(DublaParser 
			${DESSINE_BISON_SOURCE_DIR}/bison/dubla.y 
			${DESSINE_BISON_SOURCE_DIR}/../bin/y.tab.c)

FLEX_TARGET(ScannerDubla 
			${DESSINE_BISON_SOURCE_DIR}/flex/dubla.l 
			${DESSINE_BISON_SOURCE_DIR}/../bin/lex.yy.c)

ADD_FLEX_BISON_DEPENDENCY(ScannerDubla DublaParser)

file(
	GLOB_RECURSE
	source_files_parser
	${DESSINE_BISON_SOURCE_DIR}/c/*)

add_executable(Foo
  	${DESSINE_BISON_SOURCE_DIR}/../bin/lex.yy.c
	${DESSINE_BISON_SOURCE_DIR}/../bin/y.tab.c
	${source_files_parser}
	)
target_link_libraries(Foo
							${FLEX_LIBRARIES} 
							${BISON_LIBRARIES}
							${GTK3_LIBRARIES}
							cairo)
