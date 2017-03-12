#include <iostream>
#include <SDL2/SDL_image.h>

#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
  std::cout << "INFO: Quit TextureManager";
  // Clean up resources
  if (!textures_.empty()) {
    for (std::map<std::string, SDL_Texture*>::iterator it = textures_.begin();
         it != textures_.end(); it++) {
      SDL_DestroyTexture (it->second);
    }
    std::cout << " and cleanup textures";
  }
  std::cout << std::endl;
}

TextureManager* TextureManager::instance_ = NULL;

TextureManager* TextureManager::instance()
{
  if (!instance_) {
    instance_ = new TextureManager();
    return instance_;
  }

  return instance_;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool TextureManager::load (std::string fileName,
                           std::string id,
                           SDL_Renderer* renderer)
{
  // Load sprite image
  SDL_Surface* surface = IMG_Load (fileName.c_str());
  if (!surface) {
    std::cout << "ERROR: Could not load image '" << fileName << "': "
              << SDL_GetError() << std::endl;
    return false;
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface (renderer, surface);
  SDL_FreeSurface (surface);

  if (!texture) {
    std::cout << "ERROR: Could not create texture from surface: "
              << SDL_GetError() << std::endl;
    return false;
  }

  // Texture loaded OK, add it to the list
  textures_[id] = texture;
  return true;
}


/** @brief Draw the texture id on screen
  *
  * (documentation goes here)
  */
void TextureManager::draw (std::string id,
                           int x, int y, int w, int h,
                           SDL_Renderer* renderer,
                           SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x = srcRect.y = 0;
  srcRect.w = desRect.w = w;
  srcRect.h = desRect.h = h;
  desRect.x = x;
  desRect.y = y;

  SDL_RenderCopyEx (renderer, textures_[id], &srcRect, &desRect, 0.0, NULL, flip);
}


/** @brief Draw the current frame of the texture on screen.
  *
  * (documentation goes here)
  */
void TextureManager::drawFrame (std::string id,
                                int x, int y, int w, int h,
                                int currentRow, int currentFrame,
                                SDL_Renderer* renderer,
                                SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x = w * currentFrame;
  srcRect.y = h * (currentRow - 1);
  srcRect.w = desRect.w = w;
  srcRect.h = desRect.h = h;
  desRect.x = x;
  desRect.y = y;

  SDL_RenderCopyEx (renderer, textures_[id], &srcRect, &desRect, 0.0, NULL, flip);
}

