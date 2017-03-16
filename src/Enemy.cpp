#include <SDL2/SDL.h>
#include "Enemy.h"

Enemy::Enemy(const LoaderParams* params)
: SDLGameObject(params)
{
  //ctor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Enemy::draw()
{
  SDLGameObject::draw();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Enemy::update()
{
  currentFrame_ = int((SDL_GetTicks()/100) % 6);
  velocity_.x(1);
  velocity_.y(1);

  SDLGameObject::update();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Enemy::clean()
{
}

