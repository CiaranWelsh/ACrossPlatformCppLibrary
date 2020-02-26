
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
# for linux but not cygwin
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # for g++
    message(STATUS "GNUED")
    target_compile_options(ACrossPlatformCppLibrary PRIVATE -Wall -Wextra -shared )

    # fix linker error: undefined reference to dlopen
    # https://gist.github.com/kwk/3595733
    target_link_directories(ACrossPlatformCppLibrary PRIVATE dl)
#    target_link_libraries(ACrossPlatformCppLibrary PRIVATE /lib/x86_64-linux-gnu/dl)
#    target_link_libraries(ACrossPlatformCppLibrary PRIVATE /lib/x86_64-linux-gnu/libdl.so.2)
    # set shared library suffix
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(STATUS "CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}")
    add_compile_options(/Wall)
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
        message(STATUS "release")
        add_compile_options(/MD)
    elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        message(STATUS "debug")
        add_compile_options(/MDd)
    endif ()
    # this is where we set the DLLEXPORT variable to enable exporting symbols
else ()
    message(FATAL "nope")
endif ()
target_compile_definitions(ACrossPlatformCppLibrary PUBLIC -DLIBRARY_EXPORTS=1)

install(TARGETS ACrossPlatformCppLibrary DESTINATION ${CMAKE_INSTALL_PREFIX})


# copy the shared lib to location where it will be used for testing
#   https://stackoverflow.com/questions/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake
# uses generator expressions in combination with add_custom_command
#   https://stackoverflow.com/questions/35695152/cmake-generator-expression-is-not-being-evaluated
add_custom_command(
        TARGET ACrossPlatformCppLibrary
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:ACrossPlatformCppLibrary>"
        "$<TARGET_FILE_DIR:test>/ACrossPlatformCppLibrary${CMAKE_SHARED_LIBRARY_SUFFIX}"
)

