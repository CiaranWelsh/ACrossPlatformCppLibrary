$CMAKE_URL = "https://github.com/Kitware/CMake/releases/download/v3.17.0-rc1/cmake-3.17.0-rc1-win64-x64.zip"
$CWD = $(Get-Location)
$CMAKE_DOWNLOADED_FILE = "$CWD\cmake.zip"
$CMAKE_DIR = "$CWD\cmake"
$CMAKE_BIN_DIR = "$CWD\cmake\cmake-3.17.0-rc1-win64-x64\bin"
$MSVC_X64_ROOT = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64"
$DEVENV = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe"

if (![System.IO.File]::Exists($CMAKE_DOWNLOADED_FILE)){
	Invoke-WebRequest $CMAKE_URL -OutFile $CMAKE_DOWNLOADED_FILE
}
if (!(Test-Path $CMAKE_DIR)){
	Expand-Archive $CMAKE_DOWNLOADED_FILE -DestinationPath $CMAKE_DIR
}
$Env:Path += ";$CMAKE_BIN_DIR"
echo $Env:Path

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 16 2019" ..

& $DEVENV ACrossPlatformCppLibrary.sln -Build
echo $pwd
cd test
echo $pwd
cd Debug 
echo $pwd
ls

.\test.exe

cd $CWD







