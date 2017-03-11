#include <iostream>
#include "GameSDL.h"


GameSDL::GameSDL()
  : window_ (NULL), renderer_ (NULL), texture_(NULL), isRunning_ (false)
{
  //ctor
}


/** Clean up SDL resources and quit
 */
GameSDL::~GameSDL()
{
  std::cout << "INFO: Clean up SDL and quit!" << std::endl;
  SDL_DestroyWindow (window_);
  SDL_DestroyRenderer (renderer_);
  SDL_DestroyTexture(texture_);
  SDL_Quit();
}


/** Initialize SDL subsystems
 *
 * \param title Title of the rendering window
 * \param
 * \return
 *
 */
bool GameSDL::init (const char* title,
                    int xPos, int yPos,
                    int width, int height,
                    int flags)
{
  // Initialize SDL
  if (SDL_Init (SDL_INIT_EVERYTHING) < 0) {
    std::cout << "ERROR: Unable to init SDL: " << SDL_GetError() << std::endl;
    return false;
  }

  // Create rendering window
  window_ = SDL_CreateWindow (title, xPos, yPos, width, height, flags);
  if (!window_) {
    std::cout << "ERROR: Unable to create window: " << SDL_GetError() << std::endl;
    return false;
  }

  // Get the renderer
  renderer_ = SDL_CreateRenderer (window_, -1, 0);

  // Load sprite image
  SDL_Surface* surface = SDL_LoadBMP("assets/rider.bmp");
  texture_ = SDL_CreateTextureFromSurface(renderer_, surface);
  SDL_FreeSurface(surface);

  // Get the dimensions of the texture
  SDL_QueryTexture(texture_, NULL, NULL, &srcRect_.w, &srcRect_.h);

  // Set the area dimensions we want to draw the texture on the window
  desRect_.w = srcRect_.w;
  desRect_.h = srcRect_.h;
  desRect_.x = srcRect_.x = 0;
  desRect_.y = srcRect_.y = 0;

  isRunning_ = true;
  std::cout << "INFO: SDL initialized OK!" << std::endl;

  return true;
}


void GameSDL::render()
{
  // Set drawing color
  SDL_SetRenderDrawColor (renderer_, 0, 0, 0, 255);

  // Clear the window to the color
  SDL_RenderClear (renderer_);

  // Draw the texture
  SDL_RenderCopy(renderer_, texture_, &srcRect_, &desRect_);
  //SDL_RenderCopy(renderer_, texture_, NULL, NULL);

  // Show the window
  SDL_RenderPresent (renderer_);
}


void GameSDL::handleEvents()
{
  SDL_Event e;
  // Handle events on queue: take the most recent event from the queue
  while (SDL_PollEvent (&e) != 0) {
    // User requests quit
    if (e.type == SDL_QUIT) {
      isRunning_ = false;
    }
  }
}


void GameSDL::update()
{

}


void GameSDL::clean()
{
}


bool GameSDL::isRunning()
{
  return isRunning_;
}
