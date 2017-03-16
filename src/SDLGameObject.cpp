#include <SDL2/SDL.h>
#include "GameSDL.h"
#include "TextureManager.h"
#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* params)
: GameObject(params),
  position_(params->x(), params->y()),
  velocity_(0, 0),
  acceleration_(0, 0)
{
  width_ = params->width();
  height_ = params->height();
  textureId_ = params->textureId();

  currentRow_ = 1;
  currentFrame_ = 1;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void SDLGameObject::draw()
{
  TextureManager::instance().drawFrame(textureId_,
                                       position_.x(), position_.y(), width_, height_,
                                       currentRow_, currentFrame_,
                                       GameSDL::instance().renderer());
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void SDLGameObject::update()
{
  velocity_ += acceleration_;
  position_ += velocity_;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void SDLGameObject::clean()
{
}
