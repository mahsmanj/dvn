# Allow the easy inclusion of cmake modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Allow build targets to find the project include files
include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)

# Define required libraries
include(lib/boost)
include(lib/gtest)

# Include the user's settings if they exist
if (EXISTS ${PROJECT_SOURCE_DIR}/user.cmake)
	include(user.cmake)
endif()
