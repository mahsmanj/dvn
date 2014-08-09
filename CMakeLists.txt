# Set the required version of CMake
cmake_minimum_required(VERSION 3.0.1)

# Set the project name
project(dvn)

# Set the project version numbers
set(USER_VERSION_MAJOR 0)
set(USER_VERSION_MINOR 0)

# Initialize project-specific CMake settings -- this must proceed project()
include(cmake/initialize.cmake)

# Platform specific compiler flags

if (MSVC)
	# Get rid of a couple warnings
	#set(CMAKE_CXX_LINK_FLAGS "/NODEFAULTLIB:library")
endif()

# Define build targets

add_subdirectory(src/dvn)
add_subdirectory(test/dvn)

add_subdirectory(src/hello)
