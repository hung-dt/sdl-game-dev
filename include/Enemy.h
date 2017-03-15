#ifndef ENEMY_H
#define ENEMY_H

#include <SDLGameObject.h>


class Enemy : public SDLGameObject
{
  public:
    Enemy(const LoaderParams*);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif // ENEMY_H
