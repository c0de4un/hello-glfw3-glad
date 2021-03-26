# CMake Includes
set ( CMAKE_INCLUDES_DIR "cmake/" )

# Platform
set ( PLATFORM "0" CACHE STRING "Manually set platform (windows, linux, android, mac or ios)" )

# Libraries Dir
set ( LIBS_DIR "${CMAKE_SOURCE_DIR}/libs/" CACHE STRING "Libraries & Includes dir" )

# Sources Dir
set ( SRC_DIR "${CMAKE_SOURCE_DIR}/src/" CACHE STRING "Public/Include project headers dir" )

# Public-Sources Dir
set ( PUBLIC_DIR "${SRC_DIR}public/" CACHE STRING "Public/Include project sources dir" )

# Private-Sources Dir
set ( PRIVATE_DIR "${SRC_DIR}private/" CACHE STRING "Private project sources dir" )

# Current Build Target ID
set ( BUILD_TARGET "HelloOpenGL" CACHE STRING "Private project sources dir" )

# Output dir
set ( RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin" CACHE STRING "Private project sources dir" )

# ABI
set ( CPU_ARCHITECTURE "x86" CACHE STRING "CPU Architecture base" )
set ( CPU_ARCHITECTURE_BIT "64" CACHE STRING "CPU Architecture bit-extension" )