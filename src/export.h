//
// Created by Ciaran on 2/23/2020.
//

#ifndef ACROSSPLATFORMCPPLIBRARY_EXPORT_H
#define ACROSSPLATFORMCPPLIBRARY_EXPORT_H

#pragma once

//#if defined(_WIN32) || defined(_WIN64)
#    ifdef LIBRARY_EXPORTS
#pragma message ( "C Preprocessor got here!" )

#        define EXPORTED __declspec(dllexport)
#    else
#pragma message ( "C Preprocessor got here!2" )
#        define EXPORTED __declspec(dllimport)
#    endif
//#elif
//#    define EXPORTED
//#endif

#endif //ACROSSPLATFORMCPPLIBRARY_EXPORT_H
