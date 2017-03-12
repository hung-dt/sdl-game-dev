#ifndef GAMESDL_H
#define GAMESDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


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

    SDL_Texture* texture_;    /**< HW-accelerated rendering */
    SDL_Rect srcRect_;        /**< Area of texture to draw on window */
    SDL_Rect desRect_;        /**< Area on window to draw texture on */

    bool isRunning_;          /**< Game loop condition */
};

#endif // GAMESDL_H
