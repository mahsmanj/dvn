# Allow the easy inclusion of cmake modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Allow build targets to find the project include files
include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)

#TODO: Shorten and simplify the path specifications below
# Define required libraries
file(GLOB_RECURSE PACKAGE_FILES cmake/packages/*.cmake)
foreach(PACKAGE_FILE ${PACKAGE_FILES})
	include(${PACKAGE_FILE})
endforeach()

# Define required libraries for the local machine, if they exist on filesystem
file(GLOB_RECURSE PACKAGE_FILES cmake/packages_local/*.cmake)
foreach(PACKAGE_FILE ${PACKAGE_FILES})
	include(${PACKAGE_FILE})
endforeach()

# Include the user's local machine settings if they exist on filesystem
if (EXISTS cmake/initialize_local.cmake)
	include(initialize_local)
endif()
