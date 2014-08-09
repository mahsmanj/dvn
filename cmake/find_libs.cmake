# Find the information for the specified libs in TARGET_LIBS.
#
# This produces the following variables:
#
#     TARGET_INCLUDE_DIRS
#
#     TARGET_LIBRARY_DIRS_DEBUG
#     TARGET_LIBRARY_DIRS_RELEASE
#
#     TARGET_LIBRARY_FILES_DEBUG
#     TARGET_LIBRARY_FILES_RELEASE
#
#     TARGET_LIBRARIES_DEBUG - absolute paths to library files
#     TARGET_LIBRARIES_RELEASE
#
#     TARGET_CXX_FLAGS
#     TARGET_CXX_FLAGS_DEBUG
#     TARGET_CXX_FLAGS_RELEASE
#
#     TARGET_LINK_FLAGS
#     TARGET_LINK_FLAGS_DEBUG
#     TARGET_LINK_FLAGS_RELEASE

# For each specified library in TARGET_LIBS
foreach (LIB ${TARGET_LIBS})
	# Ensure all library names are uppercase
	string(TOUPPER ${LIB} LIB)

	# Get the library information from the library variables

    list(APPEND TARGET_INCLUDE_DIRS ${${LIB}_INCLUDE_DIRS})

	list(APPEND TARGET_LIBRARY_DIRS_DEBUG ${${LIB}_LIBRARY_DIRS_DEBUG})
	list(APPEND TARGET_LIBRARY_DIRS_RELEASE ${${LIB}_LIBRARY_DIRS_RELEASE})

	list(APPEND TARGET_LIBRARY_FILES_DEBUG ${${LIB}_LIBRARY_FILES_DEBUG})
	list(APPEND TARGET_LIBRARY_FILES_RELEASE ${${LIB}_LIBRARY_FILES_RELEASE})

	list(APPEND TARGET_CXX_FLAGS ${${LIB}_CXX_FLAGS})
	list(APPEND TARGET_CXX_FLAGS_DEBUG ${${LIB}_CXX_FLAGS_DEBUG})
	list(APPEND TARGET_CXX_FLAGS_RELEASE ${${LIB}_CXX_FLAGS_RELEASE})

	list(APPEND TARGET_LINK_FLAGS ${${LIB}_LINK_FLAGS})
	list(APPEND TARGET_LINK_FLAGS_DEBUG ${${LIB}_LINK_FLAGS_DEBUG})
	list(APPEND TARGET_LINK_FLAGS_RELEASE ${${LIB}_LINK_FLAGS_RELEASE})
endforeach()

# For each library file
foreach (LIBRARY_FILE ${TARGET_LIBRARY_FILES_DEBUG})

	# Find the library in the given paths
	find_library(
		LIB_${LIBRARY_FILE}_DEBUG
		${LIBRARY_FILE}
		${TARGET_LIBRARY_DIRS_DEBUG})

	list(APPEND TARGET_LIBRARIES_DEBUG ${LIB_${LIBRARY_FILE}_DEBUG})

	# find_library caches the library variable for cmake-gui. This line hides
	# this variable from the cache. We may want to uncomment this to show
	# the user what libraries were found.
	#unset(LIB_${LIBRARY_FILE}_DEBUG CACHE)
endforeach()

#TODO: Refactor this loop and the one above into a function of some kind
# For each library file
foreach (LIBRARY_FILE ${TARGET_LIBRARY_FILES_RELEASE})

	# Find the library in the given paths
	find_library(
		LIB_${LIBRARY_FILE}_RELEASE
		${LIBRARY_FILE}
		${TARGET_LIBRARY_DIRS_RELEASE})

	list(APPEND TARGET_LIBRARIES_RELEASE ${LIB_${LIBRARY_FILE}_RELEASE})

	# find_library caches the library variable for cmake-gui. This line hides
	# this variable from the cache. We may want to uncomment this to show
	# the user what libraries were found.
	#unset(LIB_${LIBRARY_FILE}_RELEASE CACHE)
endforeach()
