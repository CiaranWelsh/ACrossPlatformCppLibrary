# powershell.exe
# some variables like paths, urls etc.
$REPO_URL = "https://github.com/CiaranWelsh/ACrossPlatformCppLibrary.git"
$CMAKE_URL = "https://github.com/Kitware/CMake/releases/download/v3.17.0-rc1/cmake-3.17.0-rc1-win64-x64.zip"
$CWD = $(Get-Location)
$REPO_ROOT = "$CWD\ACrossPlatformCppLibrary"
$CMAKE_DOWNLOADED_FILE = "$CWD\cmake.zip"
$CMAKE_DIR = "$CWD\cmake"
$CMAKE_BIN_DIR = "$CWD\cmake\cmake-3.17.0-rc1-win64-x64\bin"
$MSVC_X64_ROOT = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.24.28314\bin\Hostx64\x64"
$DEVENV = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe"

# download cmake if we haven't already 
if (![System.IO.File]::Exists($CMAKE_DOWNLOADED_FILE)){
	$ProgressPreference = "SilentlyContinue"
	Invoke-WebRequest $CMAKE_URL -OutFile $CMAKE_DOWNLOADED_FILE
}

# unzip if we haven't already 
if (!(Test-Path $CMAKE_DIR)){
	Expand-Archive $CMAKE_DOWNLOADED_FILE -DestinationPath $CMAKE_DIR
}

# add cmake bin directory to the path variable 
$Env:Path += ";$CMAKE_BIN_DIR"
echo $Env:Path

echo "Generating msvc sln"
# generate msvc files for building
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 16 2019" ..

ls
# build using command line msvc tools
if (!(Test-Path $DEVENV)){
	throw "cannot find devenv at $DEVENV"
}
& $DEVENV ACrossPlatformCppLibrary.sln -Build

# need a reasonably long wait time for devenv to finish up or we wont 
# be able to find the test binary
Start-Sleep -s 10

echo "In build: $pwd"
ls
cd test
echo "in test $pwd"
ls
cd Debug 
echo "in debug: $pwd"
ls
.\test.exe

cd $CWD







