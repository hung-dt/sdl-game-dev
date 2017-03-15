#include <SDL2/SDL.h>
#include "GameSDL.h"
#include "TextureManager.h"
#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* params)
: GameObject(params)
{
  x_ = params->x();
  y_ = params->y();
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
                                       x_, y_, width_, height_,
                                       currentRow_, currentFrame_,
                                       GameSDL::instance().renderer());
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void SDLGameObject::update()
{
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void SDLGameObject::clean()
{
}
