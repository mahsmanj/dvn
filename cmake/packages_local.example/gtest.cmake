set(GTEST_ROOT "D:/Libraries/packages/gtest-1.7.0")

set(GTEST_INCLUDE_DIRS ${GTEST_ROOT}/include CACHE PATH "" FORCE)

set(GTEST_LIBRARY_DIRS_DEBUG ${GTEST_ROOT}/lib CACHE PATH "" FORCE)
set(GTEST_LIBRARY_DIRS_RELEASE ${GTEST_ROOT}/lib CACHE PATH "" FORCE)

set(GTEST_LIBRARY_FILES_DEBUG gtestd CACHE STRING "" FORCE)
set(GTEST_LIBRARY_FILES_RELEASE gtest CACHE STRING "" FORCE)

set(GTEST_CXX_FLAGS "" CACHE STRING "" FORCE)
set(GTEST_CXX_FLAGS_DEBUG "" CACHE STRING "" FORCE)
set(GTEST_CXX_FLAGS_RELEASE "" CACHE STRING "" FORCE)

set(GTEST_LINK_FLAGS "" CACHE STRING "" FORCE)
set(GTEST_LINK_FLAGS_DEBUG "" CACHE STRING "" FORCE)
set(GTEST_LINK_FLAGS_RELEASE "" CACHE STRING "" FORCE)
