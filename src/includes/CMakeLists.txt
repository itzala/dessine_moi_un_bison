
FILE(
	GLOB_RECURSE
	include_files
	./*
	)

INSTALL(FILES ${include_files}
        DESTINATION includes
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)