#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include <string>


class LoaderParams
{
  public:
    LoaderParams(int x, int y, int w, int h, const std::string&);
    int x() const;
    int y() const;
    int width() const;
    int height() const;
    std::string textureId() const;

  private:
    int x_, y_, width_, height_;
    std::string textureId_;
};

#endif // LOADERPARAMS_H
