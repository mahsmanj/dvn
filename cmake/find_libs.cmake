# Find the information for the specified libs in TARGET_LIBS

# For each specified library
foreach (LIB ${TARGET_LIBS})
	# Ensure all lib names are uppercase
	string(TOUPPER ${LIB} LIB)

	# Get the LIB_library_* variables into the TARGET_* variables
    list(APPEND TARGET_INCLUDE_DIRS ${LIB_${LIB}_INCLUDE_DIRS})
    list(APPEND TARGET_LIBRARY_DIRS ${LIB_${LIB}_LIBRARY_DIRS})
    list(APPEND TARGET_LIBRARIES ${LIB_${LIB}_LIBRARIES})
endforeach()
