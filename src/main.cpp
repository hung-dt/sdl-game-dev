#ifdef __cplusplus
#include <cstdlib>
#include <cstdio>
#else
#include <stdlib.h>
#include <stdio.h>
#endif

#include "GameSDL.h"

const int FPS = 60;
const int DELAY_TIME = 1000 / FPS;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main (int argc, char** argv)
{
  GameSDL& game = GameSDL::instance();

  if (!game.init ("SDL Game Development",
                  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) {
    return 1;
  }

  unsigned frameStart, frameTime;

  // Enter Game loop
  while (game.isRunning()) {
    frameStart = SDL_GetTicks();

    game.handleEvents();
    game.update();
    game.render();

    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < DELAY_TIME) {
      SDL_Delay (DELAY_TIME - frameTime);
    }
  }

  return 0;
}
