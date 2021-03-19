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
# CONFIGS
# =================================================================================

set ( PUBLIC_DIR "src/public/" )
set ( PRIVATE_DIR "src/private/" )
set ( EXECUTABLE_OBJECT "HelloOpenGL" ) # Executable Object Name

# =================================================================================
# HEADERS
# =================================================================================

set ( PROJECT_HEADERS
	"" )

# =================================================================================
# SOURCES
# =================================================================================

set ( PROJECT_SOURCES
	"${PRIVATE_DIR}main.cpp" )

# =================================================================================
# BUILD
# =================================================================================

# Add Executable Object
add_executable ( ${EXECUTABLE_OBJECT} ${PROJECT_HEADERS} ${PROJECT_SOURCES} )

# Configure Executable-Object
set_target_properties ( ${EXECUTABLE_OBJECT} PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" )

# ------------------------------------------------------------------------------
