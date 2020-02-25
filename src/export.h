//
// Created by Ciaran on 2/23/2020.
//

#ifndef ACROSSPLATFORMCPPLIBRARY_EXPORT_H
#define ACROSSPLATFORMCPPLIBRARY_EXPORT_H

#pragma once

// If windows 32/64 or cygwin
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
////  When building dll, LIBRARY_EXPORTS is defined
#    ifdef LIBRARY_EXPORTS
        // when using GNU we use linux syntax
#       ifdef __GNUC__
#           define EXPORTED __attribute__ ((dllexport))
#       else
        // when using windows we use windows syntax
#           define EXPORTED __declspec(dllexport)
#       endif
#    else
#       ifdef __GNUC__
#           define EXPORTED __attribute__ ((dllimport))
#       else
#           define EXPORTED __declspec(dllexport)
#       endif
#   endif
#   define NOT_EXPORTED
#else
#   if __GNUC__ >= 4
#       define EXPORTED __attribute__ ((visibility ("default")))
#       define NOT_EXPORTED __attribute__ ((visibility ("hidden")))
#   else
#       define EXPORTED
#       define NOT_EXPORTED
#   endif
#endif



#endif //ACROSSPLATFORMCPPLIBRARY_EXPORT_H


/*
 * https://atomheartother.github.io/c++/2018/07/12/CPPDynLib.html
 * #if defined _WIN32 || defined __CYGWIN__
 *   #ifdef WIN_EXPORT
 *     // Exporting...
 *     #ifdef __GNUC__
 *       #define EXPORTED __attribute__ ((dllexport))
 *     #else
 *       #define EXPORTED __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
 *     #endif
 *   #else
 *     #ifdef __GNUC__
 *       #define EXPORTED __attribute__ ((dllimport))
 *     #else
 *       #define EXPORTED __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
 *     #endif
 *   #endif
 *   #define NOT_EXPORTED
 * #else
 *   #if __GNUC__ >= 4
 *     #define EXPORTED __attribute__ ((visibility ("default")))
 *     #define NOT_EXPORTED  __attribute__ ((visibility ("hidden")))
 *   #else
 *     #define EXPORTED
 *     #define NOT_EXPORTED
 *   #endif
 * #endif
 */