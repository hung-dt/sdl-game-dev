#include <SDL2/SDL.h>
#include "Player.h"

Player::Player(const LoaderParams* params)
: SDLGameObject(params)
{
  //ctor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Player::draw()
{
  SDLGameObject::draw();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Player::update()
{
  currentFrame_ = int((SDL_GetTicks()/100) % 6);

  acceleration_.x(.01);

  SDLGameObject::update();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Player::clean()
{
}

