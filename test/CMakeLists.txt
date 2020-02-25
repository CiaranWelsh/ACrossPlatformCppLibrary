add_executable(test test_add.cpp)

target_include_directories(
        test PUBLIC
        ${CMAKE_SOURCE_DIR}/lib/googletest/googletest
        ${CMAKE_SOURCE_DIR}
)
MESSAGE(STATUS "CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")


MESSAGE(STATUS "LIB ${LIB}")


target_link_libraries(test
        PUBLIC
        gtest
        gtest_main
        )