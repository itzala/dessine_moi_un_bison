ADD_CUSTOM_COMMAND(OUTPUT dubla.c
	COMMAND ${FLEX} dubla.l
	MAIN_DEPENDENCY dubla.l
	COMMENT "DANS ton cul ! Remballe ton flex"
	VERBATIM
)