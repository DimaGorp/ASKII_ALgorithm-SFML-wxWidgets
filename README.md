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
![What is this](icons/1.png)
Open the folder with downloaded repository and type that command:
```console
mkdir build
```

The last step is to open a downloaded local repository folder from terminal and type next commands (step by step): 
```console
cmake -S . -B build/
cmake --build build/
```
And finaly you can run compiled script with command:

```console
build/ASKII
```
# Building for Windows
