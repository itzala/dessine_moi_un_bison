
# On créé l'exécutable
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