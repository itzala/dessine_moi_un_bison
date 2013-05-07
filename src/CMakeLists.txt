cmake_minimum_required(VERSION 2.8)
project(DESSINE_BISON C)

IF(NOT DEFINED BISON_PREFIX_OUTPUTS)
 SET(BISON_PREFIX_OUTPUTS FALSE)
ENDIF(NOT DEFINED BISON_PREFIX_OUTPUTS)

IF(NOT DEFINED BISON_GENERATE_DEFINES)
 SET(BISON_GENERATE_DEFINES FALSE)
ENDIF(NOT DEFINED BISON_GENERATE_DEFINES)

IF(NOT BISON_EXECUTABLE)
 MESSAGE(STATUS "Looking for bison")
 FIND_PROGRAM(BISON_EXECUTABLE bison)
 IF(BISON_EXECUTABLE)
   MESSAGE(STATUS "Looking for bison -- ${BISON_EXECUTABLE}")
 ENDIF(BISON_EXECUTABLE)
ENDIF(NOT BISON_EXECUTABLE)

IF(NOT DEFINED FLEX_PREFIX_OUTPUTS)
  SET(FLEX_PREFIX_OUTPUTS FALSE)
ENDIF(NOT DEFINED FLEX_PREFIX_OUTPUTS) 

IF(NOT FLEX_EXECUTABLE)
  MESSAGE(STATUS "Looking for flex")
  FIND_PROGRAM(FLEX_EXECUTABLE flex)
  IF(FLEX_EXECUTABLE)
    MESSAGE(STATUS "Looking for flex -- ${FLEX_EXECUTABLE}")
  ENDIF(FLEX_EXECUTABLE)
ENDIF(NOT FLEX_EXECUTABLE) 

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

add_subdirectory(flex)
add_subdirectory(bison)