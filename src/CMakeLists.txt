
# add our library
add_library(ACrossPlatformCppLibrary SHARED
        Adder.cpp Adder.h
        export.h
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
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message(STATUS "gnu")
    # for g++
    target_compile_options(ACrossPlatformCppLibrary PRIVATE -Wall -Wextra)
    # set shared library suffix
    set(SHARED_LIB_EXT "so")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(STATUS "msvc")
    message(STATUS "CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}")

    add_compile_options(/Wall)

    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
        message(STATUS "release")
        add_compile_options(/MD)
    elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        message(STATUS "debug")
        add_compile_options(/MDd)
    endif ()


#    target_compile_options(ACrossPlatformCppLibrary PUBLIC /EHsc /MDd /Wall /c)
    # this is where we set the DLLEXPORT variable to enable exporting symbols
    target_compile_definitions(ACrossPlatformCppLibrary PUBLIC -DLIBRARY_EXPORTS=1)
    set(SHARED_LIB_EXT "dll")
else ()
    message(FATAL "nope")
    set(SHARED_LIB_EXT "dylib")
endif ()


install(TARGETS ACrossPlatformCppLibrary DESTINATION ${CMAKE_INSTALL_PREFIX})

# copy the shared lib to location where it will be used for testing
# https://stackoverflow.com/questions/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake
add_custom_command(TARGET ACrossPlatformCppLibrary POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${PROJECT_BINARY_DIR}/src/ACrossPlatformCppLibrary.${SHARED_LIB_EXT}"      # <--this is in-file
        "${PROJECT_BINARY_DIR}/test/ACrossPlatformCppLibrary.${SHARED_LIB_EXT}")                 # <--this is out-file path
