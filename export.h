//
// Created by Ciaran on 2/23/2020.
//

#ifndef ACROSSPLATFORMCPPLIBRARY_EXPORT_H
#define ACROSSPLATFORMCPPLIBRARY_EXPORT_H

#pragma once

#ifdef _WIN32
#   ifdef WIN_EXPORT
#       define EXPORTED __declspec(dllexport)
#   else
#       define EXPORTED __declspec(dllimport)
#   endif
#else
#   define EXPORTED
#endif


#endif //ACROSSPLATFORMCPPLIBRARY_EXPORT_H
