#include <iostream>
#include "GameSDL.h"
#include "TextureManager.h"


GameSDL::GameSDL()
  : window_ (NULL), renderer_ (NULL), isRunning_ (false), currentFrame_ (0)
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

  // Load image
  TextureManager::instance()->load ("assets/animate-alpha.png", "animate", renderer_);

  isRunning_ = true;
  std::cout << "INFO: SDL initialized OK!" << std::endl;

  return true;
}


void GameSDL::render()
{
  // Set drawing color
  SDL_SetRenderDrawColor (renderer_, 34, 139, 34, 255);

  // Clear the window to the color
  SDL_RenderClear (renderer_);

  // Draw a static texture
  TextureManager::instance()->draw ("animate", 0, 0, 128, 82, renderer_);

  // Draw an animate texture
  TextureManager::instance()->drawFrame ("animate", 100, 100, 128, 82, 1, currentFrame_, renderer_);

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
  // Update window by moving to next frame to create animation
  currentFrame_ = int ( ( (SDL_GetTicks() / 100) % 6));
}


void GameSDL::clean()
{
}


bool GameSDL::isRunning()
{
  return isRunning_;
}
