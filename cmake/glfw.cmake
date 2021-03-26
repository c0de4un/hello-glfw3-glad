find_package ( GLFW3 QUIET )
if ( NOT GLFW3_FOUND )
    message ( STATUS "${PROJECT_NAME} - package GLFW3 not found. Checking local ")

    set ( GLFW_INCLUDE_DIR "${LIBS_DIR}glfw/include" )
    set ( GLFW_LIBS_PATH "${LIBS_DIR}glfw/lib/${PLATFORM}/static/${CPU_ARCHITECTURE}/${CPU_ARCHITECTURE_BIT}" )

    # STATIC Libraries for Platform
    if ( WIN32 OR WIN64 OR MINGW OR MINGW64 )
        set ( GLFW3_LOCATION "${GLFW_LIBS_PATH}/glfw3.lib" )
    else ( WIN32 OR WIN64 OR MINGW OR MINGW64 )
        message ( FATAL_ERROR "${PROJECT_NAME} - enexpected platform, configuration required" )
    endif ( WIN32 OR WIN64 OR MINGW OR MINGW64 )

    # Validate GLFW3 Includes
    if ( NOT EXISTS "${GLFW_INCLUDE_DIR}/GLFW/glfw3.h" )
        message ( FATAL_ERROR "${PROJECT_NAME} - GLFW3 headers not found at <${GLFW_INCLUDE_DIR}>" )
    endif ( NOT EXISTS "${GLFW_INCLUDE_DIR}/GLFW/glfw3.h" )

    # Add STATIC GLFW Library
    add_library( glfw STATIC IMPORTED )

    # Set GLFW Library-Object Properties
    set_target_properties( glfw PROPERTIES
    IMPORTED_LOCATION "${GLFW3_LOCATION}" )

    # Add GLFW3 to Link-List
    #set ( LIBS_TO_LINK ${LIBS_TO_LINK} glfw )

    # Link GLFW3
    target_link_libraries ( ${BUILD_TARGET} glfw )

    # Include GLFW3 Headers
    target_include_directories ( ${BUILD_TARGET} PRIVATE ${GLFW_INCLUDE_DIR} )

    message ( STATUS "${PROJECT_NAME} - GLFW3 added as STATIC library from ${GLFW3_LOCATION}" )
else ( NOT GLFW3_FOUND )
    message ( STATUS "${PROJECT_NAME} - package GLFW3 found")

    # Link GLFW3
    target_link_libraries ( ${BUILD_TARGET} ${GLFW3_LIBRARIES} )

    # Include GLFW3 Headers
    target_include_directories ( ${BUILD_TARGET} PRIVATE ${GLFW_INCLUDE_DIR} )

    message ( STATUS "${PROJECT_NAME} - GLFW3 added as STATIC library using package" )
endif ( NOT GLFW3_FOUND )