//
// Created by Ciaran on 2/23/2020.
//

#include "gtest/gtest.h"

#if defined(_WIN32) || defined (_WIN64) || defined(__CYGWIN__)
    #include <windows.h>
#elif defined(__linux__)

#include <dlfcn.h>
#endif


TEST(test, test_add_windows) {
    typedef int (*addPtr)(int, int);
#if defined(_WIN32) || defined (_WIN64) || defined(__CYGWIN__)
    std::cout << "windows" << std::endl;
    HINSTANCE hinstLib = LoadLibraryA(TEXT("ACrossPlatformCppLibrary.dll"));
    ASSERT_NE(hinstLib, nullptr);
    auto add = (addPtr) GetProcAddress(hinstLib, "add");
    ASSERT_NE(add, nullptr);
#elif defined(__linux__)
    std::cout << "GNU" << std::endl;
    void* handle;
    handle = dlopen("ACrossPlatformCppLibrary.dll.a", RTLD_LAZY);
    ASSERT_NE(handle, nullptr);
    auto add = (addPtr) dlsym(handle, "add");
#elif defined(__APPLE__)
    // something else.
#endif
    int x = 5;
    int y = 6;
    int answer = add(x, y);
    ASSERT_EQ(answer, 11);
//    BOOL fFreeResult = FreeLibrary(hinstLib);
}

//TEST(test, test2) {
//    char *fileExt;
//    char szDir[256]; //dummy buffer
//    GetFullPathName(".", 256, szDir, &fileExt);
//    printf("Full path: %s\nFilename: %s", szDir, fileExt);
//}