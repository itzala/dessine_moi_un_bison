# On créé l'exécutable test_points
file(
	GLOB_RECURSE
	source_files_test_points
	./test_points.c
	${DESSINE_BISON_SOURCE_DIR}/c/points/*
)


add_executable(
	test_points
	${source_files_test_points}
)

target_link_libraries(
	test_points
	m
)

# On créé l'exécutable test_liste_points

file(
	GLOB_RECURSE
	source_files_test_liste_points
	./test_liste_points.c
	${DESSINE_BISON_SOURCE_DIR}/c/points/*
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_points.c
)

add_executable(
	test_liste_points
	${source_files_test_liste_points}
)

target_link_libraries(
	test_liste_points
	m
)

# On créé l'exécutable test_chemin

file(
	GLOB_RECURSE
	source_files_test_chemin
	./test_chemin.c
	${DESSINE_BISON_SOURCE_DIR}/c/chemin/*
	${DESSINE_BISON_SOURCE_DIR}/c/points/*
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_points.c
)

add_executable(
	test_chemin
	${source_files_test_chemin}
)

target_link_libraries(
	test_chemin
	m
	cairo
)



# On créé l'exécutable test_liste_chemin

file(
	GLOB_RECURSE
	source_files_test_liste_chemins
	./test_liste_chemins.c
	${DESSINE_BISON_SOURCE_DIR}/c/chemin/*
	${DESSINE_BISON_SOURCE_DIR}/c/points/*
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_points.c
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_chemins.c
	${DESSINE_BISON_SOURCE_DIR}/c/image/*
)

add_executable(
	test_liste_chemins
	${source_files_test_liste_chemins}
)

target_link_libraries(
	test_liste_chemins
	m
	cairo
)



# On créé l'exécutable test_liste_chemin

file(
	GLOB_RECURSE
	source_files_test_liste_images
	./test_liste_images.c
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_points.c
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_chemins.c
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_images.c
	${DESSINE_BISON_SOURCE_DIR}/c/points/*
	${DESSINE_BISON_SOURCE_DIR}/c/chemin/*
	${DESSINE_BISON_SOURCE_DIR}/c/image/*
)

add_executable(
	test_liste_images
	${source_files_test_liste_images}
)

target_link_libraries(
	test_liste_images
	m
	cairo
)

# On créé l'exécutable test_surface

file(
	GLOB_RECURSE
	source_files_test_surface
	./test_surface.c
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_points.c
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_chemins.c
	${DESSINE_BISON_SOURCE_DIR}/c/listes/liste_images.c
	${DESSINE_BISON_SOURCE_DIR}/c/points/*
	${DESSINE_BISON_SOURCE_DIR}/c/chemin/*
	${DESSINE_BISON_SOURCE_DIR}/c/image/*
	${DESSINE_BISON_SOURCE_DIR}/c/cairo/*
)

add_executable(
	test_surface
	${source_files_test_surface}
)

target_link_libraries(
	test_surface
	m
	cairo
	${GTK3_LIBRARIES}
)