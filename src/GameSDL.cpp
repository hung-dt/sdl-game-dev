#include <iostream>
#include "GameSDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"


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


/** Return a single unique instance of GameSDL
 */
GameSDL& GameSDL::instance()
{
  static GameSDL instance_;
  return instance_;
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

  // Load texture image
  TextureManager::instance().load ("assets/animate-alpha.png", "animate", renderer_);

  gameObjects_.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
  gameObjects_.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

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

  // Draw all game objects
  for (auto go : gameObjects_) {
    go->draw();
  }

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
  // Update all game objects
  for (auto go : gameObjects_) {
    go->update();
  }
}


void GameSDL::clean()
{
}


bool GameSDL::isRunning()
{
  return isRunning_;
}

SDL_Renderer* GameSDL::renderer() const
{
  return renderer_;
}
