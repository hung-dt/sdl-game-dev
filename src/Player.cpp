#include <SDL2/SDL.h>
#include "Player.h"
#include "InputHandler.h"


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

  //acceleration_.x(.01);
  Vector2D* v = InputHandler::instance().mousePosition();
  velocity_ = (*v - position_) / 100;

  SDLGameObject::update();
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Player::clean()
{
}

