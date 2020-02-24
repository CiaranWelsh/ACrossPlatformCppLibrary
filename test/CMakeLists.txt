add_executable(test test_add.cpp)

target_include_directories(
        test PUBLIC
        ${CMAKE_SOURCE_DIR}/lib/googletest/googletest
        ${CMAKE_SOURCE_DIR}
)
MESSAGE(STATUS "CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")
#target_link_directories(test PUBLIC
#        ${CMAKE_BINARY_DIR}
#        ${CMAKE_BINARY_DIR}/src
#        )
#find_library(LIB
#        ACrossPlatformCppLibrary
#        PATHS
#            ${CMAKE_BINARY_DIR}
#            ${CMAKE_BINARY_DIR}/src
#        )

#add_library(ACrossPlatformCppLibrary SHARED IMPORTED)
#set_property(TARGET ACrossPlatformCppLibrary
#        PROPERTY IMPORTED_LOCATION
#        ${CMAKE_BINARY_DIR}/src
#        )

MESSAGE(STATUS "LIB ${LIB}")


target_link_libraries(test
        PUBLIC
        gtest
        gtest_main
        )