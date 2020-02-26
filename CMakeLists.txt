cmake_minimum_required(VERSION 3.15)

set(PROJECT_VERSION "1.0")

project(ACrossPlatformCppLibrary VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 14)

# set the default build configuration to debug
if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  message(STATUS "No build type selected, default to Debug")
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type (default Debug)" FORCE)
endif()

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

# In windows, to must set the CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS variable to true to compile a shared
# library.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# set shared library extension
# if we are on windows
if (("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows") OR ("${CMAKE_SYSTEM_NAME}" STREQUAL "CYGWIN"))
  MESSAGE(STATUS 1)
  set(SHARED_LIB_EXT "dll")
elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "LINUX")
  MESSAGE(STATUS 2)
  set(SHARED_LIB_EXT "so")
elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "DARWIN")
  MESSAGE(STATUS 3)
  set(SHARED_LIB_EXT "dylib")
endif ()

MESSAGE(STATUS "SHARED_LIB_EXT ${SHARED_LIB_EXT}")

add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(test)


message(STATUS "
CMAKE_PROJECT_NAME                  ${CMAKE_PROJECT_NAME}
PROJECT_VERSION                     ${PROJECT_VERSION}
CMAKE_BUILD_TYPE                    ${CMAKE_BUILD_TYPE}
CMAKE_CXX_COMPILER_ID               ${CMAKE_CXX_COMPILER_ID}
CMAKE_INSTALL_PREFIX                ${CMAKE_INSTALL_PREFIX}
SHARED_LIB_EXT                      ${SHARED_LIB_EXT}
CMAKE_SHARED_LIBRARY_SUFFIX         ${CMAKE_SHARED_LIBRARY_SUFFIX}
CMAKE_SHARED_LIBRARY_PREFIX         ${CMAKE_SHARED_LIBRARY_PREFIX}
CMAKE_DL_LIBS                       ${CMAKE_DL_LIBS}
")









