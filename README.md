# ASKII_ALgorithm-SFML-wxWidgets
MyPortfolio

# Building for MacOS  
To download brew type this command(if you have brew installed go to downloading SFML): 
```console
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
if you don't have installed cmake type in console the next command: 
```console
brew install cmake
```
After that type that command in Terminal:
```console
brew install sfml
```
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
build/TEST
```
