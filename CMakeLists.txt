cmake_minimum_required(VERSION 3.15)

set(PROJECT_VERSION "1.0")

project(ACrossPlatformCppLibrary VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 14)

# In windows, to must set the CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS variable to true to compile a shared
# library.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# add our library
add_library(ACrossPlatformCppLibrary SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Here's a question: why do we not have to add 'export.h' into the sources list?
# Does cmake automatically follow includes ?

# This will name your output .so files "libsomething.1.0" which is pretty useful
set_target_properties(ACrossPlatformCppLibrary
        PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION}
        )

# now we need to set some compiler specific flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    # for g++
    target_compile_options(ACrossPlatformCppLibrary PRIVATE -Wall -Wextra)
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    target_compile_options(ACrossPlatformCppLibrary /EHsc /MTd /W2 /c)
    # this is where we set the DLLEXPORT variable to enable exporting symbols
    target_compile_definitions(ACrossPlatformCppLibrary PRIVATE WIN_EXPORT)
endif ()













