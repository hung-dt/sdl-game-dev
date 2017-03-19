#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <vector>
#include <SDL2/SDL.h>


enum mouse_buttons
{
  LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
};

class InputHandler
{
  public:
    static InputHandler& instance();

    void update();
    void clean();

    void initializeJoysticks();
    bool joysticksInitialized();

    bool mouseButtonState(int) const;

  private:
    InputHandler();
    ~InputHandler();
    InputHandler(const InputHandler&);
    const InputHandler& operator=(const InputHandler&);

    std::vector<SDL_Joystick*> joysticks_;
    bool joysticksInitialized_;

    std::vector<bool> mouseButtonStates_;
};

#endif // INPUTHANDLER_H
