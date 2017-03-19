#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <vector>
#include <SDL2/SDL.h>


class InputHandler
{
  public:
    static InputHandler& instance();

    void update();
    void clean();

    void initializeJoysticks();
    bool joysticksInitialized();

  private:
    InputHandler();
    ~InputHandler();
    InputHandler(const InputHandler&);
    const InputHandler& operator=(const InputHandler&);

    std::vector<SDL_Joystick*> joysticks_;
    bool joysticksInitialized_;
};

#endif // INPUTHANDLER_H
