# Battleships

This is a grid based battleship game played between two players who attempt to destroy their oponents ships, the player who manages to destroy all ships first wins. Currently only a game within two players is supported however another instance can be created by inheriting class Game. Moreover on compilation the code generates a shared library which can be used any where on your system however for convinience there is a executable file which instantly starts the game.  

## Environment & Requirements  

The code is developed in C++ with C++11 features, moreover for building the code the compilation instruction are implemented in CMake. The code when compiled generates a shared library and also an executable file which can be used to run the code directly without even writing any code. The code can be build with enabling or disabling unit tests. Presently the have been successfully compiled and tested on Linux (Ubuntu 14.04 LTS) and Mac OSX 10.11.2 with both Clang and Gnu compilers although on windows system there are some issues persisting (WIP).  

These requirements for compiling code  
* C++ compiler (GNU <= v4.8, Clang <= v3.6, vc++)
* Cmake v2.8 or greater
* Mac & linux
* Windows (VC++ compiler and CMake)  

### For Generating Project Files  

* Xcode - `cmake -G Xcode .`
* Visual Studio Solution - `cmake -G "Visual Studio 10" .`  

## Installation

While obtaining code from [GitHub](https://github.com)  
```
git clone --recursive https://github.com/saifmulla/Battleships
```  
### Installation script  

after obtaining the code simply run `./install.sh` from project root directory

### Manual Installation  

For clean compile and installation of code inside code directory
```
mkdir build && cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=<installation_path_for_binaries>
make && make install
```
The above steps should install shared library in lib directory and `run` in bin directory and all header files in include directory

### Manual installation with unit tests
For unit testing [Google Testing Framework](https://github.com/google/googletest) is used to compile along with unit testing, although the framework is predownloaded in source code provided in `external` directory.
```
mkdir build && cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=<installation_path_for_binaries> -DBUILD_UNIT_TESTS=ON
if any preference for compiler add extra parameter -DCMAKE_CXX_COMPILER=<compiler-name>
make test or ctest
make && make install
```  

## Running the code
The compilation generates shared library and runnable binary file, although it is not necessary to use the shared library
the code is written in executable `run` which can be used to generate outputs. The executable through compilation is generated in same directory where it is compiled therefore can be run by `./run` command however if desired this executable could be globally accessed by setting up `$PATH` and `$LD_LIBRARY_PATH` on linux or `$DYLD_LIBRARY_PATH` on Mac OSX.  
```
run
```  
Moreover while inputing the grid index for the moment one has to input the exact 0 based 2d grid index for the grid, like 0 0 or 0 9 this is very inconvinient but will be trying to provide a better interface very soon.  
  