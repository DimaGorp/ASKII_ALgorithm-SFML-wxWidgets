# ASKII_ALgorithm-SFML-wxWidgets
MyPortfolio

# Building for MacOS  
To download homebrew type this command(if you do have a brew you do not need this commmand): 
```console
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
if you don't have installed cmake type in console the next command: 
```console
brew install cmake
```
After that you should setup a pyhton:
```console
brew install python
```
You can check your python version by simple type(we need Python3):
```console
python --version
```
if this what you see that means that everything alright:
***
![](icons/1.png)
***
Now lets setup a conan. We need version below 2.00:
```console
pip install -v "conan<2"
```
After that we can check our conan verison by simply type:
```console
conan --version
```
If you see that result that means that everything is alright and we inastalled our 1.61.0 version of conan:
```console
Conan version 1.61.0
```
Go to that repository directory throuh trminal with command:
```console
cd "[This repository directory]"
```
Type a command:
```console
mkdir build
```
Type that command to install needed .cmake files in build directory. Remember that any packages that you are installing are installs in .conan folder:
```console
cd build && conan install .. --build=missing
```
The last step is to open a downloaded local repository folder from terminal and type next commands (step by step): 
```console
cmake ..
make
```
And finaly you can run compiled script with command:
```console
./ASKII
```
# Building for Windows
Install pyhton for windows [How to install Python 3.8 on Windows 10 in 2020](https://youtu.be/LuQjh2Q0UzQ?si=x4LcXUvL6kSy3iU5).Dont forget to add python to PATH and customise installation by 'install python for all users' and 'install pip'.
After that check python version and pip version to make sure that they was added to PATH variable. Just type in your terminal:
```console
python --version
```
```console
pip --version
```
Also you need to check if cmake is installed:
```console
cmake --version
```
After that we can install conan:
```console
pip install -v "conan<2"
```
You need to add directory where your conan.exe file is located to your PATH varibale. It ususally install in your Script/ directory. So make sure that you added it.
After that you can check you conan version by type:
```console
conan --version
```
If you see that result that means that everything is alright and we inastalled our 1.61.0 version of conan:
```console
Conan version 1.61.0
```
Go to that repository directory throuh trminal with command:
```console
cd "[This repository directory]"
```
Type a command:
```console
mkdir build
```
Type that command to install needed .cmake files in build directory. Remember that any packages that you are installing are installs in .conan folder:
```console
cd build && conan install .. --build=missing
```
The last step is to open a downloaded local repository folder from terminal and type: 
```console
cmake ..
```
Go to your /build directory and open Visual Studio soluttion.
After that you can follow [this tutorial](https://simpleitk.readthedocs.io/en/v2.1.0/buildingWindows.html) to run that project. Dont forget to build 'ALL_BUILD'. Choose 'Release' configuration and make 'ASKII' as the current project. After that you can run you solution and be happy with your result.
