#include <iostream>
#include "InputHandler.h"
#include "GameSDL.h"

InputHandler::InputHandler()
{
  for (int i = 0; i < 3; i++) {
    mouseButtonStates_.push_back(false);
  }
  mousePosition_ = new Vector2D(0, 0);
}

InputHandler::~InputHandler()
{
  delete mousePosition_;
}


InputHandler& InputHandler::instance()
{
  static InputHandler instance_;
  return instance_;
}

void InputHandler::update()
{
  SDL_Event e;

  keyStates_ = SDL_GetKeyboardState(0);

  // Handle events on queue: take the most recent event from the queue
  while (SDL_PollEvent (&e) != 0) {
    // User requests quit
    if (e.type == SDL_QUIT) {
      GameSDL::instance().quit();
    }

    if (e.type == SDL_MOUSEBUTTONDOWN) {
      if (e.button.button == SDL_BUTTON_LEFT) {
        mouseButtonStates_[LEFT] = true;
      }

      if (e.button.button == SDL_BUTTON_MIDDLE) {
        mouseButtonStates_[MIDDLE] = true;
      }

      if (e.button.button == SDL_BUTTON_RIGHT) {
        mouseButtonStates_[RIGHT] = true;
      }
    }

    if (e.type == SDL_MOUSEBUTTONUP) {
      if (e.button.button == SDL_BUTTON_LEFT) {
        mouseButtonStates_[LEFT] = false;
      }

      if (e.button.button == SDL_BUTTON_MIDDLE) {
        mouseButtonStates_[MIDDLE] = false;
      }

      if (e.button.button == SDL_BUTTON_RIGHT) {
        mouseButtonStates_[RIGHT] = false;
      }
    }

    if (e.type == SDL_MOUSEMOTION) {
      mousePosition_->x(e.motion.x);
      mousePosition_->y(e.motion.y);
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


bool InputHandler::mouseButtonState(int buttonNumber) const
{
  return mouseButtonStates_[buttonNumber];
}

Vector2D* InputHandler::mousePosition() const
{
  return mousePosition_;
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
  if (keyStates_) {
    return (keyStates_[key] == 1);
  }
  return false;
}
