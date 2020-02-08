# SDL Game Dev Journal

## Compile SDL-2.0.10 in Linux Mint 19.3
In SDL source dir:
```shell
mkdir build && cd build
cmake .. \
-DCMAKE_INSTALL_PREFIX=~/opt/sdl-2.0.10 \
-DCMAKE_BUILD_TYPE=Release \
-DSDL_TEST=OFF \
-DSDL_SHARED=ON \
-DSDL_STATIC=OFF
make -j 4
make install
```
Add to SDL_HOME and LD_LIBRARY_PATH (.zshrc or .bashrc):
```shell
export SDL_HOME=$HOME/opt/sdl-2.0.10
export LD_LIBRARY_PATH=$SFML_HOME/lib:$SDL_HOME/lib:$LD_LIBRARY_PAT
```

## Compile a sample app
Source file:
```cpp
```

CMakeLists.txt
```
cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDL2Test Main.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES})
```

## References
* []()
