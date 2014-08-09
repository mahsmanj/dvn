# Create a static library.
# Expected variables to be defined:
#     TARGET_NAME - name of the build target
#     TARGET_DEPENDS - in-project build targets this target depends on
#     TARGET_LIBS - libraries with which to link

# Find the information for the specified libs in TARGET_LIBS
# This produces the following variables:
#     TARGET_INCLUDE_DIRS - include directories for the specified libraries
#     TARGET_LIBRARY_DIRS - library directories for the specified libraries
#     TARGET_LIBRARIES - names of the specified libraries for linking
include(find_libs)

# Append the target dependicies to the libraries variable
list(APPEND TARGET_LIBRARIES ${TARGET_DEPENDS})

# Recursively get all possible source code in the current directory
file(GLOB_RECURSE TARGET_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Add the library as a build target
add_library(${TARGET_NAME} STATIC ${TARGET_SRC})

# Specify the include directories to search for include files
include_directories(${TARGET_INCLUDE_DIRS})

# Specify the current build target's libraries to link with
target_link_libraries(${TARGET_NAME} ${TARGET_LIBRARY_DIRS} ${TARGET_LIBRARIES})

# Set the output name of the build target
set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

# Set the build target's version from the project/user version
set_target_properties(${TARGET_NAME} PROPERTIES
	VERSION "${USER_VERSION_MAJOR}.${USER_VERSION_MINOR}")
