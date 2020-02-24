//
// Created by Ciaran on 2/23/2020.
//

#include <windows.h>
#include "gtest/gtest.h"

TEST(test, test_add_windows) {
//#if defined(_WIN32) || defined (_WIN64)
    typedef int (*addPtr)(int, int);
//    HINSTANCE hinstLib = LoadLibrary(TEXT("D:\\ACrossPlatformCppLibrary\\test\\ACrossPlatformCppLibrary.dll"));
    HINSTANCE hinstLib = LoadLibraryA(TEXT("ACrossPlatformCppLibrary.dll"));
    std::cout << hinstLib << std::endl;
    ASSERT_NE(hinstLib, nullptr);
    auto add = (addPtr) GetProcAddress(hinstLib, "add");
    ASSERT_NE(add, nullptr);
    int x = 5;
    int y = 6;
    int answer = add(x, y);
    ASSERT_EQ(answer, 11);
    BOOL fFreeResult = FreeLibrary(hinstLib);
//#else
//    ASSERT_TRUE(true);
//#endif
}

TEST(test, test2) {
    char *fileExt;
    char szDir[256]; //dummy buffer
    GetFullPathName(".", 256, szDir, &fileExt);
    printf("Full path: %s\nFilename: %s", szDir, fileExt);
}