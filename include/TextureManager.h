#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <SDL2/SDL.h>


/** A singleton class to manage texture loading and drawing
 */
class TextureManager
{
public:
  bool load (std::string, std::string, SDL_Renderer*);

  void draw (std::string id,
             int x, int y, int w, int h,
             SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawFrame (std::string id,
                  int x, int y, int w, int h, int currentRow, int currentFrame,
                  SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  static TextureManager& instance();

private:
  TextureManager();
  ~TextureManager();
  TextureManager(const TextureManager&);
  const TextureManager& operator=(const TextureManager&);

  std::map<std::string, SDL_Texture*> textures_;
};

#endif // TEXTUREMANAGER_H
