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
  x_--;
  currentFrame_ = int((SDL_GetTicks()/100) % 6);
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Player::clean()
{
}

