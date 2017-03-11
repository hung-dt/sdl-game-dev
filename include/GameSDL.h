#ifndef GAMESDL_H
#define GAMESDL_H

#include <SDL2/SDL.h>


class GameSDL
{
  public:
    /** Default constructor */
    GameSDL();

    /** Default destructor */
    ~GameSDL();

    bool init(const char*, int, int, int, int, int);
    void render();
    void update();
    void handleEvents();
    void clean();

    bool isRunning();

  private:
    SDL_Window* window_;      /**< The window we'll be rendering to */
    SDL_Renderer* renderer_;  /**< Renderer */
    bool isRunning_;          //!< Member variable "isRunning_"
};

#endif // GAMESDL_H
