#include <iostream>
#include "InputHandler.h"
#include "GameSDL.h"

InputHandler::InputHandler()
{

}

InputHandler::~InputHandler()
{

}


InputHandler& InputHandler::instance()
{
  static InputHandler instance_;
  return instance_;
}

void InputHandler::update()
{
  SDL_Event e;
  // Handle events on queue: take the most recent event from the queue
  while (SDL_PollEvent (&e) != 0) {
    // User requests quit
    if (e.type == SDL_QUIT) {
      GameSDL::instance().quit();
    }
  }
}

/** Close all opened joysticks
 */
void InputHandler::clean()
{
  for (int i = 0; i < joysticks_.size(); i++) {
    SDL_JoystickClose(joysticks_[i]);
  }
}

void InputHandler::initializeJoysticks()
{
  if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
  }

  if (SDL_NumJoysticks() > 0) {
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
      SDL_Joystick* js = SDL_JoystickOpen(i);
      if (js) {
        joysticks_.push_back(js);
      } else {
        std::cout << "ERROR: Cannot open joystick: " << SDL_GetError() << std::endl;
      }
    }
    SDL_JoystickEventState(SDL_ENABLE);
    joysticksInitialized_ = true;
    std::cout << "INFO: Initialized " << joysticks_.size() << " joysticks" << std::endl;
  } else {
    joysticksInitialized_ = false;
  }
}
