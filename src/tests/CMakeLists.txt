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
)



# On créé l'exécutable test_liste_chemin

file(
	GLOB_RECURSE
	source_files_test_liste_chemins
	./test_liste_chemins.c
	${DESSINE_BISON_SOURCE_DIR}/c/chemin/*
	${DESSINE_BISON_SOURCE_DIR}/c/points/*
	${DESSINE_BISON_SOURCE_DIR}/c/listes/*
	${DESSINE_BISON_SOURCE_DIR}/c/image/*
)

add_executable(
	test_liste_chemins
	${source_files_test_liste_chemins}
	)

target_link_libraries(
	test_liste_chemins
	m
)



# On créé l'exécutable test_liste_chemin

file(
	GLOB_RECURSE
	source_files_test_liste_image
	./test_liste_images.c
	${DESSINE_BISON_SOURCE_DIR}/c/listes/*
	${DESSINE_BISON_SOURCE_DIR}/c/points/*
	${DESSINE_BISON_SOURCE_DIR}/c/chemin/*
	${DESSINE_BISON_SOURCE_DIR}/c/image/*
)

add_executable(
	test_liste_image
	${source_files_test_liste_image}
	)

target_link_libraries(
	test_liste_image
	m
)

