# Create a static library.
# Expected variables to be defined:
#     TARGET_NAME - name of the build target
#     TARGET_DEPENDS - in-project build targets this target depends on
#     TARGET_LIBS - libraries with which to link


#TODO: Refactor duplicate code from create_*.cmake
# Find the information for the specified libs in TARGET_LIBS
include(find_libs)

# Append the target dependicies to the libraries variable
list(APPEND TARGET_LIBRARIES_DEBUG ${TARGET_DEPENDS})
list(APPEND TARGET_LIBRARIES_RELEASE ${TARGET_DEPENDS})

# Recursively get all possible source code in the current directory
file(GLOB_RECURSE TARGET_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Add the current directory as a possible source of include files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Specify the include directories to search for include files
include_directories(${TARGET_INCLUDE_DIRS})



# Add the static library as a build target
add_library(${TARGET_NAME} STATIC ${TARGET_SRC})

# Specify the current build target's libraries to link with
if (TARGET_LIBRARIES_DEBUG)
	target_link_libraries(${TARGET_NAME} debug ${TARGET_LIBRARIES_DEBUG})
endif()

if (TARGET_LIBRARIES_RELEASE)
	target_link_libraries(${TARGET_NAME} optimized ${TARGET_LIBRARIES_RELEASE})
endif()


# Set the output name of the build target
set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME ${TARGET_NAME})

# Set the build target's version from the project/user version
set_target_properties(${TARGET_NAME} PROPERTIES
	VERSION "${USER_VERSION_MAJOR}.${USER_VERSION_MINOR}")
