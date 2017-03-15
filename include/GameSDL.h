#ifndef GAMESDL_H
#define GAMESDL_H

#include <SDL2/SDL.h>

#include <vector>

#include "GameObject.h"

/**
 * Singleton game class
 */
class GameSDL
{
public:
  static GameSDL& instance();
  bool init (const char*, int, int, int, int, int);
  void render();
  void update();
  void handleEvents();
  void clean();
  SDL_Renderer* renderer() const;
  bool isRunning();

private:
  GameSDL();
  ~GameSDL();
  GameSDL(const GameSDL&);
  const GameSDL& operator=(const GameSDL&);

  SDL_Window* window_;      /**< The window we'll be rendering to */
  SDL_Renderer* renderer_;  /**< Renderer */

  bool isRunning_;          /**< Game loop condition */
  int currentFrame_;        /**< Which frame we are rendering */

  std::vector<GameObject*> gameObjects_;
};

#endif // GAMESDL_H
