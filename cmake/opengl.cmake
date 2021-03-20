if ( WINDOWS ) # Windows SDK OpenGL32
    find_library( opengl "OpenGL32.lib" )
else ( WINDOWS )
    message ( FATAL_ERROR "${PROJECT_NAME} - OpenGL STATIC-Library location for current platform is not set, configuration required" )
endif ( WINDOWS )

# Check
if ( opengl )
    message( STATUS "${PROJECT_NAME} - opengl - found at: ${opengl}" )
else ( opengl )
    message( FATAL_ERROR "${PROJECT_NAME} - opengl - not found" )
endif ( opengl )

# Add OpenGL to Link-List
set ( LIBS_TO_LINK ${LIBS_TO_LINK} ${opengl} )