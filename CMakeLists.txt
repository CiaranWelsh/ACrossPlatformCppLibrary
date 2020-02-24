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


add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(test)


message(STATUS "

CMAKE_INSTALL_PREFIX    ${CMAKE_INSTALL_PREFIX}
")









