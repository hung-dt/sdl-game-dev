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
  x_++;
  y_++;
  currentFrame_ = int((SDL_GetTicks()/100) % 6);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Enemy::clean()
{
}

