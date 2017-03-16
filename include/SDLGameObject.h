#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include <GameObject.h>
#include "LoaderParams.h"
#include "Vector2D.h"


class SDLGameObject : public GameObject
{
  public:
    SDLGameObject(const LoaderParams*);

    virtual void draw();
    virtual void update();
    virtual void clean();

  protected:
    Vector2D position_;
    Vector2D velocity_;
    Vector2D acceleration_;
    int width_, height_, currentRow_, currentFrame_;
    std::string textureId_;
};

#endif // SDLGAMEOBJECT_H
