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

## SDL 2.0.10 in Windows
### Installation
- Download development libraries [here](http://libsdl.org/download-2.0.php). We need MinGW development libraries:
![SDL download](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/mingw/mingw_package.png)
- Extract to `\Dev\SDL2-2.0.10`
- Create an environment variable `SDL2_HOME`
```
setx SDL2_HOME D:\Dev\SDL2-2.0.10\x86_64-w64-mingw32
```
- Put `\Dev\SDL2-2.0.10\x86_64-w64-mingw32\bin` to %PATH% so dynamic libraries can be found.
### Compile a sample app
- Sample app:
```cpp
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
```
- Build using CMake

Create a config file in `\Dev\SDL2-2.0.10\x86_64-w64-mingw32\lib\cmake\SDL2\SDL2_Config.cmake`:
```
set(prefix "$ENV{SDL2_HOME}") 
set(exec_prefix "${prefix}")
set(libdir "${exec_prefix}/lib")

set(SDL2_PREFIX "$ENV{SDL2_HOME}")
set(SDL2_EXEC_PREFIX "$ENV{SDL2_HOME}")
set(SDL2_LIBDIR "${exec_prefix}/lib")
set(SDL2_INCLUDE_DIRS "${prefix}/include/SDL2")
set(SDL2_LIBRARIES "-L${SDL2_LIBDIR} -lmingw32 -lSDL2main -lSDL2 -mwindows")
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
```

Create a CMakeLists.txt to build the sample app:
```
cmake_minimum_required(VERSION 3.10.0)
project(sdl2 VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH $ENV{SDL2_HOME}/lib/cmake/SDL2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -Wextra -O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(SDL2_Config)

add_executable(sdl2_app main.cpp)
target_include_directories(sdl2_app
    PRIVATE ${SDL2_INCLUDE_DIRS}
)
target_link_libraries(sdl2_app
    PRIVATE ${SDL2_LIBRARIES}
)
```

## References

* [Lazy Foo's SDL tutorials](http://lazyfoo.net/tutorials/SDL/index.php)
