
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