#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include <GameObject.h>
#include "LoaderParams.h"


class SDLGameObject : public GameObject
{
  public:
    SDLGameObject(const LoaderParams*);

    virtual void draw();
    virtual void update();
    virtual void clean();

  protected:
    int x_, y_, width_, height_, currentRow_, currentFrame_;
    std::string textureId_;
};

#endif // SDLGAMEOBJECT_H
