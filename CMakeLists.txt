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
    # ENGINE.CORE
    "${PUBLIC_DIR}engine/cfg/memory.hpp"
    "${PUBLIC_DIR}engine/cfg/mutex.hpp"
    "${PUBLIC_DIR}engine/core/utils/metrics/ILogger.hxx"
    "${PUBLIC_DIR}engine/core/utils/metrics/Log.hpp"
    "${PUBLIC_DIR}engine/core/utils/metrics/DefaultLogger.hpp"
    "${PUBLIC_DIR}engine/core/graphics/IGraphicsManager.hxx"
    "${PUBLIC_DIR}engine/core/graphics/GraphicsManager.hpp"
    "${PUBLIC_DIR}engine/core/ecs/systems/ISystem.hxx"
    "${PUBLIC_DIR}engine/core/ecs/systems/System.hpp"
    # ENGINE.WINDOWS
    "${PUBLIC_DIR}engine/windows/graphics/WinGraphics.hpp"
    )

# =================================================================================
# SOURCES
# =================================================================================

set ( PROJECT_SOURCES
    # APP
    "${PRIVATE_DIR}main.cpp"
    # ENGINE.CORE
    "${PRIVATE_DIR}engine/core/utils/metrics/Log.cpp"
    "${PRIVATE_DIR}engine/core/utils/metrics/DefaultLogger.cpp"
    "${PRIVATE_DIR}engine/core/graphics/GraphicsManager.cpp"
    "${PRIVATE_DIR}engine/core/ecs/systems/System.cpp"
    # ENGINE.WINDOWS
    "${PRIVATE_DIR}engine/windows/graphics/WinGraphics.cpp"
    )

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
# BUILD
# =================================================================================

# Add Executable Object
add_executable ( ${BUILD_TARGET} ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${EXECUTABLE_RESOURCES} )

# Configure Executable-Object
set_target_properties ( ${BUILD_TARGET} PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY "${RUNTIME_OUTPUT_DIRECTORY}" )

# =================================================================================
# LIBRARIES
# =================================================================================

# - - - - - - - - - - - - - - - - - - OpenGL - - - - - - - - - - - - - - - - - - -

include ( "${CMAKE_INCLUDES_DIR}opengl.cmake" )

# - - - - - - - - - - - - - - - - - - GLFW - - - - - - - - - - - - - - - - - - - -

include ( "${CMAKE_INCLUDES_DIR}glfw.cmake" )

# ------------------------------------------------------------------------------
