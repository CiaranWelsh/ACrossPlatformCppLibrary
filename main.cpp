/*
 * This is a simple library for messing around building cross platform c++ dynamic libraries
 *
 * Things to do
 * ------------
 * 1) At first, I will keep things simple and get basic support for cross platform
 * 2) Build the library, compile using msvc
 * 3) Integrate googletest into the project
 * 3) Configure the CI in github to build using msvc in the cloud
 * 4) configure the CI to also try linux/mac
 * 5) return to the cmake file and use GenerateExportHeader
 * 6) Try adding googletest as an external project, rather than including the source code itself.
 * 7) find out a bit about PIC code. Do all shared libraries need to be compiled with PIC support?
 * 8) learn more about 'visibility': https://gcc.gnu.org/wiki/Visibility
 *
 */

#include "export.h"
extern "C"
{
  EXPORTED int add(int a, int b)
  {
      return a + b;
  }
}