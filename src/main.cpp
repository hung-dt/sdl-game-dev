#ifdef __cplusplus
#include <cstdlib>
#include <cstdio>
#else
#include <stdlib.h>
#include <stdio.h>
#endif

#include "GameSDL.h"

int main (int argc, char** argv)
{
  GameSDL game;

  if (!game.init ("SDL Game Development",
                  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                  640, 480, SDL_WINDOW_SHOWN)) {
    return 1;
  }

  // Enter Game loop
  while (game.isRunning()) {
    game.handleEvents();
    game.update();
    game.render();
  }

  return 0;
}
