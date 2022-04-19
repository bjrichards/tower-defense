# Single Player Strategic Game: Shape Wars

## Description
Shape Wars is a 2D single player (player versus computer) game based on sending out soldiers to destory the enemy tower. Players can upgrade their soldiers, add more HP to their tower, and increase their mana by using their gold which is obtained during the game.

The further the player progresses in the game the more difficult and powerful the enemy becomes. 

This game is created using a prototype of the Noelle engine. This is a 2D game engine created by me. The engine is built on top of SDL2 using the C++ language.

## Table of Contents
* [How to Run](#how-to-run)
* [How to Use](#how-to-use)

<a name="how-to-run"></a>
## How to Run
The GitHub repo only contains a Windows build (.exe), however the source can be downloaded and built on any OS that supports g++.

### Required modules:
* [SDL2](https://www.libsdl.org/)
* [SDL2-TTF](https://github.com/libsdl-org/SDL_ttf)

From the above modules, place the following into the bin folder:
* libfreetype-6.dll
* SDL2_ttf.dll
* SDL2.dll
* zlib1.dll

### Windows
On Windows, you can either navigate to the bin folder in File Explorer and double click the <b>tower_wars.exe</b> or you can run from cmd as:
```console
./tower_wars.exe
```

### Linux/MacOs/etc.
The application can be made using the included makefile.

First, SDL2 and SDL-ttf needs to be downloaded and placed appropriately in the include and lib folders.

Then the application can be made with make by running the following command in the top project directory:
```console
make
```

Then run the application by navigating to the bin folder and running the following command:
```console
./tower_wars.exe
```

<a name="how-to-use"></a>
## How to Use
TBD

