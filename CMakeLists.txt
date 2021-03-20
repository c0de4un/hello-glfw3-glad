# ------------------------------------------------------------------------------

# // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#
# Example of GLFW3 + GLAD using CMake
#
# License: see "LICENSE" file.
#
# // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.6 FATAL_ERROR ) # QT & Android

# =================================================================================
# OPTIONS
# =================================================================================

set ( CXX_VERSION 11 )

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "Hello_OpenGL" )

# Project Version
set ( PROJECT_VERSION 0.0.1 )

# Project Description
set ( PROJECT_DESCRIPTION "GLFW3 and GLAD CMake-Example" )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# C++ Version
set ( CMAKE_CXX_STANDARD ${CXX_VERSION} )
#set ( CMAKE_CXX_STANDARD 17 ) # Android stdlibc++ 14+
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set Flags
# Flags:
# -fexceptions - enable C++ exceptions (GCC & MSVC), fcxx-exceptions (Clang);
set ( CMAKE_CXX_FLAGS "-fexceptions -fcxx-exceptions" ${CMAKE_CXX_FLAGS} )

# =================================================================================
# OPTIONS & CONSTANTS
# =================================================================================

include ( "cmake/options.cmake" )

# =================================================================================
# CONFIGS
# =================================================================================

# Build-Type (debug, release)
include ( "${CMAKE_INCLUDES_DIR}buildType.cmake" )

# Platform
if ( PLATFORM STREQUAL "0" )
    include ( "${CMAKE_INCLUDES_DIR}platform.cmake" )
endif ( PLATFORM STREQUAL "0" )

# =================================================================================
# HEADERS
# =================================================================================

set ( PROJECT_HEADERS
    "${LIBS_DIR}glad/include/gl.h" )

# =================================================================================
# SOURCES
# =================================================================================

set ( PROJECT_SOURCES
    "${PRIVATE_DIR}main.cpp" )

# =================================================================================
# RESOURCES
# =================================================================================

# Windows Resources
if ( WINDOWS )
    set ( EXECUTABLE_RESOURCES "res/win/win_res.rc" )
else ( WINDOWS )
    set ( EXECUTABLE_RESOURCES "" )
endif ( WINDOWS )

# =================================================================================
# LIBRARIES
# =================================================================================

# List of Libraries-Objects to Link Target with
set ( LIBS_TO_LINK "" )

# - - - - - - - - - - - - - - - - - - OpenGL - - - - - - - - - - - - - - - - - - -

include ( "${CMAKE_INCLUDES_DIR}opengl.cmake" )

# - - - - - - - - - - - - - - - - - - GLFW - - - - - - - - - - - - - - - - - - - -

include ( "${CMAKE_INCLUDES_DIR}glfw.cmake" )

# =================================================================================
# BUILD
# =================================================================================

# Add Executable Object
add_executable ( ${EXECUTABLE_OUTPUT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${EXECUTABLE_RESOURCES} )

# Configure Executable-Object
set_target_properties ( ${EXECUTABLE_OUTPUT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY "${RUNTIME_OUTPUT_DIRECTORY}" )

# Link
target_link_libraries ( ${EXECUTABLE_OUTPUT_NAME} ${LIBS_TO_LINK} )

# ------------------------------------------------------------------------------
