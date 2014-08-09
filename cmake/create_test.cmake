# Create a test program.
# Expected variables to be defined:
#     TARGET_NAME - name of the build target
#     TARGET_DEPENDS - in-project build targets this target depends on
#     TARGET_LIBS - libraries with which to link

# Everything is the same as creating an executable except for the post-build
include(create_executable)

# Run the test executable after building the target
add_custom_command(
	TARGET ${TARGET_NAME}
	DEPENDS ${TARGET_NAME}
	POST_BUILD COMMAND ${TARGET_NAME})
