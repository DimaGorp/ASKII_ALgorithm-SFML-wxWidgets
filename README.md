# ASKII_ALgorithm-SFML-wxWidgets
MyPortfolio

# Building for MacOS  
To download homebrew type this command(if you do have a brew you do not need this commmand): 
```console
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
Check if cmake is installed:
```console
cmake --version
```
if its not, install it with brew
```console
brew install cmake
```
check if your git is downloaded:
```console
git --version
```
if its not,, install it with brew:
```console
brew install git
```
After that you should clone a vcpkg to a current directory:
```console
git clone https://github.com/microsoft/vcpkg.git
```
Go to vcpkg folder and run bootstrap-vcpkg.sh script or you can do it with this command:
```console
./vcpkg/bootstrap-vcpkg.sh
```
Type a command:
```console
mkdir build
```
Type a command:
```console
cmake -S . -B  build/ -DCMAKE_TOOLCHAIN_FILE="./vcpkg/scripts/buildsystems/vcpkg.cmake"  -G "Xcode"
```

if you compile your version for XCode you should go to build folder and open Xcode solution. Run ALL_BUILD script and after that you can run ASKII script and enjoy your programm
# Building for Windows

Check if cmake is installed:
```console
cmake --version
```
if its not, intall cmake from [official page](https://cmake.org/download/)
check if your git is downloaded:
```console
git --version
```
if its not download it from [official page](https://git-scm.com/downloads):
After that you should clone a vcpkg to a current directory:
```console
git clone https://github.com/microsoft/vcpkg.git
```
Go to vcpkg folder and run bootstrap-vcpkg.bat script or you can do it with this command:
```console
./vcpkg/bootstrap-vcpkg.bat
```
Type a command:
```console
mkdir build
```
Type a command:
```console
cmake -S . -B  build/ -DCMAKE_TOOLCHAIN_FILE="./vcpkg/scripts/buildsystems/vcpkg.cmake" 
```

if you are building for visual studio:
Go to your /build directory and open Visual Studio soluttion.
After that you can follow [this tutorial](https://simpleitk.readthedocs.io/en/v2.1.0/buildingWindows.html) to run that project. Dont forget to build 'ALL_BUILD'.Make 'ASKII' as the current project. After that you can run you solution and be happy with your result.
