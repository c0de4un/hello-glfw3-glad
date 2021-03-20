if ( ${CMAKE_BUILD_TYPE} STREQUAL Debug )
    message ( STATUS "${PROJECT_NAME} - DEBUG-Mode enabled" )

    set ( BUILD_TYPE "debug" )
    set ( DEBUG ON )
    add_definitions ( -DDEBUG=1 )
else ( ${CMAKE_BUILD_TYPE} STREQUAL Debug )
    message ( STATUS "${PROJECT_NAME} - DEBUG-Mode disabled" )

    set ( BUILD_TYPE "release" )
    set ( DEBUG OFF )
    add_definitions ( -DDEBUG=0 )
endif ( ${CMAKE_BUILD_TYPE} STREQUAL Debug )